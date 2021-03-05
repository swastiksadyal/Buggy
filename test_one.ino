 
#define BRAKEVCC 0
#define CW   1
#define CCW  2
#define BRAKEGND 3
#define CS_THRESHOLD 100

/*  VNH2SP30 pin definitions
 xxx[0] controls '1' outputs
 xxx[1] controls '2' outputs */
int inApin[2] = {7, 4};  // INA: Clockwise input
int inBpin[2] = {8, 9}; // INB: Counter-clockwise input
int pwmpin[2] = {5, 6}; // PWM input
int cspin[2] = {2, 3}; // CS: Current sense ANALOG input
int enpin[2] = {0, 1}; // EN: Status of switches output (Analog pin)
int statpin = 11;

// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 13; 
// Create a servo object 
Servo Servo1;
 void setup()  
 {  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); 
  pinMode(statpin, OUTPUT);
  Servo1.attach(servoPin);

  // Initialize digital pins as outputs
  for (int i=0; i<2; i++)
  {
    pinMode(inApin[i], OUTPUT);
    pinMode(inBpin[i], OUTPUT);
    pinMode(pwmpin[i], OUTPUT);
  }
  // Initialize braked
  for (int i=0; i<2; i++)
  {
    digitalWrite(inApin[i], LOW);
    digitalWrite(inBpin[i], LOW);
  }
  // motorGo(0, CW, 1023);
  // motorGo(1, CCW, 1023) 
 } 
 void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)
{
  if (motor <= 1)
  {
    if (direct <=4)
    {
      // Set inA[motor]
      if (direct <=1)
        digitalWrite(inApin[motor], HIGH);
      else
        digitalWrite(inApin[motor], LOW);

      // Set inB[motor]
      if ((direct==0)||(direct==2))
        digitalWrite(inBpin[motor], HIGH);
      else
        digitalWrite(inBpin[motor], LOW);

      analogWrite(pwmpin[motor], pwm);
    }
  }
}
/* motorGo() will set a motor going in a specific direction
 the motor will continue going in that direction, at that speed
 until told to do otherwise.
 
 motor: this should be either 0 or 1, will selet which of the two
 motors to be controlled
 
 direct: Should be between 0 and 3, with the following result
 0: Brake to VCC
 1: Clockwise
 2: CounterClockwise
 3: Brake to GND
 
 pwm: should be a value between ? and 1023, higher the number, the faster
 it'll go
 */
 void motorOff(int motor)
{
  // Initialize braked
  for (int i=0; i<2; i++)
  {
    digitalWrite(inApin[i], LOW);
    digitalWrite(inBpin[i], LOW);
  }
  analogWrite(pwmpin[motor], 0);
}


 
 void loop()  
 {  
  if(Serial.available())  
  {  
   String c = Serial.readString();
   char bum = c[0];
   // do aga
   if (bum == 'W')
   {
    Serial.print("forward");// wait for a second  
    motorGo(1, CW, 1000);
    motorGo(0, CCW, 1000);
    delay(500);
   }
   else if (bum == 'S'){
    Serial.print("Back");
    motorGo(1, CCW, 1000);
    motorGo(0, CCW, 1000);
    delay(500);
   }
   else if (bum == 'L'){
    Serial.print("Left move fixed");
    Servo1.write(150);
   }
  else if (bum == 'R'){
    Serial.print("Right move fixed");
    Servo1.write(15);
   }
 else if (bum == 'A'){
    Serial.print("move left forward");
   }
   else if (bum == 'D'){
    Serial.print("Move right forward");
   }
  else if (bum == 'Z'){
    Serial.print("Back left");
   }
  else if (bum == 'C'){
    Serial.print("Back right");
   }
   else{
    Serial.print("But world didnt worked!");
    Serial.print(bum);
   }}
  }    
