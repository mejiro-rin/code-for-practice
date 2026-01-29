// 3650. 边反转的最小路径总成本

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        const long long INF = 1LL << 60;
        vector<vector<pair<int, long long>>> g(n);  // {to, cost}
        for (auto& e : edges) {
            int in = e[0], to = e[1];
            long long w = e[2];
            g[in].emplace_back(to, w);
            g[to].emplace_back(in, w * 2);
        }

        vector<long long> dist(n, INF);
        dist[0] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [cost, u] = pq.top(); pq.pop();
            if (cost > dist[u]) continue;

            for (auto [v, w] : g[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        if (dist[n - 1] == INF) return -1;
        if (dist[n - 1] > INT_MAX) return -1;  // 防止溢出
        return dist[n - 1];
    }
};

int main(){
    Solution test;
    vector<vector<int>> edges = {{0,1,3},{3,1,1},{2,3,4},{0,2,2}};
    cout << test.minCost(4, edges) << endl;
    return 0;
}