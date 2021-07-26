#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int> v, int key, bool flag)
{
    int n = v.size();
    int l=0, r=n-1, mid, res = -1;

    while(l <= r)
    {
        mid = l + (r-l)/2;

        if(v[mid] == key)
        {
            res = mid;

            if(flag == true)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
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

    return res;    
}

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
    	int n, key, l, r;
    	cin>>n;
    	vector<int> v(n);

    	for(int i=0; i<n; i++)
    	{
    		cin>>v[i];
    	}
        
        cin>>key;

        l = binary_search(v, key, true);

        if(l == -1)
        {
            cout<<"Key Not Present";
        }
        else
        {
            r = binary_search(v, key, false);

            cout<<key<<" - "<<(r-l+1);
        }

        cout<<endl;
    }
    return 0;
}