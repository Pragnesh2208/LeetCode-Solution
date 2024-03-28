/************************************Optimal solution Using  Heap*************************************************/
/************************************Time Complexity is O(KLogN)**************************************************/
/************************************As While loop can run K time as we will maximum push N elements**************/
/************************************Space Complexity is O(N)*****************************************************/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
        set<pair<int,int>> visited;
        int n = matrix.size();
        int ans = -1 ;
        visited.insert({ 0 , 0});
        minHeap.push({matrix[0][0] , { 0 , 0}});
        
        while(k > 0 && !minHeap.empty()) {
            pair<int, pair<int,int>> minEle = minHeap.top();
            int fi = minEle.second.first , si = minEle.second.second;
            minHeap.pop();

            if(fi + 1 < n && visited.find({fi + 1, si}) == visited.end()) {
                minHeap.push({matrix[fi + 1][si] , {fi + 1 , si}});
                visited.insert({fi + 1 , si});
            }
            if(si + 1 < n && visited.find({fi , si + 1}) == visited.end()) {
                minHeap.push({matrix[fi][si + 1] , { fi , si + 1}});
                visited.insert({fi , si + 1});
            }

            if(k == 1) ans =  minEle.first;
            k--;
        }

        return ans;
    }
};