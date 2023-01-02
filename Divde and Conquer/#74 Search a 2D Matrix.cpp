/************************Optimal solution to Sort a Linked List*************************/
/************************Time Complexity = O( (N * M)Log (N * M)**************************************************/
/************************Space Complexity = O(1)*************************************************/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0 , high = m*n - 1;
        bool flag = false;
        while(low <= high) {
            int mid = (high + low) / 2;
            int row = mid / n  , col = mid % (n );
            
            if( matrix[row][col] == target ) {
                flag = true;
                break;
            }
            if( matrix[row][col] > target ) {
                high = mid - 1;
            }
            else low = mid + 1;

        }
        return flag;
    }
};