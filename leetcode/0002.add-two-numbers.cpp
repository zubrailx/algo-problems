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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      // next just remove this element
      ListNode* head = new ListNode();
      
      ListNode* tail = head;
      int val;
      int overflow = 0;
      
      int l1v, l2v;
      while (!(l1 == nullptr && l2 == nullptr) || overflow == 1) {
        if (l1 == nullptr) { l1v = 0; }
        else {l1v = l1->val; }
        
        if (l2 == nullptr) { l2v = 0; }
        else {l2v = l2->val; }
        
        tail->next = new ListNode();
        tail = tail->next;
        
        val = l1v + l2v + overflow;
        tail->val = (val % 10);
        if (val > 9) {
          overflow = 1;
        } else {
          overflow = 0;
        }
        
        if (l1 != nullptr) {l1 = l1->next; }
        if (l2 != nullptr) {l2 = l2->next; }
      }
      // don't want to create new variable
      tail = head->next;
      delete head;
      return tail;
    }
};

