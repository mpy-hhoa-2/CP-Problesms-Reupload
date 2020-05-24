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

int n, p, c;
map <string, vi> M;
vector <pair <int, string>> cards;
int currPos[10];

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    ms(currPos, -1);
    cin >> n >> p;
    FOR(i,0,n-1){
        string s;
        cin >> s;
        M[s].push_back(i);
    }
    cin >> c;
    FOR(i,0,c){
        int x;
        string s;
        cin >> x >> s;
        cards.push_back({x, s});
    }

    int t = 0;
    while(1){
        int x = cards[t % c].F;
        string s = cards[t % c].S;
        if(x == 1 || x == 2){
            vi &v = M[s];
            auto it = ub(all(v), currPos[t % p]);
            if(it == v.end()){
                printf("%d\n", t % p + 1);
                return 0;
            }
            currPos[t % p] = *it;
        }
        if(x == 2){
            vi &v = M[s];
            auto it = ub(all(v), currPos[t % p]);
            if(it == v.end()){
                printf("%d\n", t % p + 1);
                return 0;
            } 
            currPos[t % p] = *it;
        }
        if(x == 3){
            currPos[t % p] = M[s][0];
        }
        t++;
    }

    return 0;
}
