#include<bits/stdc++.h>
using namespace std;

int find(vector<int>p,int i)
{
    if(p[i] < 0)
    {
        return i;
    }
    
    return find(p,p[i]);
}

bool unionbyweight(vector<int> &p, int u, int v)
{
    int pu = find(p,u);
    int pv = find(p,v);
    if(pu != pv)
    {
        if(p[pu] < p[pv])
        {
            p[pu] = p[pu] + p[pv];
            p[pv] = pu;
        }
        else
        {
            p[pv] = p[pv] + p[pu];
            p[pu] = pv;
        }

        return true;
    }
    return false;
}

int krus(vector<vector<int>>&v,int n)
{
    int ans=0;
    vector<pair<int,pair<int,int>>> g;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(v[i][j] != 0)
            {
                g.push_back(make_pair(v[i][j],make_pair(i,j)));
            }
        }  
    }
        
    sort(g.begin(),g.end(), greater<pair<int, pair<int, int>>>());

    vector<int>p(n,-1);

    for(auto i : g)
    {
        int u=i.second.first;
        int v=i.second.second;
        int w=i.first;

        if(unionbyweight(p,u,v))
        {
            ans=ans+w;
        }
    }   

    return ans;
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
    cout<<"Minimum spanning weight : "<<krus(v,n);

    return 0;
}