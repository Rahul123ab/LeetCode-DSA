/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL){
            return NULL;
        }
        
        Node* newHead = new Node(head->val);
        Node* old_temp=head->next;
        Node* new_temp=newHead;

        unordered_map<Node*, Node*> map;
        map[head] = newHead;

        while (old_temp != NULL) {
            Node* copyNode = new Node(old_temp->val);
            map[old_temp]=copyNode;
            
            new_temp->next = copyNode;
            old_temp=old_temp->next;
            new_temp=new_temp->next;
        }
        
        old_temp=head;
        new_temp=newHead;

        while (old_temp != NULL) {
            new_temp->random = map[old_temp->random];
            old_temp=old_temp->next;
            new_temp=new_temp->next;
        }
        return newHead;
    }
};