#include <Wire.h>
#include "ds3231.h"


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
}

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
  delay(1000);

  

   
}
