//https://codeforces.com/contest/808/problem/A

#include<bits/stdc++.h>
using namespace std;
int main(){
        long long n,n1;
        int total=0;
        cin>>n;
        n1=n;
        while(n1) n1 = n1 / 10,++total;
        long long next=1;
        for(int e=1;e<=total-1;e++) next*=10;
        n1 = n;
        for (int e = 1; e <= total; e++) e==total ? n1 %= 10 : n1 /=10;
        ++n1,n1*=next;
        cout<<n1-n;
        return 0;
}