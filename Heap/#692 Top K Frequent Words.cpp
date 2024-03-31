/***********************Better Solution using heaps ************************/
/***********************Time Complexity = O(NLogK)***************************/
/***********************Space Complexity = O(K)******************************/

class Solution {
  
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int>mp;
        priority_queue<pair<int,  string>>minHeap;
        vector<pair <int , string>>resWords;
        vector<string>res;
        int n = words.size();

        for(int i = 0 ; i < n ; i++) {
            mp[words[i]]++;
        }

        for(auto p : mp) {
            minHeap.push({-p.second , p.first});
            if(minHeap.size() > k ) minHeap.pop();
        }

        while(!minHeap.empty()) {
            resWords.push_back(minHeap.top());
            minHeap.pop();
        }

        sort(resWords.begin() , resWords.end());
        for(auto &p : resWords) {
            res.push_back(p.second);
        }
       return res;
    }
};