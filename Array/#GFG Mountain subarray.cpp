/******************** Brute Force approach To find Maximum product of two elements in  array****************/
/*******************Time complexity = O(N^2) Big o of N Square*********************************************/
/*******************Space complexity = O(1)***************************************************************/
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