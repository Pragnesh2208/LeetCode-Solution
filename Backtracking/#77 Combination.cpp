/********************************Optimal approach to Print all Permutation*********/ 
/********************************Time Complexity  = O (  C(N*K)* K  )************************/
/********************************Here K to putting temp in ans and N * K for total permutations************/
/********************************Space Complexity  = O ( K )******************************/

class Solution {
public:
    void getCombination(int k ,int ind, int n , vector<int> &temp , vector<vector<int>> & arr ) {

        if(temp.size() == k)
        {
            arr.push_back(temp);
            return;
        }
        
        for(int i = ind  ; i <= n ; i++ ) {
            temp.push_back(i);
            getCombination( k ,i + 1,n , temp , arr );
            temp.pop_back();
        }              
    }

    vector<vector<int>> combine(int n, int k) {
            vector<vector<int>>ans;
            vector<int>temp;
            getCombination(k , 1 , n , temp , ans);
            return ans;
    }
};