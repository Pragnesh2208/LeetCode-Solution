/****************Optimal Solution to check is Subsequence**********/
/****************Time Complexity = O(l2)*******************/
/****************Space Complexity = O(1)***************************/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l1 = s.length() , l2 = t.length();
        int i = 0 , j = 0;
        while(i != l1 && j != l2) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == l1;
    }
};

/****************Optimal Solution for follow-up question***********/
/****************Time Complexity = O( Length of all S + L2 )*******************/
/****************Space Complexity = O(L2)***************************/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<int , vector<int>> mp;
        int l1 = s.length() , l2 = t.length();
        for(int i = 0 ; i < l2; i++) {
            mp['a' - t[i]].push_back(i);
        }
        int prev= -1;
        for(int i = 0 ; i < l1 ; i++) {
            int l = mp['a' - s[i]].size();
            int low = 0 , high = l - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                int index = mp['a' - s[i]][mid]; 
                if (index > prev) {
                    high = mid - 1; 
                }
                else low = mid + 1;
            }
          
            if(high >= 0 && prev<mp['a' - s[i]][high]){
                prev =  mp['a' - s[i]][high];
              
            }
            
             
            else if(low < l && prev <mp['a' - s[i]][low])
            prev = mp['a' - s[i]][low];
            else return false;
            
            
        }
        return true;
    }
};