/***************************Brute Force Approach to find Two Sum in BST *****************/
/**************************Time Complexity = O(N)*************************/
/************************Space Complexity = O(N)*************************/
class Solution {
    private:
    void inorder(TreeNode * root , vector<int>&arr) {
        if(root == NULL)
            return;
        inorder(root -> left , arr);
        arr.push_back(root -> val);
        inorder(root -> right , arr);
    }
    bool search(vector<int>&arr , int k) {
        int low = 0;
        int high = arr.size() - 1;
        while(low < high) {
            int sum = arr[low] + arr[high];
            if(sum == k)
                return true;
            else if(sum > k) high = high -1;
            else low = low + 1;
        }
        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
      inorder(root , arr);
       return search(arr , k);
    }
};

/***************************Optimal Approach to find Two Sum in BST using BST Iterator*****************/
/**************************Time Complexity = O(N)*************************/
/************************Space Complexity = O(H)*************************/
class BSTIterator {
    stack<TreeNode*> s;
    TreeNode* node;
    bool forward;
public:
    BSTIterator(TreeNode *root, bool ford) {
        node=root;
    forward= ford; 
    }
    int next() {
        int nextVal ;
        while (node || !s.empty()) {
            
            if (node) {
                s.push(node);
                node = forward ? node->left : node->right;
            }
            else {
                node = s.top();
                s.pop();
                nextVal = node->val;
                node = forward ? node->right : node->left;
                break;
               
            }
        }
         return nextVal;  
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        
        BSTIterator l(root, true);
        BSTIterator r(root, false);
        int i = l.next();
        int j = r.next();
        while( i < j) {
            int sum = i + j;
            if (sum == k) {
                return true;
            }
            else if (sum < k) {
                i = l.next();
            }
            else {
                j = r.next();
            }
        }
        return false;
    }
};