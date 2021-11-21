#include<iostream>
#include<vector>

using namespace std;

int matrixchain(vector<int> v, int n)
{
    vector<vector<int>>dp(n, vector<int>(n));
 
    int j, k, q;
 
    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }
 
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = dp[i][k] + dp[k + 1][j] + v[i - 1] * v[k] * v[j];
                if (q < dp[i][j])
                {
                    dp[i][j] = q;
                }
            }
        }
    }
 
    return dp[1][n - 1];
}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n, k=0, temp;
    cin>>n;

    vector<int> v(n+1);

    for(int i = 0; i <= n*2; i++)
    {
    	cin>>temp;
    	if(i == 0)
    	{
    		v[k++] = temp;
    	}
    	else if(v[k-1] != temp)
    	{
    		v[k++] = temp;
    	}
    }

    cout<<matrixchain(v, n+1);

    return 0;
}

