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

typedef double ll;
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

ll sq(ll x){
    return x*x;
}

ll sq(ll x, ll y, ll z){
    return sq(x) + sq(y) + sq(z);
}
ll radii[MAXN];
int n, k;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    rii(n, k);
    FOR(i,0,n){
        ll x, y, z;
        scanf("%lf", &x);
        scanf("%lf", &y);
        scanf("%lf", &z);
        radii[i] = sq(x, y, z);
    }

    sort(radii, radii + n);
    printf("%.11lf\n", sqrt(radii[k-1]));

    return 0;
}
