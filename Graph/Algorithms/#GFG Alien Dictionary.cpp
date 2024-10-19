/**
 * Optimal Solution For Alien Dictionary
 * Time Complexity = O(N * M)
 * Space Complexity = O(K)
 */

class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        // code here
        vector<bool>added(k , false);
        vector<vector<int>>graph(k);
        for(int ind = 0 ; ind < n - 1; ind++) {
            string word1 = dict[ind];
            string word2 = dict[ind + 1];
            int minLen = min(word1.length() , word2.length()) - 1;
            int ind2 = 0 ;
            while( ind2 < minLen && word1[ind2] == word2[ind2]) {
                ind2++;
            }
            int parentNode = word1[ind2] - 'a';
            int childNode = word2[ind2] - 'a';
            graph[parentNode].push_back(childNode);
        }
        
        vector<int>indegree(k , 0);
        
        for(int node = 0 ; node < k ; node++) {
            for(int childNode : graph[node]){
                indegree[childNode]++;
            }
        }
        
        queue<int>que;
        
        for(int node = 0; node < k ;node++){
            
            if(indegree[node] == 0) que.push(node);
        }
            
        string ans;
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            char ch = 'a' + node;
            ans.push_back(ch);
            added[node] = true;
            for(int childNode : graph[node]) {
                indegree[childNode]--;
                if(indegree[childNode] == 0) que.push(childNode);
            }
        }
        
        
        
        for(int node = 0 ; node < k ; node++) {
            if(!added[node]) {
                ans.push_back('a' + node);
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}