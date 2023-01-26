/***********Reference video link  https://youtu.be/_SgsB1ZhcIQ ******/

/****************Solution to count sorted vowel string using backtracking**********/
/****************Time Complexity = O(5^N)******************************************/
/****************Space Complexity = O(N) recursion space stack*********************/
class Solution {
    int cnt = 0;
    void p(int ind , int &n , string str , string temp) {
        if(temp.length() == n) {
            cnt++;
            return;
        }
       
        for(int i = ind ; i < str.length() ; i++) {
            temp.push_back(str[i]);
            p(i , n , str , temp);
            temp.pop_back();
        }
        return ;
    }
public:
    int countVowelStrings(int n) {
        string str = "aeiou";
        string temp;
        for(int i = 0 ; i < str.length() ;i++) {
            temp.push_back(str[i]);
            p(i , n , str,temp);
            temp.pop_back();
        }
        return cnt;
    }
};

/****************Solution to count sorted vowel string using DP**********/
/****************Time Complexity = O(N)**********************************/
/****************Space Complexity = O(1)*********************************/

class Solution {
public:
    int countVowelStrings(int n) {
        int ans = 0;
        vector<int>combination(5 , 1);
        for(int i = 2 ; i <= n ; i++) {
            for(int j = 3 ; j >= 0 ; j--) {
                combination[j] += combination[j+1];
            }
        }

        for(auto i : combination) ans+=i;
        return ans;
    }
};


/****************Solution to count sorted vowel string using Maths**********/
/****************Time Complexity = O(1)*************************************/
/****************Space Complexity = O(1)************************************/
class Solution {
public:
    int countVowelStrings(int n) {
        return (n+4) *(n+3) *(n+2)*(n+1) / 24;
    }
};