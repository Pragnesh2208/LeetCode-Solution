/***********************Recursive  Brute Force Approach To find Mode in Binary Search Tree********/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(N)**************************************************/
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;
        vector<int> result;
        int modeCount = getModeCount(root, map);
        
        for(pair<int,int> p : map) {
            if(p.second == modeCount) {
                result.push_back(p.first);
            }
        }
        
        return result;
        
    }
    int getModeCount(TreeNode* root, unordered_map<int, int> &map) {
        if(root == NULL)
            return 0;
        
        if(map.find(root->val) == map.end()) {
            map.insert(pair<int, int>(root->val, 1));
        }
        else {
            map[root->val]++;
        }
        return max(map[root->val], max(getModeCount(root->left, map), getModeCount(root->right, map)));
    }
};
/***********************Optimal Approach To find Mode in Binary Search Tree******************/
/************************Time Complexity = O(N)**********************************************/
/************************Space Complexity = O(H) + O(Modes)**********************************/
class Solution {
public:
    int maxFreq = 0, currFreq = 0, precursor = INT_MIN;
    vector<int> res;

    vector<int> findMode(TreeNode *root)
    {
        inorderTraversal(root);
        return res;
    }
    void inorderTraversal(TreeNode *root)
    {
        if (root == NULL) return;
        // Stop condition
        inorderTraversal(root->left); 
        // Traverse left subtree
        if (precursor == root->val) currFreq++;
        else currFreq = 1;
        if (currFreq > maxFreq)
        {// Current node value has higher frequency than any previous visited
            res.clear();
            maxFreq = currFreq;
            res.push_back(root->val);
        }
        else if (currFreq == maxFreq)
        {// Current node value has a frequency equal to the highest of previous visited
            res.push_back(root->val);
        }
        precursor = root->val; // Update the precursor
        inorderTraversal(root->right); // Traverse right subtree
    }
};