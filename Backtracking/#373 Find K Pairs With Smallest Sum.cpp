/************************************Optimal solution to Find K Pairs With Smallest Sum********************************/
/************************************Time Complexity is O( log K) ****************************************************/
/************************************Here we are Stroing k element in Priority Que***************/
/************************************Space Complexity is O( K)*****************************************************/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int , pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int , pair<int,int>>>>minHeap;
        set<pair<int,int>>visited;
        int n = nums1.size() , m = nums2.size();
        vector<vector<int>> ans;

        minHeap.push({nums1[0] + nums2[0] , {0 , 0}});

        visited.insert({0 , 0});

        while( k > 0 && !minHeap.empty()) {
            pair<int , pair<int,int>> minEle = minHeap.top();
            int firstEle = minEle.second.first;
            int secondEle = minEle.second.second;
            int fi = firstEle , si = secondEle;
            ans.push_back({nums1[firstEle] , nums2[secondEle]});
            minHeap.pop();
            k--;
            if(fi + 1 < n && visited.find({fi + 1 , si}) == visited.end()) {
                minHeap.push({nums1[fi + 1] + nums2[si] , {fi + 1,  si}});
                visited.insert({fi + 1, si});
            }

            if(si + 1 < m && visited.find({fi, si + 1}) == visited.end()) {
                minHeap.push({nums1[fi] + nums2[si + 1] , {fi , si + 1}});
                visited.insert({fi , si + 1});
            }
        }

        return ans;
    }
};