/**
 * @file 0002.add-two-numbers.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/add-two-numbers/
 * @version 0.1
 * @date 2023-09-24
 *
 * @copyright Copyright (c) 2023
 *
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l1_cur = l1;
        ListNode *l2_cur = l2;
        ListNode *res = nullptr, *cur_res = nullptr;
        int cur = 0;
        while (l1_cur != nullptr || l2_cur != nullptr || cur > 0) {
            if (l1_cur != nullptr) {
                cur += l1_cur->val;
                l1_cur = l1_cur->next;
            }
            if (l2_cur != nullptr) {
                cur += l2_cur->val;
                l2_cur = l2_cur->next;
            }
            if (res == nullptr) {
                res = new ListNode(cur % 10);
                cur_res = res;
            } else {
                cur_res->next = new ListNode(cur % 10);
                cur_res = cur_res->next;
            }
            cur /= 10;
        }
        return res;
    }
};
