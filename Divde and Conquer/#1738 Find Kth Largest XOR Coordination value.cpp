
/************************Optimal solution to Find Kth Largest XOR Coordinate value*************************/
/************************Time Complexity = O(N*M*LogK)**************************************************/
/************************Space Complexity = O(N*M)*************************************************/
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix[0].size() , n = matrix.size();
         vector<int>x (m , 0);
        vector<vector<int>>sum (n , x);
        priority_queue<int , vector<int> , greater<int>>pq;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++ ) {
                int summation = matrix[i][j];
                if(i - 1 >= 0 && j - 1 >= 0) summation ^= sum[i-1][j-1];
                if(i - 1 >= 0) summation ^= sum[i-1][j];
                
                if(j - 1 >= 0) summation ^= sum[i][j-1];
                
                sum[i][j] = summation;
                pq.push(summation);
                if(pq.size() == k + 1) pq.pop();

            }
        }        
        return pq.top();
    }
};