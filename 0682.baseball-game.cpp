/**
 * @file 0682.baseball-game.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/baseball-game
 * @version 0.1
 * @date 2023-09-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <deque>
#include <numeric>
#include <string>
#include <vector>

class Solution {
  public:
    int calPoints(std::vector<std::string> &operations) {
        std::deque<int> record;
        for (const std::string &cur : operations) {
          if ("D" == cur) {
            record.push_back(record.back() * 2);
          } else if ("C" == cur) {
            record.pop_back();
          } else if ("+" == cur) {
            record.push_back(record.back() + record[record.size()-2]);
          } else {
            record.push_back(std::stoi(cur));
          }
        }
        return std::accumulate(record.begin(), record.end(), 0);
    }
};
