

#include <Stepper.h>
 

#define STEPS 20
 

Stepper stepper(STEPS, 8, 9, 10, 11);
 
const int button =  4; 
const int pot    = A0; 
 
void setup()
{

  pinMode(button, INPUT_PULLUP);
}
 
int direction_ = 1, speed_ = 0;
 
void loop()
{
  if ( digitalRead(button) == 0 ) 
    if ( debounce() )  
    {
      direction_ *= -1;  
      while ( debounce() ) ;  
    }
 

  int val = analogRead(pot);
 

  
  if ( speed_ != map(val, 0, 1023, 5, 100) )
  { 
    speed_ = map(val, 0, 1023, 5, 100);
    
    stepper.setSpeed(speed_);
  }
 
  
  stepper.step(direction_);
 
}
 

bool debounce()
{
  byte count = 0;
  for(byte i = 0; i < 5; i++) {
    if (digitalRead(button) == 0)
      count++;
    delay(10);
  }
  if(count > 2)  return 1;
  else           return 0;
}
