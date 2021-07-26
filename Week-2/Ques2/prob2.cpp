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
    	int n; 
        bool flag = false;
    	cin>>n;
    	vector<int> v(n);

    	for(int i=0; i<n; i++)
    	{
    		cin>>v[i];
    	}

    	for(int i=0; i<n; i++)
    	{
    		for (int j = i+1; j < n; j++)
    		{
    			auto it = find (v.begin()+j+1, v.end(), (v[i]+v[j]));

    			if(it != v.end())
    			{
    				cout<<i+1<<", "<<j+1<<", "<<it-v.begin() + 1;
    				flag = true;
    				break;
    			}

    		}
    	}

    	if(flag == false)
    	{
    		cout<<"No Sequence Found";
    	}
    	cout<<endl;

    }

    return 0;
}