#include <bits/stdc++.h>
using namespace std;
int main()
{
        long long n, n1;
        string str;
        cin >> n;
        map<int, string, greater<>> roman;
        roman.insert(make_pair(1, "I"));
        roman.insert(make_pair(4, "IV"));
        roman.insert(make_pair(5, "V"));
        roman.insert(make_pair(9, "IX"));
        roman.insert(make_pair(10, "X"));
        roman.insert(make_pair(40, "XL"));
        roman.insert(make_pair(50, "L"));
        roman.insert(make_pair(90, "XC"));
        roman.insert(make_pair(100, "C"));
        roman.insert(make_pair(400, "CD"));
        roman.insert(make_pair(500, "D"));
        roman.insert(make_pair(900, "CM"));
        roman.insert(make_pair(1000, "M"));
        for (auto e = roman.begin(); e != roman.end();)
        {
                if (n >= e->first)
                {
                        str += e->second, n -= e->first;
                        e = roman.begin();
                }
                else
                {
                        e++;
                }
        }
        cout << str;

        return 0;
}