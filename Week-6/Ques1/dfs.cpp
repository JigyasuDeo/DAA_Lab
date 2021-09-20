#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool isPathDfs(vector<vector<int>> &v, int s, int d)
{
    vector<int> visited(v.size()+1, 0);
    stack<int> stack;
    stack.push(s);
    visited[s] = true;

    while(!stack.empty())
    {
        int vertex = stack.top();
        stack.pop();

        for(int i = 1; i < v.size(); i++)
        {
            if(v[vertex][i] == 1 && i == d)
            {
                return true;
            }

            if(v[vertex][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                stack.push(i);
            }
        }
    }

    return false;

}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n, s, d;
    cin>>n;
    vector<vector<int>> v(n+1 , vector<int> (n+1));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin>>v[i][j];
        }
    }

    cin>>s>>d;

    if(isPathDfs(v, s, d) == true)
    {
        cout<<"Yes Path Exist";
    }
    else
    {
        cout<<"No Path Does Not Exist";
    }

    return 0;

}