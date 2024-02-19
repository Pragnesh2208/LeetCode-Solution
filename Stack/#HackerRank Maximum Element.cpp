/************************************Better Approach to implement stack with getMax function*****/
/************************************Time complexity = O( 1 ) ************************************/
/************************************Space Complexity = O ( N )**********************************/

struct maxElementStack {
    int ele , maxEle;
};

vector<int> getMax(vector<string> operations) {
    int n = operations.size();
    stack<maxElementStack>st;
    vector<int>ans;
    for(int i = 0 ; i < n ; i++) {
        int operation = (operations[i][0] - '0');
        
        switch (operation) {
            case 1: {
                int number = stoi(operations[i].substr(2));
                if(st.empty()) {
                    st.push({number , number});
                } else {
                    int maxE = st.top().maxEle;
                    if(number > maxE) {
                        st.push({number , number});
                    } else {
                        st.push({number , maxE});
                    }
                }
                break;
            }
            case 2: {
                st.pop();
                break;
            }
            
            case 3: {
              ans.push_back(st.top().maxEle);
            }
        }
    }
    return ans;
}

/************************************Better Approach to implement stack with getMax function*****/
/************************************Time complexity = O( 1 ) ************************************/
/************************************Space Complexity = O ( 1 )**********************************/

vector<int> getMax(vector<string> operations) {
    int n = operations.size();
    stack<int>st;
    vector<int> ans;
    int maxEle = -1;

    for(int i = 0 ; i < n ; i++) {
        int operation = (operations[i][0] - '0');
        switch (operation) {
            case 1: {
                int number =  stoi(operations[i].substr(2));
                if(st.empty()) {
                    maxEle = number;
                    st.push(number);
                } else {
                    if(number > maxEle) {
                        st.push(2 * number - maxEle);
                        maxEle = number;
                    } else {
                        st.push(number);
                    }
                }
                break;
            }
            
            case 2: {
                int number = st.top();
                if(number > maxEle) {
                    maxEle = 2 * maxEle - number;
                }
                st.pop();
                break;
            }
            
            case 3: {
                ans.push_back(maxEle);
                break;
            }  
        }    
}
return ans;
}