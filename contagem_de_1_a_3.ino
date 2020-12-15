#include <SerialDisplay.h>

SerialDisplay displays(D2,D1,4); // (data, clock, number of modules)
byte count = 0;

void setup(){
  Serial.begin(19200);
  displays.Off(0);
  displays.Info(&Serial);
 
}


void loop(){
  if(count < 10){
    displays.Print(count,1);
    displays.Print(count,2);
    displays.Print(count,3);
    displays.Print(count,4);
    displays.Dot(1);
    displays.Dot(2);
    displays.Dot(3);
    displays.Dot(4);
    count++;
  } else {
    displays.Off(1);
    count = 0;
  }
  delay(1000);
}
