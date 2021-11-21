#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mergeFiles(vector<int> &v, int n) 
{
    sort(v.begin(), v.end());

    int cost = 0;

    if(n <= 1)
    {
        cost = v[0];
    }

    for (int i = 1; i < n; i++) 
    {
        v[i] = v[i] + v[i - 1];
        cost = cost + v[i];
    }

    return cost;
}

int main() 
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout<<mergeFiles(v, n)<<endl;

    return 0;
}

