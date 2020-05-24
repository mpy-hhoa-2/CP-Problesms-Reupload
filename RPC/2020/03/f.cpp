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
const int MAXN = 2e5+5;

double dp[111][111][111];
double s[111], d[111];
char score[111][111];
int t, p;

double f(int t, int i, int k){
    if(k < 0) return 0;
    if(i == p) return 1;
    if(dp[t][i][k] != -1) return dp[t][i][k];
    if(score[t][i] == 'X') return dp[t][i][k] = f(t, i+1, k-1);
    if(score[t][i] == '-') return dp[t][i][k] = f(t, i+1, k);
    return dp[t][i][k] = s[t] * d[i] * f(t, i+1, k-1)
                       + (1.0 - s[t] * d[i]) * f(t, i+1, k);
}

char tmp[5];

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    FOR(i,0,111) FOR(j,0,111) FOR(k,0,111) dp[i][j][k] = -1;

    rii(t, p);
    FOR(i,1,t) scanf("%lf", &s[i]);
    FOR(i,0,p) scanf("%lf", &d[i]);

    FOR(i,1,t) FOR(j,0,p) scanf("%s", tmp), score[i][j] = tmp[0];
    FOR(j,0,p) scanf("%s", tmp), score[0][j] = tmp[0];
    
    int cnt = 0;
    FOR(i,0,p) if(score[0][i] == 'X') cnt++;

    double ans = 1;
    FOR(i,1,t) ans *= f(i, 0, cnt);

    printf("%.11lf\n", ans);

    return 0;
}