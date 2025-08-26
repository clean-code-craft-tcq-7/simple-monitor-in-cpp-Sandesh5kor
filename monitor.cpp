#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;
using std::string;

// Language support
enum class Language { EN, DE };
Language currentLanguage = Language::EN;

void setLanguage(Language lang) {
    currentLanguage = lang;
}

string translate(const string& key, const string& vitalName) {
    if (currentLanguage == Language::DE) {
        if (key == "out_of_range") return " " + vitalName + " ist außerhalb des Bereichs!\n";
    }
    // Default: English
    if (key == "out_of_range") return " " + vitalName + " is out of range!\n";
    return "";
}

void vitalsCheckAttention() {
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

bool isVitalOk(float value, float lower, float upper, const string& name) {
    if (value < lower || value > upper) {
        cout << translate("out_of_range", name);
        vitalsCheckAttention();
        return false;
    }
    return true;
}

bool vitalsOk(float temperature, float pulseRate, float spo2,
              float bloodSugar, float bloodPressure, float respiratoryRate) {
    return isVitalOk(temperature, 95, 102, "Temperature") &&
           isVitalOk(pulseRate, 60, 100, "Pulse Rate") &&
           isVitalOk(spo2, 90, 100, "Oxygen Saturation") &&
           isVitalOk(bloodSugar, 70, 110, "Blood Sugar") &&
           isVitalOk(bloodPressure, 90, 150, "Blood Pressure") &&
           isVitalOk(respiratoryRate, 12, 20, "Respiratory Rate");
}
