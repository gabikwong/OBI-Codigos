
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> tipo(n);
    vector<int> preco(n);
    map<int, vector<int>> aux;
    for (int i = 0; i < n; i++)
        cin >> tipo[i];
    for (int i = 0; i < n; i++)
        cin >> preco[i];
    // preco, tipo , id
    set<pair<int, pair<int, int>>> geral;
    // preco, id
    vector<set<pair<int, int>>> estoque(m + 1);
    for (int i = 0; i < n; i++)
    {
        geral.insert({preco[i], {tipo[i], i}});
        estoque[tipo[i]].insert({preco[i], i});
    }
    int c;
    cin >> c;
    int resp = 0;
    for (int i = 0; i < c; i++)
    {
        int u;
        cin >> u;
        if (!u)
        {
            if (!geral.empty())
            {
                auto [p, aux] = *geral.begin();
                resp += p;
                geral.erase(geral.begin());
                estoque[aux.first].erase({p, aux.second});
            }
        }
        else
        {
            if (!estoque[u].empty())
            {
                auto [p, id] = *estoque[u].begin();
                resp += p;
                estoque[u].erase(estoque[u].begin());
                geral.erase({p, {u, id}});
            }
        }
    }
    cout << resp;
}