#include <iostream>
#include <thread>
#include <chrono>
#include <mpi.h>

enum TrafficLightState {
    RED,
    GREEN,
    YELLOW
};

const int NUM_DIRECTIONS = 4;
TrafficLightState lightStates[NUM_DIRECTIONS] = {RED, RED, RED, RED};
int carCounts[NUM_DIRECTIONS] = {5, 3, 0, 2};  // Hard-coded car counts for each direction

void controlTrafficLight(int direction) {
    while (true) {
        int carsInDirection = carCounts[direction];

        if (carsInDirection > 0) {
            lightStates[direction] = GREEN;
            int greenDuration = 5 + carsInDirection * 2; // Green light duration with additional 2 seconds per car
            std::cout << "Direction " << direction << ": Green Light for " << greenDuration << " seconds\n";
            std::this_thread::sleep_for(std::chrono::seconds(greenDuration));
            carCounts[direction] = 0; // Reset car count to 0 after green light
        } else if (lightStates[direction] == GREEN) {
            lightStates[direction] = YELLOW;
            std::cout << "Direction " << direction << ": Yellow Light for 3 seconds\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
        } else {
            lightStates[direction] = RED;
            std::cout << "Direction " << direction << ": Red Light\n";
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait for 1 second while in red
        }

        // Move to the next direction (cyclically)
        direction = (direction + 1) % NUM_DIRECTIONS;
    }
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank >= NUM_DIRECTIONS) {
        MPI_Finalize();
        return 0;
    }

    controlTrafficLight(rank);

    MPI_Finalize();
    return 0;
}
