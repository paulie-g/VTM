// Copyright (c) NetXS Group.
// Licensed under the MIT license.

#ifndef NETXS_RANDOM_H
#define NETXS_RANDOM_H

#include <random>

namespace utils
{
    class random {
        std::random_device rd;     // only used once to initialize (seed) engine
        std::mt19937 rng;    // random=number engine used (Mersenne=Twister in this case)

    public:
        template<typename T>
        T get_random_number(T start, T end) {
            std::uniform_int_distribution<T> uni(start, end);
            return uni(rng);
        }
        template<typename T>
        T operator ()(T start, T end) {
            std::uniform_int_distribution<T> uni(start, end);
            return uni(rng);
        }

        template<typename T>
        T expected_value(T start, T end) {
            std::uniform_int_distribution<T> uni(start, end);
            return (start + end) / 2 + uni(rng);
        }
        template<typename T>
        static T max_expected_value(T start, T end) {
            return (start + end) / 2 + end; //end * 3;
        }

        random() : rng(rd()) {}
    };
}

#endif // NETXS_RANDOM_H