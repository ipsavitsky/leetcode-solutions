/**
 * @file 0881.boats-to-save-people.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/boats-to-save-people/
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <algorithm>
#include <list>
#include <vector>

class Solution {
  public:
    int numRescueBoats(std::vector<int> &people, int limit) {
        int res = 0;
        std::sort(people.begin(), people.end());
        std::vector<int>::const_iterator left_prsn = people.cbegin();
        std::vector<int>::const_iterator right_prsn = std::prev(people.cend());
        while (left_prsn <= right_prsn) {
            ++res;
            if (*left_prsn + *right_prsn <= limit) {
                ++left_prsn;
            }
            --right_prsn;
        }
        return res;
    }
};