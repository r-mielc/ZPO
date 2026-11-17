#pragma once

namespace car_core {

// Minimalny model silnika: przechowuje zadaną prędkość z ograniczeniem modułu.
// Ograniczenie przyspieszenia i hamowania będzie kolejnym krokiem projektu.
class Motor {
public:
  explicit Motor(double max_speed);

  void setSpeed(double requested_speed);
  double speed() const noexcept;
  double maxSpeed() const noexcept;

private:
  double max_speed_;
  double speed_ = 0.0;
};

}  // namespace car_core
