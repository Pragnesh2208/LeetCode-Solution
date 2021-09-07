/******************** Optimal approach To Remove duplicates from array************************/
/*******************Time complexity = O(N)****************************************************/
/*******************Space complexity = O(N)***************************************************/
class Solution {
public:
    vector<int> removeDuplicate(vector<int>& arr, int n)
    {
      vector<int>ans;
      unordered_set<int>s;
      for(int i=0;i<n;i++)
    {
        if(s.find(arr[i])==s.end())
        {
            ans.push_back(arr[i]);
            s.insert(arr[i]);
        }    
    }
    return ans;
    }
};