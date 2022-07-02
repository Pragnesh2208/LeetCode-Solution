/***************************Optimal approach to find the All Path from source to target*****************/
/***************************the given graph is DAG so maximum edges will be 2^N**********************/
/***************************Our Time complexity will be O(N+E) but E is 2^N so time complexity is O(2^ N)*******/
/**************************Space Complexity is O(N) As maximum size of tree can be the height of N*************/
class Solution {
    
    private:
    void traversal(int node , vector<vector<int>>& list,vector<int>&temp,vector<vector<int>>&ans ){
        
        temp.push_back(node);
       
       if(node == list.size() - 1){
           ans.push_back(temp);
           return;
       }
        
        for(int child : list[node] ){    
            traversal(child , list ,temp ,ans); 
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<vector<int>>list(n , vector<int>());
        vector<vector<int>> ans;
        vector<int>temp;
        traversal( 0 ,graph ,temp , ans );
        
        return ans;
    }
};