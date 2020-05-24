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
const int MAXN = 2e2+5;
const double PI = 2*acos(0.0);

double dp[MAXN][MAXN];
double c[MAXN];
int t[MAXN], q[MAXN];
int n, m;

ll cost(int i, int j){
    if(i > j) swap(i, j);
    return min(j - i, m + i - j);
}

double f(int i, int j){
    if(i == n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    double ret = INFLL;
    FOR(k,0,m) if(q[k] == t[i]){
        ret = min(ret, c[cost(j, k)] + f(i+1, k));
    }
    return dp[i][j] = ret;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    FOR(i,0,MAXN) FOR(j,0,MAXN) dp[i][j] = -1;
    ri(n);
    FOR(i,0,n) ri(t[i]);
    ri(m);
    FOR(i,0,m) ri(q[i]);

    FOR(i,0,m) c[i] = 2 * sin((PI / m) * i);

    double ans = INFLL;
    FOR(i,0,m) ans = min(ans, f(0,i));

    printf("%.11lf\n", 1.0  + ans);

    return 0;
}
