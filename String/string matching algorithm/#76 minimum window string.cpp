/**********************************Optimal solution to find minimum window string**************/
/**********************************Time Complexity is O(N+M)***********************************/
/**********************************Space Complexity is O(N+M)**********************************/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char , int>shouldFind , hasToFind;
        for(int i = 0 ; i < t.length() ; i++) shouldFind[t[i]]++;
        int count=0;
        int start = -1 , end = -1;
        int j = 0 , maxLength = INT_MAX;
        string str = "";
        for(int i = 0 ; i < s.length() ; i++) {
            if(!shouldFind[s[i]]) continue;

            else {
                if(shouldFind[s[i]] > hasToFind[s[i]]) 
                    count++;
                hasToFind[s[i]]++;

                if(count == t.length() ) {

                    while(count == t.length()) {
                         if(shouldFind[s[j]]) {
                             if(shouldFind[s[j]] == hasToFind[s[j]]) count--; 
                             hasToFind[s[j]]--;
                         }
                      j++;  
                    }
                      
                    if( i - j - 1 < maxLength) {
                    
                     start = j - 1;
                    end = i;
                    maxLength = i - j - 1;
                 
                    }
                }  
            }
        }

        if(start != -1)  
        while(start <= end ) {
                        str.push_back(s[start]);
                        start++;
                        }
        return str;
    }
};