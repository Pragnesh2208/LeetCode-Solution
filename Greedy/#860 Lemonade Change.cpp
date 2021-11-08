/********************************Optimal approach to Solve Lemonade Change Problem********/ 
/********************************Time Complexity  = O (  N  )*****************************/
/********************************Space Complexity  = O ( 1 )******************************/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ten = 0 , five = 0 , pos = 0;
        bool flag = true;
        for(auto i : bills) {
        if (i == 5 ) five++;
        else if( i == 10 && five > 0) {
            five--;
            ten++;
        }
        else if( i == 20) {
            if(five > 0 && ten > 0){
                five--;
                ten--;
            }
            else if(five >= 3 )
                five -= 3;
            else 
                flag = false;
        }
            else {
                flag = false;
            }
            if (flag == false) {
                break;
            }
        }
        return flag;
    }
};