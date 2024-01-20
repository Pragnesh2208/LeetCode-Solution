/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length() , ans = 0 , maxF = 0;
        vector<int>fr(2 , 0);

        for(int i = 0 , j = 0 ; i < n ; i++) {
            maxF = max(maxF , ++fr[answerKey[i]  == 'T']) ;

            while(i - j + 1 - maxF > k) {
                fr[answerKey[j++] == 'T']--;
            }

            ans = max(ans , i - j + 1);
        }

        return ans;
    }
};