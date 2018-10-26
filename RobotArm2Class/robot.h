#ifndef ROBOT_H
#define ROBOT_H

class Cervo {
  public: //methodes
    void init(int pin0, unsigned long analogPin0, int angle0);
    void bornes(int angleMin0, int angleMax0);
    void vitesse(int vitesseMax0);
    int getAngle();
    int getDangle();
    void pilotage();

  private://attributs
    int pin;
    unsigned long analogPin;
    int angle;
    int dAngle = 0;
    int angleMax;
    int angleMin;
    int vitesseMax;
};

class Pince {
  public:
    void init(int angleMax0, int angleMin0, unsigned long analogPin0, unsigned long temps0, unsigned long tempsRebond0);
    void pilotagePince();
    int getAngle();
    int getEtats();
  private:
    int etatA = 0;
    int etatB = 0;
    int ouvert = 0;
    int angleMax;
    int angleMin;
    int angle = 80;
    unsigned long analogPin;
    unsigned long temps;
    unsigned long tempsRebond;
};
#endif
