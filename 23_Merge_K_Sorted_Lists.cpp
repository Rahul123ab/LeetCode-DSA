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

    ListNode* divide(vector<ListNode*>& lists, int start, int end) {
        if(start > end) {
            return NULL;
        }
        if(start == end) {
            return lists[start];
        }

        int mid = start + (end - start)/2;
        ListNode* left = divide(lists, start, mid);
        ListNode* right = divide(lists, mid+1, end);

        return conquer(left, right);
    }

    ListNode* conquer(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(list1 != NULL && list2 != NULL) {
            if(list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if(list1 != NULL) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }
        return dummy.next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return NULL;
        }
        return divide(lists, 0, lists.size()-1);        
    }
};