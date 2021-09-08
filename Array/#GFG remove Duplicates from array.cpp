/******************** Brute Force approach To Remove duplicates from array************************/
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
/******************** Optimal approach To Remove duplicates from array************************/
/*******************Time complexity = O(N)****************************************************/
/*******************Space complexity = O(1)***************************************************/

class Solution{
    private:
vector<int> removeDuplicate(vector<int>& arr, int n)
    {  long  prod=arr[0];
      long  index=1;
      for(int i=1;i<n;i++)
      {
          if(prod%arr[i]!=0)
          {
              arr[index]=arr[i];
            
              prod*=arr[index];
              
                index++;
          }     
      }
      arr.erase(arr.begin()+index,arr.end());
      return arr;
    }
}