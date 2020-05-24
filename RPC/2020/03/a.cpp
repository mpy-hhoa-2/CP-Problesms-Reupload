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
const int MAXN = 2e3+5;

int n, m;
int u[MAXN], v[MAXN];

double p[MAXN];
double dp[1<<16][MAXN];
double ans[20];

double solve(int msk, int i){
    if(i == 0) return msk == (1<<n) - 1 ? 1.0 : 0.0;
    if(dp[msk][i] != -1) return dp[msk][i];
    if(~msk>>u[i]&1) return dp[msk][i] = solve(msk, i-1);
    if(msk>>v[i]&1) return dp[msk][i] = (1 - p[i]) * solve(msk, i-1);
    return dp[msk][i] = p[i] * solve(msk | (1<<v[i]), i-1) + solve(msk, i-1);
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    FOR(i,0,1<<16) FOR(j,0,MAXN) dp[i][j] = -1;

    rii(n, m);
    FOR(i,1,m+1){
        rii(u[i], v[i]); u[i]--, v[i]--;
        scanf("%lf", &p[i]);
    }

    FOR(msk,0,1<<n){
        double x = solve(msk, m);
        FOR(i,0,n) if(msk>>i&1) ans[i] += x;
    }
    FOR(i,0,n) printf("%.11lf\n", ans[i]);

    return 0;
}
