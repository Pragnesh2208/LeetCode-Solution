/************************Optimal solution to find Beautiful Array*************************/
/************************Time Complexity = O(NLogN)**************************************************/
/************************Space Complexity = O(N)*************************************************/
/****************************Refer video of Happy coding and solution of lee215*********************************/
class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int>res={1};
        while(res.size() < n) {
            vector<int>temp;
            for(int i = 0 ; i < res.size() ; i++) 
                if(res[i]*2-1 <= n) 
                    temp.push_back(res[i]*2 - 1); 

            for(int i = 0 ; i < res.size() ; i++) 
                 if(res[i]*2 <= n) 
                    temp.push_back(res[i]*2);
                
            res = temp;
        }
        return res;
    }
};