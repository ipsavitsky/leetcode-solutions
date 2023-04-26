/**
 * @file 0258.add-digits.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/add-digits/
 * @version 0.1
 * @date 2023-04-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

class Solution {
  private:
    int get_sum_of_digits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

  public:
    int addDigits(int num) {
        int res = get_sum_of_digits(num);
        while (res > 10) {
            res = get_sum_of_digits(res);
        }
        return res;
    }
};