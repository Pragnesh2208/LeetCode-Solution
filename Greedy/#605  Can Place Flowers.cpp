/********************************Optimal approach to usign greedy********/ 
/********************************Time Complexity  = O (N)*****************************/
/********************************Space Complexity  = O (1)******************************/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n = flowerbed.size();
        if(n == 1 && flowerbed[0] == 0) {
            flowerbed[0] = 1;
            k--;
        } 
        if(flowerbed[0] == 0 && n >= 2 && flowerbed[1] == 0) {
            k--;
            flowerbed[0] = 1;
        }
        for(int i = 1 ; i < n - 1 ; i++) {
            if(flowerbed[i] == 0 && flowerbed[i - 1] != 1 && flowerbed[i + 1] != 1)  {
                flowerbed[i] = 1;
                k--;
            }
        }

        if(n > 1 && flowerbed[n - 1] == 0  && flowerbed[n - 2] == 0) {
            k--;
            flowerbed[0] = 1;
        }

        return k <= 0;
    }
};