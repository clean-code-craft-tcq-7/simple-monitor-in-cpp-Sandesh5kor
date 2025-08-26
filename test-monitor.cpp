#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenHeartRateIsTooLow) {
  ASSERT_FALSE(vitalsOk(98.6, 50, 98));
}

TEST(Monitor, NotOkWhenHeartRateIsTooHigh) {
  ASSERT_FALSE(vitalsOk(98.6, 101, 98));
}

TEST(Monitor, NotOkWhenTemperatureIsTooLow) {
  ASSERT_FALSE(vitalsOk(94.0, 70, 98));
}

TEST(Monitor, NotOkWhenTemperatureIsTooHigh) {
  ASSERT_FALSE(vitalsOk(103.0, 70, 98));
}

TEST(Monitor, NotOkWhenOxygenSaturationIsTooLow) {
  ASSERT_FALSE(vitalsOk(98.6, 70, 89));
}

TEST(Monitor, NotOkWhenOxygenSaturationIsTooHigh) {
  ASSERT_FALSE(vitalsOk(98.6, 70, 100));
}

TEST(Monitor, OkWhenAllVitalsAreNormal) {
  ASSERT_TRUE(vitalsOk(98.6, 70, 98));
}

TEST(Monitor, OkWhenAllVitalsAreAtEdge) {
  ASSERT_TRUE(vitalsOk(95.0, 60, 90));
  ASSERT_TRUE(vitalsOk(102.0, 100, 100));
}

TEST(Monitor, OkWhenAllVitalsAreAtEdge2) {
  ASSERT_TRUE(vitalsOk(95.0, 100, 90));
  ASSERT_TRUE(vitalsOk(102.0, 60, 100));
}

TEST(Monitor, OkWhenAllVitalsAreAtEdge3) {
  ASSERT_TRUE(vitalsOk(95.0, 60, 100));
  ASSERT_TRUE(vitalsOk(102.0, 100, 90));
}

TEST(Monitor, OkWhenAllVitalsAreAtEdge4) {
  ASSERT_TRUE(vitalsOk(95.0, 100, 100));
  ASSERT_TRUE(vitalsOk(102.0, 60, 90));
}

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}

TEST(Monitor, NotOkWhenAnyVitalIsOffRange2) {
  ASSERT_FALSE(vitalsOk(94, 70, 98));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}
