/**********************Optimal Approach to Find path in zigzag Labelled Binary Tree****************************/
/*********************Time complexity = O (LOGN)*******************************************************/
/**********************Space complexity = O (1)*****************************************************/
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = 0;
        while((1 << level) <= label) level++;
        
        vector<int> path(level);
        for(;level != 0 ; label  /= 2 , level--) {
            path[level -1] = label;
            label = (1 << level) - 1 - label  + (1 << (level - 1)) ;
        }
        return path;
    }
};
