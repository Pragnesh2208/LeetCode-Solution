/********************************Optimal approach to get Permutation Sequence*********/ 
/********************************Time Complexity  = O( N ^ 2 )************************/
/********************************Space Complexity  = O ( N )******************************/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>num;
        string ans;
        int fact = 1;
        for(int i = 1 ; i < n ; i++) {
            fact *= i;
            num.push_back(i);
        }

        num.push_back(n);
        k -= 1;
        while(num.size() > 0 ) {
            ans += to_string(num[k / fact]);
            num.erase(num.begin() + (k / fact));
            k  = k % fact;
            if(num.size() == 0) break;
            fact /= num.size();
        }
        return ans;
    }
};