#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void showCriticalMessage(const string& message) {
    cout << message << endl;
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\r *" << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  if (temperature > 102 || temperature < 95) {
    showCriticalMessage("Temperature is critical");
    return 0;
  } else if (pulseRate < 60 || pulseRate > 100) {
    showCriticalMessage("Pulse Rate is out of range!");
    return 0;
  } else if (spo2 < 90) {
    showCriticalMessage("Oxygen Saturation out of range!");
    return 0;
  }
  return 1;
}
