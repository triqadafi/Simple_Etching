#include "Arduino.h"
#define FI_TRIGGER (digitalRead(4) == LOW)
bool FI_STATE = false;
unsigned long FI_MILLIS = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT); digitalWrite(0, LOW);
  pinMode(4, INPUT); digitalWrite(4, HIGH);
}

void loop() {
  if(!FI_STATE && FI_TRIGGER){
    FI_MILLIS = millis();
    FI_STATE = true;
  }
  if(FI_STATE){
    if(millis() - FI_MILLIS < 400){
      digitalWrite(0, HIGH);
    }else if(millis() - FI_MILLIS > 400){
      FI_STATE = false;
      digitalWrite(0, LOW);
    }
  }
}
