#include<bits/stdc++.h>
using namespace std;

int prim(vector<vector<int>>&v, int n)
{
    vector<bool>visited(n,false);
    vector<int>weight(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int, int>>>pq;

    int s=0, sum=0;;
    weight[s]=0;

    pq.push(make_pair(weight[s],s));

    while(pq.empty() == false)
    {
        int i = pq.top().second;
        pq.pop();

        if(visited[i] == false)
        {
            visited[i]=true;
            for(int j = 0;j < n; j++)
            {
                if(visited[j] == false && v[i][j] != 0 && v[i][j] < weight[j])
                {
                    weight[j]=v[i][j];
                    pq.push(make_pair(weight[j],j));
                }
            }
        }
    }

    for(auto i: weight)
    {
        sum = sum + i;
    }

    return sum;
}

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

    vector<vector<int>>v(n, vector<int>(n));

    for(int i = 0;i < n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j]; 
        }
    }
    cout<<"Minimum spanning weight : "<<prim(v,n);

    return 0;
}