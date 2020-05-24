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

int n;
vii lifts[MAXN];

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    ri(n);
    FOR(i,0,n){
        int x, y, a;
        rii(x, y); ri(a);
        lifts[y].pb({x, a});
    }

    int ans = 0;
    FOR(y,0,MAXN) sort(all(lifts[y]));
    FOR(y,0,MAXN-1){
        int i = 0, j = 0, cnt = 0;
        int sz1 = lifts[y].size();
        int sz2 = lifts[y+1].size();

        FOR(i,0,lifts[y].size()) cnt += (lifts[y][i].S > 0);

        while(i < sz1 && j < sz2){
            if(!lifts[y][i].S) {i++; continue;}
            if(lifts[y+1][j].S == 1 && cnt < sz2 - j) {j++; continue;}
            lifts[y+1][j].S--;
            ans++;
            i++, j++, cnt--;
        }
    }

    printf("%d\n", ans);

    return 0;
}
