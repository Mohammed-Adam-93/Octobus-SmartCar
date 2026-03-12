# include <EnableInterrupt.h>
# include <PID_v1.h>

// Define motors pins
const int enA = 3;
const int inA1 = 2;
const int inA2= 4;
const int enB = 5;
const int inB1 = 7;
const int inB2 = 6;
const int enC = 10;
const int inC1 = 8;
const int inC2 = 9;
const int enD = 11;
const int inD1 = 13;
const int inD2 = 12;
// ---Inputs in rpm---
double rpmA = 60;         // Recommended between 60 and 150 RPM, this the
double rpmB = rpmA;       // user iput not the input used by the PID controller
double rpmC = 60;
double rpmD = rpmC;
// -- PID variables --
double SetpointA, InputA, OutputA;
double SetpointB, InputB, OutputB;
double SetpointC, InputC, OutputC;
double SetpointD, InputD, OutputD;
double KpA=0.2, KiA=0.2, KdA=0.0;      // These values are the same for all motors excepting MotorD
double KpB=0.2, KiB=0.2, KdB=0.0;
double KpC=0.2, KiC=0.2, KdC=0.0;
double KpD=0.21, KiD=0.27, KdD=0.0;    //KpD=0.19, KiD=0.23, KdD=0.0;

double previousTimeA=millis(); 
double previousTimeB=millis(); 
double previousTimeC=millis();
double previousTimeD=millis();
PID myPIDA(&InputA, &OutputA, &SetpointA, KpA, KiA,KdA, DIRECT);
PID myPIDB(&InputB, &OutputB, &SetpointB, KpB, KiB,KdB, DIRECT);
PID myPIDC(&InputC, &OutputC, &SetpointC, KpC, KiC,KdC, DIRECT);
PID myPIDD(&InputD, &OutputD, &SetpointD, KpD, KiD,KdD, DIRECT);

double sampleTime = 100;
double MAX_PWM = 255;
double MIN_PWM = 40;

// --- Define Encoder Pararmeters and the callbacks for the interrupt ---
const int entApin = A1; 
const int entBpin = A2; 
const int entCpin = A0; 
const int entDpin = A3; 
volatile long pulseCntA;
volatile long pulseCntB;
volatile long pulseCntC;
volatile long pulseCntD;

const unsigned long INT_Count = 40;          // 40 corresponds to the NO. encoder wheel slots

void encoderISRA(){
  pulseCntA++;
  if (pulseCntA >= INT_Count) {
    InputA =(double)INT_Count*1000/(double)(millis()-previousTimeA);
    previousTimeA = millis();
    pulseCntA = 0.0;
  }
}
void encoderISRB(){
  pulseCntB++;
  if (pulseCntB >= INT_Count) {
    InputB =(double)INT_Count*1000/(double)(millis()-previousTimeB);
    previousTimeB = millis();
    pulseCntB = 0.0;
  }
}
void encoderISRC(){
  pulseCntC++;
  if (pulseCntC >= INT_Count) {
    InputC =(double)INT_Count*1000/(double)(millis()-previousTimeC);
    previousTimeC = millis();
    pulseCntC = 0.0;
  }
}
void encoderISRD(){
  pulseCntD++;
  if (pulseCntD >= INT_Count) {
    InputD =(double)INT_Count*1000/(double)(millis()-previousTimeD);
    previousTimeD = millis();
    pulseCntD = 0.0;
  }
}

// --- Serial communication between Arduino and Raspberry Pi ---
char inputBuffer[80];
byte bufferIndex = 0;
// ___The message that will be sent___
//MOVE FWD 120
//TURN LEFT 80
//STOP
// ___Aknowkledgment to be sent after completion___
// Aknowledgement messages
//OK MOVE FWD 120
//OK TURN LEFT 80
//OK STOP

int flag = 0;

void setup() {
  // open the serial
  Serial.begin(115200);

  pinMode(entApin, INPUT_PULLUP);
  pinMode(entBpin, INPUT_PULLUP);
  pinMode(entCpin, INPUT_PULLUP);
  pinMode(entDpin, INPUT_PULLUP);

  enableInterrupt(entApin, encoderISRA, CHANGE);
  enableInterrupt(entBpin, encoderISRB, CHANGE);
  enableInterrupt(entCpin, encoderISRC, CHANGE);
  enableInterrupt(entDpin, encoderISRD, CHANGE);

  pinMode(enA, OUTPUT);
  pinMode(inA1, OUTPUT);
  pinMode(inA2, OUTPUT);
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, LOW);

  pinMode(enB, OUTPUT);
  pinMode(inB1, OUTPUT);
  pinMode(inB2, OUTPUT);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, LOW);

  pinMode(enC, OUTPUT);
  pinMode(inC1, OUTPUT);
  pinMode(inC2, OUTPUT);
  digitalWrite(inC1, LOW);
  digitalWrite(inC2, LOW);

  pinMode(enD, OUTPUT);
  pinMode(inD1, OUTPUT);
  pinMode(inD2, OUTPUT);
  digitalWrite(inD1, LOW);
  digitalWrite(inD2, LOW);

  myPIDA.SetMode(AUTOMATIC);
  myPIDB.SetMode(AUTOMATIC);
  myPIDC.SetMode(AUTOMATIC);
  myPIDD.SetMode(AUTOMATIC);
  myPIDA.SetOutputLimits(MIN_PWM, MAX_PWM);
  myPIDB.SetOutputLimits(MIN_PWM, MAX_PWM);
  myPIDC.SetOutputLimits(MIN_PWM, MAX_PWM);
  myPIDD.SetOutputLimits(MIN_PWM, MAX_PWM);
  myPIDA.SetSampleTime(sampleTime);
  myPIDB.SetSampleTime(sampleTime);
  myPIDC.SetSampleTime(sampleTime);
  myPIDD.SetSampleTime(sampleTime);
}

