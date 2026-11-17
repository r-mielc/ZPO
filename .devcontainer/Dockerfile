
FROM ros:jazzy-ros-base-noble

# Pakiety potrzebne do budowania C++ i uruchamiania testów GoogleTest przez ament.
# Kod projektu montujemy przez Compose, więc zmiana źródeł nie wymaga przebudowy obrazu.
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    python3-colcon-common-extensions \
    ros-jazzy-ament-cmake-gtest \
    && rm -rf /var/lib/apt/lists/*


WORKDIR /workspace/project/vehicle_ws
CMD ["bash"]
