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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //1. check if k nodes actully exists in the LL
        ListNode* temp = head;
        int count = 0;

        while (count < k) {
            if(temp == NULL) {
                return head;
            }
            temp = temp->next;
            count++;
        }

        //2. Recursive call for rest of the LL

        ListNode* prev=reverseKGroup(temp, k);

        //3. Reverse the current k size group
        
        temp=head;
        count=0;
        ListNode* next = NULL;

        while(count < k) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }

        return prev;
    }
};