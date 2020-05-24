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

int p[MAXN];
void fillSieve(){
    for(ll i = 4; i < MAXN; i += 2) p[i] = 2;
    for(ll i = 3; i*i < MAXN; i += 2) if(!p[i])
        for(ll j = i*i; j < MAXN; j += 2*i) p[j] = i;
}

int n, k, cnt;
int pr[MAXN];
int lst[MAXN];
vector<ll> ans;

ll solve(){
    fillSieve();
    ans.pb(1);

    priority_queue<pair<ll, int>> pq;
    int i = n + 1, sz = 0;
    while(sz < k){
        if(!p[i]){
            pr[sz] = i;
            pq.push({-i, sz++});
        }
        i++;
    }

    while(cnt < k){
        ll x = -pq.top().F;
        int i = pq.top().S;
        pq.pop();

        if(x != ans.back()) {
            ans.push_back(x);
            if(x != pr[i]) cnt++;
        }
        
        pq.push({-pr[i] * ans[++lst[i]], i});
    }

    return ans.back();
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    rii(n, k);
    printf("%lld\n", solve());

    return 0;
}
