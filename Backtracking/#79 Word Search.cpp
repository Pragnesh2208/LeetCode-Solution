/********************************Optimal approach to Word Search *************************************************/ 
/********************************Time Complexity  = O (  4 ^ (N * M )  )************************/
/********************************Here at every cel we can go to 4 direction************************/
/********************************Space Complexity  = O ( N * M)******************************/
/********************************The max Size of Word can be count of all cell which is (M * N )***********************/ 
class Solution {
private:
    bool dfs(int i , int j , string &str ,vector<vector<char>>& board ) {
        if(!str.size())
            return true;
        if(i < 0 || j < 0 || i >=board.size() || j >=board[0].size() || board[i][j] != str[0])
            return false;
        char  c= board[i][j];
        board[i][j] = '*';
        string newstr = str.substr(1);
        bool res = false;
       
        int nexti[] = { 1 , - 1 , 0 , 0};
        int nextj[] = { 0 , 0 , 1 , -1};
        
        for(int itr = 0 ; itr < 4 ; itr++) {
             if(dfs(i + nexti[itr] , j + nextj[itr], newstr, board)) { 
                 res = true;
                 break;
             }    
        }
        board[i][j] = c;
        return res;
        
    }
  
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        bool res = 0;
        for(int i = 0 ; i < rows ; i++ ) {
            for(int j = 0 ; j < cols ; j ++) {
                if( dfs(i , j , word , board))
                    res = true;
                if(res)
                    break;
                
            }
        }
        return res;
    }
};