/*#include <iostream>
#include <random>

#include <iomanip>
#include <fstream>

#include <map>
#include <queue>

std::queue<double> queue;
int i = 0;

const int peopleCount = 100000;
double arriveTime[peopleCount];
double serveTime[peopleCount];
const double stay_coeff = 0.9;

void try_to_serve(double time) {
    if (queue.size() == 0) {
        return;
    }
    queue.front() -= time;
    if (queue.front() > 0) {
        return;
    }
    double tempTime = -queue.front();
    queue.pop();
    try_to_serve(tempTime);
}

void try_to_push(double time) {
    arriveTime[i] -= time;
    if (arriveTime[i] > 0) {
        return;
    }
    int r = rand() % 10 + 1;
    if (r <= stay_coeff * 10) {
        queue.push(serveTime[i]);
        std::cout << "pushed." << std::endl;
    } else {
        std::cout << "ran away." << std::endl;
    }
    i++;
    try_to_push(-arriveTime[i-1]);
}

int main(int argc, char** argv) {
    const double lambda = 3; // per minute
    const double mu = 4;

    std::mt19937 rnd_gen(time(0));
    std::exponential_distribution<> rng (lambda);
    std::exponential_distribution<> rng1 (mu);

    for(int i = 0; i < peopleCount; i++) {
        arriveTime[i] = rng(rnd_gen);
        serveTime[i] = rng1(rnd_gen);
    }

    double sum = 0;

    std::ofstream file;
    file.open("output/arrive_time.txt");

    for (int i = 0; i < peopleCount; i++) {
        std::cout << arriveTime[i] << " ";
        sum += arriveTime[i];
        file << arriveTime[i] << " ";
    }
    std::cout << std::endl;

    file.close();

    file.open("output/serve_time.txt");

    for (int i = 0; i < peopleCount; i++) {
        std::cout << serveTime[i] << " ";
        sum += serveTime[i];
        file << serveTime[i] << " ";
    }
    std::cout << std::endl;

    file.close();

    std::cout << sum/peopleCount << std::endl;

    /////
    double increment = 0.001;
    double time = 0;

    file.open("output/queue_size.txt");

    while (i < peopleCount) {
        try_to_push(increment);
        try_to_serve(increment);
        time += increment;
        
        std::cout << "Current time is " << time << std::endl;
        std::cout << "Size of queue: " << queue.size() << std::endl;

        file << time << ":" << queue.size() << " ";

        
    }

    std::cout << "Peoples are done" << std::endl;

    while (queue.size() != 0) {
        try_to_serve(increment);
        time += increment;
        std::cout << "Current time is " << time << std::endl;
        std::cout << "Size of queue: " << queue.size() << std::endl;
        file << time << ":" << queue.size() << " ";
        
    }

    file.close();

    return 0;
}*/



#include "Simulation.h"

int main() {
    Simulation sim(4, 3, 0.2, 100000, 0.001); //CTOR: lambda, mu, stay_coeff, peopleCount, increment (in minutes)
    sim.simulate();
}