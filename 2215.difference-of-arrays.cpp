/**
 * @file 2215.difference-of-arrays.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/find-the-difference-of-two-arrays/
 * @version 0.1
 * @date 2023-05-03
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> findDifference(std::vector<int> &nums1,
                                                 std::vector<int> &nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::vector<int>::iterator unique_1 =
            std::unique(nums1.begin(), nums1.end());
        std::vector<int>::iterator unique_2 =
            std::unique(nums2.begin(), nums2.end());
        std::vector<int> res1, res2;
        std::set_difference(nums1.begin(), unique_1, nums2.begin(), unique_2,
                            std::back_inserter(res1));
        std::set_difference(nums2.begin(), unique_2, nums1.begin(), unique_1,
                            std::back_inserter(res2));
        return {res1, res2};
    }
};

int main() {
    std::vector<int> v1{1, 2, 3, 3};
    std::vector<int> v2{1, 1, 2, 2};
    Solution sol;
    sol.findDifference(v1, v2);
}