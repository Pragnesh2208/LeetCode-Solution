/********************Method 1 - Using Heap*************************************************/
/********************Brute Force  approach to Find k Closest Element***********************/
/*******************Time complexity = O( (N + k ) LOGk) ***********************************/
/*******************Space complexity = O(K)  **********************************************/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       int n = arr.size();
       priority_queue<pair<int,int>>pq;
       for(int  i = 0 ; i < n ; i++ ) {
           if(pq.size() == k ) {
               if(pq.top().first > abs(arr[i] - x )) {
                  pq.pop();
                   pq.push({abs(arr[i] - x),arr[i]});
               }
           }
           else {
               pq.push({abs(arr[i] - x ) , arr[i]});
           }
       }
        int  i  = pq.size();
        vector<int>ans(i);
        while(!pq.empty()) {
            ans[--i] = pq.top().second;
            pq.pop();
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};

/********************Method 2 - Using Two Pointer Approach***************************/
/********************Better approach to Find k Closest Element***********************/
/*******************Time complexity = O(N)****************************************/
/*******************Space complexity = O(1)******************************************/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0 , right = n -1;
        while(right  - left + 1 > k) {
            
            if( arr[right] - x < x - arr[left]) 
                left++;
            else
                right--;
        }
        return vector<int> (arr.begin() + left , arr.begin() + right + 1 );
    }
};

/********************Method 3 - Using Binary Search Approach***************************/
/********************Better approach to Find k Closest Element***********************/
/*******************Time complexity = O(Log N )****************************************/
/*******************Space complexity = O(1)******************************************/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int right = n - k , left = 0;
        while(left < right) {
            int mid =  (right + left)/2;
            if(x - arr[mid] > arr[mid + k] - x )
                left = mid + 1;
            else
                right = mid;
                
        }
        return vector<int>(arr.begin() + left , arr.begin()+left+k);
    }
};
