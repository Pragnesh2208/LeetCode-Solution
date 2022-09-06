#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> prefixTable(string &pat)
{
    int m = pat.length();
    vector<int> table(m, 0);
    for(int i = 1 ; i < m ;i++){
        int j = table[i-1];
        while(j > 0 && table[i] != table[j]) {
            j = table[j-1];
        }
        if(pat[i] == pat[j]) j++;
        table[i] = j;
        
    }
    return table;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // auto start = std::chrono::system_clock::now();
    // Some computation here

    freopen("../input.txt", "r ", stdin);
    freopen("../output.txt", "w", stdout);
    int test;
    cin >> test;
    while (test--)
    {
        string text, pat;
        cin >> text >> pat;
        vector<int> table = prefixTable(pat);
        int i = 0, j = 0;
        bool flag = false;
        
        int m = pat.length() , n = text.length();
       while( i < n) {
        if(pat[j] == text[i]) {
            if(j == m - 1) {
                flag = true;
                cout<<(i - j) + 1 <<" ";
                if(j > 0)
                j = table[j-1];
                else{
                     j = 0;
                     i++;
                }
            } else{
                j++;
                i++;
            }
        } else{
               if(j > 0) {
                    j = table[j-1];
                }
                else{
                    i++;
                }
            }
       }
        if(!flag) cout<<-1;
        cout<<endl;
    }
    // auto end = std::chrono::system_clock::now();

    // std::chrono::duration<double> elapsed_seconds = end - start;
    // cout << endl;
    // cout << elapsed_seconds.count() << " Seconds";
}

