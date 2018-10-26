#include <Servo.h>
#include "robot.h"
//def de pins de commande des servos
int m = 2;  //middle
int r = 3;  //right
int l = 4;  //left
int c = 5;  //claw
int tempsRebond = 10;
int temps;
//def des pins de lecture analogique des servos
unsigned long mid = A0;
unsigned long ri = A1;
unsigned long le = A2;
unsigned long cla = A3;

//def angles initiaux
int angleMid = 90;
int angleRight = 90;
int angleLeft = 90;
int angleClaw = 90;

//def servos
Servo middle, right, left, claw;


Cervo MID, RIGHT, LEFT;

Pince CLAW;

void setup() {
  Serial.begin(9600);
  temps = millis() - tempsRebond;
  
  middle.attach(m);
  right.attach(r);
  left.attach(l);
  claw.attach(c);

  middle.write(angleMid);
  right.write(angleRight);
  left.write(angleLeft);
  claw.write(angleClaw);

  MID.init(m, mid, angleMid);
  MID.bornes(10, 170);
  MID.vitesse(5);
  
  RIGHT.init(r, ri, angleRight);
  RIGHT.bornes(10, 170);
  RIGHT.vitesse(5);
  
  LEFT.init(l, le, angleLeft);
  LEFT.bornes(10, 170);
  LEFT.vitesse(5);
  
  CLAW.init(180, 0, cla, temps, tempsRebond);
}

void loop() {
  int delai = 70; //Delai modifiable ici
  
  MID.pilotage();
  angleMid = MID.getAngle();
  RIGHT.pilotage();
  angleRight = RIGHT.getAngle();
  LEFT.pilotage();
  angleLeft = LEFT.getAngle();
  
  CLAW.pilotagePince();
  angleClaw = CLAW.getAngle();

  int A,B;
  A,B = CLAW.getEtats();
  
  Serial.println(A,B);
  ecritureAngles(angleMid, angleClaw, angleRight, angleLeft);
  delay(delai);
}

void ecritureAngles(int angleMid, int angleClaw, int angleRight, int angleLeft) {
  middle.write(angleMid);
  claw.write(angleClaw);
  right.write(angleRight);
  left.write(angleLeft);
}


