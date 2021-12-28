#include "ExtendedIde.h"
#include "Timer.h"


unsigned long myTime;

void setup() {
  Serial.begin(115200);
  
  //Serial.println("LlaadaExtendedIde");
  ExtendedIde test(5 ,21300);


  
  }

void loop() {

  myTime = millis();

  Serial.println(myTime); // prints time since program started
  delay(1000);   
}
/*
Timer0                                                    Pines        5     6
1    -> 8Mh/1    =  8MHz           8MHz/256 = 31250Hz                OC0B   OC0B   
8    -> 8Mh/8    =  1MHz           1MHz/256 = 3906Hz          
64   -> 8Mh/64   = 125KHz     125.000Hz/256 = 488,28Hz    
256  -> 8Mh/256  = 31,25KH     31.250Hz/256 = 122,07Hz
1024 -> 8Mh/1024 = 7,8125Hz      7,8125/256 = 0,031Hz 

Timer2                                                    Pines       3      11
1    -> 8Mh/1    =  8MHz           8MHz/256 = 31250Hz               OC2B   OC2B
8    -> 8Mh/8    =  1MHz           1MHz/256 = 3906Hz      
64   -> 8Mh/64   = 125KHz     125.000Hz/256 = 488,28Hz
256  -> 8Mh/256  = 31,25KH     31.250Hz/256 = 122,07Hz
1024 -> 8Mh/1024 = 7,8125Hz      7,8125/256 = 0,031Hz 


//Frecuencia Timer 1 16MH           pin 9 y 10

1 -> 16Mh/1 = 16MHz                  16MHz/256 = 62.500Hz
8 -> 16Mh/8 = 2MHz                    2MHz/256 = 7.812,5Hz
64 -> 16Mh/64 = 250KHz              250KHz/256 = 976,5625Hz
256 -> 16Mh/256 = 62,5KH          62.500Hz/256 = 244,14Hz
1024 -> 16Mh/1024 = 15,625Hz      15,625Hz/256 = 0.061Hz
(Entiendo que no hay más combinaciones)
*/