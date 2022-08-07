
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

char pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin=(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  pos = Serial.read();
  if (Serial.available() > 0) {
    if (pos == 'R') {
     myservo.write(180);
      delay(100);

    }
    if (pos == 'L') {
     myservo.write(0);
      delay(100);}
  }
}
