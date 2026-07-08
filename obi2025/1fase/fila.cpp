#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int resp = 0;
    int maior = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] <= maior)
            resp++;
        else
            maior = a[i];
    }
    cout << resp;
}