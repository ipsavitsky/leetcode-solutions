/**
 * @file 0860.lemonade-change.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/lemonade-change/
 * @version 0.1
 * @date 2023-10-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <cstdint>
#include <vector>

class Solution {
  private:
    struct {
        uint32_t fives = 0;
        uint32_t tens = 0;
    } cash_state;

  public:
    bool lemonadeChange(std::vector<int> &bills) {
        for (int bill : bills) {
            switch (bill) {
            case 5:
                ++cash_state.fives;
                break;
            case 10:
                ++cash_state.tens;
                if (cash_state.fives > 0) {
                    --cash_state.fives;
                } else {
                    return false;
                }
                break;
            case 20:
                if (cash_state.tens > 0 && cash_state.fives > 0) {
                    --cash_state.tens;
                    --cash_state.fives;
                } else if (cash_state.fives >= 2) {
                    cash_state.fives -= 2;
                } else {
                    return false;
                }
                break;
            }
        }
        return true;
    }
};
