/*
A group of people plan to go to an island by crossing the river using a boat. 
There are 'M' number of people and 'N' number of boats parked at the boat mooring.
The people and the boats are serially numbered and the weight of each person i is
given as array element a[i] and the maximum capacity a boat can carry is given as array element b[j], 
i=1, 2,..., M-1 and j-1, 2... N-1. It takes one hour to reach from the boat mooring 
to the island and another 1 hour to return from the island to the boat mooring. All 
the people are initially waiting at the boat mooring. The task here is to find 
the minimum amount of time taken for all the people to reach the island.

Note:

• A boat can carry only one person at any Instance of time whose weight 
is less than or equal to the maximum weight that this boat can carry. 
• If the weight of one or more persons is more than the maximum capacity of any boat, display '0'.

Example 1:

Input:

5->Value of M
2-> Value of N 
(8,7,6,8,4)-> a[], Elements a[0] to a[M-1], where each input element is separated by a new line (11,7)> b[],
Elements b[0] to b[N-1], where each input element is separated by a new line 

Output:5

Explanation:

From the inputs given above: Let the boats be b0 and b1. 
Number of persons: 5 
Number of boats: 2 
Maximum weight b0 can carry: 11 
Maximum weight b1 can carry: 7

Hour 1: bo will carry a[0]=8, b1 will carry a[1]=7.

Hour 2 Both the boats will return.

Hour 3: b0 well carry a[2]=6 b1 will carry a[4]=4.

Hour 4: Both the boats will return. 

Hour 5: b0 will carry a[3]=8 as the boat b1's is maximum.

Example 2:

Input:

4-> Value of M

5-> Value of N 
(5,2,8,9) a elements a[0] to a[M-1], where each input element is separated by a new line

(7,5,9,2,4) bl. Elements b[0] to b[N-1], where each input element is separated by a new line.
Output:
3

From the inputs given above:

Let the boats be b0, b1, b2, b3 and b4. Number of persons: 4

Number of boats: 5

Maximum weight b0 can carry: 7

Maximum weight b1 can carry: 5

Maximum weight b2 can carry: 9

Hour 1: b1 will carry a[0]=5. b2 will carry a[3]=9. b3 will carry a[1]=2. 
b4 cannot carry anyone as the other persons are heavier than the capacity of b4. 

Hour 2: All the boats will return. 

Hour 3: b2 will carry a[2]=8.

Maximum weight b3 can carry

Maximum weight b4 can carry: 4

After three hours, all the people will have reached the

Hence, the output is 3.
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m,n;
   cin>>m>>n;
   int a[m],b[n];
   for(int i=0;i<m;i++)
   {
       cin>>a[i];
   }
   for(int i=0;i<n;i++)
   {
       cin>>b[i];
   }
   sort(a,a+m);
   sort(b,b+n);

   if(a[m-1]>b[n-1])
   {
       cout<<"0";
   } 
   else
   {
       int result=0;
       int k=0;
       while(1)
        {
            for(int i=0;i<n;i++)
            {
                if(a[k]!=0 && a[k]<=b[i])
                {
                    a[k++]=0;
                }
                if(k>=m)
                {
                    break;
                }
            }
        int temp = 0;
        for(int i=0;i<m;i++)
        {
            if(a[i]!=0)
            {
               temp=1;
               break;
            }
        }
        result+=2;
        if(temp==0)
        {
            result--;
            break;
        }
        else
        {
            continue; 
        }
        }
    cout<<result<<endl;
   }
    return 0;
}