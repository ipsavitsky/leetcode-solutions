#include <algorithm>

class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        for (auto it = nums.cbegin(); it != std::prev(nums.cend()); ++it) {
            if (*it == *(it + 1)) {
                return *it;
            }
        }
        return 0;
    }
};
