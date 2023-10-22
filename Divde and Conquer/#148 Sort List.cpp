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

/************************Optimal solution to Sort a Linked List*************************/
/************************Time Complexity = O(N*LogN)**************************************************/
/************************Space Complexity = O(1)*************************************************/

class Solution {
    ListNode * mergeList(ListNode *l1 , ListNode *l2) {
              
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode *p1  ;
       
        p1 = l1->val > l2-> val ? l2  : l1;
  
        ListNode * d = new ListNode(-1);
        d -> next = p1;
        if(l1 -> val > l2 -> val) l2 = l2 -> next;
        else l1 = l1 -> next;

        while(l1 != NULL && l2 != NULL) {
           
            if(l1 -> val > l2 -> val) {
                p1->next = l2;
              
                l2 = l2 -> next;
            }
               
            else  {
                p1 -> next = l1;
               l1 =  l1 -> next;
            }
              p1 = p1 -> next;
        }

        while(l1 != NULL) {
            p1 -> next = l1;
          p1 = p1 -> next;
            l1 = l1 -> next;
        }

        while(l2 != NULL) {
            p1 -> next = l2;
              p1 = p1 -> next;
            l2 = l2 -> next;
        }
        return d -> next;
    }

    ListNode * mergesortList(ListNode * head) {
        if(head -> next == NULL) return head;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next != NULL && fast -> next -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        } 
        ListNode * temp = slow -> next;
        slow -> next = NULL;
        slow = temp;

        ListNode * l1 = mergesortList(head);
        ListNode * l2 = mergesortList(slow);
      
        return mergeList(l1 , l2);
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
     return mergesortList(head);   
    }
};


/*
Clean Code
*/
// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/
class Solution{
  public:
    Node * getMid(Node * head) {
        if(!head) return NULL;
        Node * slow = head , * fast = head;
        while(fast -> next && fast -> next -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    
    Node * mergeTwoLists(Node * first , Node * second) {
        if(!first) return second;
        if(!second) return first;
        Node * dummyHead = new Node(0);
        Node * tail = dummyHead;
        while(first && second) {
            if(first -> data < second -> data) {
                tail -> next = first;
                first = first -> next;
            }else {
                tail -> next = second;
                second = second -> next;
            }
            tail = tail -> next;
        }
        
        if(first) tail -> next = first;
        if(second) tail -> next = second;
        return dummyHead -> next;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(!head || head -> next == NULL) return head;
        Node * mid = getMid(head);
        
        if(mid) {
            Node * temp = mid -> next;
            mid  -> next = NULL;
            mid = temp;      
        }
        
        
        Node * left = mergeSort(head);
        Node * right = mergeSort(mid);
        return mergeTwoLists(left , right);
        
    }
};
