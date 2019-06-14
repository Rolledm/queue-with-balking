#ifndef SIMULATION_H
#define SIMULATION_H

#include <deque>
#include "Logger.h"

#define LOG(severity, message) Logger::getInstance().log(severity, message)

class Simulation {
public:
    Simulation(const double lambda, const double mu, const double stay_coeff, const int peopleCount, const double timeDelta);
    ~Simulation();

    void tryToServe(double time);
    void tryToPush(double time);

    void simulate();

private:
    const double lambda;
    const double mu;
    const double stay_coeff;

    const int peopleCount;
    const double timeDelta;

    double* arriveTime;
    double* serveTime;
    int i = 0;

    std::deque<double> queue;

    int servedPeople = 0;
    double timeInSystem = 0;
    double timeInQueue = 0;
};

#endif