
#include <wiringPi.h>
#include <stdio.h>

int main()
{
  int led_pin = 9;
  int led_state = 0;
  int switch_count = 0;

  if(wiringPiSetup() == -1)
  {
    return 1;
  }

  // set pinmode by WiringPi-Table
  pinMode(led_pin, OUTPUT);

  // turn off LED
  digitalWrite(led_pin, 0); 
  led_state = 0;

  while(1)
  {
    if(led_state == 0) 
    {
           led_state = 1;
      printf("%d: Trun LED on\n", switch_count);
    }
    else
    {
      digitalWrite(led_pin, 0);
      led_state = 0;
      printf("%d: Trun LED off\n",switch_count);
    }

    // delay for 1 second
    delay(1000);
    switch_count ++;
  }
  
  return 0;
}



