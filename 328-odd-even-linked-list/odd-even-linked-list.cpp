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
    ListNode* oddEvenList(ListNode* head) {

 // If the list is empty or has only one node
if (head == NULL || head->next == NULL)
return head;
// odd points to first node (position 1)
 ListNode* odd = head;

// even points to second node (position 2)
        ListNode* even = head->next;

        // Save the head of the even list
        ListNode* evenHead = even;

        // Traverse until there are no more even nodes
        while (even != NULL && even->next != NULL) {

            // Connect current odd node to next odd node
            odd->next = even->next;

            // Move odd pointer
            odd = odd->next;

            // Connect current even node to next even node
            even->next = odd->next;

            // Move even pointer
            even = even->next;
        }

        // Attach even list after odd list
        odd->next = evenHead;

        return head;
    }
};