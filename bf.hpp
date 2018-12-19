#ifndef _BRUTEFORCE_HPP_
#define _BRUTEFORCE_HPP_

#include "npcdefs.hpp"

namespace NPC
{
    template <typename T>
    void propogate(T* data, size_t len, uint64 accum, bool& found)
    {
        if (found)
            return;

        if (accum == sum_array(data, len))
        {
            found = true;
            return;
        }

        for (size_t i = 0; i < len; i++)
        {
            if (data[i] == 0)
                continue;

            auto saved = data[i];
            data[i] = 0;
            propogate(data, len, saved + accum, found);
            data[i] = saved;
        }
    }

    template <typename T>
    bool brute_force(T * data, size_t len)
    {
        bool found = false;

        for (size_t i = 0; i < len; i++)
        {
            auto saved = data[i];
            data[i] = 0;
            propogate(data, len, saved, found);
            data[i] = saved;
        }

        return found;
    }
}

#endif // _BRUTEFORCE_HPP_
