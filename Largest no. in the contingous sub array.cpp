#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
       deque<int> m;
       vector<int>v;
        m.resize(0);
        for (int i = 0; i <n; i++)
        {
            while(!m.empty() && arr[m.back()]<arr[i])
                m.pop_back();
            m.push_back(i);
            if(i+1>=k)
            {
                while(!m.empty() && m.front()<=i-k)
                    m.pop_front();
                v.push_back(arr[m.front()]);
            }
        }
        return v;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
