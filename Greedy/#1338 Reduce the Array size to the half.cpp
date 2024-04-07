/********************************Better approach using greedy*********************************/ 
/********************************Time Complexity  = O (NLogN) ***********************************/
/********************************Space Complexity  = O (N) **********************************/
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<int>freq(1e5 + 1 , 0);
        for(int i = 0 ; i < n ; i++) {
            freq[arr[i]]++;
        }

        sort(freq.begin() , freq.end(),greater<int>());
        int count = 0;
        for(int i = 0 ; i <= 1e5 && count < (n / 2) ; i++) {
            count += freq[i];
            ans++;
        }
        return ans;
    }
};


/********************************Optimal approach using greedy + countsort*********************************/ 
/********************************Time Complexity  = O (N) ***********************************/
/********************************Space Complexity  = O (N) **********************************/
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int ans = 0 , maxFreq = 0;
        vector<int>freq(1e5 + 1 , 0);
        for(int i = 0 ; i < n ; i++) {
            freq[arr[i]]++;
            maxFreq = max(maxFreq , freq[arr[i]]);
        }

        vector<int>bucket(maxFreq + 1 , 0);

        for(int i = 0; i <= 1e5; i++) {
            if(freq[i] != 0) {
                bucket[freq[i]]++;
            }
        }

        int half = (n / 2);
        int curCount = maxFreq;
        while(half > 0) {
            if(bucket[curCount] > 0) {
                half -= curCount;
                bucket[curCount]--;
                ans++;
            } else {
                curCount--;
            }
        }      
        return ans;
    }
};