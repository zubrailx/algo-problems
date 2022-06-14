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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode *dummy = new ListNode();
      ListNode *dist = dummy;
      dist->val = INT_MIN;
      dist->next = head;

      ListNode *next;
      next = dist->next;
      ListNode *tmp;
      while (next) {
        tmp = next->next;
        if (tmp && tmp->val == next->val) {
          tmp = next;
          while (tmp && tmp->val == next->val) {
            tmp = tmp->next;
          }
          dist->next = tmp;
          next = tmp;
        } else {
          dist = next;
          next = next->next;
        } 
      }
      next = dummy->next;
      delete dummy;
      return next;
    }
};
