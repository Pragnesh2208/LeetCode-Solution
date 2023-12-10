/**
 * Optimal Approach to find the Solution
 * Time Complexity = O(N)
 * Space Complexity = O(1)
 * Here N is number of character in string
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string ExcelColumn(int n)
    {
        // Your code goes here
        string ans = "";
        while(n) {
            ans = char(65 + ( (n - 1) % 26)) + ans;
            n  = ( n - 1) / 26;
        }
        
        return ans;
    }
};