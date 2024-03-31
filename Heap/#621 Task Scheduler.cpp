/***********************Better Solution using heaps + queue************************/
/***********************Time Complexity = O(NLogK)***************************/
/***********************Space Complexity = O(K)******************************/
/***********************K stand for unique strings***************************/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        queue<pair<int , pair<int,char>>>que;
        priority_queue<pair<int,char>>maxHeap;
        vector<int>freq(26 , 0);
        int len = tasks.size();
        int intervals = 0;

        for(int i = 0 ; i < len ; i++) {
            freq[tasks[i] - 'A']++; 
        }

        for(int i = 0 ;  i < 26 ; i++) {
            if(freq[i] > 0)
            maxHeap.push({freq[i] , char('A' + i) });
        }   

        while(!maxHeap.empty() || !que.empty()) {
            if(!que.empty() && que.front().first <= intervals) {
                maxHeap.push(que.front().second);
                que.pop();
            }

            if(!maxHeap.empty()) {
                pair<int,char>topEle = maxHeap.top();
                maxHeap.pop();
                topEle.first--;
                if(topEle.first > 0)
                    que.push({intervals + n + 1 , topEle});
            }
            intervals++;
        }

        return intervals;
        
    }
};

/***********************Optimal Solution using Greedy +  Maths************************/
/***********************Time Complexity = O(N)***************************/
/***********************Space Complexity = O(1)******************************/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int n = tasks.size();
        cout<<n<<endl;
        vector<int>freq(26 , 0);
        int maxCount = 0;
        for(int i = 0 ; i < n ; i++) {
            freq[tasks[i] - 'A']++;

        }
        sort(freq.begin() , freq.end() , greater<int>());
        maxCount = freq[0];
        int emptySpace = (maxCount - 1) * k;
        for(int i = 1; i < 26 ;i++) {
            if(emptySpace > 0)
            emptySpace -= min(freq[i] , (maxCount - 1));
        }

        if(emptySpace < 0) emptySpace = 0;

        return n + emptySpace;
    }
};