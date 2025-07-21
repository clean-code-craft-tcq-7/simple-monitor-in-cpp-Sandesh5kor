#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;
using std::string;

void showCriticalMessage(const string& message) {
    cout << message << endl;
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\r *" << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int vitaltemperatureOk(int temperature)
{
  if (temperature > 102 || temperature < 95) {
    showCriticalMessage(string("Temperature is critical"));
    return 0;
  }
  return 1;
}

int vitalpulseRateOk(int pulseRate)
{
  if (pulseRate < 60 || pulseRate > 100) {
    showCriticalMessage(string("Pulse Rate is out of range!"));
    return 0;
  }
  return 1;
}

int vitalspo2Ok(int spo2)
{
  if (spo2 < 90) {
    showCriticalMessage(string("Oxygen Saturation out of range!"));
    return 0;
  }
  return 1;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return vitaltemperatureOk(temperature) && 
         vitalpulseRateOk(pulseRate) && 
         vitalspo2Ok(spo2);
}
