// Yep, this is actually -*- c++ -*-
#include <AFMotor.h>
#include <Servo.h> 

// Connect a stepper motor with 48 steps per revolution (7.5 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor(48, 2);

Servo myservo;

#define MAX_POS 2000
#define DELTA_POS 10
int position = 1000;

void setup() {
  myservo.attach(10); // Attach to servo 1

  Serial.begin(9600);
  Serial.println("Hello Piano!");

  motor.setSpeed(0); // RPM
}

String strbuf = "";
int inputval = 0;

void loop()
{
  //  Serial.println("---");
  if (Serial.available() > 0) {
    int c = Serial.read();
    strbuf += (char)c;
    if (c == '\r') {
      inputval = strbuf.toInt();
      strbuf = "";
      Serial.println(inputval);
      //      Serial.println("newline");
    }
  }

  int speed = inputval;
  if (speed >= 10) speed = 10;
  if (speed > 0) speed *= 6;
  if (speed <= -10) speed = -10;
  int rpm = abs(speed)*10;
  motor.setSpeed(rpm);
  if (speed >= 0) myservo.write(180);
  else myservo.write(80);

  if (speed != 0) {
    if (speed > 0) {
      //    if (speed > 0 && position < MAX_POS) {
      motor.step(DELTA_POS, FORWARD, SINGLE);
      //      motor.step(DELTA_POS, FORWARD, DOUBLE);
      position += DELTA_POS;
      Serial.println(position);
    }
    else if (speed < 0) {
      //    else if (speed < 0 && position > 0) {
      motor.step(DELTA_POS, FORWARD, SINGLE);
      // motor.step(DELTA_POS, FORWARD, DOUBLE);
      position -= DELTA_POS;
      Serial.println(position);
    }
  }
}
