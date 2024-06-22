/********************************Brute force approach to Generator All Permutation*********/ 
/********************************Time Complexity  = O (  C(N*K)* K  )************************/
/********************************Here K to putting temp in ans and N * K for total permutations************/
/********************************Space Complexity  = O ( K )******************************/
class CombinationIterator {
    public :
    int pos = 0;
    vector<string> comb;
    
    void getCombination(int ind , string cha , string temp , int len ) {
        if(temp.size() == len ){
            comb.push_back(temp);
            return;
        }
        for(int i = ind ; i < cha.size() ; i++) {
            temp.push_back(cha[i]);
           
            getCombination(i + 1 , cha , temp , len);
          
            temp.pop_back();
        }
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        string temp ="";
        getCombination( 0 , characters , temp , combinationLength );
    }
    
    string next() {
        string st = comb[pos];
        pos++;
        return st;
    }
    
    bool hasNext() {
        return pos < comb.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

/********************************Optimal approach to Generator All Permutation*********/ 
/********************************Time Complexity  = O ( K  )************************/
/********************************Space Complexity  = O ( K )******************************/
class CombinationIterator {
private:
    vector<int> combination;
    int k;
    string str;
    bool isNext = false;
    
    string getNextPermuation() {
        string nextPermuation;
        isNext = false;
        for (int i = 0; i < k; i++) {
            int index = combination[i];
            nextPermuation.push_back(str[index]);  
        }
        for(int i =  k - 1 ; i >=  0; i--) {
            if(combination[i] + 1 != combination[i + 1]) {
                combination[i] = combination[i] + 1;
                for(int j = i + 1 ; j < k ; j++) {
                    combination[j] = combination[i] + j - i;
                }
                isNext = true;
                break;
            }
        }
        return nextPermuation;
    }

public:
    CombinationIterator(string characters, int combinationLength) {
        k = combinationLength;
        str = characters;
        for (int i = 0; i < k; i++) {
            combination.push_back(i);
        }
        combination.push_back(str.length());
        if(str.length()) {
            isNext = true;
        }
    }

    string next() { return getNextPermuation(); }

    bool hasNext() {
        return isNext;
    }
};