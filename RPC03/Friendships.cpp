#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    vector<long long> edges;

    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        edges.resize(n + 1, 0LL);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find_set(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) 
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            edges[a] += edges[b];
            edges[a] += 1;
        } else {
            edges[a] += 1;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    DSU dsu(N);

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        dsu.union_set(a, b);
    }

    long long answer = 0;
    for (int i = 1; i <= N; i++) {
        if (dsu.find_set(i) == i) {
            long long k = dsu.sz[i];
            long long e = dsu.edges[i];
            long long complete = (k * (k - 1)) / 2;
            answer += (complete - e);
        }
    }

    cout << answer << "\n";
    return 0;
}