#include "Simulation.h"

int main() {
    Simulation sim(4, 3, 0.2, 10000, 0.001); //CTOR: lambda, mu, stay_coeff, peopleCount, increment (in minutes)
    sim.simulate();
}