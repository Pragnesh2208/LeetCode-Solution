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

/************************************Optimal solution to find next greater element******/
/************************************Time complexity = Theta of ( l2  + l1 ) *****************/
/************************************Space Complexity = O ( l2 )************************/
/*Using Array*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        stack<int>st;
        vector<int>ans(n , -1);
        vector<int>mp(10001 , 0);

        for(int i = m - 1 ; i >=0 ; i--){
            while( st.size() > 0 && st.top() < nums2[i]) {
                st.pop();
            }
            if(st.size() == 0 ) mp[nums2[i]] = -1;
            else
            mp[nums2[i]] = st.top();
            
            st.push(nums2[i]);
        }

        for(int i = 0 ; i < n ; i++) {
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};