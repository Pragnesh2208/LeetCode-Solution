/*****************************Optimal solution of Step By Knight******************************/
/****************************Time Complexity = O( V + E)**************************************/
/***************************Space Complexity = O(N) as we are using visit**s*******************/

class Solution 
{
    public:

	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    KnightPos[0] -=1;
	    KnightPos[1] -=1;
	    TargetPos[0] -=1;
	    TargetPos[1] -=1;
	   
	      if(TargetPos[0] == KnightPos[0] && TargetPos[1] == KnightPos[1]){
	          return 0;
	      }
	       queue<pair<int,int>>que;
	    int count = 0;
	    que.push({KnightPos[0] , KnightPos[1]});
	    
	     int arrI[] = {-1 ,1 , 1, -1 ,2 , 2 , -2 , -2};
	     int arrJ[] = {-2 ,-2 ,2, 2 , -1 , 1 ,-1 , 1 };
	     vector<vector<bool>>visit(N , vector<bool>(N , false));
	    while(!que.empty()) {
	        int size = que.size();
	        
	         count++;
	        while(size--){
	           
	            int posX = que.front().first;
	            int posY = que.front().second;
	            que.pop();
	            for(int i = 0 ; i < 8 ;i++){
	                   
	                int x = arrI[i] + posX;
	                int y = arrJ[i] + posY;
	              
	                if(x >= 0 && x < N && y >= 0 && y< N && visit[x][y] ==false ) {
	                    que.push({x , y});
	                    visit[x][y] = true;
	                    if(TargetPos[0] == x && TargetPos[1] == y){
	                    return count;
	                    }
	                   
	                }
	            }
	        }
	         
	          
	    }
	    return 0;
	}
};
