//What is love?

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

#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ri(a) scanf("%d",&a)
#define rii(a,b) scanf("%d %d",&a,&b)
#define riii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define lri(a) scanf("%lld",&a)
#define lrii(a,b) scanf("%lld %lld",&a,&b)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define debug true
#define dprintf debug && printf
#define all(v) v.begin(),v.end()

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

//Baby don't hurt me

int n,m;
int v[1001][1001];
int cost[1001];
int cnt[1001];
int nd;
vi ans;

bool check(int x, int q, int i){
	int sum = 0;

	FOR(j,0,m){
		if(v[i][j] >= x) sum += v[i][j] - x + 1;
	}

	return sum <= q;
}

int BS(int l, int r, int x, int i){
	
	while(l<r){
		int m = (l+r)/2;
		if(check(m+x, m, i)) r = m;
		else l = m+1;
	}

	return r;
}

//Don't hurt me

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

	rii(n,m);

	nd = n;

	FOR(i,0,n){
		int mx = 0;
		int mxj = 0;
		cost[i] = 0;
		int win = 1;

		FOR(j,0,m){
			ri(v[i][j]);
			if(v[i][j] >= mx){
				mx = v[i][j];
				mxj = j;
			}
			if(mxj) win = 0;
		}

		if(!win){
			nd--;
			cost[i] = BS(0, mx-v[i][0]+1, v[i][0], i);
			//printf("cost[%d] = %d\n",i,cost[i]);
			ans.pb(cost[i]);
		}
	}

	int r=0;

	if(nd <= n/2){
		sort(all(ans));
		int i=0;
		while(nd <= n/2){
			r += ans[i];
			i++;
			nd++;
		}
	}

	printf("%d\n", r);

    return 0;
}
//No more