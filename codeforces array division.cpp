//https://codeforces.com/contest/808/problem/D

#include<bits/stdc++.h>
using namespace std;
int main(){
        long long n,s=0,stot=0;
        cin>>n;
        vector<int>vec(n+5,0);
        unordered_map<long long,int> all,counter;
        for (int e = 0; e < n; e++)
        {
                cin>>vec[e];
                stot=stot+vec[e];
        }
        for(int e=1;e<n;e++)
        {
                all[vec[e]]++;
        }
        if(stot & 1)
        {
                cout << "NO\n";
                return 0;
        }
        counter[vec[0]]=1;
        for (int e = 0; e < n; e++)
        {
                s+=vec[e];
                if(s==stot/2)
                {
                        cout << "YES\n";
                        return 0;
                }        
                if(s < stot/2)
                {
                        long long x= stot/2-s;
                        if(all[x] > 0)
                        {
                                cout << "YES\n";
                                return 0;
                        }
                
                }
                else
                {
                        long long y=s-stot/2;
                        if(counter[y] > 0)
                        {
                                cout << "YES\n";
                                return 0;
                        }
                }
                all[vec[e+1]]--;
                counter[vec[e+1]]++;
        }
        cout<<"NO\n";
        return 0;
}