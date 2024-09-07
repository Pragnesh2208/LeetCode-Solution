/*********************Optimal Approach for Find Floor in BST************/
/*********************Time complexity = O (N )**************************/
/**********************Space complexity = O (H)*************************/

class Solution{

public:
    int floor(Node* root, int x) {
        if(root == NULL) return -1;
        if(root -> data == x) return x;
        int temp = root -> data > x ? floor(root -> left , x) : floor(root -> right , x);
        if(temp == -1) {
            if(root -> data > x) {
                return -1;
            } else root -> data;
        }
    }
};
