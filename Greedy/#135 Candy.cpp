/********************************Better approach to using Greedy + heap********/ 
/********************************Time Complexity  = O (NLogN)*****************************/
/********************************Space Complexity  = O (N)******************************/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int minCandy = 0;
        vector<int>candy( n , 1);
        priority_queue<pair<int , int> , vector<pair<int,int>> , greater<pair<int,int>>>minHeap;

        for(int i = 0 ; i < n ; i++) {
            minHeap.push({ratings[i] , i});
        }

        while(!minHeap.empty()) {
            pair<int,int> topEle = minHeap.top();
            minHeap.pop();
            int index = topEle.second;
            if(index - 1 >= 0 && ratings[index - 1] < ratings[index] ) {
                int dif = candy[index - 1] - candy[index];
                candy[index] += dif + 1;
            }

            if(index + 1 < n && ratings[index + 1] < ratings[index] && candy[index] <= candy[index + 1]) {
                int dif = candy[index + 1] - candy[index];
                candy[index] += dif + 1;
            }
        }

        for(int i = 0; i < n ; i++) {
            minCandy += candy[i];
        }

        return minCandy;
    }
};

/********************************Optimal approach to using Greedy ********/ 
/********************************Time Complexity  = O (N)*****************************/
/********************************Space Complexity  = O (N)******************************/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int minCandy = 0;
        vector<int>rightCandy(n , 1) , leftCandy( n  , 1);

        for(int i = 1 ; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                leftCandy[i] = (leftCandy[i - 1]  + 1);
            }
        } 

        for(int i = n - 2 ; i >= 0 ; i--) {
            if(ratings[i] > ratings[i + 1]) { 
                rightCandy[i] = (rightCandy[i + 1] + 1);
            };
        }
        
        for(int i = 0; i < n ; i++) {
            minCandy += max(leftCandy[i] , rightCandy[i]);
        }

        return minCandy;
    }
};

/********************************Optimal approach to using Greedy with single array********/ 
/********************************Time Complexity  = O (N)*****************************/
/********************************Space Complexity  = O (N)******************************/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 0;
        vector<int>candies(n , 1);

        for(int i = 1 ; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                candies[i] = (candies[i - 1]  + 1);
            }
        } 

        sum += candies[n  - 1];
        for(int i = n - 2 ; i >= 0 ; i--) {
            if(ratings[i] > ratings[i + 1]) { 
                candies[i] = max(candies[i] , candies[i + 1] + 1 );
            };
            sum += candies[i];
        }

        return sum;
    }
};