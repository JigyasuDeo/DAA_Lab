#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void printp(vector<int> path, int i)
{
	if (path[i] == - 1)
	{
		cout<<i+1<<" ";
        return;
	}

    cout<<i+1<<" ";

    printp(path, path[i]);
}

void output(vector<int> dis, vector<int> path, int s)
{
    for (int i = 0; i < dis.size(); i++)
    {
    	printp(path, i);
    	cout<<" : "<<dis[i]<<endl;;
        
    }
}

int mdist(vector<int> dis, vector<bool> inc)
{
	int m = INT_MAX, index;

	for(int i = 0; i < dis.size(); i++)
	{
		if(inc[i] == false && dis[i] <= m)
		{
			m = dis[i];
			index = i;
		}
	}

	return index;
}

void dijkstra(vector<vector<int>> v, int s)
{
	vector<int> dis(v.size(), INT_MAX);
	vector<bool> inc(v.size(), false);
	vector<int> path(v.size());
	path[s] = -1;

	dis[s] = 0;

	for(int i = 0; i < v.size() - 1; i++)
	{
		int p = mdist(dis, inc);

		inc[p] = true;

		for(int j = 0; j < v.size(); j++)
		{
			if(inc[j] == false && v[p][j] > 0 && dis[p] + v[p][j] < dis[j])
			{
				dis[j] = dis[p] + v[p][j];
				path[j] = p;
			}
		}

	}

	output(dis, path, s);
}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n, s;
    cin>>n;
    vector<vector<int>> v(n , vector<int> (n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>v[i][j];
        }
    }

    cin>>s;

    dijkstra(v, s-1);
}