#include<iostream>
#include<vector>

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

void bellman(vector<vector<int>> v, int s)
{
    vector<int> dis(v.size(), INT_MAX);
	vector<int> path(v.size());
	path[s] = -1;
	dis[s] = 0;

    for(int k = 0; k < v.size()-1; k++)
    {
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < v.size(); j++)
            {
                if(v[i][j] > 0 && dis[i] + v[i][j] < dis[j])
                {
                    dis[j] = dis[i] + v[i][j];
                    path[j] = i;
                }
            }
        }
    }

    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v.size(); j++)
        {
            if(v[i][j] > 0 && dis[i] + v[i][j] < dis[j])
            {
                cout<<"!! Negative Cycle Detected !!";
                return;
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

    bellman(v, s-1);

    return 0;
}

