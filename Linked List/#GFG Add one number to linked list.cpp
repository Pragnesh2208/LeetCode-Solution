/******************************Optimal approach to Add one number to linked list*********************/
/******************************Time complexity = O(N)***********************************************/
/******************************Space complexity = O(1)**********************************************/
 class Solution {
 public:
    Node* addOne(Node *head) 
    {
        Node *Curr=head;
        Node *last=NULL;
        while(Curr->next!=NULL)
        {
            if(Curr->data!=9)
            last=Curr;
            Curr=Curr->next;
        }
        if(Curr->data!=9)
        last=Curr;
        if(last!=NULL)
        {
            last->data=last->data+1;
            last=last->next;
        }
       else 
        {
            last=new Node(1);
            last->next=head;
            head=last;
            last=head->next;
            
        }
        while(last!=NULL)
        {
            last->data=0;
            last=last->next;
        }
        return head;
    }
};