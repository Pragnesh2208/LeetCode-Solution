/************************Optimal solution to find K Closest points to origin*************************/
/************************Time Complexity = Theta(N) and O(N^2)**************************************************/
/************************Space Complexity = O(1)*************************************************/
/****************************QuickSelect algorithm using lomuto partition*******************/
class Solution {
    private:
   int quickSelect(vector<pair<int , vector<int>>>&nums , int low , int high , int k) {
        int j = low;
        int pivot = high;
        for(int i = low ; i <= high ; i++) {
            if(nums[i].first > nums[pivot].first) 
                swap(nums[i],nums[j++]);
        }

        swap(nums[j],nums[pivot]);
        int count = high - j + 1;
        if(count == k) return j;
        else if(count > k) return quickSelect(nums , j + 1 ,high , k );
        else return quickSelect(nums , low , j - 1 , k - count);
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int , vector<int>>>dist;

        for(int i = 0  ; i < points.size() ; i++) {
            int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            dist.push_back({d,points[i]}); 
        }

        int p =  quickSelect(dist ,0 , points.size() - 1 , k);
        vector<vector<int>>ans;
       
        for(int i = p ; i < dist.size() ;i++)
            ans.push_back(dist[i].second);
        return ans;
    }
};