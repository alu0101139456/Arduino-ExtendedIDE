#include<vector>
#include<utility>

class Clock_t {
 private:
  
 public:
  
  Clock_t(){}
  virtual std::pair<int, float> GetAproximateFreq(float);
  virtual int getNumberTimer();
  ~Clock_t(){}
};


class Timer8:public Clock_t {
 private:
  std::vector<std::pair<int,float>> frequencies_;
 public:
  Timer8();
  void SetFrequencies();
  std::pair<int, float> GetAproximateFreq(float) override;
  int getNumberTimer() { return 8;}
  ~Timer8(){}
};

Timer8::Timer8(){
  SetFrequencies();
}

void Timer8::SetFrequencies() {
  //16Mh/1 = 16MHz ---> 16MHz/256 = 62.500Hz
  frequencies_[0].first = 1; 
  frequencies_[0].second  = 31250;
  //16Mh/8 = 1MHz  ---> 1MHz/256 = 3.906Hz
  frequencies_[1].first = 8;
  frequencies_[1].second = 3906;
  //16Mh/64 = 250KHz  ---> 250KHz/256 = 976,5625Hz
  frequencies_[2].first = 64;
  frequencies_[2].second = 488.28;
  //16Mh/256 = 62,5KH  ---> 62.500Hz/256 = 244,14Hz
  frequencies_[3].first = 256;
  frequencies_[3].second = 122.07;
  //16Mh/1024 = 15,625Hz  ---> 15,625Hz/256 = 0.061Hz
  frequencies_[4].first = 1024;
  frequencies_[4].second = 0.031;
} 

std::pair<int, float> Timer8::GetAproximateFreq(float aprox) {
  
  for (size_t i = 0; i < frequencies_.size(); i++) {
    if ( aprox > frequencies_[i].second ) {
      return frequencies_[i];
    }    
  }
  return frequencies_[frequencies_.size()-1];
}


class Timer16 :public Clock_t {
private:
  std::vector<std::pair<int,float>> frequencies_;
public:
  Timer16();
  void SetFrequencies();
  std::pair<int, float> GetAproximateFreq(float) override;
  int getNumberTimer() { return 16;}
  ~Timer16(){}
};

Timer16::Timer16() {
  SetFrequencies();
}

void Timer16::SetFrequencies() {
  //16Mh/1 = 16MHz ---> 16MHz/256 = 62.500Hz
  frequencies_[0].first = 1; 
  frequencies_[0].second  = 62500;
  //16Mh/8 = 2MHz  ---> 2MHz/256 = 7.812,5Hz
  frequencies_[1].first = 8;
  frequencies_[1].second = 7812.5;
  //16Mh/64 = 250KHz  ---> 250KHz/256 = 976,5625Hz
  frequencies_[2].first = 64;
  frequencies_[2].second = 976.5625;
  //16Mh/256 = 62,5KH  ---> 62.500Hz/256 = 244,14Hz
  frequencies_[3].first = 256;
  frequencies_[3].second = 244.14;
  //16Mh/1024 = 15,625Hz  ---> 15,625Hz/256 = 0.061Hz
  frequencies_[4].first = 1024;
  frequencies_[4].second = 0.0605;
} 

std::pair<int, float> Timer16::GetAproximateFreq(float aprox) {
  
  for (size_t i = 0; i < frequencies_.size(); i++) {
    if ( aprox > frequencies_[i].second ) {
      return frequencies_[i];
    }    
  }
  return frequencies_[frequencies_.size()-1];
}

