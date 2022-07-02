/*****************************Optimal solution of Find The Town Judge****************************************/
/****************************Time Complexity = O( V + E)******************************************************/
/***************************Space Complexity = O(N) as we are using  array*******************************/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int>c1(n+1 ,0);
        
       for(int i = 0; i < trust.size() ;i++){
           
          int parent = trust[i][0];
          int child = trust[i][1];
           c1[parent]--;
           c1[child]++;
       }
        
       for(int i = 1 ; i <=n ;i++){
           if(c1[i] == n-1)
               return i;
       }
        return -1;
    }
};