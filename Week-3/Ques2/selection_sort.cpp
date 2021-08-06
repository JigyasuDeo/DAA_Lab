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

    int t;
    cin>>t;

    while(t--)
    {
    	int n, comp=0, swaps=0, idx; 
    	cin>>n;
    	vector<int> v(n);

    	for(int i=0; i<n; i++)
    	{
    		cin>>v[i];
    	}

        for (int i = 0; i < n-1; i++)
        {
            idx = i;

            for (int j = i+1; j < n; j++)
            {
                comp++;
                if(v[j] < v[idx])
                {
                    idx = j;
                }
            }

            swap(v[i], v[idx]);
            swaps++;
        }


        for(auto it : v)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        cout<<"Comparisons = "<<comp<<endl;
        cout<<"Swaps = "<<swaps<<endl;
    }

    return 0;
}