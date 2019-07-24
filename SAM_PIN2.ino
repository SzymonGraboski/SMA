//Projek SMA

#include <AccelStepper.h>
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Y2_STEP_PIN         46 //Z
#define Y2_DIR_PIN          48 //Z
#define Y2_ENABLE_PIN       62 //Z
#define Y2_MIN_PIN          18 //Z
#define Y2_MAX_PIN          19 //Z

#define P_STEP_PIN         26 //E0
#define P_DIR_PIN          28 //E0
#define P_ENABLE_PIN       24 //E0
#define P_MIN_PIN         1  //AUX1
#define P_MAX_PIN         3  //AUX1

#define F_STEP_PIN         36 //E01
#define F_DIR_PIN          34 //E01
#define F_ENABLE_PIN       30 //E01
#define F_MIN_PIN         44  //AUX2
#define F_MAX_PIN         2  //AUX1

#define ARC_PIN            10 //D10


AccelStepper Xaxis(1, X_STEP_PIN , X_DIR_PIN);
AccelStepper Yaxis(1, Y_STEP_PIN , Y_DIR_PIN);
AccelStepper Y2axis(1,Y2_STEP_PIN ,Y2_DIR_PIN);
AccelStepper Paxis(1, P_STEP_PIN , P_DIR_PIN);
AccelStepper Faxis(1, F_STEP_PIN , F_DIR_PIN);

void setup() {
  Xaxis.setMaxSpeed(400);
  Yaxis.setMaxSpeed(400);
  Y2axis.setMaxSpeed(400); 
  Faxis.setMaxSpeed(400);
  Paxis.setMaxSpeed(400);

  Xaxis.setSpeed(200);
  Yaxis.setSpeed(80);
  Y2axis.setSpeed(80);
  Paxis.setSpeed(80);  
  Faxis.setSpeed(80);
 
  pinMode(F_DIR_PIN, OUTPUT);
  digitalWrite(F_DIR_PIN, LOW);
   pinMode(P_DIR_PIN, OUTPUT);
  digitalWrite(P_DIR_PIN, LOW);
   pinMode(X_DIR_PIN, OUTPUT);
  digitalWrite(X_DIR_PIN, LOW);
   pinMode(Y_DIR_PIN, OUTPUT);
  digitalWrite(Y_DIR_PIN, LOW);
   pinMode(Y2_DIR_PIN, OUTPUT);
  digitalWrite(Y2_DIR_PIN, LOW);
   pinMode(Y2_DIR_PIN, OUTPUT);

   
   pinMode(F_STEP_PIN, OUTPUT);
  digitalWrite(F_STEP_PIN, LOW);
   pinMode(P_STEP_PIN, OUTPUT);
  digitalWrite(P_STEP_PIN, LOW);
   pinMode(X_STEP_PIN, OUTPUT);
  digitalWrite(X_STEP_PIN, LOW);
   pinMode(Y_STEP_PIN, OUTPUT);
  digitalWrite(Y_STEP_PIN, LOW);
   pinMode(Y2_STEP_PIN, OUTPUT);
  digitalWrite(Y2_STEP_PIN, LOW);
   pinMode(Y2_STEP_PIN, OUTPUT); 

    pinMode(F_ENABLE_PIN, OUTPUT);
  digitalWrite(F_ENABLE_PIN, LOW);
   pinMode(P_ENABLE_PIN, OUTPUT);
  digitalWrite(P_ENABLE_PIN, LOW);
   pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
   pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
   pinMode(Y2_ENABLE_PIN, OUTPUT);
  digitalWrite(Y2_ENABLE_PIN, LOW);
   pinMode(Y2_ENABLE_PIN, OUTPUT); 
  
    pinMode(ARC_PIN, OUTPUT);
  digitalWrite(ARC_PIN , LOW);

  pinMode(X_MIN_PIN , INPUT_PULLUP);
  pinMode(Y_MIN_PIN , INPUT_PULLUP);
  pinMode(Y2_MIN_PIN , INPUT_PULLUP);
  pinMode(F_MIN_PIN , INPUT_PULLUP);
  pinMode(P_MIN_PIN , INPUT_PULLUP);

  pinMode(X_MAX_PIN , INPUT_PULLUP);
  pinMode(Y_MAX_PIN , INPUT_PULLUP);
  pinMode(Y2_MAX_PIN , INPUT_PULLUP);
  pinMode(F_MAX_PIN , INPUT_PULLUP);
  pinMode(P_MAX_PIN , INPUT_PULLUP);
  }
 
  
    
     
  
  
   void loop()
{
   
   while(true)
   {
    homing(digitalRead(X_MIN_PIN)==HIGH, Xaxis);
    if(digitalRead(X_MIN_PIN)==LOW);
    {
      break;
    }
   }

   while(true)
   {
    homing(digitalRead(P_MIN_PIN)==HIGH, Paxis);
    if(digitalRead(P_MIN_PIN)==LOW);
    {
      break;
    }
   }

   while(true)
   {
    homing(digitalRead(F_MIN_PIN)==HIGH, Faxis);
    if(digitalRead(F_MIN_PIN)==LOW);
    {
      break;
    }
   }

   while(true)
   {
    homing(digitalRead(Y_MIN_PIN)==HIGH, Yaxis, Y2axis);
    if(digitalRead(Y_MIN_PIN)==LOW);
    {
      break;
    }
   }

   /*while(digitalRead(X_MIN_PIN)==HIGH){
     Xaxis.runSpeed();
     }

     while(digitalRead(P_MIN_PIN)==HIGH){
     Paxis.runSpeed();
    
     }
     while(digitalRead(F_MIN_PIN)==HIGH){
     Faxis.runSpeed();
    
     }
     
     while(digitalRead(Y_MIN_PIN)==HIGH){
     Yaxis.runSpeed();
     Y2axis.runSpeed();
     
    
     }

     */
  */
     
   /* przydałoby się wykonywać funkcje po przesłaniu na serial polecenia "home"
    *  Nastęnie po przesłaniu po serialu "feedadd" maszyna zczytuje ilosc map bitowych na karcie pamieci i zjerzdza tyle warstw w dół
    *  na serialu "start" feed wyjerzdza o warstwę print obniża o warstwę riko(y i y2) jadą nad przesyp i cofa się (Y i Y2) nad pole robocze

     */
     

      
}

void homing(bool isHigh, AccelStepper stepper)
{
  if(isHigh)
  {
  stepper.runSpeed();
  }
}

void homing(bool isHigh, AccelStepper stepper1, AccelStepper stepper2)
{
  if(isHigh)
  {
  stepper1.runSpeed();
  stepper2.runSpeed();
  
  }
}
