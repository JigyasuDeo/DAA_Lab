#include<bits/stdc++.h>
#define INF INT_MAX
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

    vector<vector<int>> v(n, vector<int>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
            if(i != j && v[i][j] == 0)
            {
                v[i][j]=INF;
            }
        }
    }
    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (v[i][j] > (v[i][k] + v[k][j]) && (v[k][j] != INF && v[i][k] != INF))
                {
                    v[i][j] = v[i][k] + v[k][j];
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]==INF)
            {
                cout<<"INF ";
            }
            else
            {
                cout<<v[i][j]<<" ";
            }
        }

        cout<<endl;
    }

    return 0;  
}