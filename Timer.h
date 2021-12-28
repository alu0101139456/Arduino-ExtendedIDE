#pragma once


#include <Arduino_AVRSTL.h>



/////////////////////////////////////////////////////////////////
//                CLASE PADRE DE TIMER                         //
/////////////////////////////////////////////////////////////////

class Clock_t {
 private:
  
 public:
  
  Clock_t() {}
  virtual std::pair<int,float> GetAproximateFreq(float)=0;
  virtual int GetNumberTimer()=0;
  virtual int GetPrescaler()=0;
  virtual float GetFrequency()=0;
  virtual void PrintFrequencies()=0;
  int abss(int x)  {     
      return x > 0 ? x : (-1 * x);
  }
  ~Clock_t() {}
};

/////////////////////////////////////////////////////////////////
//                CLASE HIJA PARA TIMER 8                      //
/////////////////////////////////////////////////////////////////
class Timer8:public Clock_t {
 private:
  std::vector<std::pair<int,float>> frequencies_;
  int prec_;
  float freq_;
 public:
  Timer8() {
    SetFrequencies();
  }
  void SetFrequencies() {
    //8MHz/1 = 16MHz ---> 16MHz/256 = 62.500Hz
    frequencies_.push_back(std::pair<int,float>(1, 31250));
    //8MHz/8 = 1MHz  ---> 1MHz/256 = 3.906Hz
    frequencies_.push_back(std::pair<int,float>(8, 3906));
    //8MHz/64 = 250KHz  ---> 250KHz/256 = 976,5625Hz
    frequencies_.push_back(std::pair<int,float>(64, 488.28));
    //8MHz/256 = 62,5KH  ---> 62.500Hz/256 = 244,14Hz
    frequencies_.push_back(std::pair<int,float>(256, 122.07));
    //8MHz/1024 = 15,625Hz  ---> 15,625Hz/256 = 0.061Hz
    frequencies_.push_back(std::pair<int,float>(1024, 0.031));
  }

  
  std::pair<int,float> GetAproximateFreq(float aprox) override { 
  int index;
  for (size_t i = 1; i < frequencies_.size()-1; i++) { 
       
      if ( aprox > frequencies_[i].second ) { 
        int a = abss(aprox - frequencies_[i].second); 
        int b = abss(aprox - frequencies_[i-1].second); 
        int best = a < b ? a:b; 
   
        if (best == a) 
          index = i; 
        else index = i-1; 
        prec_ = frequencies_[index].first;
        freq_ = frequencies_[index].second;
        return frequencies_[index]; 
      }     
    }
    prec_ = frequencies_[frequencies_.size()-1].first;
    freq_ = frequencies_[frequencies_.size()-1].second; 
    return frequencies_[frequencies_.size()-1]; 
  }

  int GetPrescaler() { return prec_; }
  float GetFrequency() { return freq_; }
  int GetNumberTimer() { return 8; }
  
  void PrintFrequencies() override {
    for (int i = 0; i < 5; i++) {
      Serial.print("Presc:");
      Serial.println(frequencies_[i].first);
      Serial.print("Freq:");
      Serial.println(frequencies_[i].second);     
    }
  }
  ~Timer8(){}
};


/////////////////////////////////////////////////////////////////
//                CLASE HIJA PARA TIMER 16                      //
/////////////////////////////////////////////////////////////////


class Timer16 :public Clock_t {
private:
  std::vector<std::pair<int,float>> frequencies_;
  int prec_;
  float freq_;
public:
  Timer16() {
    SetFrequencies();
  }
  void SetFrequencies() {
    
    //16Mh/1 = 16MHz ---> 16MHz/256 = 62.500Hz
    frequencies_.push_back(std::make_pair<int,float>(1, 62500));
    //16Mh/8 = 2MHz  ---> 2MHz/256 = 7.812,5Hz
    frequencies_.push_back(std::pair<int,float>(8, 7812.5));
    //16Mh/64 = 250KHz  ---> 250KHz/256 = 976,5625Hz
    frequencies_.push_back(std::pair<int,float>(64, 976.5625));
    //16Mh/256 = 62,5KH  ---> 62.500Hz/256 = 244,14Hz
    frequencies_.push_back(std::pair<int,float>(256, 244.14));    
    //16Mh/1024 = 15,625Hz  ---> 15,625Hz/256 = 0.061Hz
    frequencies_.push_back(std::pair<int,float>(1024, 0.0605));
  }


  std::pair<int,float> GetAproximateFreq(float aprox) override { 
  int index;
  /*if ( aproz > 62.500){
    prec_ = frequencies_[0].first;
    freq_ = frequencies_[0].second;
    return frequencies_[0];
  }*/
  for (size_t i = 1; i < frequencies_.size()-1; i++) { 
       
      if ( aprox > frequencies_[i].second ) { 
        int a = abss(aprox - frequencies_[i].second); 
        int b = abss(aprox - frequencies_[i-1].second); 
        int best = a < b ? a:b; 

        Serial.print("A=");
        Serial.println(a);
        Serial.print("B=");
        Serial.println(b);
        
        if (best == a) {
          index = i; 
        }
        else  {
          index = i-1; 
        }
        Serial.print("INDEX:");
        Serial.println(index);
        prec_ = frequencies_[index].first;
        freq_ = frequencies_[index].second;
        
        return frequencies_[index]; 
      }     
    }
    prec_ = frequencies_[frequencies_.size()-1].first;
    freq_ = frequencies_[frequencies_.size()-1].second; 
    return frequencies_[frequencies_.size()-1]; 
  }

  int GetPrescaler() { return prec_; }
  float GetFrequency() { return freq_; }
  int GetNumberTimer() { return 16;}
  void PrintFrequencies() override {
    for (int i = 0; i < 5; i++) {
      Serial.print("Presc:");
      Serial.println(frequencies_[i].first);
      Serial.print("Freq:");
      Serial.println(frequencies_[i].second);     
    }
  }
  ~Timer16(){}

};
