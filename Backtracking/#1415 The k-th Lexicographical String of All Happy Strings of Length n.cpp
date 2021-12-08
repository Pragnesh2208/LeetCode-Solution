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
       int perm =  1 <<( n - 1);
        if( k > 3 * perm)
            return "";
        k--;
        char ch = 'a' + int (k / perm) ;
        string s = to_string(ch);
        while(perm  > 1) {
            k = k % perm;
            perm >>= 1;
            s += k / perm == 0 ? 'a' + (s.back() == 'a') : 'b' + (s.back() == 'b');
        }
        return s;
    }
};
