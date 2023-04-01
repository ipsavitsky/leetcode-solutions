#include <vector>
#include <cmath>
#include <numeric>

class Solution {
public:
    long long pickGifts(std::vector<int>& gifts, int k) {
        for (int i = 0; i < k; ++i) {
            std::vector<int>::iterator m_iter = std::max_element(gifts.begin(), gifts.end());
            *m_iter = std::sqrt(*m_iter);
        }
        return std::accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};