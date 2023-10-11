/**
 * @file 0976.largest-perimeter-triangle.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/largest-perimeter-triangle/
 * @version 0.1
 * @date 2023-10-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <vector>

class Solution {
  public:
    int largestPerimeter(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        for (std::vector<int>::const_reverse_iterator it = nums.crbegin();
             it < std::prev(nums.crend(), 2); ++it) {
            if (*(it + 2) + *(it + 1) > *it) {
                return *(it + 2) + *(it + 1) + *it;
            }
        }
        return 0;
    }
};
