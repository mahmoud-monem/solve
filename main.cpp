#include <bits/stdc++.h>

#define ll long long

using namespace std;

void readFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //    freopen("input.txt", "r", stdin);
//    freopen ("output.txt","w",stdout);
#endif
}

const int MOD = 1e9 + 7;
const int N = 1e5 + 5, M = 2e5 + 5;
int vis[N], vid;
string ans[M];

struct graph {
    int n, to[M], cost[M], ne, head[N], nxt[M];

    void init(int n) {
        this->n = n;
        ne = 2;
        memset(head, -1, (n + 1) * sizeof head[0]);
    }

    void addEdge(int u, int v, int c) {
        to[ne] = v;
        cost[ne] = c;
        nxt[ne] = head[u];
        head[u] = ne++;
    }

    void addBiEdge(int u, int v, int c) {
        addEdge(u, v, c);
        addEdge(v, u, c);
    }
} adj;

int edgeFrom[M], edgeTo[M], edgeCost[M], a[1000][1000];
vector<vector<int> > cycles;
vector<int> cur;

void generateCycles(int u) {
    vis[u] = 1;
    cur.push_back(u);
    for (int e = adj.head[u]; ~e; e = adj.nxt[e]) {
        int v = adj.to[e];
        if (!vis[v]) generateCycles(v);
        else if (vis[v] == 1) {
            vector<int> tmp;
            tmp.push_back(v);
            for (int i = cur.size() - 1; i >= 0 && cur[i] != v; i--) tmp.push_back(cur[i]);
            tmp.push_back(v);
            for(int i = 0; i < tmp.size() - 1; i++){

            }
            if (tmp.size() > 3) cycles.push_back(tmp);
        }
    }
    cur.pop_back();
    vis[u] = 2;
}

int main() {
    readFile();
    int n;
    cin >> n;
    adj.init(n);
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        cin >> edgeFrom[i] >> edgeTo[i] >> edgeCost[i];
        adj.addBiEdge(edgeFrom[i], edgeTo[i], edgeCost[i]);
        a[edgeFrom[i]][edgeTo[i]] = a[edgeTo[i]][edgeFrom[i]] = i;
    }
    generateCycles(1);
    return 0;
} 