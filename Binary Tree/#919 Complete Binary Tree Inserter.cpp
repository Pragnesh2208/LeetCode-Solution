/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/***********************Optimal Approach For Complete Binary Tree Inserter****************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(H)**************************************************/
class CBTInserter {
    private:
    queue<TreeNode * > que;
    TreeNode * start , curr;
public:
    CBTInserter(TreeNode* root) {
        start = root;
         que.push(root);
        while(true) {
           TreeNode * node = que.front();
            if(node -> left)
                que.push(node -> left);
            if(node -> right)
                que.push(node -> right);
            if(node -> right && node -> left)
                que.pop();
            else
                break;
        }
    }
    
    int insert(int val) {
        TreeNode *N = new TreeNode (val);
        TreeNode * node = que.front();
        if(node -> left == NULL) {
            node  -> left  = N;
                que.push(node -> left);
        }
        else if(node -> right == NULL) {
            node -> right = N;
            que.pop();
                que.push(node -> right);
        }
        return node -> val;
    }
    
    TreeNode* get_root() {
        return start;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */