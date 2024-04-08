/********************************Optimal approach using greedy*********************************/ 
/********************************Time Complexity  = O (N) ***********************************/
/********************************Space Complexity  = O (1) **********************************/

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size() , l = 0 , r = 0;
        for(int i = n - 2 ; i >=0 ; i--) {
            if(arr[i] > arr[i + 1]) {
                l = i; 
                break;
            }
        }

        r = l + 1;

        for(int i = r ; i < n ; i++) {
            if(arr[i] < arr[l] && arr[i] > arr[r]) {
                r = i;
            }
        }

        swap(arr[l] , arr[r]);
        return arr;
    }
};