#include "car_core/motor.hpp"

#include <limits>
#include <stdexcept>

#include <gtest/gtest.h>

TEST(MotorTest, StartsStoppedAndAcceptsSpeedWithinLimit) {
  car_core::Motor motor(2.0);
  EXPECT_DOUBLE_EQ(motor.speed(), 0.0);
  EXPECT_DOUBLE_EQ(motor.maxSpeed(), 2.0);

  motor.setSpeed(1.25);
  EXPECT_DOUBLE_EQ(motor.speed(), 1.25);
}

TEST(MotorTest, LimitsSpeedInBothDirections) {
  car_core::Motor motor(2.0);
  motor.setSpeed(3.0);
  EXPECT_DOUBLE_EQ(motor.speed(), 2.0);

  motor.setSpeed(-3.0);
  EXPECT_DOUBLE_EQ(motor.speed(), -2.0);
}

TEST(MotorTest, RejectsInvalidValuesWithoutChangingCurrentSpeed) {
  EXPECT_THROW(car_core::Motor(0.0), std::invalid_argument);
  EXPECT_THROW(car_core::Motor(-1.0), std::invalid_argument);

  car_core::Motor motor(2.0);
  motor.setSpeed(1.0);
  EXPECT_THROW(motor.setSpeed(std::numeric_limits<double>::quiet_NaN()),
               std::invalid_argument);
  EXPECT_DOUBLE_EQ(motor.speed(), 1.0);
}
