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
  ListNode* reverseList(ListNode* head) {
    if (head == NULL) return NULL;  
    // rh - reverse head
    auto rh = head;
    // oh - original next
    auto on = head->next;
    rh->next = NULL;
    // tmp - previous value of rh
    auto tmp = rh;
    while (on != NULL) {
      rh = on;
      on = on->next;
      rh->next = tmp;
      tmp = rh;
    }
    return rh;
  }
  
public:
  bool isPalindrome(ListNode* head) {
    // second jump * 2
    auto first = head;
    auto second = head;
    // find center
    ListNode* first_next;
    while (first != NULL) {
      first_next = first->next;
      if (first_next == NULL) {
        break;
      }
      second = second->next;
      first = first_next->next;
    }
    // now second points to center of list (if even then l / 2 + 1)
    second = reverseList(second);
    first = head;
    while (second != NULL) {
      if (first->val != second->val) return false;
      first = first->next;
      second = second->next;
    }
    return true;   
  }
};

