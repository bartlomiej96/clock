#include "TinyStepper_28BYJ_48.h"
#include <TimeLib.h>

int LastMinute;
int ThisMinute;

int LastSecond;
int ThisSecond;

//for the 21-02485-03 stepper, the colors in order are yellow, red, black/white, blue

TinyStepper_28BYJ_48 stepper1;
TinyStepper_28BYJ_48 stepper2; 
int MinuteCount;
time_t t;

void setup()
{
stepper1.connectToPins(8,9,10,11);
stepper2.connectToPins(4,5,6,7);

setTime(1,1,1,1,1,1); //set the time to Jan 1, 2001
//It really does not matter what the time is set to,
//we are checking to see if a minute has passed.
t = now();
LastMinute = minute(t);
LastSecond = second(t);

stepper1.moveRelativeInSteps(205);
MinuteCount = 1;
}

void loop()
{

t = now();
ThisMinute = minute(t);
ThisSecond = second(t);

if ( ThisSecond != LastSecond ) {
delay(200); // wait for 500ms
LastSecond = ThisSecond;
}


if ( ThisMinute != LastMinute ) {
stepper1.moveRelativeInSteps(205);
MinuteCount++;
LastMinute = ThisMinute;
}

//tick the hour ring every 5 minutes
if (MinuteCount > 5) {
stepper1.moveRelativeInSteps(205);
MinuteCount = 1;
}

delay(200);
}
