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
/********************Method - 1 by reversing input  Linked List *************************************/
/********************Optimal approach to Add two numbers in Linked List*********************/
/*******************Time complexity = O(max(M,N))*******************************************************/
/*******************Space complexity = O(max(M,N))*****************************************************/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ptr1 =  reverse(l1);
        ListNode * ptr2 =  reverse(l2);
        ListNode * dummy = new ListNode(0);
        ListNode * ptr3 =  dummy;
        int carry = 0;
        while(ptr1 != NULL || ptr2 != NULL || carry != 0) {
            int sum = 0;
            if(ptr1 != NULL) {
                sum += ptr1 -> val;
                ptr1 = ptr1 -> next;
            }
            if(ptr2 != NULL) {
                sum += ptr2 -> val;
                ptr2 = ptr2 -> next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode * Node = new ListNode(sum % 10);
            ptr3 -> next = Node;
            ptr3 = ptr3 -> next;
            
        }
        return reverse(dummy -> next);
       
    }
    ListNode * reverse(ListNode * head) {
        ListNode * prev = NULL;
        while(head != NULL) {
            ListNode * next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

/********************Method - 2 by Not reversing input  Linked List *************************************/
/********************Optimal approach to Add two numbers in Linked List*********************/
/*******************Time complexity = O(max(M,N))*******************************************************/
/*******************Space complexity = O(max(M,N))*****************************************************/
class Solution {
public:
 // This function return the size of LinkedList;
    int lengthOfList(ListNode * head) {
        int size = 0;
        while(head != NULL) {
            size++;
            head = head -> next;
        }
        return size;
    }
    // Funtion to reverse the output Linked List
	
    ListNode * reverse ( ListNode * head) {
        ListNode * prev = NULL;
        while(head != NULL) {
            cout<<head -> val <<" ";
            ListNode * next = head -> next;
            head -> next = prev;
            prev = head ;
            head = next;
        }
        return prev;
    }
    
	// Our original function which return the answer 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode * dummy = new ListNode (0);
        ListNode * ptr1 = dummy , *prev = NULL ;
       int lengthofList1 = lengthOfList(l1);  //size of 1st Linked List 
       int lengthofList2 = lengthOfList(l2); // size of 2nd Linked List
       
	   int carry = 0;  // initially the carry is 0
 
 // if the size of 2nd Linked List is greater than 1st Linked List we will swap them 
 // As we are considering 1st Linked List having larger size than second Linked List. 
       
	   if(lengthofList2 > lengthofList1) {
            swap (l1,l2);
            swap(lengthofList2 , lengthofList1);
        }
        // We calculate difference between size of both Linked List
       
	   int diff = lengthofList1 - lengthofList2; 
	   
	   //Now we are having 1st Linked List larger so we will start traversing 
	   //untill difference of Length of Both List become 0
       
	   while(diff > 0)
        {
            ListNode * node = new ListNode(l1 -> val);
            ptr1 -> next = node;
            ptr1 = ptr1 -> next;
            l1 = l1 -> next;
            diff-- ;
        }
        
       while( l1 != NULL || l2 != NULL ) {
           int sum = 0;
           if( l1 != NULL) {
               sum += l1 -> val;
               l1 = l1 -> next;
           }
           if( l2 != NULL) {
               sum += l2 -> val;
               l2 = l2 -> next;
           }
           ListNode * node = new ListNode (sum);
           ptr1 ->next =node;
           ptr1 = ptr1 -> next;
       }
        
        dummy = reverse(dummy -> next);
        ptr1 = dummy;
       // Now we check if node has value more than 10 if yes we will change it
	   
        while(ptr1 != NULL || carry != 0) {
            
            if(prev)
            {
                ListNode * node = new ListNode(carry);
                prev -> next = node;
               
                carry = carry / 10;
                break;
            }
            if(ptr1 ->next == NULL ) {
                prev = ptr1;
            }
            
            int val = carry + ptr1 -> val;
           ptr1 -> val = val>=10 ? val % 10 : val;
            
             carry = val / 10;
          
            ptr1 = ptr1 -> next;
        }
        
        return reverse(dummy);
   
    }
};