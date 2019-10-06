#include <Servo.h>

const int ANALOG_PIN = A0; 
#define SERVO_PIN 12

Servo my_servo;

void setup() 
{
  Serial.begin(9600);
  my_servo.attach(SERVO_PIN);
}

void loop() 
{
  int pot_value;
  int servo_val;

  pot_value = analogRead(ANALOG_PIN);

  servo_val = map(pot_value, 0, 1023, 0, 180);

  my_servo.write(servo_val);

  delay(10);

}
