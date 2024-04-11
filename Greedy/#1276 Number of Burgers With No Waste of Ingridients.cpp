/********************************Brute Force approach using greedy********/ 
/********************************Time Complexity  = O (N) ****************/
/********************************Space Complexity  = O (1) ***************/
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(2 * cheeseSlices > tomatoSlices || tomatoSlices % 2 == 1 || 4 * cheeseSlices < tomatoSlices) return {};

        vector<int>res(2,0);
        while(cheeseSlices !=0 && tomatoSlices != 0) {
            if(2 * cheeseSlices < tomatoSlices) {
                res[0]++;
                tomatoSlices -= 4;

            } else {
                tomatoSlices -= 2;
                res[1] += cheeseSlices;
                break;
            }
            cheeseSlices--;
        }
        return res;
    }
};

/********************************Optimal Force approach using Maths*******/ 
/********************************Time Complexity  = O (1) ****************/
/********************************Space Complexity  = O (1) ***************/
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(2 * cheeseSlices > tomatoSlices || tomatoSlices % 2 == 1 || 4 * cheeseSlices < tomatoSlices) return {};
        int b = (4 * cheeseSlices - tomatoSlices) / 2;
        int a = cheeseSlices - b;

        return {a , b};
    }
};