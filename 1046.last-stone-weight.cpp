#include <algorithm>
#include <vector>

class Solution {
  public:
    int lastStoneWeight(std::vector<int> &stones) {
        auto begin_it = stones.begin();
        while (std::distance(begin_it, stones.end()) > 1) {
            std::nth_element(begin_it, std::next(stones.begin()), stones.end(),
                             std::greater{});
            
            if (*begin_it == *std::next(begin_it)) {
                begin_it = std::next(begin_it, 2);
            } else {
                *begin_it -= *std::next(begin_it);
                std::swap(*begin_it, *std::next(begin_it));
                ++begin_it;
            }
        }
        return std::distance(begin_it, stones.end()) > 0 ? *begin_it : 0;
    }
};
