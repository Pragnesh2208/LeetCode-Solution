/*
* Optimal Solution for LFU Cache
* Time Complexity for get and put is O(1)
* Space Complexity = O(N)
*/
class customListNode {
    public:
    int data;
    int key;
    int count;
    customListNode * next , * prev;
    customListNode(int key , int val) {
        this -> key = key;
        data = val;
        count = 0;
        next = nullptr;
        prev = nullptr;
    }
};
class LFUCache {
public:
    int minFreq = 0;
    int maxLimit = 0;
    unordered_map<int , pair<customListNode *, customListNode *>> freqList;
    unordred_map<int , customListNode *> bucketList;

    LFUCache(int capacity) {
        maxLimit = capacity;
    }

    void removeFromList(customListNode * node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        customListNode * head = freqList[node -> count].first , * tail = freqList[node -> count].second;
        if(tail -> prev == head ) {
            delete(head);
            delete(tail);
            freqList.erase(node -> count);
        }
        return;
    }

    void pushFront(customListNode * node) {
        int freq = node -> count + 1;
        customListNode * root ;

        if(freqList.find(freq) != freqList.end()) {
            root = freqList[freq].first;
        } else {
            customListNode * head = new customListNode(-1 , -1);
            customListNode * tail = new customListNode(-1 , -1);
            freqList[freq].first = head;
            head -> next = tail;
            tail -> prev = head;
            freqList[freq].second = tail;
            root = head;
        }
        node -> count = freq;
        node -> next  = root -> next;
        node -> prev = root;
        root -> next = node;
        node -> next -> prev = node;   
    }
    
    int get(int key) {
        if(bucketList.find(key) != bucketList.end()) {
            customListNode * node = bucketList[key];
            removeFromList(node);
            pushFront(node);
            return node -> data;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(bucketList.find(key) != bucketList.end()) {
            customListNode * node = bucketList[key];
            node -> data = value;
            removeFromList(node);
            pushFront(node);
        } else {
            if(bucketList.size() < maxLimit) {
                customListNode * node = new customListNode(key , value);
                pushFront(node);
                bucketList[key] = node;
            } else {
                customListNode * temp = freqList.begin() -> second.second -> prev;
                customListNode * node = new customListNode(key , value);
                bucketList[key] = node;
                removeFromList(temp);
                bucketList.erase(temp -> key);
                delete(temp);
                pushFront(node);
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */