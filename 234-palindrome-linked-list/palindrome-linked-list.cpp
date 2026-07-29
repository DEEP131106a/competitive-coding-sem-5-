// *we use two pointer approach here and reverse the linked list from the middle of the array 

 class Solution {
public:

    // Function to reverse a linked list
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL)
        {
            next = curr->next;     
            curr->next = prev;     
            prev = curr;           
            curr = next;          
        }

        return prev;   // New head of reversed list
    }

    bool isPalindrome(ListNode* head) {

        // Empty list or single node is always palindrome
        if(head == NULL || head->next == NULL)
            return true;

        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverse(slow);

        // Step 3: Compare first and second halves
        ListNode* firstHalf = head;

        while(secondHalf != NULL)
        {
            if(firstHalf->val != secondHalf->val)
                return false;

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Step 4: All nodes matched
        return true;
    }
};
