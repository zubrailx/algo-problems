/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// solution #1 (returns last element from recursion)
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if (head == nullptr) {return nullptr; } 
      ListNode* tail = head;
      while (tail->next) tail = tail->next;
      recursion(head);
      return tail;
    }
  
    ListNode* recursion(ListNode* head) {
      if (head->next == nullptr) { return head; }
      auto sorted_l = recursion(head->next);
      sorted_l->next = head;
      head->next = nullptr;
      return head;
    }
};
*/


// solution #2 (returns first element from recursion)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if (head == nullptr || head->next == nullptr) return head;
      auto sorted_f = reverseList(head->next);
      head->next->next = head;
      head->next = nullptr;
      return sorted_f;
    }
};


// iterative is obvious
