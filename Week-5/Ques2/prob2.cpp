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
    	int n, key; 
        bool flag = false;
    	cin>>n;
    	vector<int> v(n);

    	for(int i=0; i<n; i++)
    	{
    		cin>>v[i];
    	}

        cin>>key;

        sort(v.begin(), v.end());

        int l=0, r=n-1;

        while(l < r)
        {
            if(v[l] + v[r] == key)
            {
                flag = true;
                cout<<"("<<v[l]<<" "<<v[r]<<")"<<" ";
                l++, r--;
            }
            else if(v[l] + v[r] < key)
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        if(flag == false)
        {
            cout<<"No Such pair Exist";
        }
        cout<<endl;
    }

    return 0;
}