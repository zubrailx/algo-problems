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

ListNode* first_sol(ListNode* head, int n) {
  // create temp element
  ListNode *nw = new ListNode(0, head);
  head = nw;

  ListNode* last = head;
  while(last->next != nullptr) {
    last = last->next;
  }

  ListNode *prev;
  for (int i = 0; i < n; ++i) {
    prev = head;
    while(prev->next != last) {
      prev = prev->next;
    }
    last = prev;
  }

  prev->next = prev->next->next;

  head = nw->next;
  delete nw;
  return head;
}

ListNode* second_sol(ListNode* head, int n) {
  ListNode* first = head, *second = head;
  for (int i = 0; i < n; ++i) first = first->next;
  if (!first) return head->next;
  while(first->next) {
    first = first->next;
    second = second->next;
  }
  second->next = second->next->next;
  return head;
}
  
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      //return first_sol(head, n);
      return second_sol(head, n);
    }
};

