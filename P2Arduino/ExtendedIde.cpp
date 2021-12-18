#include "ExtendedIde.h"


ExtendedIde::ExtendedIde(int pin, float freq) {
  pin_ = pin;
  freq_ = freq;
  SelectTimerWithPin();
}

void ExtendedIde::PrintParameters() {
  //Serial.println("Pin: %d", pin_);
  //Serial.println("Frecuencia: %f", freq_);
  //Serial.println("Timer seleccionado: %d" ,clock_->getNumberTimer();
  //Serial.println("Frecuencia más cercana: %f" ,prescAndFreq_.val_2);
  //Serial.println("Prescalar: %d", prescAndFreq_.val_1()()) ;
}


void ExtendedIde::SelectTimerWithPin() {
  if (pin_ == 5 || pin_ == 6) {
    clock_ = new Timer8();
    prescAndFreq_ = clock_->GetAproximateFreq(freq_);
    ModifyRegisterTimer0();

  }
  else if (pin_ == 3 || pin_ == 11) {
    clock_ = new Timer8();
    prescAndFreq_ = clock_->GetAproximateFreq(freq_);
    ModifyRegisterTimer2();
  }
  else if (pin_ == 9 || pin_ == 10) {
    clock_ = new Timer16();
    prescAndFreq_ = clock_->GetAproximateFreq(freq_);
    ModifyRegisterTimer1();
  }
  else {
    // Serial.println("Error: Pin fuera de rango"); 
  }    
}

void ExtendedIde::ModifyRegisterTimer0() {
  switch (prescAndFreq_.val_1()) {
    case 1:
      TCCR0B &= !( 1 << CS02 | 1 << CS01 ); // Para poner bits a 0
      TCCR0B |=  ( 1 << CS00 ); // Para poner bits a 1
      break;
    case 8:
      TCCR0B &= !( 1 << CS02 );
      TCCR0B |=  ( 1 << CS01 ); 
      TCCR0B &= !( 1 << CS00 );
      break;
    case 64:
      TCCR0B &= !( 1 << CS02 );
      TCCR0B |=  ( 1 << CS01 | 1 << CS00 );
      break;
    case 256:
      TCCR0B |=  ( 1 << CS02 );
      TCCR0B &= !( 1 << CS01 | 1 << CS00 );
      break;
    case 1024:
      TCCR0B |=  ( 1 << CS02 );
      TCCR0B &= !( 1 << CS01 );
      TCCR0B |=  ( 1 << CS00 );
      break;
  
  default:
    // Serial.println("Valor del prescaler no valido\n");
    break;
  }
  //TCCR0B &= !( 1 << CS02 );
  //TCCR0B |= (  1 << CS01 | 1 << CS00);

  // variable registro con sus cs asociados
  // TCCR0B -> timer0 (cs02, cs01, cs00)
  // TCCR1B -> timer1 (cs12, cs11, cs10)
  // TCCR2B -> timer2 (cs22, cs21, cs20)
}

void ExtendedIde::ModifyRegisterTimer1() {
  switch (prescAndFreq_.val_1()) {
    case 1:
      TCCR1B &= !( 1 << CS12 | 1 << CS11 ); // Para poner bits a 0
      TCCR1B |=  ( 1 << CS10 ); // Para poner bits a 1
      break;
    case 8:
      TCCR1B &= !( 1 << CS12 );
      TCCR1B |=  ( 1 << CS11 ); 
      TCCR1B &= !( 1 << CS10 );
      break;
    case 64:
      TCCR1B &= !( 1 << CS12 );
      TCCR1B |=  ( 1 << CS11 | 1 << CS10 );
      break;
    case 256:
      TCCR1B |=  ( 1 << CS12 );
      TCCR1B &= !( 1 << CS11 | 1 << CS10 );
      break;
    case 1024:
      TCCR1B |=  ( 1 << CS12 );
      TCCR1B &= !( 1 << CS11 );
      TCCR1B |=  ( 1 << CS10 );
      break;
  
  default:
    // Serial.println("Valor del prescaler no valido");
    break;
  }
}

void ExtendedIde::ModifyRegisterTimer2() {
  switch (prescAndFreq_.val_1()) {
    case 1:
      TCCR2B &= !( 1 << CS22 | 1 << CS21 ); // Para poner bits a 0
      TCCR2B |=  ( 1 << CS20 ); // Para poner bits a 1
      break;
    case 8:
      TCCR2B &= !( 1 << CS22 );
      TCCR2B |=  ( 1 << CS21 ); 
      TCCR2B &= !( 1 << CS20 );
      break;
    case 64:
      TCCR2B &= !( 1 << CS22 );
      TCCR2B |=  ( 1 << CS21 | 1 << CS20 );
      break;
    case 256:
      TCCR2B |=  ( 1 << CS22 );
      TCCR2B &= !( 1 << CS21 | 1 << CS20 );
      break;
    case 1024:
      TCCR2B |=  ( 1 << CS22 );
      TCCR2B &= !( 1 << CS21 );
      TCCR2B |=  ( 1 << CS20 );
      break;
  
  default:
    // Serial.println("Valor del prescaler no valido");
    break;
  }
}
