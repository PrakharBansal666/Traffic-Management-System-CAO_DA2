# Traffic Management System(CAO_DA2)
This C++ program uses OpenMPI and simulates a traffic intersection with four directions (North, South, East, and West). Here's a simplified explanation of what the code does:
We have four traffic lights, one for each direction, at the intersection.
Each traffic light can be in one of three states: RED, YELLOW, or GREEN.
Initially, all traffic lights start as RED.
We also keep track of the number of cars waiting in each direction.
The program runs forever, simulating the operation of the traffic lights.
When cars are waiting in a particular direction, the traffic light for that direction turns GREEN.
The duration of the GREEN light depends on how many cars are waiting in that direction. More cars mean a longer GREEN light.
After the GREEN light, there is a YELLOW light for a fixed 3 seconds.
Then, the light turns RED for 1 second before repeating the cycle.
The program ensures that the traffic lights for each direction take turns, so they don't all turn GREEN at the same time.
We use a technology called MPI to make each traffic light work independently. It's like having four traffic light controllers, one for each direction, working together.
Each controller runs in a separate "thread" to manage the traffic light for its direction.
Once all the controllers have done their job, the program finishes running.
