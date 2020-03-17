#include <Wire.h>
#include "ds3231.h"

int Apin = 53;
int Bpin = 51;
int Cpin = 49;
int Dpin = 47;
int Epin = 45;
int Fpin = 43;
int Gpin = 41;

int gnd1 = 2;
int gnd2 = 3;
int gnd3 = 4;
int gnd4 = 5;


int subSecond;

int subMinute[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int subHour[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int Ahours[] = { 8,  9, 10, 10, 11, 12, 13, 14, 14};
int Amin[] =   {29, 17,  5, 53, 41, 29, 17,  5, 53};  

int currentAmin;


void setup()
{
    Serial.begin(9600);
    Wire.begin();
    DS3231_init(DS3231_CONTROL_INTCN);
    DS3231_clear_a1f();

     pinMode(Apin,OUTPUT);
  pinMode(Bpin,OUTPUT);
  pinMode(Cpin,OUTPUT);
  pinMode(Dpin,OUTPUT);
  pinMode(Epin,OUTPUT);
  pinMode(Fpin,OUTPUT);
  pinMode(Gpin,OUTPUT);

  pinMode(gnd1, OUTPUT);
  pinMode(gnd2, OUTPUT);
  pinMode(gnd3, OUTPUT);
  pinMode(gnd4, OUTPUT);
}

int myTime = 5;

void loop()
{
    struct ts t;
    DS3231_get(&t);
  
 
  for (int i = 0; i <= 8; i++) {
    subHour[i] = Ahours[i] - t.hour;
    if (subHour[i] != 0) {
            subMinute[i] = ((60 - t.min) + Amin[i]) - 1;
    } else {
              subMinute[i] = Amin[i] - t.min;
    }
      subSecond = 60 - t.sec;
  }


  int ten = subSecond / 10;
  int one = subSecond - (ten*10);

  int minten = subMinute[5] / 10;
  int minone = subMinute[5] - (minten*10);

  
  if (ten == 6) {
    ten = 0;
    minone++;
  }

  digitalWrite(gnd1,LOW);
  digitalWrite(gnd2,HIGH);
  digitalWrite(gnd3,HIGH);
  digitalWrite(gnd4,HIGH);
  dis(one);
  
  delay(myTime);

  digitalWrite(gnd1, HIGH);
  digitalWrite(gnd2, LOW);
  digitalWrite(gnd3, HIGH);
  digitalWrite(gnd4, HIGH);
  dis(ten);

  delay(myTime);

  digitalWrite(gnd1, HIGH);
  digitalWrite(gnd2, HIGH);
  digitalWrite(gnd3, LOW);
  digitalWrite(gnd4, HIGH);
  dis(minone);

  delay(myTime);

  digitalWrite(gnd1, HIGH);
  digitalWrite(gnd2, HIGH);
  digitalWrite(gnd3, HIGH);
  digitalWrite(gnd4, LOW);
  dis(minten);

  delay(myTime);

  

/*
  Serial.print(subSecond);

  Serial.print("----");
  
  Serial.print(ten);
  Serial.print("-");
  Serial.println(one);
 */

/*
    Serial.print(t.hour);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print(":");
  Serial.print(t.sec);
  Serial.print("  ||   ");
  Serial.print(00);
  Serial.print(":");
  Serial.print(subMinute[4]);
  Serial.print(":");
  Serial.println(subSecond);

  */

  

   
}





void dis (int number) {
  if (number == 0) {
    zero();
  } else if (number == 1) {
    one();
  } else if (number == 2) {
    two();
  } else if (number == 3) {
    three();
  } else if (number == 4) {
    four();
  } else if (number == 5) {
    five();
  } else if (number == 6) {
    six();
  } else if (number == 7) {
    seven();
  } else if (number == 8) {
    eight();
  } else if (number == 9) {
    nine();
  }
}



void zero () {
  digitalWrite(Apin, HIGH);
  digitalWrite(Bpin, HIGH);
  digitalWrite(Cpin, HIGH);
  digitalWrite(Dpin, HIGH);
  digitalWrite(Epin, HIGH);
  digitalWrite(Fpin, HIGH);
  digitalWrite(Gpin, LOW);
}


void one () {
  digitalWrite(Apin, LOW);
  digitalWrite(Bpin, HIGH);
  digitalWrite(Cpin, HIGH);
  digitalWrite(Dpin, LOW);
  digitalWrite(Epin, LOW);
  digitalWrite(Fpin, LOW);
  digitalWrite(Gpin, LOW);
}

void two () {
  digitalWrite(Apin, HIGH);
  digitalWrite(Bpin, HIGH);
  digitalWrite(Cpin, LOW);
  digitalWrite(Dpin, HIGH);
  digitalWrite(Epin, HIGH);
  digitalWrite(Fpin, LOW);
  digitalWrite(Gpin, HIGH);
}

void three () {
  digitalWrite(Apin, HIGH);
  digitalWrite(Bpin, HIGH);
  digitalWrite(Cpin, HIGH);
  digitalWrite(Dpin, HIGH);
  digitalWrite(Epin, LOW);
  digitalWrite(Fpin, LOW);
  digitalWrite(Gpin, HIGH);
}

void four () {
  digitalWrite(Apin, LOW);
  digitalWrite(Bpin, HIGH);
  digitalWrite(Cpin, HIGH);
  digitalWrite(Dpin, LOW);
  digitalWrite(Epin, LOW);
  digitalWrite(Fpin, HIGH);
  digitalWrite(Gpin, HIGH);
}

void five () {
  digitalWrite(Apin, HIGH);
  digitalWrite(Bpin, LOW);
  digitalWrite(Cpin, HIGH);
  digitalWrite(Dpin, HIGH);
  digitalWrite(Epin, LOW);
  digitalWrite(Fpin, HIGH);
  digitalWrite(Gpin, HIGH);
}

void six () {
  digitalWrite(Apin, HIGH);
  digitalWrite(Bpin, LOW);
  digitalWrite(Cpin, HIGH);
  digitalWrite(Dpin, HIGH);
  digitalWrite(Epin, HIGH);
  digitalWrite(Fpin, HIGH);
  digitalWrite(Gpin, HIGH);
}

void seven () {
  digitalWrite(Apin, HIGH);
  digitalWrite(Bpin, HIGH);
  digitalWrite(Cpin, HIGH);
  digitalWrite(Dpin, LOW);
  digitalWrite(Epin, LOW);
  digitalWrite(Fpin, LOW);
  digitalWrite(Gpin, LOW);
}

void eight () {
  digitalWrite(Apin, HIGH);
  digitalWrite(Bpin, HIGH);
  digitalWrite(Cpin, HIGH);
  digitalWrite(Dpin, HIGH);
  digitalWrite(Epin, HIGH);
  digitalWrite(Fpin, HIGH);
  digitalWrite(Gpin, HIGH);
}

void nine () {
  digitalWrite(Apin, HIGH);
  digitalWrite(Bpin, HIGH);
  digitalWrite(Cpin, HIGH);
  digitalWrite(Dpin, HIGH);
  digitalWrite(Epin, LOW);
  digitalWrite(Fpin, HIGH);
  digitalWrite(Gpin, HIGH);
}
