/*********************Optimal Approach for Find Ceil in BST*************/
/*********************Time complexity = O (N )**************************/
/**********************Space complexity = O (H)*************************/

int findCeil(Node* root, int val) {
    if (root == NULL) return -1;

    // Your code here
    if(root -> data == val) return root -> data;
    int temp = root -> data > val ? findCeil(root -> left , val) : findCeil(root -> right , val);
    if(temp == -1) {
        if(root -> data > val)
        return root -> data;
        else return -1;
        
    }
    return temp;
}