#include "bf.hpp"
#include "kmkk.hpp"

#include <fstream>
#include <random>

typedef unsigned long ulong;

namespace
{
    constexpr auto seed = 1337;
    constexpr auto u_min = 1;
    constexpr auto u_max = 10;
    constexpr auto set_length = 100;
}

int main(void)
{
    std::mt19937 gen(seed);
    std::uniform_int_distribution<ulong> dis(u_min, u_max);
    ulong _set[set_length];

    for (auto i = 0; i < set_length; i++)
        _set[i] = dis(gen);

    // test
    auto res1 = NPC::brute_force(_set, set_length);
    auto res2 = NPC::kmkk(_set, set_length);
    // test


    return 0;
}
