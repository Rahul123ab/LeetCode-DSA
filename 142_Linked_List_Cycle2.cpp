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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;
                //to remove cycle follow these 3 steps
                //ListNode* prev=NULL;  // step 1
                while (slow != fast) {
                    slow = slow->next;
                    //prev=fast;        //step 2
                    fast = fast->next;
                }
                //prev->next = NULL //step 3
                return slow;
            }
        }
        return NULL;
    }
};