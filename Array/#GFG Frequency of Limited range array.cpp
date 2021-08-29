/******************** Brute force approach To find Frequency in limited range array****************/
/*******************Time complexity = O(N) **************************************************/
/*******************Space complexity = O(N)  ***********************************************/

 class Solution {
     public:
 void frequencyCount(vector<int>& arr,int N, int P)
    { 
      int  count[P]={0};
 
      for(int i=0;i<N;i++)
     { count[arr[i]-1]++;}
        for(int i=0;i<P;i++)
        cout<<count[i]<<" ";
    }
};

/******************** Optimal approach To find Frequency in limited range array****************/
/*******************Time complexity = O(N) **************************************************/
/*******************Space complexity = O(1)  ***********************************************/

 void frequencyCount(vector<int>& arr,int N, int P)
    { 
      for(int i=0;i<N;i++)
      arr[i]-=1;
      sort(arr.begin() , arr.end());
      int index=N;
      for(int i=0 ; i< N;i++)
      {
          if(arr[i]>=N)
          {
              if(index == N)
              index=i;
              arr[i] =0 ;
              
          }
      }
      for(int i=0;i<index;i++)
      arr[arr[i]%N]+=N;
      for(int i=0 ;i<N ;i++)
      arr[i]/=N;
    }