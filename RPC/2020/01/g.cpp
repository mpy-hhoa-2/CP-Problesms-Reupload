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

const int INFx = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
//const int MAXN = 2e5+5;

/*--------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/

int n,m;
int getNode(int i, int j){
	return i*m + j;
}

//////////////////////// min cost max flow ///////////////////////////////////////

const int MAXN = 903;
const ll INF = 1LL<<61;

int N;
ll cap[MAXN][MAXN], flow[MAXN][MAXN], cost[MAXN][MAXN];
ll dist[MAXN], pi[MAXN], width[MAXN];
pair<int, int> dad[MAXN];
bool found[MAXN];
void add_edge(int from, int to, ll u, ll c) {
	cap[from][to] = u;
	cost[from][to] = c;
}
void relax(int s, int k, ll u, ll c, int dir) {
	ll val = dist[s] + pi[s] - pi[k] + c;
	if (u && val < dist[k]) {
		dist[k] = val;
		dad[k] = {s, dir};
		width[k] = min(u, width[s]);
	}
}
ll dijk(int s, int t) {
	fill(found, found+N+1, false);
	fill(dist, dist+N+1, INF);
	fill(width, width+N+1, 0);
	dist[s] = 0;
	width[s] = INF;	
	while(s != -1){
		int best = -1;
		found[s] = true;
		FOR(k, 0, N){
			if(found[k]) continue;
			relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
			relax(s, k, flow[k][s], -cost[k][s], -1);
			if(best == -1 || dist[k] < dist[best]) best = k;
		}
		s = best;
	}
	FOR(k, 0, N) pi[k] = min(pi[k] + dist[k], INF);
	return width[t];
}

pair<ll, ll> get_flow(int s, int t, ll flow_limit = INF){
	ll totflow = 0, totcost = 0;
	while(ll amt = dijk(s, t)){
		if(totflow + amt > flow_limit) amt = flow_limit - totflow;
		totflow += amt;
		for (int x = t; x != s; x = dad[x].first) {
			if (dad[x].second == 1) {
				flow[dad[x].first][x] += amt;
				totcost += amt * cost[dad[x].first][x];
			} else {
				flow[x][dad[x].first] -= amt;
				totcost -= amt * cost[x][dad[x].first];
			}
		}
		if(totflow == flow_limit) break;
	}
	return {totflow, totcost};
}

///////////////////////////////////////////////////////////////////////////////

// BFS ///////////////////////////////////////////////////////////////////////

int sp[MAXN];
vi G[MAXN];

void bfs(int s){
	FOR(i,0,N) sp[i] = INFx;
	queue<int> q;
	q.push(s);
	sp[s] = 0;
	while(!q.empty()){
		int v = q.front();
		q.pop();

		for(auto u : G[v]){
			if(sp[u] > sp[v] + 1){
				sp[u] = sp[v] + 1;
				q.push(u);
			}
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////

int grid[MAXN][MAXN];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool limit(int i, int j){
	return i>=0 && i<n && j>=0 && j<m;
}

void getGraph(){
	FOR(i,0,n){
		FOR(j,0,m){
			if(grid[i][j]){
				int u = getNode(i,j);
				FOR(k,0,4){
					int ni = i+dx[k], nj = j + dy[k];
					if(limit(ni, nj) && grid[ni][nj]){
						int v = getNode(ni,nj);
						add_edge(u,v,1,1);
						G[u].pb(v);
					}
				}
			}
		}
	}
}


int main(){

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	rii(n,m);

	N = n*m + 2;
	int s = N-2;
	int t = N-1;
	int B = -1;
	int C = -1;
	int F = -1;


	FOR(i,0,n){
		FOR(j,0,m){
			char c;
			cin >> c;
			if(c == 'C') C = getNode(i,j);
			if(c == 'B') B = getNode(i,j);
			if(c == 'F') F = getNode(i,j);
			grid[i][j] = (int)(c != 'x');
		}
	}


	getGraph();

	bfs(F);

	add_edge(s,B,1,0);
	add_edge(s,C,1,0);
	add_edge(F,t,2,0);

	pair<ll, ll> r = get_flow(s, t);

	//printf("%d %d %d %d\n", r.S,  sp[B] + sp[C], sp[B], sp[C]);

	if(r.F != 2) printf("-1\n");
	else printf("%lld\n", r.S);

	//if(r.S == sp[B] + sp[C]) printf("%d\n", r.S);
	//else printf("-1\n");

	return 0;
}

//No more