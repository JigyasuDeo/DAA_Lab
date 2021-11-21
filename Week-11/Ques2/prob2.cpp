#include<iostream>
#include<vector>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n, sum=0, t1, t2;
    cin>>n;

    vector<int>v(n);

    for (int i = 0; i < n; i++)
    {
    	cin>>v[i];
    }

    cin>>sum;

    vector<vector<int>> dp(sum+1, vector<int> (n, 1));

    for(int i = 1; i < sum+1 ; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i - v[j] >= 0)
            {
                t1 = dp[i - v[j]][j];
            }
            else
            {
                t1 = 0;
            }

            if(j >= 1)
            {
                t2 = dp[i][j-1];
            }
            else
            {
                t2 = 0;
            }

            dp[i][j] = t1 + t2;
        }
    }

    cout<<dp[sum][n-1]<<endl;

    return 0;
}