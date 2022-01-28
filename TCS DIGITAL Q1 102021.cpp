/*
Given two arrays arr1[] and arr2[] of size N, the task is to count the minimum number 
of swaps of same-indexed elements from both the arrays arr1[] and arr2[] required to 
make the sum of all elements of both the arrays even. If it is not possible, then print “-1”.

Examples:
nput: arr1[] = {1, 4, 2, 3}, arr2[] = {2, 3, 4, 1}
Output: 0
Explanation: Sum of all elements of arr1[] and arr2[] is 10 and 10 respectively, which is 
already even. Therefore, the count of operations required is 0.

Input: arr1[] = {11, 14, 20, 2}, arr2[] = {5, 9, 6, 3}
Output: 1
Explanation: Sum of all elements of arr1[] and arr2[] is 37 and 23 respectively. Swapping 
arr1[1]( = 14) and arr2[1]( = 9) makes the sum of arr1[] and arr2[], 32 and 28 respectively. 
Therefore, the count of operations required is 1.

*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m,n;
   cin>>m>>n;
   int a[m],b[n];
   int sum1=0,sum2=0;
   for(int i=0;i<m;i++)
   {
       cin>>a[i];
       sum1+=a[i];
   }
   for(int i=0;i<n;i++)
   {
       cin>>b[i];
       sum2+=b[i];
   }
   if(!(sum1&1) && !(sum2&1))
   {
       cout<<"0";
       exit(0);
   }
   if((sum1&1) && !(sum2&1) || !(sum1&1) && (sum2&1))
   {
       cout<<"-1";
       exit(0);
   }
   else
    {
        if(m<=1 || n<=1)
        {
            cout<<"-1";
            exit(0);
        }
       cout<<"1";
    }

    return 0;
}