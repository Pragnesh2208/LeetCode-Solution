
/*
Celebrity Problem Optimal Solution Using Stack
Time Complexity = O(N)
Space Complexity = O(N)
*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
       stack<int>st;
       int ans = -1;
       for(int i = 0 ; i <  n; i++) {
           st.push(i);
       }
       
       while(st.size() > 1) {
           int first = st.top();
           st.pop();
           
           int two = st.top();
           st.pop();
           
           if(M[first][two] == 1 && M[two][first] == 0) st.push(two);
           else if(M[two][first] == 1 && M[first][two] == 0) st.push(first);  
       }
       if(!st.empty()) {
           int index = st.top();
           st.pop();
           ans  = index;
            for(int j = 0; j < n ; j++) {
                if(M[index][j] == 1) ans = -1;
                if(M[j][index] == 0 &&  j != index) ans = -1;
            }
            
       }
       
       return ans;
    }
};