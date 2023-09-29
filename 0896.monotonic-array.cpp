/**
 * @file 0896.monotonic-array.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/monotonic-array/
 * @version 0.1
 * @date 2023-09-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <type_traits>
#include <vector>

class Solution {
  public:
    bool isMonotonic(std::vector<int> &nums) {
        enum class Direction {
            increasing,
            decreasing,
            unknown
        } direction = Direction::unknown;

        using cv_it = std::remove_reference_t<decltype(nums)>::const_iterator;
        for (cv_it cur = nums.cbegin(); cur != std::prev(nums.cend()); ++cur) {
            cv_it next = std::next(cur);
            if (*next > *cur) {
                if (Direction::unknown == direction)
                    direction = Direction::increasing;
                else if (Direction::decreasing == direction)
                    return false;
            } else if (*next < *cur) {
                if (Direction::unknown == direction)
                    direction = Direction::decreasing;
                else if (Direction::increasing == direction)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    std::vector<int> a{1, 2, 2, 3};
    sol.isMonotonic(a);
}
