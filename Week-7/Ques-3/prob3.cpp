#include<iostream>
#include<vector>

using namespace std;

int kedges(vector<vector<int>> v, int s, int d, int k)
{
	if(k == 0 && s == d)
	{
		return 0;
	}
	if(k == 1 && v[s][d] != 0)
	{
		return v[s][d];
	}
	if(k <= 0)
	{
		return -1;
	}

	int res = INT_MAX;

	for(int i = 0; i < v.size(); i++)
	{
		if(v[s][i] != 0 && s != i && d != i)
		{
			int temp = kedges(v, i, d, k-1);

			if(temp != -1 && temp != INT_MAX)
			{
				res = min(res, v[s][i] + temp);
				
			}
		}

	}

	return res;
}

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
    	int n, s,d,k;
	    cin>>n;
	    vector<vector<int>> v(n , vector<int> (n));

	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < n; j++)
	        {
	            cin>>v[i][j];
	        }
	    }

	    cin>>s>>d>>k;

	    int res = kedges(v, s-1, d-1, k);
	    
	    if(res == INT_MAX)
	    {
	    	cout<<"No Edge Possible";
	    }
	    else
	    {
	    	 cout<<"Weight of Shortest Path from ("<<s<<","<<d<<") with "<<k<<" edges : "<<res;
	    }
	    cout<<endl;
    }

    return 0;
    
}