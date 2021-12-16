#include "ExtendedIde.h"



ExtendedIde::ExtendedIde(int pin, float freq) {
  pin_ = pin;
  freq = freq_;
  SelectTimerWithPin();
  prescAndFreq_ = clock_->GetAproximateFreq(freq_);
}

void ExtendedIde::PrintParamters() {
  std::cout << "Pin: " << pin_ << std::endl;
  std::cout << "Frecuencia: " << freq_ << std::endl;
  std::cout << "Timer seleccionado: " << clock_->getNumberTimer() << std::endl;
  std::cout << "Frecuencia más cercana: " << prescAndFreq_.second << std::endl;
  std::cout << "Prescalar: " << prescAndFreq_.first << std::endl;
}


void ExtendedIde::SelectTimerWithPin() {
  if(pin_ == 5 || pin_ == 6) {
    clock_ = new Timer8();
  }
  else if (pin_ == 3 || pin_ == 11) {
    clock_ = new Timer8();
  }
  else if (pin_ == 9 || pin_ == 10) {
    clock_ = new Timer16();
  }
  else {
    std::cerr << "Error: Pin fuera de rango"; 
  }    
}
