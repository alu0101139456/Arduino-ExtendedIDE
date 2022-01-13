#include "Timer.h"

Timer::Timer() {}

Timer::~Timer() {}

int Timer::abss(int x)  {     
  return x > 0 ? x : (-1 * x);
}

// DUDA: ¿COMO OBTENER EL PRESCALER?
// Idea: tener 1 solo vector con los presc y 
// en caso de que sea el timer01 descartar el 32 y 128 (index2 y 4)
void Timer::SetFrequencies(int frec) {
  for(int i = 0; i < prescalers_.size(); i++) {
    frequencies_.push_back(frec / prescalers_[i] / 256);
  }
}

std::pair<int,float> Timer::GetAproximateFreq(float aprox, int timer) {   
  int a, b, bestFreq;
  for (size_t i = 1; i < frequencies_.size()-1; i++) {
    if (timer != 2) {
      if (i == 2 || i == 4) {
        continue;
      }
    }
    if (aprox > frequencies_[i]) {
      a = abs(aprox - frequencies_[i]); 
      b = abs(aprox - frequencies_[i-1]); 
      bestFreq = a < b ? i : i-1;

      presc_ = prescalers_[bestFreq];
      freq_ = frequencies_[bestFreq];

      return std::make_pair(presc_, freq_);
    } 
  }
  presc_ = prescalers_[prescalers_.size()-1];
  freq_ = frequencies_[frequencies_.size()-1];

  return std::make_pair(presc_, freq_);
}

int Timer::GetPrescaler() {
  return presc_;
}

float Timer::GetFrequency() {
  return freq_;
}

void Timer::PrintFrequencies() {
  for (int i = 0; i < frequencies_.size(); i++) {
    Serial.print("Presc:");
    // !! Cambiar presc_
    Serial.println(prescalers_[i]);
    Serial.print("Freq:");
    Serial.println(frequencies_[i]);     
  }
}
