/* 
   Author: Sriharsha
   Description:
   Notes:
 */

#include "config.h"


/* Setup Function */
void setup(void){
  
  /* Configure Serial port */
  Serial.begin(9600);
  
  /* Configure I/O Pins functionality */
  pinMode(M1_OUT1, OUTPUT);
  pinMode(M1_OUT2, OUTPUT);
  pinMode(M2_OUT1, OUTPUT);
  pinMode(M2_OUT2, OUTPUT);
  pinMode(M1_EN,   OUTPUT);
  pinMode(M2_EN,   OUTPUT);
  
  /* Print message on serial terminal */
  Serial.println("Robot Started..");
  
  /* Stop the motor */
  motorStop();
}

/* Motor Stop Function */
void motorStop(void){
  digitalWrite(M1_EN,   LOW);
  digitalWrite(M2_EN,   LOW);
  digitalWrite(M1_OUT1, HIGH);
  digitalWrite(M1_OUT2, HIGH);
  digitalWrite(M2_OUT1, HIGH);
  digitalWrite(M2_OUT2, HIGH);
}

/* Motor Forward Function */
void motorFw(void){
  /* Write PWM values to EN pn */
  analogWrite(M1_EN,    M1_SPEED);
  analogWrite(M2_EN,    M2_SPEED);
  digitalWrite(M1_OUT1, HIGH);
  digitalWrite(M1_OUT2, LOW);
  digitalWrite(M2_OUT1, HIGH);
  digitalWrite(M2_OUT2, LOW);
  Serial.println("Robot running forward");
}

/* Motor Backward Function */
void motorBw(void){
  /* Write PWM values to EN pn */
  analogWrite(M1_EN,    M1_SPEED);
  analogWrite(M2_EN,    M2_SPEED);
  digitalWrite(M1_OUT1, LOW);
  digitalWrite(M1_OUT2, HIGH);
  digitalWrite(M2_OUT1, LOW);
  digitalWrite(M2_OUT2, HIGH);
  Serial.println("Robot running backward");
}

/* Motor Left Function */
void motorLeft(void){
  /* Write PWM values to EN pn */
  analogWrite(M1_EN,    M1_SPEED);
  analogWrite(M2_EN,    M2_SPEED);
  digitalWrite(M1_OUT1, HIGH);
  digitalWrite(M1_OUT2, LOW);
  digitalWrite(M2_OUT1, LOW);
  digitalWrite(M2_OUT2, LOW);
  Serial.println("Robot turning left");
}

/* Motor Right Function */
void motorRight(void){
  /* Write PWM values to EN pn */
  analogWrite(M1_EN,    M1_SPEED);
  analogWrite(M2_EN,    M2_SPEED);
  digitalWrite(M1_OUT1, LOW);
  digitalWrite(M1_OUT2, LOW);
  digitalWrite(M2_OUT1, HIGH);
  digitalWrite(M2_OUT2, LOW);
  Serial.println("Robot turning right");
}

/* Read Sensor Function */
int readSensor(int ch){
  long senVal = 0;
  for(int i = 0;i < AVG_SAMPLE_RATE;i++){
    senVal += analogRead(ch);
  }
  return int(senVal / AVG_SAMPLE_RATE);
}

/* Loop function which runs forever */
void loop(void){
  int sen1, sen2;
  sen1 = readSensor(SEN1);
  sen2 = readSensor(SEN2);

  /* If both sensor detected white, then stop the motor */
  if(sen1 > SEN1_THRESHOLD && sen2 > SEN2_THRESHOLD){
    motorStop();
  }

  /* If Sensor 1 in White Region */
  else if(sen1 > SEN1_THRESHOLD){
    motorLeft();
  }

  /* If Sensor 2 in White Region */
  else if(sen2 > SEN1_THRESHOLD){
    motorRight();
  }

  /* If both are deteted black */
  else {
    motorFw();
  }

  /* Delay to avoid sensor stranged response */
  delay(LOOP_DELAY);
  
} 