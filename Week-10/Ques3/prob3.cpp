#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n, maximum = -1, ele;
    cin>>n;

    vector<int>v(n);
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        mp[v[i]]++;

        if(mp[v[i]] > maximum)
        {
            maximum = mp[v[i]];
            ele = v[i];
        }
    }

    if(maximum > n/2)
    {
        cout<<"Yes"<<endl;
        cout<<ele;
    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;
}