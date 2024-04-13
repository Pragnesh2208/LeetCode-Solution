/************************************Optimal approach for Tower of Hanoi***********************/ 
/************************************Time Complexity  = O (2 ^ N)******************************/
/************************************Space Complexity  = O (N)*********************************/
class Solution{
    public:
    // You need to complete this function
    void print(int num , int from , int to) {
        cout<<"move disk "<<num<<" from rod "<<from<<" to rod "<<to<<endl;
        return;
    }
    // avoid space at the starting of the string in "move disk....."
    long long toh(int num, int from, int to, int aux ) {
        // Your code here
        if(num == 1 ) {
            print(num , from , to);
            return 1;
        }
        
        long long count = toh(num - 1, from , aux , to);
        print(num , from , to);
        count +=toh(num - 1 , aux , to , from);
        return count + 1;
    }

};