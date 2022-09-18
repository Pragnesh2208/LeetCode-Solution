class Node {
    Node * links[26];
    bool end = false;
    public:
    bool isContain(char ch){
        return links[ch -'a'] != NULL;
    }
    void put(char ch){
        Node * node = new Node();
        links[ch - 'a'] = node;
    }
    Node * get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        end = true;
    }
    bool isEnd(){
        return end;
    }
};
class Trie{
    private:
    Node * root;
        public:
    Trie(){
        root = new Node();
    }

    int insert(string st){
        Node * node = root;
        int count = 0;
        int n = st.length();
        for(int i = 0 ; i < n ; i++) {
            if(!node -> isContain(st[i])) {
                count++;
                node -> put(st[i]);
            }
            node = node -> get(st[i]);
        }
        node -> setEnd();
        return count;
    }  
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Trie *obj = new Trie();
    int ans = 0;
    int n = s.length();
    for(int i = 0 ; i < n ; i++){
        string temp;
        temp.assign(s.begin() + i , s.end());
        ans += obj->insert(temp);
    }
    return ans + 1;
}