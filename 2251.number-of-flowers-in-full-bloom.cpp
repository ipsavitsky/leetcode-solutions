/**
 * @file 2251.number-of-flowers-in-full-bloom.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/number-of-flowers-in-full-bloom/
 * @version 0.1
 * @date 2023-10-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <iterator>
#include <vector>

class Solution {
  public:
    std::vector<int> fullBloomFlowers(std::vector<std::vector<int>> &flowers,
                                      std::vector<int> &people) {
        std::vector<int> starts;
        std::vector<int> ends;
        starts.reserve(flowers.size());
        ends.reserve(flowers.size());

        for (const std::vector<int> &flower : flowers) {
            starts.push_back(flower[0]);
            ends.push_back(flower[1] + 1);
        }

        std::sort(starts.begin(), starts.end());
        std::sort(ends.begin(), ends.end());

        std::vector<int> res;
        res.reserve(flowers.size());

        using v_cit = std::vector<int>::const_iterator;

        for(int person : people) {
           v_cit st_it = std::upper_bound(starts.cbegin(), starts.cend(), person);
           v_cit end_it = std::upper_bound(ends.cbegin(), ends.cend(), person);

           res.push_back(std::distance(starts.cbegin(), st_it) - std::distance(ends.cbegin(), end_it));
        }

        return res;
    }
};
