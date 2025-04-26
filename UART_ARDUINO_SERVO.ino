#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Initialisation du PCA9685
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define NOMBRE_SERVO 14

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

String a = "";
String incomingByte = "";


// Tableau des positions
const int positions[NOMBRE_SERVO][2] = {
  //[min~150, max~450]
  {160, 450}, // 00 : A, bas, G
  {160, 450}, // 01 : A, bas, D
  {160, 450}, // 02 : A, bas, planche
  {160, 450}, // 03 : A, haut, G
  {160, 450}, // 04 : A, haut, D
  {160, 450}, // 05 : B, bas, GG
  {160, 450}, // 06 : B, bas, G
  {160, 450}, // 07 : B, bas, D
  {160, 450}, // 08 : B, bas, DD
  {160, 450}, // 09 : B, haut, planche
  {160, 450}, // 10 : B, haut, GG
  {160, 450}, // 11 : B, haut, G
  {160, 450}, // 12 : B, haut, D
  {160, 450}  // 13 : B, haut, planche
};


void mvtServo(int indiceServo, int Servoposition) {
  if (indiceServo < 0 || indiceServo >= NOMBRE_SERVO) return; // Sécurité indice
  if (Servoposition != 0 && Servoposition != 1) return;       // Sécurité position

  int pulse = positions[indiceServo][Servoposition];
  pwm.setPWM(indiceServo, 0, pulse);
}

/////////////////////////////////////////////////////////////////////
///////////////////    FONCTIONS DE MOUVEMENTS    ///////////////////
/////////////////////////////////////////////////////////////////////


/////////////////////   FONCTION FACE A   ///////////////////////

void A_bas_attrapper(){
  int id_liste_servo_bouger [2][2] = {{0, 1}, {1, 0}};

  for (int i=0; i < ARRAY_SIZE(id_liste_servo_bouger); i++) {
    mvtServo(id_liste_servo_bouger[i][0], id_liste_servo_bouger[i][1]);
  }
  return;
}

void A_bas_lacher(){
  int id_liste_servo_bouger [2][2] = {{0, 0}, {1, 1}};

  for (int i=0; i < ARRAY_SIZE(id_liste_servo_bouger); i++) {
    mvtServo(id_liste_servo_bouger[i][0], id_liste_servo_bouger[i][1]);
  }
  return;
}

void A_haut_attrapper(){
  int id_liste_servo_bouger [2][2] = {{2, 0}, {3, 1}};

  for (int i=0; i < ARRAY_SIZE(id_liste_servo_bouger); i++) {
    mvtServo(id_liste_servo_bouger[i][0], id_liste_servo_bouger[i][1]);
  }
  return;
}

void A_haut_lacher(){
  int id_liste_servo_bouger [2][2] = {{2, 1}, {3, 0}};

  for (int i=0; i < ARRAY_SIZE(id_liste_servo_bouger); i++) {
    mvtServo(id_liste_servo_bouger[i][0], id_liste_servo_bouger[i][1]);
  }
  return;
  return;
}

void A_planche_attrapper(){
  mvtServo(2, 1);
  return;
}

void A_planche_lacher(){
  mvtServo(2, 0);
  return;
}

/////////////////////   FONCTION FACE B   ///////////////////////

void B_bas_attrapper(){
  int id_liste_servo_bouger [4][2] = {{5, 1}, {6, 0}, {7, 1}, {8, 0}};

  for (int i=0; i < ARRAY_SIZE(id_liste_servo_bouger); i++) {
    mvtServo(id_liste_servo_bouger[i][0], id_liste_servo_bouger[i][1]);
  }
  return;
  return;
}

void B_bas_lacher(){
  int id_liste_servo_bouger [4][2] = {{5, 0}, {6, 1}, {7, 0}, {8, 1}};

  for (int i=0; i < ARRAY_SIZE(id_liste_servo_bouger); i++) {
    mvtServo(id_liste_servo_bouger[i][0], id_liste_servo_bouger[i][1]);
  }
  return;
}

void B_haut_attrapper(){
  int id_liste_servo_bouger [4][2] = {{10, 1}, {11, 0}, {12, 1}, {13, 0}};
  
  for (int i=0; i < ARRAY_SIZE(id_liste_servo_bouger); i++) {
    mvtServo(id_liste_servo_bouger[i][0], id_liste_servo_bouger[i][1]);
  }
  return;
}

void B_haut_lacher(){
  int id_liste_servo_bouger [4][2] = {{10, 0}, {11, 1}, {12, 0}, {13, 1}};
  
  for (int i=0; i < ARRAY_SIZE(id_liste_servo_bouger); i++) {
    mvtServo(id_liste_servo_bouger[i][0], id_liste_servo_bouger[i][1]);
  }
  return;
}

void B_planche_attrapper(){
  mvtServo(9, 1);
  return;
}

void B_planche_lacher(){
  mvtServo(9, 0);
  return;
}


/////////////////////////////////////////////////////////////////////
//////////////////    FONCTIONS DE SETUP & LOOP    //////////////////
/////////////////////////////////////////////////////////////////////

void switchCase(int valeurUART){

  switch (valeurUART){
    case 1101:
      A_bas_attrapper();
      Serial.println("A_bas_attrapper");
      break;

    case 1100:
      A_bas_lacher();
      Serial.println("A_bas_lacher");
      break;

    case 1111:
      A_haut_attrapper();
      Serial.println("A_haut_attrapper");
      break;
    
    case 1110:
      A_haut_lacher();
      Serial.println("A_haut_lacher");
      break;
    
    case 1011:
      A_planche_attrapper();
      Serial.println("A_planche_attrapper");
      break;
    
    case 1010:
      A_planche_lacher();
      Serial.println("A_planche_lacher");
      break;
    
    case 1201:
      B_bas_attrapper();
      Serial.println("B_bas_attrapper");
      break;
    
    case 1200:
      B_bas_lacher();
      Serial.println("B_bas_lacher");
      break; 
       
    case 1211:
      B_haut_attrapper();
      Serial.println("B_haut_attrapper");
      break;
     
    case 1210:
      B_haut_lacher();
      Serial.println("B_haut_lacher");
      break;  
      
    case 1021:
      B_planche_attrapper();
      Serial.println("B_planche_attrapper");
      break;  
      
    case 1020:
      B_planche_lacher();
      Serial.println("B_planche_lacher");
      break;
    
    default:
      Serial.println("ERREUR SWITCH");
      break;
    
  }
  
  return;
}

void setup() {
  pwm.begin();
  pwm.setPWMFreq(50);
  
  Serial.begin(115200);

}

void loop() {
  if(Serial.available() > 0){
    int valeurRecue;
    a = Serial.readStringUntil('\n');

    //Serial.println("Received : "+a);
    if(a.length() >= 5) {
      Serial.println("ERREUR LECTURE");
      a = "";
      return;
    }

    valeurRecue = a.toInt();
    
    switchCase(valeurRecue);

    //Serial.println("Message send");
    a = "";
  }
  
}
