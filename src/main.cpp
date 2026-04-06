#include <Arduino.h>
#include <ESP32Servo.h>

#define TRIG 5
#define ECHO 18
#define SERVO_PIN 13

Servo servo;

float readDistance(){
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  float duration = pulseIn(ECHO, HIGH);
  float distance = duration * 0.034 / 2;

  return distance;
}

void setup() {
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  servo.attach(SERVO_PIN);
}

void loop() {
  // indo
  for (int angle = 0; angle <=150; angle++){
   servo.write(angle);
   delay(5);

   float dist = readDistance();

   Serial.print(angle);
   Serial.print(" / ");
   Serial.println(dist);
  }

  // voltando
  for (int angle = 150; angle >= 0; angle--) {
    servo.write(angle);
    delay(5);

    long dist = readDistance();

    Serial.print(angle);
    Serial.print(",");
    Serial.println(dist);
  }
}
