#include <iostream>
#include <random>

#include <iomanip>
#include <fstream>

#include <map>


int main(int argc, char** argv) {
    double lambda;
    const int peopleCount = 100;

    if (argc == 2) {
        lambda = std::stod(argv[1]);
    } else {
        lambda = 3; // per minute
    }
    
    std::mt19937 rnd_gen(time(0));
    std::exponential_distribution<> rng (lambda);


    double arriveTime[peopleCount];

    for(int i = 0; i < peopleCount; i++) {
        arriveTime[i] = rng(rnd_gen);
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

    std::cout << sum/peopleCount << std::endl;

    return 0;
}