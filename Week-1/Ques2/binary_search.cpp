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
    	int n, key, comp = 0;
    	bool flag = false;
    	cin>>n;
    	vector<int> v(n);

    	for(int i=0; i<n; i++)
    	{
    		cin>>v[i];
    	}
        
        cin>>key;
        int l=0, r=n-1, mid;

    	while(l <= r)
    	{
    		mid = l + (r-l)/2;

    		comp++;

    		if(v[mid] == key)
    		{
    			flag = true;
    			break;
    		}
    		else if(v[mid] > key)
    		{
    			r = mid-1;
    		}
    		else if(v[mid] < key)
    		{
    			l = mid+1;
    		}
    	}

    	(flag == true) ? (cout<<"Key is Present in Array"<<endl ) : (cout<<"Key is Not Present in an Array"<<endl );

    	cout<<"No. of Comparison = "<<comp<<endl;
    }
    return 0;
}