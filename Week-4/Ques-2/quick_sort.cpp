#include<iostream>
#include <cstdlib>
#include<ctime>
#include<vector>
using namespace std;

int partition(vector<int>& v, int l, int h, int& comp, int& s)
{
    srand(time(NULL));
    int random = l + rand() % (h - l);
    s++;
    swap(v[random], v[l]);

    int p = v[l];
    l--, h++;
    while(true)
    {
        comp++;
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
            comp++;
            return h;
        }
        s++;
        swap(v[l], v[h]);
    }
}

void quick_sort(vector<int>& v, int l, int h, int& comp, int& s)
{
    if(l < h)
    {
        int m =  partition(v, l, h, comp, s);
        quick_sort(v, l, m, comp, s);
        quick_sort(v, m+1, h, comp, s);
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
    	int n, comp = 0, s = 0; 
    	cin>>n;
    	vector<int> v(n);

    	for(int i=0; i<n; i++)
    	{
    		cin>>v[i];
    	}

        quick_sort(v, 0, n-1, comp, s);

        for(auto it : v)
        {
            cout<<it<<" ";
        }
        cout<<endl;

        cout<<"Comparisons = "<<comp<<endl;
        cout<<"Swaps = "<<s;

        cout<<endl;


    }

    return 0;
}