/*************************Optimal approach to find subsequent array of size 3in array********************/
/*************************Time complexity = O(N)********************************************************/
/**************************Space complexity = O(N)*****************************************************/

class Solution {
public:
    vector<int> find3Numbers(vector<int> arr, int N) {
       vector<int>ans;
        int left[N],right[N];
       
        int l=INT_MAX;
        for(int i=0;i<N;i++)
        {
            l=min(arr[i],l);
            left[i]=min(l , arr[i]);
        }
       int r=INT_MIN;
        for(int i=N-1;i>=0;i--)
        {
            r=max(r,arr[i]);
            right[i]=max(arr[i],r);
        }
        for(int i=0;i<N;i++)
        {
            if(left[i]!=right[i] && left[i]!=arr[i] && right[i]!=arr[i])
            {
                ans.push_back(left[i]);
                ans.push_back(arr[i]);
                ans.push_back(right[i]);
                break;
            }
        }
        return ans;
    }
};