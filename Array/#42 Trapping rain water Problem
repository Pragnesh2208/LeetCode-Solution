/******************** Brute Force approach To find trapping rain water****************************/
/*******************Time complexity = O(N)********************************************************/
/*******************Space complexity = O(N)*******************************************************/
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left[n],right[n];
        int Max=INT_MIN;
        for(int i=1;i<n;i++)
        {
            Max=max(Max,height[i-1]);
            left[i]=Max;
        }
        Max=INT_MIN;
        for(int i=n-2;i>=0;i--)
        {
            Max=max(Max,height[i+1]);
            right[i]=Max; 
        }
        cout<<endl;
        int sum=0;
        for(int i=1;i<n-1;i++)
        {
            if(left[i] > 0 && right[i] > 0 && height[i] < left[i] && height[i] < right[i])
            {
                sum+=min(left[i],right[i]) - height[i];
            }
        }
        return sum;  
    }
};
/********************Optimal approach To find trapping rain water*******************************/
/********************Time complexity = O(N)********************************************************/
/*******************Space complexity = O(1)*******************************************************/
class Solution {
public:
   
        int trap(vector<int>& height){
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) 
    {
        if (height[left] < height[right]) 
        {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
            cout<<"left "<<left_max<<" ";
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
             cout<<"right "<<right_max<<" ";
        }
        cout<<endl;
    }
    return ans;
}  
};