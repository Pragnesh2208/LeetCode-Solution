/***********************Optimal Solution using heaps + queue ************************/
/***********************Time Complexity = O(NLogK)***************************/
/***********************Space Complexity = O(K)******************************/
/***********************K stand for unique strings***************************/
class Solution {
public:
    string rearrangeString(string s, int k) {
        queue<pair<int , pair<int , char>>> que;
        priority_queue<pair<int , char>> maxHeap;
        vector<int>freq(26);
        int n = s.length();
        string ans = "";

        for(int i = 0 ; i < n ; i++) {
            freq[s[i] - 'a']++;
        }

        for(int i = 0 ; i < 26 ; i++) {
            if(freq[i] > 0) {
                maxHeap.push({freq[i] , char('a' + i)});
            }
        }

        pair<int,char> prevEle = {-1, 'a'};

        while(!maxHeap.empty()) {
            pair<int , char> topEle = maxHeap.top();
            maxHeap.pop();
            int count = topEle.first - 1;
            char c = topEle.second;
            prevEle = topEle;
            ans += c;
            if(count > 0) {
                topEle.first = count;
                que.push({ ans.length() + k - 1 ,topEle});
            }

            if(!que.empty() && que.front().first <= ans.length()) {
                maxHeap.push(que.front().second);
                que.pop();
            }  
        }
        return prevEle.first == 1 && ans.length() == s.length() ?ans : "";
    }
};