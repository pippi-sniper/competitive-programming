#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const double pi = 3.14159265358979;
const ll inf = 1e17;
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define dtor(deg) (((deg)/360)*2*pi)
#define all(a) a.begin(),a.end()
#define overload(_1,_2,_3,_4,name,...) name
#define _rep1(n) for(int i = 0; i < (n); i++)
#define _rep2(i,n) for(int i = 0; i < (n); i++)
#define _rep3(i,a,b) for(int i = (a); i < (b); i++)
#define _rep4(i,a,b,c) for(int i = (a); i < (b); i += (c))
#define rep(...) overload(__VA_ARGS__,_rep4,_rep3,_rep2,_rep1)(__VA_ARGS__)
#define _rrep1(n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep2(i,n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep3(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define _rrep4(i,a,b,c) for(int i = (b) - 1; i >= (a); i -= (c))
#define rrep(...) overload(__VA_ARGS__,_rrep4,_rrep3,_rrep2,_rrep1)(__VA_ARGS__)
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define vv(type,name,size,...) vector<vector<type>> name(size,vector<type>(__VA_ARGS__))
#define ForEach(a,b) for_each(a.begin(),a.end(),b)
struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;
template <class T> bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }

int h, w;
bool done[100][100];

ll dfs(int i, int j, int a, int b){
    if(a < 0 || b < 0) return 0;
    if(j == w) j = 0, i++;
    if(i == h) return 1;
    if(done[i][j]) return dfs(i, j+1, a, b);
    ll res = 0;
    done[i][j] = 1;
    res += dfs(i, j+1, a, b-1);
    if(j < w - 1 && !done[i][j+1]){
        done[i][j+1] = 1;
        res += dfs(i, j+1, a-1, b);
        done[i][j+1] = 0;
    }
    if(i < h - 1 && !done[i+1][j]){
        done[i+1][j] = 1;
        res += dfs(i, j+1, a-1, b);
        done[i+1][j] = 0;
    }
    done[i][j] = 0;
    return res;
}

void Main(){
    int a = 1000000, b = 1000000;
    rep(i,1,10){
        h = 3, w = i; 
        cout << dfs(0, 0, a, b) << endl;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}