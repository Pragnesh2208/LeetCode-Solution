#include <bits/stdc++.h>
using namespace std;\

class Trie
{
    private:
    Trie *link[26] = {NULL};
    bool End = false;

public:
    bool contains(char ch)
    {
        return this->link[ch - 'a'] != NULL;
    }

    void put(char ch, Trie *node)
    {
        this->link[ch - 'a'] = node;
    }

    Trie *get(char ch)
    {   
        return this->link[ch - 'a'];
    }
    bool isEnd()
    {
        return this->End;
    }

    void setEnd()
    {
        this->End = true;
    }
};

void insert(string &word, Trie *node)
{
    for (int i = 0; i < word.length(); i++)
    {   
        if (!node->contains(word[i]))
        {
            node->put(word[i], new Trie());
        }
        node = node->get(word[i]);
    }
    node->setEnd();
}

bool search(string word, Trie *node)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (!node->contains(word[i]))
        {
            return false;
        }
        else
        
        {  
            node = node->get(word[i]);
        }
    }
    return node -> isEnd();
}

int main()
{

    freopen("../input.txt", "r ", stdin);
    freopen("../Toutput.txt", "w", stdout);
    Trie root;
    Trie * node = &root;
    Trie temp = root;
    string word;
    cin >> word;
    insert(word, node);
    cin>>word;
    insert(word, node);

    string str1;
    cin >> str1;
    cout << search(str1, node);
}