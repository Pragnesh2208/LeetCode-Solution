/***********************Optimal Solution using heap +  Greedy**************************/
/***********************Time Complexity = O(K * NLogN)***************************/
/***********************Space Complexity = O(N)******************************/
class Solution {
    vector<int> kthSmallestPairs(vector<int> &v1 , vector<int>&v2 , int k) {
        priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int,int>>>  , greater<pair<int , pair<int,int>>>>minHeap;
        set<pair<int,int>>visited;
        vector<int>res;
        int n = v1.size() , m = v2.size();

        minHeap.push({ v1[0] + v2[0],{ 0 , 0 }});
        visited.insert({0,0});
        while(k-- && !minHeap.empty()) {
            pair<int,int> topEle = minHeap.top().second;
            res.push_back(minHeap.top().first);
            minHeap.pop();

            int fi = topEle.first , si = topEle.second;
        
            if(fi + 1 < n && visited.find({fi + 1 , si}) == visited.end()) {
                minHeap.push({v1[fi + 1] + v2[si] , {fi + 1 , si}});
                visited.insert({fi + 1 , si});
            }

            if(si + 1 < m && visited.find({fi, si + 1}) == visited.end()) {
                minHeap.push({v1[fi] + v2[si + 1] , {fi , si + 1}});
                visited.insert({fi , si + 1});
            }
        }

        return res;
    }
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int>res = mat.front();
        int n = mat.size();

        for(int i = 1 ; i < n ; i++) {
            res = kthSmallestPairs(res, mat[i] , k);
        }

        return res[k - 1];
    }   
};