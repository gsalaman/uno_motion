#include <Servo.h>

const int ANALOG_PIN = A0; 
#define SERVO_PIN 12

#define STEP_PIN  2
#define DIR_PIN   3
#define MS1_PIN   4
#define MS2_PIN   5  
#define ENABLE_PIN 6

Servo my_servo;

void setup() 
{
  Serial.begin(9600);
  my_servo.attach(SERVO_PIN);

  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(MS1_PIN, OUTPUT);
  pinMode(MS2_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);

  //set step size.
  digitalWrite(ENABLE_PIN, LOW);
  digitalWrite(MS1_PIN, HIGH);
  digitalWrite(MS2_PIN, HIGH);
}

void loop() 
{
  int pot_value;
  int servo_val;

  pot_value = analogRead(ANALOG_PIN);

  servo_val = map(pot_value, 0, 1023, 0, 180);

  my_servo.write(servo_val);

  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(50);
  digitalWrite(STEP_PIN,LOW);
  delayMicroseconds(50);

}
