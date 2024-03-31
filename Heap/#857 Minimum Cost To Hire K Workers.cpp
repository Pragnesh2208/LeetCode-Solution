/***********************Optimal Solution using heap +  Greedy**************************/
/***********************Time Complexity = O(NLogN)***************************/
/***********************Space Complexity = O(N)******************************/

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double , double>>worker;
        priority_queue<double>maxHeap;
        int n = quality.size();

        for(int i =  0 ; i <  n ; i++) {
            worker.push_back({(wage[i] * 1.0) / (quality[i] * 1.0) , quality[i]});
        }

        sort(worker.begin() , worker.end());

        double sumWage = 0;
        double minCost = 0;
        for(int i = 0 ; i < k ; i++) {
            sumWage += worker[i].second;
            maxHeap.push(worker[i].second);
        }

        minCost = sumWage * worker[k - 1].first;
    
        for(int captain = k ; captain < n ; captain++) {
           
            if(!maxHeap.empty() && worker[captain].second < maxHeap.top()) {
                sumWage -= maxHeap.top();
                maxHeap.pop(); 
                maxHeap.push(worker[captain].second);
                sumWage += worker[captain].second;
                minCost = min(minCost , sumWage * worker[captain].first);
            }
        }

        return minCost;
    }
};