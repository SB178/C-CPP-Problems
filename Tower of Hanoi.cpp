#include<bits/stdc++.h>

using namespace std;

void H(int n,char from,char to,char aux)
{
	if(n==1)
	{
		cout<<n<<"-"<<from<<"-"<<to<<"\n";
		return;
	}
	else
	{
		H(n-1,from,aux,to);
		cout<<n<<"-"<<from<<"-"<<to<<"\n";
		H(n-1,aux,to,from);
	}
}

int main()
{
	H(4,'F','T','A');
	return 0;

} 