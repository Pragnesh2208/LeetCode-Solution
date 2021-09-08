/**********************Brute approach To replace all 0's with 5's in array**************************/
/**********************Time complexity = O(Length of N)*********************************************/
/**********************Space complexity = O(Length of N)******************************************************/
int convert0To5Rec(int num)
{
	
	if (num == 0)
		return 5;
	int digit = num % 10;
	if (digit == 0)
		digit = 5;

	return convert0To5Rec(num / 10)*10 + digit;
}


/********************* Optimal approach To replace all 0's with 5's in array************************/
/*********************Time complexity = O(Length of N)**********************************************/
/**********************Space complexity = O(1)*****************************************************/
 class Solution {
 public:
    int convertFive(int n)
    {
    if(n==0)
    return 5;
    int j=1;
    int ans=0;
    while(n!=0)
    {
     int a=n%10;
     if(a==0)
     {
         ans+=5*j;
         j*=10;
     }
     else{
         ans+=a*j;
         j*=10;
         
     }
     n=n/10;
    }
return ans;
    }
};

