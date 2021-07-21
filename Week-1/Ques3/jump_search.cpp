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
        int l, r;

        for (r = 0; v[r] <= key; r=r*2)
        {
            comp++;
            l = r;
            if(v[r] == key)
            {
                flag = true;
                break;
            }
            if(r*2 >= n)
            {
                r = n-1;
                break;
            }
            if(r == 0)
            {
                r = 1;
            }
        }

        if(flag == false)
        {
            for(int i=l+1; i <= r; i++)
            {
                comp++;
                if(v[i] == key)
                {
                    flag = true;
                    break;
                }
            }
        }
        
        (flag == true) ? (cout<<"Key is Present in Array"<<endl ) : (cout<<"Key is Not Present in an Array"<<endl );

        cout<<"No. of Comparison = "<<comp<<endl;
    }
    return 0;
}