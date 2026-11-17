cmake_minimum_required(VERSION 3.8)
project(car_core)

find_package(ament_cmake REQUIRED)

# Biblioteka zawiera wyłącznie C++; inne pakiety będą mogły jej używać.
add_library(car_core src/motor.cpp)
target_compile_features(car_core PUBLIC cxx_std_17)
target_include_directories(car_core PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

install(DIRECTORY include/ DESTINATION include)
install(TARGETS car_core
  EXPORT export_car_core
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
ament_export_targets(export_car_core HAS_LIBRARY_TARGET)

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(test_motor test/test_motor.cpp)
  target_link_libraries(test_motor car_core)
endif()

ament_package()
