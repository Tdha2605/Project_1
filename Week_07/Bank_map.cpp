
#include <bits/stdc++.h>

using namespace std;

int count_1, u, v, k, count_2;
int visited[100009];
long long money, Tmoney, Sum[100009];
vector<int> a[100009];
map<string, int> Map;
string facc, tacc, Time, Bank, quest;

int dfs(int t, int u, int sl)
{
    if (sl == k)
    {
        for (int v : a[u])
            if (v == t)
                return 1;
        return 0;
    }

    for (int v : a[u])
        if (visited[v] == 0)
        {
            visited[v] = 1;
            if (dfs(t, v, sl + 1))
                return 1;
            visited[v] = 0;
        }

    return 0;
}
int main()
{

    while (1)
    {
        cin >> facc;
        if (facc == "#")
            break;

        cin >> tacc >> money >> Time >> Bank;
        if (Map[facc] == 0)
            count_1++, Map[facc] = count_1;
        if (Map[tacc] == 0)
            count_1++, Map[tacc] = count_1;
        count_2++;
        Tmoney += money;

        u = Map[facc];
        v = Map[tacc];
        Sum[u] += money;
        a[u].push_back(v);
    }

    while (1)
    {
        cin >> quest;
        if (quest == "#")
            break;

        if (quest == "?number_transactions")
            cout << count_2 << '\n';

        if (quest == "?total_money_transaction")
            cout << Tmoney << '\n';

        if (quest == "?list_sorted_accounts")
        {
            for (auto it = Map.begin(); it != Map.end(); it++)
                cout << it->first << ' ';
            cout << '\n';
        }

        if (quest == "?total_money_transaction_from")
        {
            cin >> facc;
            u = Map[facc];
            cout << Sum[u] << '\n';
        }

        if (quest == "?inspect_cycle")
        {
            cin >> facc >> k;
            u = Map[facc];
            memset(visited, 0, sizeof(visited));
            visited[u] = 1;
            cout << (dfs(u, u, 1)) << '\n';
        }
    }
    return 0;
}