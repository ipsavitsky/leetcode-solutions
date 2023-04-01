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