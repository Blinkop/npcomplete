#include "bf.hpp"
#include "kmkk.hpp"
#include "npcdefs.hpp"

#include <fstream>
#include <random>
#include <iostream>

namespace
{
    constexpr auto seed = 1337;
    constexpr auto u_min = 1;
    constexpr auto u_max = 10;
    constexpr auto set_length = 100;
}

int main(void)
{
    // std::mt19937 gen(seed);
    // std::uniform_int_distribution<uint32> dis(u_min, u_max);
    // uint32 _set[set_length];

    // for (auto i = 0; i < set_length; i++)
    //     _set[i] = dis(gen);

    uint32 _set[] = {1, 2, 3, 4, 5};

    //auto res1 = NPC::brute_force(_set, 5);
    auto res2 = NPC::kmkk(_set, 5);

    //std::cout << std::boolalpha << res1 << std::endl;
    std::cout << std::boolalpha << res2 << std::endl;

    return 0;
}
