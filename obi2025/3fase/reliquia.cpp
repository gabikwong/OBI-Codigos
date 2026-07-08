#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin >> n;
    vector<int> idx;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a)
            idx.push_back(i);
    }
    int resp = 0;
    for (int i = 0; i < idx.size(); i++)
    {
        int l = (i > 0) ? idx[i - 1] : 0;
        int r = (i < idx.size() - 1) ? idx[i + 1] : n + 1;
        resp += (idx[i] - l) * (r - idx[i]);
    }
    cout << resp;
}