#include<iostream>
#include<vector>
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
    	int n, max=1;
    	char alpha; 
    	cin>>n;
    	vector<char> v(n);
    	vector<int> occ(26, 0);

    	for(int i=0; i<n; i++)
    	{
    		cin>>v[i];
    	}

    	for(int i=0; i<n; i++)
    	{
    		occ[v[i]]++;
    		if(occ[v[i]] > max)
    		{
    			max = occ[v[i]];
    			alpha = v[i];
    		}
    	}

    	if(max == 1)
    	{
    		cout<<"No Duplicates Present";
    	}
    	else
    	{
    		cout<<alpha<<" - "<<max;
    	}
    	cout<<endl;
    }

    return 0;
}