#pragma once

#include <Arduino_AVRSTL.h>

class Timer {
  private:
    std::vector<float> frequencies_;
    int presc_;
    float freq_;

    //std::vector<int> presc_timer01 = {1, 8, 64, 256, 1024};
    std::vector<int> prescalers_ = {1, 8, 32, 64, 128, 256, 1024};

  public:
    Timer();
    ~Timer();

    std::pair<int,float> GetAproximateFreq(float);
    void SetFrequencies(int frec, int timer);
    int GetPrescaler();
    float GetFrequency();
    void PrintFrequencies();

    int abss(int x);
};