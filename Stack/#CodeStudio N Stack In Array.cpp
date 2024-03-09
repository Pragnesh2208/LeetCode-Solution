/*N Stack in Array Optimal Solution*/
/*Time Compleixty = O(1)*/
/*Space Complexity = O(N)*/
#include <bits/stdc++.h> 
class NStack
{
public:
    // Initialize your data structure.
    
    vector<int>data , next ,top;
    int arraySize  , numberOfStack , emptyIndex = 0;
    NStack(int k, int n)
    {
        arraySize = n ;
        numberOfStack = k;
        for(int i = 0 ; i  < n ; i++) {
            data.push_back(-1);
            next.push_back(i + 1);
        }
        for(int i = 0 ; i < k ; i++) top.push_back(-1);
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(emptyIndex  == arraySize) return false;
        
        data[emptyIndex] = x;
        int temp = emptyIndex;
        emptyIndex = next[emptyIndex];
        next[temp] = top[m - 1];
        top[m - 1] = temp;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        
        int topIndex = top[m - 1];
        if(topIndex == -1) return -1;
        top[m - 1] = next[topIndex];
        next[topIndex] = emptyIndex;
        emptyIndex = topIndex;
        return data[topIndex];
    }
};