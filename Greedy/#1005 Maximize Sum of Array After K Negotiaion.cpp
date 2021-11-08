/*******************************Method - 1 *******************************************************/
/********************************Optimal approach to Maximize Sum of Array After K Negotition*****/
/********************************Time Complexity  = O (  N  )*************************************/
/********************************Space Complexity  = O ( 1 )**************************************/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
      vector<int>st(201,0);
        int total = 0;
        for(auto i : nums) {
            st[i + 100]++;   
        }
        while(k--) {
             int pos = 0;
            while(st[pos] == 0) 
                pos++;
            if(pos < 100) {
            st[pos]--;
            st[200 - pos]++;
            }
            else if(pos > 100)
            {
                st[pos]--;
                st[200 - pos ]++;
                cout<<200 - pos<<" ";
            }
        }
        for(int i = 0 ; i < 100 ; i++ ) {
            while(st[i] > 0 ){
                total += i-100;
                st[i]--;
            }
        }
        for(int i = 101 ; i < 201 ; i++ ) {
            while(st[i] > 0 ) {
                total += i-100;
                st[i]--;
            }
        }
        return total;
    }
};
/*******************************Method - 2 ***********************************************************/
/********************************Optimal approach to Maximize Sum of Array After K Negotition********/
/********************************Time Complexity  = O (  N  )****************************************/
/********************************Space Complexity  = O ( 1 )*****************************************/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
      vector<int>st(201,0);
        int total = 0;
        for(auto i : nums) {
            st[i + 100]++;   
        }
        for(int i = -100 ; i <=100 && k; i++) {
            if(st[i + 100] > 0) {
            auto K = i < 0 ? min (k , st[i + 100]) : k % 2;
             st[i + 100] -= K;
             st[-i + 100] += K;
             k = i < 0 ? k-K :0;   
            }
            
        }
        for(int i = -100 ; i <= 100 ; i++ ) {
            total += i*st[i + 100];
            st[i + 100] = 0;
            
        }
        return total;
    }
};