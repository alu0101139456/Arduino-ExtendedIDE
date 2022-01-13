
#include "Timer.h"

#include <Arduino.h>

class ExtendedIde {

private:
    int pin_;
    float freq_;
    Timer timer;
    std::pair<int, float> prescAndFreq_;
    
public:
    ExtendedIde(int pin, float freq);
    void SelectTimerWithPin();
    void PrintParameters();
    void SelectPrescaler();
    void ModifyRegisterTimer0();
    void ModifyRegisterTimer1();
    void ModifyRegisterTimer2();

};

// Frecuencia timer0 -> 62500Hz
// 1 -> 16Mh/1 = 16MHz                  16MHz/256 = 62.500Hz
// 8 -> 16Mh/8 = 2MHz                    2MHz/256 = 7.812,5Hz
// 64 -> 16Mh/64 = 250KHz              250KHz/256 = 976,5625Hz
// 256 -> 16Mh/256 = 62,5KH          62.500Hz/256 = 244,14Hz
// 1024 -> 16Mh/1024 = 15,625Hz      15,625Hz/256 = 0.061Hz

// Frecuencia timer1/timer2 -> 31250 Hz
// 1    -> 8Mh/1    =  8MHz           8MHz/256 = 31250Hz   
// 8    -> 8Mh/8    =  1MHz           1MHz/256 = 3906Hz
// 32   -> 8Mh/32   = 250KHz     250.000Hz/256 = 976.5625Hz      
// 64   -> 8Mh/64   = 125KHz     125.000Hz/256 = 488,28Hz
// 128  -> 8Mh/128 = 62,5kHz     62.5khz/256 = 244.14Hz
// 256  -> 8Mh/256  = 31,25KH     31.250Hz/256 = 122,07Hz
// 1024 -> 8Mh/1024 = 7,8125Hz      7,8125/256 = 0,031Hz

// Timer0/Timer1 pins 5,6/9,11 
// Prescalers 1 8 64 128 256 1024

// Timer2 pins 3,11
// Prescalers 1 8 32 64 128 256 1024
