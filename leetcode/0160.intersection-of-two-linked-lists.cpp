/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      auto p1 = headA;
      auto p2 = headB;
      if (p1 == nullptr || p2 == nullptr) return nullptr;
      
      while (p1 != p2) {
        p1 = p1 == nullptr ? headB : p1->next;
        p2 = p2 == nullptr ? headA : p2->next;
      }
      return p1;
    }
};

// can also be done with length
