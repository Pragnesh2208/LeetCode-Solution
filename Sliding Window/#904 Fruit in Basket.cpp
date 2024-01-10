/*Solution Using Naive Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(N)*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        map<int , int>bucket;
        int uniq = 0 , ans = 0;
        for(int i = 0 , j = 0 ; i < n ; i++){
            uniq += ++bucket[fruits[i]] == 1 ? 1 : 0;

            while(uniq > 2) {
                uniq -= --bucket[fruits[j++]] == 0 ? 1 : 0;
            }

            ans = max(ans , i - j  + 1);
        }
        return ans;
    }
};

/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<pair<int,int>>bucket;
        bucket.push_back({-1 , 0});
        bucket.push_back({-1 , 0});

        int ans = 0;
        for(int i = 0 , j = 0 ; i < n ; i++){
            if(bucket[0].first != fruits[i] && bucket[1].first != fruits[i]){
                while(bucket[0].second != 0 && bucket[1].second != 0) {
                    if(fruits[j++] == bucket[0].first) {
                        bucket[0].second--;
                    } else {
                        bucket[1].second--;
                    }
                }

                if(bucket[0].second == 0 ) bucket[0].first = -1;
                else bucket[1].first = -1;
            }
            
            if(bucket[0].first == fruits[i] || bucket[0].first == -1) {
                bucket[0].first = fruits[i];
                bucket[0].second++;
            } else if(bucket[1].first == fruits[i] || bucket[1].first == -1) {
                bucket[1].first = fruits[i];
                bucket[1].second++;
            } 

            ans = max(ans , i - j + 1); 

        }
        return ans;
    }
};