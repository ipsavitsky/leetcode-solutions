/**
 * @file 0206.reverse-linked-lists.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/reverse-linked-list/
 * @version 0.1
 * @date 2023-04-26
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
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *saved_head = head;
        ListNode *next = head->next;

        while (next->next != nullptr) {
            ListNode *forward_node = next->next;
            next->next = head;
            head = next;
            next = forward_node;
        }

        next->next = head;

        saved_head->next = nullptr;
        return next;
    }
};