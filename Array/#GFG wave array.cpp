/********************Optimal approach To wave array*******************************/
/********************Time complexity = O(N)********************************************************/
/*******************Space complexity = O(1)*******************************************************/
 public:
    void convertToWave(vector<int>& arr, int n){
        
        if(n%2!=0)
        n=n-1;
        for(int i=0;i<n;i=i+2)
        {
            swap(arr[i],arr[i+1]);
        }   
    }
};