/******************** Brute Force approach To find Mountain subarray form***************************/
/*******************Time complexity = O(N^2) Big o of N Square**************************************/
/*******************Space complexity = O(1)*********************************************************/
class Solution{
  public:
    vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                                int q) {
    vector<bool>ans;
    for(int j=0;j<q;j++)
    {
        int l=queries[j].first;
        int r=queries[j].second;
        int i=l;
        while(i+1<=r && a[i+1]>=a[i])
            i++;
            while(i+1<=r && a[i+1]<=a[i])
            i++;
        if(i==r)
        ans.push_back(true);
        else
        ans.push_back(false);
    }
                                    
        return ans;
        
    }
};

/*********************Optimal approach To find Mountain subarray form************************/
/*********************Time complexity = O(N) ****************************************************/
/*********************Space complexity = O(N)****************************************************/

class Solution{
  public:
    vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                                int q) {
        // code here
       vector<int>left( n , 0);
       vector<int>right(n ,0);
       int incr = 0 , decr = 0;
       //find the left greater
       for(int i = 1 ; i < n ; i++){
            if(a[i] > a[i-1])
            incr = i;
            right[i] = incr;
       }
       //find the right greater
       for(int i = n-2 ; i >= 0 ; i--){
            if(a[i] > a[i+1])
             decr= i;
            left[i] = decr;
       }
    
       vector<bool>ans;
       for(int i = 0 ; i < q ; i++){
           pair<int , int>query = queries[i];
           int l = query.first;
           int r = query.second;
           ans.push_back(right[r] == left[l]);
       }
       
         return ans;
    }
};
