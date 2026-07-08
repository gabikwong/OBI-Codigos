
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int maior = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maior = max(maior, a[i]);
    }
    for (int j = maior; j > 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= j)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}