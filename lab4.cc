#include "bf.hpp"
#include "kmkk.hpp"
#include "npcdefs.hpp"

#include <fstream>
#include <random>
#include <iostream>
#include <chrono>

namespace
{
    constexpr auto seed = 1337;
    constexpr auto u_min = 1;
    constexpr auto u_max = 10;
    constexpr auto max_length = 100;
    constexpr auto max_length_bf = 6;

    void log_time(long long time, size_t N, uint32 algorithm, const std::string& filename)
    {
        std::ofstream outfile;

        outfile.open(filename, std::ios::app);
        outfile << std::to_string(algorithm) << "," << std::to_string(N) << "," << std::to_string(time) << std::endl;
    }

}

int main(void)
{
    std::mt19937 gen(seed);
    std::uniform_int_distribution<uint32> dis(u_min, u_max);
    uint32 _set[max_length];

    for (auto i = 0; i < max_length; i++)
        _set[i] = dis(gen);

    for (auto i = 2; i <= max_length_bf; i++)
    {
        auto start = std::chrono::system_clock::now();
        auto res1 = NPC::brute_force(_set, i);
        auto end = std::chrono::system_clock::now();
        log_time((end - start).count(), i, 0, "time.csv");
    }

    for (auto i = 2; i <= max_length; i++)
    {
        auto start = std::chrono::system_clock::now();
        auto res2 = NPC::kmkk(_set, i);
        auto end = std::chrono::system_clock::now();
        log_time((end - start).count(), i, 1, "time.csv");
    }

    return 0;
}
