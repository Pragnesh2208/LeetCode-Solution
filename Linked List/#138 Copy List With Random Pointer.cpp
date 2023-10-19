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

/******************************Brute force solution***********************************/
/******************************Time Complexity = O(NLogN)*****************************/
/******************************Space Complexity = O(N)********************************/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        map<Node * , Node *>bucket;

        for(Node * tail = head ; tail ; tail = tail -> next) {
            Node * copyNode = new Node(tail -> val);
            bucket[tail] = copyNode;
        }
        for(Node * tail = head ; tail;tail = tail -> next) {
            Node * copyNode = bucket[tail];
            copyNode -> random = bucket[tail -> random];
            copyNode -> next = bucket[tail -> next];
        }

        return bucket[head];
    }
};

/******************************Optimal solution***********************************/
/******************************Time Complexity = O(N)*****************************/
/******************************Space Complexity = O(1)********************************/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node * tail = head;
        while(tail) {
            Node * copyNode = new Node(tail -> val);
            copyNode -> next = tail -> next;
            tail -> next = copyNode;
            tail = copyNode -> next;
        }

        tail = head;
        Node * copyList = tail -> next;

        while(tail) {
            Node * copyNode = tail -> next;
            if(tail -> random)
            copyNode -> random = tail -> random -> next;
            tail = copyNode -> next;
        }
        tail = head;
        while(tail) {
            cout<<tail -> val<<" ";
            tail = tail -> next;
        }

        tail = head;

        while(tail){
            Node * copyNode = tail -> next;
            Node * nextNode = copyNode -> next;
            if(nextNode)
            copyNode -> next = nextNode -> next;
            else copyNode -> next = nullptr;
            tail -> next = nextNode;
            tail = tail -> next;
        }
        return copyList;
    }
};