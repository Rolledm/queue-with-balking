#include "Simulation.h"

#include <random>
#include <fstream>

#include <iostream>

Simulation::Simulation(const double lambda, const double mu, const double stay_coeff, const int peopleCount, const double timeDelta) :
                                        lambda(lambda), mu(mu), stay_coeff(stay_coeff), peopleCount(peopleCount), timeDelta(timeDelta) {

        arriveTime = new double[peopleCount];
        serveTime = new double[peopleCount];
        std::mt19937 rnd_gen(time(0));
        std::exponential_distribution<> rng (lambda);
        std::exponential_distribution<> rng1 (mu);

        for(int i = 0; i < peopleCount; i++) {
            arriveTime[i] = rng(rnd_gen);
            serveTime[i] = rng1(rnd_gen);
        }
    }

Simulation::~Simulation() {
    delete[] arriveTime;
}

void Simulation::tryToPush(double time) {
    if (i >= peopleCount) return;
    arriveTime[i] -= time;
    if (arriveTime[i] > 0) {
        return;
    }
    int r = rand() % 10 + 1;
    if (r <= stay_coeff * 10) {
        queue.push_back(serveTime[i]);
        LOG(Severity::INFO, "Customer joined the queue.");
        LOG(Severity::INFO, "Customer number " + std::to_string(i) + "/" + std::to_string(peopleCount));
        for (auto& it : queue) {
            timeInSystem += it;
        }
        if (queue.size() > 1) {
            for (auto& it : queue) {
                timeInQueue += it;
            }
            timeInQueue -= queue.front();
        }
    } else {
        LOG(Severity::INFO, "Customer not joined the party.");
    }
    i++;
    tryToPush(-arriveTime[i-1]);
}

void Simulation::tryToServe(double time) {
    if (queue.size() == 0) {
        return;
    }
    queue.front() -= time;
    if (queue.front() > 0) {
        return;
    }
    double tempTime = -queue.front();
    queue.pop_front();
    LOG(Severity::INFO, "Customer served.");
    servedPeople++;
    tryToServe(tempTime);
}

void Simulation::simulate() {
    LOG(Severity::INFO, "Simulation started");

    std::ofstream file;
    file.open("output/arrive_time.txt");

    for (int i = 0; i < peopleCount; i++) {
        file << arriveTime[i] << " ";
    }
    file.close();
    file.open("output/serve_time.txt");
    for (int i = 0; i < peopleCount; i++) {
        file << serveTime[i] << " ";
    }
    file.close();

    double time = 0;
    file.open("output/queue_size.txt");

    while (i < peopleCount) {
        tryToPush(timeDelta);
        tryToServe(timeDelta);
        time += timeDelta;
        
        LOG(Severity::INFO, "Current time is " + std::to_string(time));
        LOG(Severity::INFO, "Size of queue: " + std::to_string(queue.size()));

        file << time << ":" << queue.size() << " ";
    }

    LOG(Severity::INFO, "End of people.");

    while (queue.size() != 0) {
        tryToServe(timeDelta);
        time += timeDelta;

        LOG(Severity::INFO, "Current time is " + std::to_string(time));
        LOG(Severity::INFO, "Size of queue: " + std::to_string(queue.size()));
        file << time << ":" << queue.size() << " ";
        
    }

    file << servedPeople << ":" << time << ":" << timeInSystem << ":" << timeInQueue;

    file.close();
    LOG(Severity::INFO, "Simulation finished");
}