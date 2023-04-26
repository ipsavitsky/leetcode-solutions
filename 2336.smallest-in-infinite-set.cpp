/**
 * @file 2336.smallest-in-infinite-set.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/smallest-number-in-infinite-set/
 * @version 0.1
 * @date 2023-04-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <algorithm>
#include <functional>
#include <vector>

class SmallestInfiniteSet {
  public:
    std::vector<int> added_nums;
    int ceiling = 1;

    SmallestInfiniteSet() {}

    int popSmallest() {
        if (added_nums.empty()) {
            ++ceiling;
            return ceiling - 1;
        } else {
            std::pop_heap(added_nums.begin(), added_nums.end(),
                          std::greater<int>{});
            int res = added_nums.back();
            added_nums.pop_back();
            return res;
        }
    }

    void addBack(int num) {
        std::vector<int>::iterator found_place =
            std::find(added_nums.begin(), added_nums.end(), num);
        if (num >= ceiling || found_place != added_nums.end())
            return;
        else{
            added_nums.push_back(num);
            std::push_heap(added_nums.begin(), added_nums.end(),
                           std::greater<int>{});
        }
    }
};