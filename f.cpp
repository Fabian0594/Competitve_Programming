#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;          // parent[i] = padre (representante), sz[i] = tamaño de su componente
    vector<long long> edges;         // edges[i] = cuántas aristas tiene la componente cuya raíz es i

    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        edges.resize(n + 1, 0LL);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;           // inicializa cada nodo como su propio representante
        }
    }

    int find_set(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find_set(parent[v]); // compresión de caminos
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            // Union by size: unimos la raíz más pequeña a la más grande
            if (sz[a] < sz[b]) 
                swap(a, b);
            parent[b] = a;           // b se une a la raíz de a
            sz[a] += sz[b];          // aumenta el tamaño del nuevo representante
            edges[a] += edges[b];    // suma las aristas de b
            edges[a] += 1;          // esta nueva amistad que une ambos componentes
        } else {
            // Si ya están en la misma componente, sumamos 1 arista más
            // (Para el caso de amistades duplicadas en la entrada)
            edges[a] += 1;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    DSU dsu(N); // inicializa DSU para N estudiantes

    // Leer las Q amistades
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        dsu.union_set(a, b);
    }

    // Calcular cuántas amistades nuevas genera el hechizo
    long long answer = 0;
    // Recorremos todos los estudiantes de 1..N
    // y solo procesamos si i es el representante (i == parent[i])
    for (int i = 1; i <= N; i++) {
        if (dsu.find_set(i) == i) {
            long long k = dsu.sz[i];       // tamaño de la componente
            long long e = dsu.edges[i];    // # de aristas en la componente
            long long complete = (k * (k - 1)) / 2;  // aristas que tendría un K_k
            answer += (complete - e);  // las que faltan para hacerlo completo
        }
    }

    cout << answer << "\n";
    return 0;
}