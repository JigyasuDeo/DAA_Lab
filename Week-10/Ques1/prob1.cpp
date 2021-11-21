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

    int n;
    cin>>n;

    vector<int>s(n), f(n), res;

    for (int i = 0; i < n; i++)
    {
    	cin>>s[i];
    }

    for (int i = 0; i < n; i++)
    {
    	cin>>f[i];
    }

    int i = 0;
    res.push_back(i+1);

    for(int j = 1; j < n; j++)
    {
    	if(s[j] >= f[i])
    	{
    		res.push_back(j+1);
    		i = j;
    	}
    }

    cout<<"No. of non-conflicting activities : "<<res.size()<<endl;

    cout<<"List of selected activities : ";

    for(int j = 0; j < res.size(); j++)
    {
    	cout<<res[j]<<" ";
    }

    return 0;
}