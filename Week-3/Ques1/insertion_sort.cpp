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
    	int n, comp=0, shifts=0, key; 
        bool flag = false;
    	cin>>n;
    	vector<int> v(n);

    	for(int i=0; i<n; i++)
    	{
    		cin>>v[i];
    	}

        for (int i = 1; i < n; i++)
        {
            int j = i-1;
            key = v[i];

            while(j >=0 && v[j] > key)
            {
                comp++;
                shifts++;
                v[j+1] = v[j];
                j--;
            }

            v[j+1] = key;
            shifts++;
        }

        for(auto it : v)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        cout<<"Comparisons = "<<comp<<endl;
        cout<<"Shifts = "<<shifts<<endl;
    }

    return 0;
}