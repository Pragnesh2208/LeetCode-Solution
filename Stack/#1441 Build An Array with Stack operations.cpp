/************************************Optimal approach to Build An Array With Stack Operations*************/
/************************************Time complexity = O( N)**********************************************/
/************************************Space Complexity = O ( 1 )*******************************************/
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string> res;
        int num = 1;

        for(int i=0; i<target.size(); i++) {

            while(num!=target[i]) {

                num++;
                res.push_back("Push");
                res.push_back("Pop");

            }

            res.push_back("Push");
            num++;
        }
        return res;
        
    }
};