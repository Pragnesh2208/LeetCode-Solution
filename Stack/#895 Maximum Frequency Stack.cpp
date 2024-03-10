/*
Maximum Frequency Stack Optimal Solution
Time Complexity = O(1)
Space Complexity = O(N)
*/
class FreqStack {
    private:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>elem;
    int maxFreq = 0;
public:
    FreqStack() {}
    
    void push(int val) {
        maxFreq = max(maxFreq , ++freq[val]);
        elem[freq[val]].push(val);
    }
    
    int pop() {

        int x = elem[maxFreq].top();
        elem[maxFreq].pop();
        freq[x]--;
        if(elem[maxFreq].empty()) maxFreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */