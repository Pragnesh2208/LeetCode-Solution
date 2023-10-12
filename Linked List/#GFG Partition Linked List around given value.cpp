
/*
**********************Opitmal Solution for Partition Linked List around given value******************************
**********************Time Complexity = O(N)*********************************************************************
**********************Space Complexity = O(1)********************************************************************
*/
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* partition(struct Node* head, int x) {
    // code here
    Node * less = new Node(0), * equal = new Node(0), * more = new Node(0);
    vector<Node *> tail = {less , equal , more};
    for(Node * itr = head ; itr != NULL ; itr = itr -> next) {
        int index = itr -> data < x ? 0 : itr -> data == x ? 1: 2;
        tail[index] -> next = itr;
        tail[index] = tail[index] -> next;
    }
    
    tail[2] -> next = NULL;
    tail[1] -> next = more -> next;
    tail[0] -> next = equal -> next;
    
    return less -> next;
}