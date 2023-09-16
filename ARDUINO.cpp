#include <Servo.h>

const int redPin = 9;
const int yellowPin = 10;
const int greenPin = 11;
const int trigPin = 2;
const int echoPin = 3;

Servo trafficLight;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  trafficLight.attach(5);
  
  // Initialize the traffic light to red
  trafficLight.write(0);
  digitalWrite(redPin, HIGH);
}

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  
  if (distance < 10) {
    // If an object is detected within 10cm, change the traffic light
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    trafficLight.write(90);  // Change the servo angle to rotate the arm
    delay(5000);  // Allow some time for the vehicle to pass
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    delay(2000);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, HIGH);
    trafficLight.write(0);  // Reset the servo arm to the red position
  }
}
