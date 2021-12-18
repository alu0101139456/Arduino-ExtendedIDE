
#include <Vector.h>
#include "pair_t.h"



/////////////////////////////////////////////////////////////////
//                CLASE PADRE DE TIMER                         //
/////////////////////////////////////////////////////////////////
class Clock_t {
 private:
  
 public:
  
  Clock_t() {}
  virtual pair_t GetAproximateFreq(float)=0;
  virtual int getNumberTimer()=0;

  ~Clock_t() {}
};

/////////////////////////////////////////////////////////////////
//                CLASE HIJA PARA TIMER 8                      //
/////////////////////////////////////////////////////////////////
class Timer8:public Clock_t {
 private:
  Vector<pair_t> frequencies_;
 public:
  Timer8() {
    SetFrequencies();
  }
  void SetFrequencies() {
    //8MHz/1 = 16MHz ---> 16MHz/256 = 62.500Hz
    frequencies_.push_back(pair_t(1, 31250));
    //8MHz/8 = 1MHz  ---> 1MHz/256 = 3.906Hz
    frequencies_.push_back(pair_t(8, 3906));
    //8MHz/64 = 250KHz  ---> 250KHz/256 = 976,5625Hz
    frequencies_.push_back(pair_t(64, 488.28));
    //8MHz/256 = 62,5KH  ---> 62.500Hz/256 = 244,14Hz
    frequencies_.push_back(pair_t(256, 122.07));
    //8MHz/1024 = 15,625Hz  ---> 15,625Hz/256 = 0.061Hz
    frequencies_.push_back(pair_t(1024, 0.031));
  }

  pair_t GetAproximateFreq(float aprox) override {      
    for (size_t i = 0; i < frequencies_.size(); i++) {
      if ( aprox > frequencies_[i].val_2() ) {
        return frequencies_[i];
      }    
    }
    return frequencies_[frequencies_.size()-1];
  }
  int getNumberTimer() { return 8;}
  ~Timer8(){}
};


/////////////////////////////////////////////////////////////////
//                CLASE HIJA PARA TIMER 8                      //
/////////////////////////////////////////////////////////////////


class Timer16 :public Clock_t {
private:
  Vector<pair_t> frequencies_;
public:
  Timer16() {
    SetFrequencies();
  }
  void SetFrequencies() {
    //16Mh/1 = 16MHz ---> 16MHz/256 = 62.500Hz
    frequencies_.push_back(pair_t(1, 62500));
    //16Mh/8 = 2MHz  ---> 2MHz/256 = 7.812,5Hz
    frequencies_.push_back(pair_t(8, 7812.5));
    //16Mh/64 = 250KHz  ---> 250KHz/256 = 976,5625Hz
    frequencies_.push_back(pair_t(64, 976.5625));
    //16Mh/256 = 62,5KH  ---> 62.500Hz/256 = 244,14Hz
    frequencies_.push_back(pair_t(256, 244.14));    
    //16Mh/1024 = 15,625Hz  ---> 15,625Hz/256 = 0.061Hz
    frequencies_.push_back(pair_t(1024, 0.0605));
  }
  pair_t GetAproximateFreq(float aprox) override {    
    for (size_t i = 0; i < frequencies_.size(); i++) {
      if ( aprox > frequencies_[i].val_2() ) {
        return frequencies_[i];
      }    
    }
    return frequencies_[frequencies_.size()-1];
  }
  int getNumberTimer() { return 16;}
  ~Timer16(){}

};
