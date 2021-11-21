#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item 
{
    int id;
    float weight, value, vw;
};

bool cmp(Item i1, Item i2) 
{
    return (i1.vw > i2.vw);
}

void fractionalKnapsack(vector<Item> &items, int n, int cap) 
{
    vector<pair<int, int>> ans;
    float profit = 0.0;

    for (int i = 0; i < n; i++)
    {
        items[i].vw = (items[i].value / items[i].weight);
    }

    sort(items.begin(), items.end(), cmp);

    for (int i = 0; i < n; ++i) 
    {
        if (items[i].weight <= cap) 
        {
            profit = profit + items[i].value;
            cap = cap - items[i].weight;
            ans.push_back({items[i].id, items[i].weight});
        }
        else 
        {
            profit = profit + (cap * items[i].vw);
            ans.push_back({items[i].id, cap});
            break;
        }
    }

    cout<<"Maximum value: "<<profit<<endl;
    cout<<"Item - Weight"<<endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " - " << ans[i].second << endl;
    }
}

// Driver function
int main() 
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n, cap;

    cin>>n;
    vector<Item> items(n);
    
    for (int i = 0; i < n; i++) 
    {
        cin>>items[i].weight;
        items[i].id = (i + 1);
    }

    for (int i = 0; i < n; ++i)
    {
        cin>>items[i].value;
    }

    cin>>cap;

    fractionalKnapsack(items, n, cap);

    return 0;
}