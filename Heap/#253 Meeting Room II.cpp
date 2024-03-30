/***********************Optimal Solution using heaps ************************/
/***********************Time Complexity = O(NLogN)***************************/
/***********************Space Complexity = O(N)******************************/

class Solution {
   
public:
 static bool myCmp(vector<int> &a , vector<int> &b){
        return a[0] < b[0];
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        priority_queue<int, vector<int> , greater<>> minHeap;
        sort(intervals.begin() , intervals.end() ,  myCmp);

        for(int i = 0 ; i < n ; i++) {
            if(!minHeap.empty() && intervals[i][0] >= minHeap.top()) {
                minHeap.pop();
            } 
            minHeap.push(intervals[i][1]);
        }
        
        return minHeap.size();
    }
};