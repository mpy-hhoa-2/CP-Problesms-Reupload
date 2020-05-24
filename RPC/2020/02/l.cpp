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
const int MAXN = 1<<15;
const int LOGN = 15;

ll dp[LOGN][MAXN];
ll s[MAXN];
int r;

ll sq(ll x){
    return x * x;
}

ll f(int k, int i){
    if(k == 0) return 0;
    if(dp[k][i] != -1) return dp[k][i];
    int kk = k-1;
    i = i ^ (1<<kk);
    int l = i & ((-1)<<kk), r = l + (1<<kk);
    i = i ^ (1<<kk);
    if(l > r) swap(l, r);

    ll ret = INFLL;
    FOR(j,l,r) {
        ll cost = s[i] > s[j] ? 0 : sq(s[i] - s[j]);
        ret = min(ret, cost + f(kk, j));
    }

    return dp[k][i] = f(kk, i) + ret;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    ms(dp, -1);
    ri(r);
    FOR(i,0,1<<r) lri(s[i]);
    printf("%lld\n", f(r, 0));

    return 0;
}
