/************************************Method - 1 using 3 iterations***********************************/
/************************************optimal approach to find Largest Rectangle in Histogram*********/
/************************************Time complexity = O( N)*****************************************/
/************************************Space Complexity = O ( N )**************************************/
class Solution {
public:
    vector<int> rightSmall(vector<int> heights) {

        stack<int>st;
        int n = heights.size();
        vector<int>ans(n);
        for(int  i = n-1 ; i >= 0 ; i--) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n: st.top();
            st.push(i);
        } 
        return ans;
    }
    vector<int> leftSmall(vector<int> heights) {

          stack<int>st;
        int n = heights.size();
        vector<int>ans(n);

        for(int  i = 0 ; i < n ; i++ ) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? 0 : st.top()+1;
            st.push(i);
        }
        return ans;
    }
    
    int calcArea(vector<int>left , vector<int>right , vector<int>heights) {

        int n = left.size();
        int ans = 0;

        for(int i = 0 ; i < n ; i++) {
        
            ans = max(ans , heights[i]*(right[i] - left[i]  ));
            //cout<<heights[i]<<" "<<left[i]<<" "<<right[i]<<" "<<ans<<endl;
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>right = rightSmall(heights);
        vector<int>left = leftSmall(heights);

        int maxArea = calcArea(left,right , heights);

        return maxArea;
    }
};

/************************************Method - 2 using 1 iterations***********************************/
/************************************optimal approach to find Largest Rectangle in Histogram*********/
/************************************Time complexity = O( N)*****************************************/
/************************************Space Complexity = O ( N )**************************************/
class Solution {
public:    
    int largestRectangleArea(vector<int>& height) {
        
       int n = height.size(), area = 0, h, l;
		stack<int> indexes;
		for (int i = 0; i <= n; i++) {
			while (i == n || (!indexes.empty() && height[indexes.top()] > height[i])) {
				if (i == n && indexes.empty()) h = 0, i++;
				else h = height[indexes.top()], indexes.pop();			
				l = indexes.empty() ? -1 : indexes.top();
				area = max(area, h * (i - l - 1));
			}
			indexes.push(i);
		}
		return area;
    }
};