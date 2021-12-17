#include "ExtendedIde.h"



int main() {

  ExtendedIde extended(5, 5000);

  extended.PrintParameters();

}

/*
  TCCR0B &= !( 1 << CS02 );
   
  pinMode(5, OUTPUT);
  TCCR0B |= (  1 << CS01 | 1 << CS00);

  */