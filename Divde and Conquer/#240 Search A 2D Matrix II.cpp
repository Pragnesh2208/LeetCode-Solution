/************************Naive solution of Search A 2D Matrix*************************/
/************************Time Complexity = O(M * Log(N + M))**************************************************/
/************************Space Complexity = O(1)*************************************************/
class Solution {
    bool binarySearch(int &row , int &col , vector<vector<int>>&matrix , int &target) {
        int m = matrix.size() , n = matrix[0].size();
        int  left = 0 , right = m + n - 2 * row - 2; 

        while(left <= right) {
            int index = left + (right - left) / 2;
            int r , c;
            if(index <= col ) {
                r = row;
                c = index; 
            } else {
                r = index - col + row;
                c = col;
            }

            int mid = matrix[r][c];
        
            if(mid == target) return true;
            else if( mid < target) left = index + 1;
            else right= index - 1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool flag = false;
        int m = matrix.size() , n = matrix[0].size();
        int row = 0 , col = n - 1;
        while(row < m && col >= 0) {
            flag = binarySearch(row , col , matrix , target );
            if(flag ) break;
            row++;
            col--;
        }
        return flag;
    }
};


/************************Optimal solution of Search A 2D Matrix*************************/
/************************Time Complexity = O(N + M)**************************************************/
/************************Space Complexity = O(1)*************************************************/

class Solution {
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool flag = false;
        int m = matrix.size() , n = matrix[0].size();
        int row = 0 , col = n - 1;
        while(row < m && col >= 0) {
            int mid = matrix[row][col];
            if(mid == target) {
                flag = true;
                break;
            }
            else if(mid > target) {
                col--;
            }   

            else row++;
           
        }
        return flag;
    }
};