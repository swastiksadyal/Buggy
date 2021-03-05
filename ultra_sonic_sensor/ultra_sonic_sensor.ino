const int out=12;
const int in=13;

// I have the VCC connected to 5v, GND to GND, Trig to pin 12, and Echo to pin 13.
//This is a very simple and useful ultrasonic sensor. 
//There are four pins that you would use to interface with the sensor: 
//VCC, Trig (signal output pin), Echo (signal input pin), and GND



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(out,OUTPUT);
  pinMode(in,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  long dur;
  long dis;

  digitalWrite(out,LOW);
  delayMicroseconds(2);

  digitalWrite(out,HIGH);
  delayMicroseconds(10);
  digitalWrite(out,LOW);

  dur=pulseIn(in,HIGH);

  Serial.println(String(dur));

  delay(100);
}
