/*
Optimal Solution to Implement Min Stack
Time Complexity = O(1)
Space Complexity = O(N)
Note : we tried to use O(1) Space but due to range of int it got failed
*/
class MinStack {
public:
    stack<int>st;
    int minEle = INT_MAX;
    MinStack() {}
    
    void push(int val) {

      if( val <= minEle) {
            st.push(minEle);
            minEle = val;
        }
        st.push(val);
    }
    
    void pop() {
        if(st.top() == minEle) {
            st.pop();
            minEle = st.top();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */