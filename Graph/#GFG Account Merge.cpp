/*****************************Optimal solution of Account Merge**************************/
/****************************Time Complexity = O(V * E * Log(totalEmail))*******************************************/
/***************************Space Complexity = O(TotalEmail)************************/

class DSU {
  public:
  vector<int>parent , rank;
  DSU(int size) {
      parent.resize(size + 1);
      rank.resize(size + 1 , 1);
      
      for(int i = 0 ; i <= size ; i++) {
          parent[i] = i;
      }
  }
  
  int findParent(int node) {
      if(node == parent[node]) return node;
      return parent[node] = findParent(parent[node]);
  }
  
  int areConnected(int u , int v) {
      u = findParent(u);
      v = findParent(v);
      return u == v;
  }
  
  void unionByRank(int u , int v) {
      if(areConnected(u , v)) return ;
      u = findParent(u);
      v = findParent(v);
      
      if(rank[u] > rank[v]) {
          parent[v] = u;
      }  else if(rank[v] > rank[u]) {
          parent[u] = v;
      } else {
          parent[u] = v;
          rank[v]++;
      }
  }
};

class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        unordered_map<string,int>mp;
        vector<vector<string>>mergeAccount;
        int totalAccount = accounts.size();
        DSU dsu(totalAccount);
        for(int accountIndex = 0 ; accountIndex < totalAccount ; accountIndex++) {
            vector<string>account = accounts[accountIndex];
            
        int totalEmail = account.size();
             for(int ind = 1 ; ind < totalEmail ; ind++ ) {
                string email = account[ind];
                
                if(mp.find(email) == mp.end()) mp[email] = accountIndex;
                else {
                    dsu.unionByRank(accountIndex , mp[email]);
                }
            }
        }
        
        vector<vector<string>>tempMergeAccounts(totalAccount);
        
        for(const pair<string,int>account : mp) {
            string email = account.first;
            int accountIndex = account.second;
            int ultimateParent = dsu.findParent(accountIndex);
            if(tempMergeAccounts[ultimateParent].size() == 0) {
                tempMergeAccounts[ultimateParent].push_back(accounts[ultimateParent][0]);    
            }
             tempMergeAccounts[ultimateParent].push_back(email);
        }
        
        for(vector<string>temp : tempMergeAccounts) {
            if(temp.size() <= 1) continue;
            sort(temp.begin() + 1 , temp.end());
            mergeAccount.push_back(temp);
        }
        
        return mergeAccount;
    }
};