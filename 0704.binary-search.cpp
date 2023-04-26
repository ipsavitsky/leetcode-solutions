/**
 * @file 0704.binary-search.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/binary-search/
 * @version 0.1
 * @date 2023-04-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <cstdlib>
#include <functional>
#include <vector>

class Solution {
  private:
    static int comparator(const void *a, const void *b) {
        return *static_cast<const int *>(a) - *static_cast<const int *>(b);
    }

  public:
    int search(std::vector<int> &nums, int target) {
        const int *elem = static_cast<int *>(std::bsearch(
            &target, nums.data(), nums.size(), sizeof(int), comparator));
        return std::max(elem - nums.data(), -1L);
    }
};