/************************Optimal solution to find Longest Nice Substring*************************/
/************************Time Complexity = O(N)**************************************************/
/************************Space Complexity = O(1)*************************************************/
class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size() <= 1) return "";
        
        int arr[26][2]={};
        int l = s.length();
        for(int i = 0 ; i < l ; i++) 
            arr[tolower(s[i]) - 'a'][isupper(s[i])?1:0]++;
        
        for(int i = 0; i < l ; i++) {
            if(arr[tolower(s[i]) - 'a'][0] > 0 && arr[tolower(s[i]) - 'a'][1] > 0 ) continue;
                string s1 = longestNiceSubstring(s.substr(0 ,i));
                string s2 = longestNiceSubstring(s.substr(i+1));
                return s1.size() >= s2.size() ? s1 : s2;
        }
        return s;   
    }
};