#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000;

int a[MAXN][MAXN], n, m, u, v;
bool use[MAXN];

int X(int k) {
    int x = -1, y = -1;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(!a[i][j] && !use[i] && !use[j]) {
                x = i;
                y = j;
                break;
            }
        }
        string s;
        if(x != -1) break;
    }
    if(x == -1) return k;
    int ans = 1 << 30;
    a[x][y] = a[y][x] = 1;
    ans = min(ans, X(k));
    a[x][y] = a[y][x] = 0;
    use[x] = use[y] = 1;
    n++;
    for(int i = 0; i < n; i++)
        a[n - 1][i] = a[i][n - 1] = (a[x][i] | a[y][i]);
    ans = min(ans, X(k - 1));
    for(int i = 0; i < n; i++)
        a[n - 1][i] = a[i][n - 1] = 0;
    use[x] = use[y] = 0;
    n--;
    return ans;

}

// номера вершин вводить с 1
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        a[u][v] = a[v][u] = 1;
    }
    cout << X(n);
    return 0;
}
