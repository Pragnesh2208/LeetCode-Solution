/************************************using Stack and space complexity O(n)*******/
/************************************Time complexity = O (N)******************************/
/************************************Space Complexity = O (N)*****************************/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string temp , ans = "";
        stringstream ss(path);
        while(getline (ss  , temp , '/') ){
            if(temp == "." || temp == "") continue;
            else if(temp == ".." && !st.empty()) st.pop();
            else if(temp != "..") {
                st.push(temp);
            }
        }

        while(!st.empty()) {
            ans  = "/" +  st.top() + ans;
            st.pop();
        }
        
        return ans.size() > 0 ? ans : "/";
    }
};