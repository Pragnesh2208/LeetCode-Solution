
/**************************This is brute force Approach For this problem ***************************/
/**************************TIme complexity = O(n^2) Big oh of N square ****************************/
/************************* and Space Complexity = O(1)********************************************/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        long long Max=0;
        for(long long i=0;i<n-1;i++)
        {
            long long Result=0;
            for(long j=i+1 ;j<n;j++)
            {
                Result=min(height[i],height[j]) * (j-i);
                 if(Result>Max)
                Max=Result;
            }         
        }
        return Max;
    }
};

/**************************************This is optimal solution***********************************/
/************************************** the Time complexity = O(n)*******************************/
/************************************** space complexity = O(1)**********************************/
                                    
#include<bits/stdc++.h>
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l,r;
        l=0;
        r=height.size()-1;
        long res=-1;
       while(l<r)
       {
           res=max(res,min(height[l],height[r])*(r-l));
        
           if(height[l]>height[r])
               r--;
           else
               l++;
       }
        return res;
    }
    int max(int a,int b){
        if(a>b)
            return a;
        else
            return b;
    }
    
};