#include<iostream>
#include <cstdlib>
#include<ctime>
#include<vector>
using namespace std;

int partition(vector<int>& v, int l, int h)
{
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

int quick_sort(vector<int>& v, int l, int h, int k)
{
    if(k > 0 && k <= h - l + 1)
    {
        int m =  partition(v, l, h);

        if(m-l == k-1)
        {
            return v[m];
        }
        else if(m-l > k-1)
        {
            return quick_sort(v, l, m, k);
        }
        return quick_sort(v, m+1, h, k-m+l-1);
    }
    return INT_MAX;
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
    	int n, k; 
    	cin>>n;
    	vector<int> v(n);

    	for(int i=0; i<n; i++)
    	{
    		cin>>v[i];
    	}
        cin>>k;

        int ele = quick_sort(v, 0, n-1, k);

        if(ele == INT_MAX)
        {
            cout<<"Not Present";
        }
        else
        {
            cout<<ele;
        }
        cout<<endl;


    }

    return 0;
}