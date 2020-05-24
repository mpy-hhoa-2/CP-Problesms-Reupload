#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i=n; i<(int)m; i++)
#define ROF(i,n,m) for(int i=n; i>(int)m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ri(a) scanf("%d",&a)
#define rii(a,b) ri(a),ri(b)
#define riii(a,b,c) rii(a,b),ri(c)
#define lri(a) scanf("%lld",&a)
#define lrii(a,b) lri(a),lri(b)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define debug true
#define dprintf debug && printf

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 5e5+5;

bool vist[MAXN];
int d[MAXN];
int e[MAXN];
vi G[MAXN];
int n;

int dfs(int v){
    if(vist[v]) return 0;
    vist[v] = true;
    int ret = 1;
    for(auto u : G[v]) ret += dfs(u);
    return ret;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    ms(vist, false);
    ri(n);
    FOR(i,0,n){
        rii(e[i], d[i]);
        FOR(j,0,d[i]){
            int b;
            ri(b); b--;
            G[i].pb(b);
        }
    }

    priority_queue <ii> pq;
    FOR(i,0,n) pq.push({e[i], i});
    int cnt = 0, ans = 0;
    while(!pq.empty()){
        int v = pq.top().S;
        pq.pop();

        if(vist[v]) continue;

        cnt += dfs(v) - 1;
        ans = max(ans, cnt + e[v]);
        cnt++;
    }

    printf("%d\n", ans);

    return 0;
}
