/************************************Optimal solution to find next greater element******/
/************************************Time complexity = Theta of ( l2  + l1 ) *****************/
/************************************Space Complexity = O ( l2 )************************/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int l2 = nums2.size();
        int l1 = nums1.size();
        unordered_map<int , int>Map;
        vector<int>ans;
        
        for(int i = 0 ; i < l2 ; i++ ) {
            
            while(!st.empty() && nums2[i] > nums2[st.top ()]) {
                nums2[st.top()] = nums2[i];
                st.pop();
            }
            
            st.push(i);
            Map[nums2[i]] = i;
        }
        
        while(!st.empty()) {
            nums2[st.top()] = -1;
            st.pop();
        }
        
        for(int  i = 0 ; i < l1 ;i++) {
            int index = Map[nums1[i]];
            ans.push_back(nums2[index]);
        }
        
        return ans;
    }
};