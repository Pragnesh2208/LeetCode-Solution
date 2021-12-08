/**********************************Optimal Approach to find All possible Unique Letter Tiles**********************/
/**********************************Time Complecity = O(Total Number of permutations)**************************/
/*********************************Space Complecity = O(Total Number of permutations)**************************/ 
class Solution {
    private :
    void getPermutation(string &st, int pos , string &tiles , unordered_set<string> &res) {
        
        for(int i = pos ; i < tiles.length() ; i++) {
            
            swap(tiles[i] , tiles[pos]);
            st.push_back(tiles[pos]);
            res.insert(st);
            getPermutation(st,pos+1 , tiles , res);
            st.pop_back();
            swap(tiles[i] , tiles[pos]);
        }
    }
public:
    int numTilePossibilities(string tiles) {
       unordered_set<string>res;
        int n = tiles.length();
       string st;
        getPermutation(st, 0 , tiles  , res);
        return res.size();
    }
};