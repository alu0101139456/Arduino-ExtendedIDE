
#include "ExtendedIde.h"


ExtendedIde::ExtendedIde(int pin, float freq) {
  pin_ = pin;
  freq_ = freq;
  SelectTimerWithPin();
  PrintParameters();
}

void ExtendedIde::PrintParameters() {
  Serial.print("Pin: ");
  Serial.println(pin_);
  Serial.print("Frecuencia: ");
  Serial.println(freq_);
  Serial.print("Timer seleccionado: ");
  Serial.println(clock_->GetNumberTimer());
  Serial.print("Frecuencia más cercana: ");
  Serial.println(clock_->GetFrequency());
  Serial.print("Prescalar: ");
  Serial.println(clock_->GetPrescaler());
}


void ExtendedIde::SelectTimerWithPin() {
  if (pin_ == 5 || pin_ == 6) {    //     <----- Timer 0
    clock_ = new Timer8();
    prescAndFreq_ = clock_->GetAproximateFreq(freq_);
    ModifyRegisterTimer0();
  }
  else if (pin_ == 9 || pin_ == 10) { //     <----- Timer 1
    clock_ = new Timer16();
    prescAndFreq_ = clock_->GetAproximateFreq(freq_);
    ModifyRegisterTimer1();
  } 
  else if (pin_ == 3 || pin_ == 11) {     //     <----- Timer 2
    clock_ = new Timer8();
    prescAndFreq_ = clock_->GetAproximateFreq(freq_);
    ModifyRegisterTimer2();
  } 
  else {
    Serial.println("Error: Pin fuera de rango"); 
  }    
}

void ExtendedIde::ModifyRegisterTimer0() {  //pin 5 - 6
  switch (clock_->GetAproximateFreq(freq_).first) {
    case 1:
      Serial.println("Modificando TCCR0B - Timer8 prescaler 1 >   0 0 1  ");
      TCCR0B &= !( 1 << CS02 | 1 << CS01 ); // Para poner bits a 0
      TCCR0B |=  ( 1 << CS00 ); // Para poner bits a 1
      break;
    case 8:
      Serial.println("Modificando TCCR0B - Timer8 prescaler 8 >   0 1 0  ");
      TCCR0B &= !( 1 << CS02 );
      TCCR0B |=  ( 1 << CS01 ); 
      TCCR0B &= !( 1 << CS00 );
      break;
    case 64:
      Serial.println("Modificando TCCR0B - Timer8 prescaler 64 >   0 1 1  ");
      TCCR0B &= !( 1 << CS02 );
      TCCR0B |=  ( 1 << CS01 | 1 << CS00 );
      break;
    case 256:
      Serial.println("Modificando TCCR0B - Timer8 prescaler 256 >   1 0 0  ");
      TCCR0B |=  ( 1 << CS02 );
      TCCR0B &= !( 1 << CS01 | 1 << CS00 );
      break;
    case 1024:
      Serial.println("Modificando TCCR0B - Timer8 prescaler 1024 >   1 0 1  ");
      TCCR0B |=  ( 1 << CS02 );
      TCCR0B &= !( 1 << CS01 );
      TCCR0B |=  ( 1 << CS00 );
      break;
  
  default:
    Serial.println("Valor del prescaler no valido\n");
    break;
  }

}

void ExtendedIde::ModifyRegisterTimer1() {   // pin 9 - 10
  switch (clock_->GetAproximateFreq(freq_).first) {
    case 1:
      Serial.println("Modificando TCCR1B - Timer16 prescaler 1 >   0 0 1  ");
      TCCR1B &= !( 1 << CS12 | 1 << CS11 ); // Para poner bits a 0
      TCCR1B |=  ( 1 << CS10 ); // Para poner bits a 1
      break;
    case 8:
      Serial.println("Modificando TCCR1B - Timer16 prescaler 8 >   0 1 0  ");
      TCCR1B &= !( 1 << CS12 );
      TCCR1B |=  ( 1 << CS11 ); 
      TCCR1B &= !( 1 << CS10 );
      break;
    case 64:
      Serial.println("Modificando TCCR1B - Timer16 prescaler 64 >   0 1 1  ");
      TCCR1B &= !( 1 << CS12 );
      TCCR1B |=  ( 1 << CS11 | 1 << CS10 );
      break;
    case 256:
      Serial.println("Modificando TCCR1B - Timer16 prescaler 256 >   1 0 0  ");
      TCCR1B |=  ( 1 << CS12 );
      TCCR1B &= !( 1 << CS11 | 1 << CS10 );
      break;
    case 1024:
      Serial.println("Modificando TCCR1B - Timer16 prescaler 1024 >   1 0 1  ");
      TCCR1B |=  ( 1 << CS12 );
      TCCR1B &= !( 1 << CS11 );
      TCCR1B |=  ( 1 << CS10 );
      break;
  
  default:
    // Serial.println("Valor del prescaler no valido");
    break;
  }
}

void ExtendedIde::ModifyRegisterTimer2() {   //pin 3 - 11
  switch ( clock_->GetAproximateFreq(freq_).first) {
      
    case 1:
      Serial.println("Modificando TCCR1B - Timer16 prescaler 1 >   0 0 1  ");
      TCCR2B &= !( 1 << CS22 | 1 << CS21 ); // Para poner bits a 0
      TCCR2B |=  ( 1 << CS20 ); // Para poner bits a 1
      break;
    case 8:
      Serial.println("Modificando TCCR2B - Timer8 prescaler 8 >   0 1 0  ");
      TCCR2B &= !( 1 << CS22 );
      TCCR2B |=  ( 1 << CS21 ); 
      TCCR2B &= !( 1 << CS20 );
      break;
    case 64:
      Serial.println("Modificando TCCR2B - Timer8 prescaler 64 >   0 1 1  ");
      TCCR2B &= !( 1 << CS22 );
      TCCR2B |=  ( 1 << CS21 | 1 << CS20 );
      break;
    case 256:
      Serial.println("Modificando TCCR2B - Timer8 prescaler 256 >   1 0 0  ");
      TCCR2B |=  ( 1 << CS22 );
      TCCR2B &= !( 1 << CS21 | 1 << CS20 );
      break;
    case 1024:
     Serial.println("Modificando TCCR2B - Timer8 prescaler 1024 >   1 0 1  ");
      TCCR2B |=  ( 1 << CS22 );
      TCCR2B &= !( 1 << CS21 );
      TCCR2B |=  ( 1 << CS20 );
      break;
  
  default:
    // Serial.println("Valor del prescaler no valido");
    break;
  }
}
