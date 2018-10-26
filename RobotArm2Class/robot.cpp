#include "robot.h"
#include <Arduino.h>

void Cervo::init(int pin0, unsigned long analogPin0, int angle0) {
  pin = pin0;
  analogPin = analogPin0;
  angle = angle0;

}
void Cervo::bornes(int angleMin0, int angleMax0) {
  angleMin = angleMin0;
  angleMax = angleMax0;
}
void Cervo::vitesse(int vitesseMax0) {
  vitesseMax = vitesseMax0;
}
int Cervo::getAngle() {
  return angle;
}
int Cervo::getDangle() {
  return dAngle;
}
void Cervo::pilotage() {
  dAngle = map(analogRead(analogPin), 0, 1023, -vitesseMax, vitesseMax + 2);
  dAngle = constrain(dAngle, -vitesseMax, vitesseMax);
  angle = angle + dAngle;
  angle = constrain(angle, angleMin, angleMax);
}

void Pince::init(int angleMax0, int angleMin0, unsigned long analogPin0, unsigned long temps0, unsigned long tempsRebond0) {
  analogPin = analogPin0;
  angleMax = angleMax0;
  angleMin = angleMin0;
  temps = temps0;
  tempsRebond = tempsRebond0;
}
int Pince::getEtats(){
  return etatA,etatB;
}
void Pince::pilotagePince() {
  etatB = etatA;
  etatA = digitalRead(analogPin);
  if (!etatB && etatA && millis() - temps >= tempsRebond) {
    ouvert = !ouvert;
  }
  if (ouvert == 1) {
    angle = angleMax;
  }
  else {
    angle = angleMin;
  }
}
int Pince::getAngle() {
  return angle;
}
