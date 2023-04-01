#include <iterator>
#include <vector>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        for (std::vector<int>::const_iterator f = nums.cbegin();
             f != nums.cend(); ++f) {
            for (std::vector<int>::const_iterator s = std::next(f);
                 s != nums.cend(); ++s) {
                if (target == *f + *s) {
                    return std::vector<int>{
                        static_cast<int>(std::distance(nums.cbegin(), f)),
                        static_cast<int>(std::distance(nums.cbegin(), s))};
                }
            }
        }
        return {};
    }
};