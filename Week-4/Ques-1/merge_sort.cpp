#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>& v, vector<int> temp, int l, int m, int r, int& comp)
{
	int inv = 0, i=l, j=m, k=l;
	for(i = l, j = m, k = l; (i <= m-1) && (j <= r); )
	{
		comp++;
		if(v[i] <= v[j])
		{
			temp[k++] = v[i++];
		}
		else
		{
			temp[k++] = v[j++];

			inv = inv + (m-i);
		}
	}

	while(i <= m-1)
	{
		temp[k++] = v[i++];
	}

	while(j <= r)
	{
		temp[k++] = v[j++];
	}

	for (i = l; i <= r; i++)
	{
		v[i] = temp[i];
	}

	return inv;
}

int merge_sort(vector<int>& v, vector<int> temp, int l, int r, int& comp)
{
	int inv = 0, mid;
	if(l < r)
	{
		mid = l+(r-l) / 2;

		inv = inv + merge_sort(v, temp, l, mid, comp);
		inv = inv + merge_sort(v, temp, mid+1, r, comp);

		inv = inv + merge(v, temp, l, mid+1, r, comp);
	}

	return inv;
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
    	int n, comp=0; 
    	cin>>n;
    	vector<int> v(n);
    	vector<int> temp(n);

    	for(int i=0; i<n; i++)
    	{
    		cin>>v[i];
    	}

        int inv_count = merge_sort(v, temp, 0, n-1, comp);


        for(auto it : v)
        {
        	cout<<it<<" ";
        }
        cout<<endl;
        cout<<"Comparisons = "<<comp<<endl;
        cout<<"Inversions = "<<inv_count;

        cout<<endl;
    }

    return 0;
}