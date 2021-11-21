#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct time
{
    int id;
    int d;
    int f;
};

bool compare(time t1, time t2)
{
    return (t1.f < t2.f);
}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n, sum=0;
    cin>>n;

    vector<time>t(n);
    vector<int>res;

    for (int i = 0; i < n; i++)
    {
        t[i].id = i+1;
        cin>>t[i].d;
    }

    for (int i = 0; i < n; i++)
    {
        cin>>t[i].f;
    }

    sort(t.begin(), t.end(), compare);

    for(int j = 0; j < n; j++)
    {
    	if(t[j].f >= (sum + t[j].d))
    	{
    		res.push_back(t[j].id);
    		sum = sum + t[j].d;
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