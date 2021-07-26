#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;

    while(t--)
    {
    	int n, key, count=0; 
        bool flag = false;
    	cin>>n;
    	vector<int> v(n);

    	for(int i=0; i<n; i++)
    	{
    		cin>>v[i];
    	}

        cin>>key;

        for (int i = 0; i < n; i++)
        {
            auto it = find (v.begin(), v.end(), (v[i]+key));

            if((it != v.end()) && (it-v.begin() != i))
            {
                count++;
            }
        }

        cout<<count<<endl;

    }

    return 0;
}