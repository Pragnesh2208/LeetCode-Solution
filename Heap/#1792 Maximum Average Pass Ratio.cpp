/********************Optimal approach to Find Maximum Average Pass Ratio***********************/
/*******************Time complexity = O( (N + extraStudents ) LOGN) ***************************/
/*******************Space complexity = O(N)  **************************************************/
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double , pair<int , int >>> pq;
        int n = classes.size();
        
        for(int  i = 0 ; i < n ; i++) {
            int pass = classes[i][0];
            int total = classes[i][1];
            double delta = (double)(pass+1)/(total +1) - (double)(pass)/(total);
            
            pq.push({delta , {pass , total}});
        }
        while(extraStudents--) {
            int pass = pq.top().second.first;
            int total = pq.top().second.second;
            pass++;
            total++;
            pq.pop();
            double newDelta = (double)(pass+1)/(total +1) - (double)(pass)/(total);
            pq.push({newDelta ,{pass , total} });
        
        }
        double ratio = 0.0;
        while(!pq.empty()) {
           
            ratio += (double)pq.top().second.first /(double)pq.top().second.second;
            pq.pop();
        }
         return ratio/n;   
    }
};