void loop() {
  if (flag == 1){computeSentPWM();}
  while (Serial.available() > 0){
    char c = Serial.read();

    if (c == '\n'){
      inputBuffer[bufferIndex] = '\0';
      parseCommand(inputBuffer);
      bufferIndex = 0;
    }else{
      // prevents overflow
      if (bufferIndex < sizeof(inputBuffer)){
        inputBuffer[bufferIndex++] = c;
      }
    }
  }
}

void parseCommand(char *cmd){
  char *token = strtok(cmd, " ");
  if (token == NULL) return;

  if (strcmp(token, "MOVE") == 0){
    char *dir = strtok(NULL, " ");
    char *speed = strtok(NULL, " ");
    Serial.print("OK MOVE, DIR=");
    Serial.print(dir);
    Serial.print(", SPEED=");
    Serial.println(speed);
    double speedValue = atof(speed);
    speedControl(speedValue, dir);
    return;
  }
  if (strcmp(token, "TURN") == 0){
    char *dir = strtok(NULL, " ");
    char *speed = strtok(NULL, " ");
    Serial.print("OK TURN, DIR=");
    Serial.print(dir);
    Serial.print(", SPEED=");
    Serial.println(speed);
    double speedValue = atof(speed);
    turn(speedValue, dir);
    flag = 1;
    return;
  }
  if (strcmp(token, "STOP") == 0){
    Serial.println("OK STOP");
    stop();
    return;
  }
  Serial.print("ERR Unknown command: ");
  Serial.println(token);

}


// This function lets you control speed of the motors
void speedControl(double speed, String dir) {
  if (dir == "FWD"){
  forward();
  SetpointA = speed * 40  / 60;        //number of pulses in one second, you turn your real input(rpm) to NO. pulses per second
  SetpointB = speed * 40 / 60;
  SetpointC = speed * 40 / 60;
  SetpointD = speed * 40 / 60;
  }
  
  if (dir == "BWD"){
  backward();
  SetpointA = speed * 40  / 60;        //number of pulses in one second, you turn your real input(rpm) to NO. pulses per second
  SetpointB = speed * 40 / 60;
  SetpointC = speed * 40 / 60;
  SetpointD = speed * 40 / 60;
  }
  computeSentPWM();
}

void stop(){
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, LOW);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, LOW);
  digitalWrite(inC1, LOW);
  digitalWrite(inC2, LOW);
  digitalWrite(inD1, LOW);
  digitalWrite(inD2, LOW);
}

void backward(){
  digitalWrite(inA1, HIGH);
  digitalWrite(inA2, LOW);
  digitalWrite(inB1, HIGH);
  digitalWrite(inB2, LOW);
  digitalWrite(inC1, HIGH);
  digitalWrite(inC2, LOW);
  digitalWrite(inD1, HIGH);
  digitalWrite(inD2, LOW);
}

void forward(){
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, HIGH);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
  digitalWrite(inC1, LOW);
  digitalWrite(inC2, HIGH);
  digitalWrite(inD1, LOW);
  digitalWrite(inD2, HIGH);
}

void turn(double rpm, String dir){
  if (dir == "RIGHT" || dir == "FWD_RIGHT"){
    forward();
    SetpointA = (rpm*(200.0-68.0)/66.8)*40/60;
    SetpointB = (rpm*(200.0-68.0)/66.8)*40/60;
    SetpointC = (rpm*(200.0+68.0)/66.8)*40/60;
    SetpointD = (rpm*(200.0+68.0)/66.8)*40/60;
  }else if(dir == "LEFT" || dir == "FWD_LEFT"){
    forward();
    SetpointA = (rpm*(200.0+68.0)/66.8)*40/60;
    SetpointB = (rpm*(200.0+68.0)/66.8)*40/60;
    SetpointC = (rpm*(200.0-68.0)/66.8)*40/60;
    SetpointD = (rpm*(200.0-68.0)/66.8)*40/60;
  }else if(dir == "BWD_RIGHT"){
    backward();
    SetpointA = (rpm*(200.0-68.0)/66.8)*40/60;
    SetpointB = (rpm*(200.0-68.0)/66.8)*40/60;
    SetpointC = (rpm*(200.0+68.0)/66.8)*40/60;
    SetpointD = (rpm*(200.0+68.0)/66.8)*40/60;
  }else if(dir == "BWD_LEFT"){
    backward();
    SetpointA = (rpm*(200.0+68.0)/66.8)*40/60;
    SetpointB = (rpm*(200.0+68.0)/66.8)*40/60;
    SetpointC = (rpm*(200.0-68.0)/66.8)*40/60;
    SetpointD = (rpm*(200.0-68.0)/66.8)*40/60;
  }else{
    Serial.println("Ivalid Turn parameters");
  }
  
  computeSentPWM(); 
}

void computeSentPWM(){
  myPIDA.Compute();
  myPIDB.Compute();
  myPIDC.Compute();
  myPIDD.Compute();
  analogWrite(enA, OutputA);
  analogWrite(enB, OutputB);
  analogWrite(enC, OutputC);
  analogWrite(enD, OutputD);
}