/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
/********************Optimal approach to Flatten Multilevel doubly Linked Lists *********************/
/*******************Time complexity = O(N) *******************************************************/
/*******************Space complexity = O(1)  *****************************************************/
class Solution {
public:
    Node* flatten(Node* head) {
        for(Node * curr = head ; curr != NULL ; curr = curr -> next) {
            if(curr -> child ) {
                Node * node = curr -> next;
                curr -> next = curr -> child;
                curr -> child =NULL;
                curr ->next -> prev = curr;
                Node *tree = curr -> next;
                while(tree -> next != NULL) {
                    tree = tree -> next;    
                }
                tree -> next = node ;
                if(node)
                node -> prev = tree;
                }
        }
         return head;
    }
};