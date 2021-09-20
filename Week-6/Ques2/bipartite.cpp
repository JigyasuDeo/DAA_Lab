#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool isbipartite(vector<vector<int>> &v, int s)
{
    vector<int> color(v.size()+1, 0);
    queue<int> q;
    int curr = 1;
    q.push(s);
    color[s] = curr;

    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();

        if(v[vertex][vertex] == 1)
        {
            return false;
        }

        curr = curr * -1;

        for(int i = 1; i < v.size(); i++)
        {
            if(v[vertex][i] == 1 && color[i] == 0)
            {
                color[i] = curr;
                q.push(i);
            }

            else if(v[vertex][i] == 1 && color[vertex] == color[i])
            {
                return false;
            }
        }
    }

    return true;

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
        int n, s;
        cin>>n;
        vector<vector<int>> v(n+1 , vector<int> (n+1));

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin>>v[i][j];
            }
        }

        if(isbipartite(v, 1) == true)
        {
            cout<<"Yes It is Bipartite";
        }
        else
        {
            cout<<"No It is Not Bipartite";
        }

        cout<<endl;
    }

    return 0;

}