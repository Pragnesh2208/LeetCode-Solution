/********************************Optimal approach to Solve Bag of tokens********/ 
/********************************Time Complexity  = O (NLogN)*****************************/
/********************************Space Complexity  = O ( 1 )******************************/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin() , tokens.end());
        int maxScore = 0 , score = 0 , i = 0 , j =  n - 1 ;
        while(i <= j) {
            if(power >= tokens[i]) {
                power -= tokens[i];
                score++;
                maxScore = max(maxScore , score);
                i++;
            } else if(score >= 1) {
                power += tokens[j--];
                score--;
            } else return maxScore;
        }

        return maxScore;
    }
};