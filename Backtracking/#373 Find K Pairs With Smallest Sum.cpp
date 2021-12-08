/************************************Optimal solution to Find K Pairs With Smallest Sum********************************/
/************************************Time Complexity is O( log K) ****************************************************/
/************************************Here we are Stroing k element in Priority Que***************/
/************************************Space Complexity is O( K)*****************************************************/

class Solution {
    private :
    class point{
        public:
        int num1,num2,sum , i , j;
        point(int _num1 , int _num2 , int _i ,int _j) {
            num1 = _num1;
            num2 = _num2;
            sum = num1 + num2;
            i = _i;
            j = _j;
        }  
    };
    class comp{
        public:
        bool operator()(point &p1, point &p2) {
            return p1.sum > p2.sum;      
        }
    };

public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size(), m = nums2.size();
        priority_queue<point , vector<point>,comp>pq;
        vector<vector<int>> ans;
        if(n == 0 || m == 0 )
            return ans;
        for(int i = 0 ; i < n ;i++)
            pq.push ( point( nums1[i] , nums2[0] , i , 0 ) );
    
        for(int i = 0 ; i < k && !pq.empty() ; i++)  {
            
            point temp = pq.top();
            cout<<temp.num1<<" "<<temp.num2<<endl;
            ans.push_back ( {temp.num1, temp.num2});
            pq.pop();
            if(temp.j + 1 == m)
            continue;
            pq.push(point  (temp.num1 , nums2[temp.j + 1] , temp.i , temp.j +1 ) );
            
        }
        return ans;
        
       }
};