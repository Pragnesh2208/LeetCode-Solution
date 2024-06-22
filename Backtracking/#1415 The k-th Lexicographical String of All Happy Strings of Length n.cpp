/********************************************Method - 1 *********************************************************/
//******************************************Approach :************************************************************/
/*************************We are generating all permutation and returing kth string****************************************/
/************************Brute Force Approach to get The k-th Lexicographical String of All Happy Strings of Length n******/
/************************Time Complexity = O( 3 * 2 ^ (n - 1 ))Here n = length of sttring we want*******************************************/
/***********************Space Complexity = O (n)********************************************************************************/

class Solution {
    private : 
    void getCombination( string &temp , string &st , int n , vector<string> &res) {
        if(temp.size() == n) {
            res.push_back(temp);
            return;
        }
        for(int i = 0 ; i < 3 ; i++) {
            if(temp.size() > 0 && st[i] ==temp[temp.size() - 1 ] ) 
                continue;
            temp.push_back(st[i]);
            getCombination(temp , st , n , res);
            temp.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string>res;
        string st = "abc";
        string temp = "";
        getCombination( temp , st , n , res);
        for(auto x : res)
            cout<<x<<endl;
        if(k <= res.size())
        return res[k-1];
        else 
            return "";
    }
};

/********************************************Method - 2 *********************************************************/
//******************************************Approach :************************************************************/
/*************************We are generating kth permutation and returing it****************************************/
/************************Optimal Approach to get The k-th Lexicographical String of All Happy Strings of Length n******/
/************************Time Complexity = O( n )Here n = length of sttring we want*******************************************/
/***********************Space Complexity = O (n)********************************************************************************/
class Solution {
public:
    string getHappyString(int n, int k) {
        string ans = "";
        int totalPermutation = n - 1 == 0 ? 3 : (1 << (n - 1) ) * 3 ;
        int permutationSetSize = totalPermutation / 3;
        cout<<totalPermutation<<endl;
        if(totalPermutation >= k) {
            k--;
            int mod = (k) / permutationSetSize;
            ans += 'a' + mod;
            k = k % permutationSetSize;
            permutationSetSize >>= 1;

            while(permutationSetSize) {
                int mod = (k ) / permutationSetSize;
                k = k % permutationSetSize;
                permutationSetSize >>= 1;
                ans += mod == 0 ? 'a'  +( ans.back() == 'a' ): 'b' + (ans.back() != 'c');
            }
        } 
        
        return ans;
    }
};
