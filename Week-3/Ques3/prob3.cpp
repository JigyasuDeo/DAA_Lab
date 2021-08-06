#include<iostream>
#include <cstdlib>
#include<ctime>
#include<vector>
using namespace std;

int partition(vector<int>& v, int l, int h)
{
    srand(time(NULL));
    int random = l + rand() % (h - l);
    swap(v[random], v[l]);

    int p = v[l];
    l--, h++;
    while(true)
    {
        do
        {
            l++;
        }while(v[l] < p);

        do
        {
            h--;
        }while(v[h] > p);

        if(l >= h)
        {
            return h;
        }
        swap(v[l], v[h]);
    }
}

void quick_sort(vector<int>& v, int l, int h)
{
    if(l < h)
    {
        int m =  partition(v, l, h);
        quick_sort(v, l, m);
        quick_sort(v, m+1, h);
    }
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
    	int n; 
        bool flag = false;
    	cin>>n;
    	vector<int> v(n);

    	for(int i=0; i<n; i++)
    	{
    		cin>>v[i];
    	}

        quick_sort(v, 0, n-1);

        for(int i=1; i < n; i++)
        {
            if(v[i] == v[i-1])
            {
                flag = true;
                break;
            }
        }

        (flag == true) ? cout<<"YES" : cout<<"NO";
        cout<<endl;
    }

    return 0;
}