/*
Optimal Approach to Solve using Heap
Time Complexity = O(NLogN)
Space Complexity = O(N)
*/

class MedianFinder {
    private:
    priority_queue<int>maxHeap;
    priority_queue<int , vector<int>,  greater<int>> minHeap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if( maxHeap.empty() || num < maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        double minHeapSize = minHeap.size() , maxHeapSize = maxHeap.size();
        if(((minHeapSize - maxHeapSize) > 1) || ((maxHeapSize - minHeapSize) > 1)){
                if(minHeap.size()> maxHeap.size() ) {
                    int tempEle = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(tempEle);
                }
                else if(double(maxHeap.size()) + 2 > minHeap.size()) {
                    int tempEle = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(tempEle);
                }
        }
    }
    
    double findMedian() {
        double median = -1;
        if((maxHeap.size() + minHeap.size()) % 2) {
            if(minHeap.size() > maxHeap.size()) median = minHeap.top();
            else median =  maxHeap.top();            
        } else {
            double temp1 = maxHeap.top() , temp2 = minHeap.top();
            median = (temp1 + temp2) / 2;
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */