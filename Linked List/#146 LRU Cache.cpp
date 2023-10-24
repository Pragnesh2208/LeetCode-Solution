/*
OPtimal solution for LRU Cache
Average Time Complexity for get and put is O(1)
Space Complexity = O(N)
*/
class customListNode {
    public:
    int val;
    int key;
    customListNode * next;
    customListNode * prev;
    customListNode(int value , int key) {
        val = value;
        this -> key = key;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUCache {
    int capacity;
    customListNode * head = new customListNode(-1 , -1), * tail = new customListNode(-1 , -1);
    unordered_map<int,customListNode *>bucket;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void insert(int key , int val) {
        customListNode * node = new customListNode(val , key);
        bucket[key] = node;
        node -> next = head -> next;
        head -> next = node;
        node -> next -> prev = node;
        node -> prev = head;
    }

    void deleteNode(customListNode * node){
        customListNode * temp = node -> next;
        temp -> prev = node -> prev;
        node -> prev -> next = temp;
        bucket.erase(node -> key);
        delete(node);
    }
    
    int get(int key) {
       if(bucket.find(key) == bucket.end()) return -1; 
       int val = bucket[key] -> val;
       deleteNode(bucket[key]);
       insert(key , val);
       return bucket[key] -> val;
    }
    
    void put(int key, int val) {
      if(bucket.find(key) != bucket.end()) {
          deleteNode(bucket[key]);
          insert(key , val);
      } else {
          if(bucket.size() == capacity) {
              insert(key , val);
              deleteNode(tail -> prev);
          } else {
              insert(key , val);
          }
      }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */