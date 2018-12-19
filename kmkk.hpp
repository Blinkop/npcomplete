#ifndef _KMKK_HPP_
#define _KMKK_HPP_

#include "npcdefs.hpp"

// for std::memcpy
#include <cstring>

namespace NPC
{
    template <typename T>
    bool kmkk(T * data, size_t len)
    {
        auto data_extended = new T[len * 2 - 1];
        std::memcpy(data_extended, data, len * sizeof(T));
        merge_sort_des(data_extended, 0, len*2-2);

        size_t start = 0;
        size_t end = len - 1;

        for (size_t i = 0; i < len - 1; i++)
        {
            ++end;
            data_extended[end] = data_extended[start] - data_extended[start + 1];
            start += 2;

            merge_sort_des(data_extended, start, end);
        }

        auto result = data_extended[end];
        delete[] data_extended;

        return result ? false : true;
    }
}

#endif // _KMKK_HPP_
