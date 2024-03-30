/***********************Optimal Solution using heaps ************************/
/***********************Time Complexity = O(NLogN)***************************/
/***********************Space Complexity = O(N)******************************/

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        string ans = "";
        priority_queue<pair<int , char>> maxHeap;
        vector<int>freq(26);
        
        for(int i = 0 ; i < n ; i++) {
            freq[s[i] - 'a']++;
        } 

        for(int i = 0 ; i < 26 ; i++) {
            if(freq[i] > 0 ) {
                maxHeap.push({freq[i] , char('a' + i)});
            }
        }
        pair<int ,char> prevEle = {-1 , 'a'};
        while(!maxHeap.empty()) {
            pair<int , char> topEle = maxHeap.top();
            maxHeap.pop();
            if(prevEle.first > 0 ) maxHeap.push(prevEle);
            ans += topEle.second;
            topEle.first--;
            prevEle = topEle;
        }

        return prevEle.first > 0 ? "" : ans;
    }
};