/*
Optimal Approach to Solve using Heap
Time Complexity = O(NLogK)
Space Complexity = O(K)
*/
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        int n = num;
        priority_queue<int , vector<int>, greater<int>> pq;
        vector<int>result;
        for(int i = 0 ; i < K + 1 ; i++) pq.push(arr[i]);
        int  index = K + 1;
        while(!pq.empty()) {
            int minEle = pq.top();
            pq.pop();
            
            result.push_back(minEle);
            if(index < n)
            pq.push(arr[index++]);
        }
        
        return result;
    }
};