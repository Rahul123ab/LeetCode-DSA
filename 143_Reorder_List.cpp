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
    void reorderList(ListNode* head) {
         //find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        //slow will be on the middle of the list at the end of the loop
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        //reverse the second half of the list
        ListNode* prev = NULL;
        ListNode* curr = second;
        while(curr!= NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next; 
        }
        //prev holds the head of the second half of the list

        //merge the two lists
        ListNode* first = head;
        second = prev;

        while(second != NULL) {
            ListNode* temp = first->next;
            first->next = second;
            first = temp;
            ListNode* temp2 = second->next;
            second->next = first;
            second = temp2;
        }       
    }
};