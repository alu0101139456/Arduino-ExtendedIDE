#include "ExtendedIde.h"
#include "Timer.h"



#define NORMAL 0
#define FPWD_MAX 1
#define FPWM_OCR 2

unsigned long myTime;

void setup() {
  Serial.begin(115200);
  

  ExtendedIde test( 5 , 10055.25 , FPWM_MAX);


  
  }

void loop() {

  //myTime = millis();

  //Serial.println(myTime); // prints time since program started
  //delay(1000);   
}

// Frecuencia timer0 -> 62500Hz
//                                  Timer0/Timer1 pins 5,6/9,10
// Prescalers 1 8 64 256 1024
// 1 -> 16Mh/1 = 16MHz                  16MHz/256 = 62.500Hz
// 8 -> 16Mh/8 = 2MHz                    2MHz/256 = 7.812,5Hz
// 64 -> 16Mh/64 = 250KHz              250KHz/256 = 976,5625Hz
// 256 -> 16Mh/256 = 62,5KH          62.500Hz/256 = 244,14Hz
// 1024 -> 16Mh/1024 = 15,625Hz      15,625Hz/256 = 61Hz



// Frecuencia timer1/timer2 -> 31250 Hz
                                        // Timer2 pins 3,11
// Prescalers 1 8 32 64 128 256 1024
// 1    -> 8Mh/1    =  8MHz           8MHz/256 = 31250Hz   
// 8    -> 8Mh/8    =  1MHz           1MHz/256 = 3906Hz
// 32   -> 8Mh/32   = 250KHz     250.000Hz/256 = 976.5625Hz      
// 64   -> 8Mh/64   = 125KHz     125.000Hz/256 = 488,28Hz
// 128  -> 8Mh/128 = 62,5kHz     62.5khz/256 = 244.14Hz
// 256  -> 8Mh/256  = 31,25KH     31.250Hz/256 = 122,07Hz
// 1024 -> 8Mh/1024 = 7,8125Hz      7,8125/256 = 30,5Hz

//Verificar los registros porque se cuelga con pin 5 prescaler 8
//Buscar una manera mas clara para poner los bits en los registros correspondientes
