#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
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
    	int n, m; 
        bool flag = false;
    	cin>>m;
    	vector<int> arr1(m);

    	for(int i=0; i<m; i++)
    	{
    		cin>>arr1[i];
    	}

        cin>>n;
        vector<int> arr2(n);

        for(int i=0; i<n; i++)
        {
            cin>>arr2[i];
        }

        int i=0, j=0;

        while(i < m && j < n)
        {
            if(arr1[i] == arr2[j])
            {
                cout<<arr1[i]<<" ";
                i++, j++;
            }
            else if(arr1[i] < arr2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        cout<<endl;
    }

    return 0;
}