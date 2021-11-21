#include<iostream>
#include<vector>
using namespace std;

bool partition(vector<int> v, int n, int s)
{
    if(s == 0)
    {
        return true;
    }

    if(n == 0 && s != 0)
    {
        return false;
    }

    if(v[n-1] > s)
    {
        return partition(v, n-1, s);
    }

    return partition(v, n-1, s-v[n-1]) || partition(v, n-1, s);
}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n, sum=0;
    cin>>n;

    vector<int>v(n);

    for (int i = 0; i < n; i++)
    {
    	cin>>v[i];

        sum = sum + v[i];
    }

    if(sum % 2 != 0)
    {
        cout<<"no";
    }
    else
    {
        if(partition(v, n, sum/2))
        {
            cout<<"yes";
        }
        else
        {
            cout<<"no";
        }
    }

    cout<<endl;

    return 0;
}