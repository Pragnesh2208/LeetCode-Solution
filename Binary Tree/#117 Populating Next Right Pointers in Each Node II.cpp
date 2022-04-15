/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/***********************Optimal Approach Populating Next Right Pointers in Each Node II****/
/************************Time Complexity = O(N)****************************************/
/************************Space Complexity = O(1)***************************************/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;
        Node *leftmost = root;
        while (leftmost)
        {

            Node *cur = leftmost;
            leftmost = NULL;
            Node *prev = NULL;

            while (cur)
            {
                if (cur->left)
                {
                    if (leftmost == NULL)
                        leftmost = cur->left;
                    if (prev != NULL)
                        prev->next = cur->left;
                    prev = cur->left;
                }

                if (cur->right)
                {
                    if (leftmost == NULL)
                        leftmost = cur->right;
                    if (prev != NULL)
                        prev->next = cur->right;
                    prev = cur->right;
                }
                cur = cur->next;
            }
        }
        return root;
    }
};