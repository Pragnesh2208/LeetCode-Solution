#include <bits/stdc++.h> 
class Node{
    
    Node * links[26];
    bool End = false;
    public:
    bool isContain(char ch){
        return this->links[ch - 'a'] != NULL;
    }
    void put(char ch){
        Node  *node = new Node();
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        End = true;
    }
    bool isEnd(){
        return End;
    }
};
class Trie{
    Node * root;
     public:
    Trie(){
        root = new Node();
    }
   
    void insert(string str){
        Node * node = root;
        int n = str.length();
        for(int i = 0  ;i < n ; i++) {
            if(!node->isContain(str[i])) {
                node -> put(str[i]);
            }
            node = node -> get(str[i]);
        }
        node -> setEnd();
    }
    bool longestPrefixString(string st){
        Node *node = root;
        int n = st.length();
        bool flag = true;
        if(n == 1) return true;
        for(int i = 0 ; i < n ;i++) {
            if(node->isContain(st[i])) {
                node = node -> get(st[i]);
                flag = flag & node->isEnd();
            }
            else 
                return false;
        }
        return flag;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie *trie = new Trie();
    
    for(int i = 0 ; i < n ; i++ ){
        trie->insert(a[i]);
    }
    
    string ans = "";
    for(int i = 0 ; i < n ; i++ ){
        if(trie ->longestPrefixString(a[i]) ){
            if(ans.length() < a[i].length()) {
                ans=a[i];
            }
            else if(ans.length() == a[i].length() && a[i] < ans) 
                ans = a[i];
        }
    }
 
    return ans == "" ? "None":ans;
}