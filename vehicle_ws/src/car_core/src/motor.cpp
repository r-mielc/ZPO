#include "car_core/motor.hpp"

#include <algorithm>
#include <cmath>
#include <stdexcept>

namespace car_core {

Motor::Motor(double max_speed) : max_speed_(max_speed) {
  if (!std::isfinite(max_speed) || max_speed <= 0.0) {
    throw std::invalid_argument("max_speed must be finite and positive");
  }
}

void Motor::setSpeed(double requested_speed) {
  if (!std::isfinite(requested_speed)) {
    throw std::invalid_argument("requested_speed must be finite");
  }
  speed_ = std::clamp(requested_speed, -max_speed_, max_speed_);
}

double Motor::speed() const noexcept { return speed_; }

double Motor::maxSpeed() const noexcept { return max_speed_; }

}  // namespace car_core
