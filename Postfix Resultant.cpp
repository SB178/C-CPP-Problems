/*

Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression, 
we have -4 as result.

*/

#include <bits/stdc++.h>
using namespace std;


 
class Solution
{
    public:
    
    int evaluatePostfix(string S)
    {
        
        
        stack<int>stack;
        int t;
        for(auto r:S)
        {
            if(isdigit(r))
            {
                stack.push((int)(r-'0'));
            }
            else if(r=='*' || r=='/' || r=='+' || r=='-')
            {
                switch(r)
                {
                case '+':
                {
                 t=stack.top();
                 stack.pop();
                 stack.top()=t+stack.top();
                 break;   
                }
                case '-':
                {
                 t=stack.top();
                 stack.pop();
                 stack.top()=stack.top()-t;
                 break;   
                }
                case '*':
                {
                 t=stack.top();
                 stack.pop();
                 stack.top()=t*stack.top();   
                 break;
                }
                case '/':
                {
                 t=stack.top();
                 stack.pop();
                 stack.top()=stack.top()/t;
                 break;   
                }
                };
            }
        }
        return(stack.top());
    }
};


int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}