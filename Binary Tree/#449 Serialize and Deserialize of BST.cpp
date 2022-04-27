/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/***********************Optimal Approach for Serialize and Deserialize of BST************/
/************************Time Complexity = O(N)***************************************/
/************************Space Complexity = O(N)**************************************/
class Codec {

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#,";
        string temp;
       queue<TreeNode * > que;
        que.push(root);
        while(!que.empty()) {
            TreeNode * node = que.front();
             que.pop();   
            if(node == NULL ) temp.append("#,");
            else {
                temp.append(to_string(node -> val) + ',');
                
                que.push(node -> left);
                que.push(node -> right);
            } 
           
        }
        return temp;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string String) {
        if(String.length() == 0 )
            return NULL;
        
        stringstream data(String );
    
        queue<TreeNode *>que;
        string str;
        getline(data , str , ',');
        if(str == "#") return NULL;
        TreeNode * root = new TreeNode (stoi(str));
        que.push(root);
        while(!que.empty()) {
            
            TreeNode * node = que.front();

            que.pop();

            getline(data , str , ',');
            
            if(str == "#") node -> left = NULL;
            
            else{
                TreeNode * Left = new TreeNode(stoi(str));
                node -> left = Left;
                que.push(Left);
            }
            
            getline(data , str , ',');
            
            if(str == "#") node -> right = NULL;
            
            else{
                TreeNode * Right = new TreeNode(stoi(str));
                node -> right = Right;
                que.push(Right);
            }
        }
        return root;  
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;