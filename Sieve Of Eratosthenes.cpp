#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	cin>>n;
	int ar[n+1]={0};
	for(int i=2;i*i<=n;i++)
	{
		for(int j=i*i;j<=n;j+=i)
		{
			ar[j]=1;
		}
	}
	for(int i=2;i<n;i++)
	{
		if(ar[i]==0)
		{
			cout<<i<<" ";
		}
	}

	return 0;

} 