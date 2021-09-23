#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
    cin>>n; 
    int ar[n],min=0,max=0,k=0;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        if(min>ar[i]) min=ar[i];
        if(max<ar[i]) max=ar[i];
    }
    int br[max]={0};
    for(int i=0;i<n;i++)
    {
        br[ar[i]-1]++;
    }
    for(int i=0;i<max;i++)
    {
        if(br[i]==1) cout<<i+1;
    }
    return 0;
}  