#include <iostream>
#include <random>

#include <iomanip>
#include <fstream>

#include <map>
#include <queue>

std::queue<double> queue;
int i = 0;

const int peopleCount = 10;
double arriveTime[peopleCount];
double serveTime[peopleCount];

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
    queue.push(serveTime[i]);
    i++;
    try_to_push(-arriveTime[i-1]);
}

int main(int argc, char** argv) {
    const double lambda = 4; // per minute
    const double mu = 3;

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
        std::cout << arriveTime[i] << " ";
        sum += arriveTime[i];
        file << arriveTime[i] << " ";
    }
    std::cout << std::endl;

    file.close();

    std::cout << sum/peopleCount << std::endl;


    /////
    double increment = 0.1;
    double time = 0;
    while (i < peopleCount) {
        std::cout << "Current time is " << time << std::endl;
        std::cout << "Size of queue: " << queue.size() << std::endl;
        try_to_push(increment);
        try_to_serve(increment);
        time++;
    }

    return 0;
}