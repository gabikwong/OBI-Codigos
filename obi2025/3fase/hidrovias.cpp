#include <bits/stdc++.h>
using namespace std;
#define int long long
#define NMAX 100005
vector<int> pai(NMAX), tam(NMAX, 1);
int find(int v)
{
    if (pai[v] == v)
        return v;
    return pai[v] = find(pai[v]);
}
void une(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (tam[b] > tam[a])
        swap(a, b);
    pai[b] = a;
    tam[a] += tam[b];
}

int32_t main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int cont = 0;
    bool resp = true;
    vector<pair<int, int>> aresta;
    for (int i = 0; i <= n; i++)
        pai[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;

        if (t == 1)
        {
            if (find(a) == find(b))
                resp = false;
            une(a, b);
        }
        if (t == 2)
        {
            aresta.push_back({a, b});
        }
    }
    for (auto [a, b] : aresta)
    {

        if (find(a) == find(b))
            cont++;
        else
            une(a, b);
    }
    if (cont <= k && resp)
        cout << "S";
    else
        cout << "N";
}