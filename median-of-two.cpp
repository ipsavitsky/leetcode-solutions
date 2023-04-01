#include <algorithm>
#include <iterator>
#include <vector>

class Solution {
  public:
    double findMedianSortedArrays(std::vector<int> &nums1,
                                  std::vector<int> &nums2) {
        std::vector<int> merged_nums;
        merged_nums.reserve(nums1.size() + nums2.size());
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
                   std::back_inserter(merged_nums));
        unsigned int middle_element = merged_nums.size() / 2;
        return merged_nums.size() % 2 == 0
                   ? static_cast<double>(merged_nums[middle_element - 1] +
                                         merged_nums[middle_element]) /
                         2
                   : merged_nums[middle_element];
    }
};