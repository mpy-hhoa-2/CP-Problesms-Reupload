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

struct state{
	int len, link;
	map<char, int> mp;
	bool terminal;
};
struct Suffix_Automaton{
	state & operator[](int i){ return G[i]; }
	vector<state> G;
	int N;
	void build(string S){
		int last = 0;
		G.clear();
		G.pb({0, -1});
		for(char c : S){
			int v = G.size(), p=last; 
			G.pb({G[last].len+1});
			for(;p>-1 && !G[p].mp.count(c); p=G[p].link)
				G[p].mp[c]=v;
			if(p == -1){
				G[v].link = 0;
			}else{
				int q=G[p].mp[c];
				if(G[p].len+1 == G[q].len){
					G[v].link = q;
				}else{
					int qq = G.size();
					G.pb({G[p].len+1, G[q].link, G[q].mp});
					G[v].link = G[q].link = qq;
					for(;p>-1 && G[p].mp[c] == q; p=G[p].link)
						G[p].mp[c] = qq;
				}
			}
			last = v;
		}
		N = G.size();
		while(last>0){
			G[last].terminal = true;
			last = G[last].link;
		}
	}
};

Suffix_Automaton SA;
string codes[MAXN];
bool useful[MAXN];
int cnt[20];
int n;

ll sum(ll x){
    return (x*(x+1))/2;
}

ll sum(int l, int r){
    return sum(r) - sum(l-1);
}

double solve(int i){
    string s = "";
    FOR(id,0,n) if(id != i) {
        for(auto c : codes[id]) s += c;
    }

    SA.build(s);
//
//    FOR(i,0,SA.N){
//		printf("%d:\n",i);
//		for(auto it=SA.G[i].mp.begin(); it!=SA.G[i].mp.end(); it++)
//			printf("  %c -> %d\n",it->first,it->second);
//	}
//	printf("\n");
//	FOR(i,0,SA.N){
//		printf("%d   %d\n",i,SA.G[i].link);
//	}
//	printf("##\n\n");

    int cur = 0;
    ll ans = 0;
    int len = 0;
    for(auto c : codes[i]){
        while(cur && !SA[cur].mp.count(c)){
            int ln = SA[cur].link;
            ans += sum(SA[ln].len + 2, len + 1);
            cur = ln;
            len = SA[cur].len;
        }
        if(SA[cur].mp.count(c)) cur = SA[cur].mp[c], len++;
        else ans++;
    }

    return (1.0 * ans) / (codes[i].size() - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    FOR(i,0,n) cin >> codes[i];
    FOR(i,0,n) cnt[codes[i].back() - '0']++;
    FOR(i,0,n) useful[i] = cnt[codes[i].back() - '0'] == 1;
    FOR(i,0,n) codes[i] += '#';
    FOR(i,0,n) {
        if(useful[i])
            cout << solve(i) << endl;
        else cout << "Impossible\n";
    }


    return 0;
}
