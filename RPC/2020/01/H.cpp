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
const int MAXN = 55;

int n,m,sz;
vector <int>  ans(MAXN);
int a[MAXN][MAXN]; 
char s[255];

int f(char s[]){
    sz = strlen(s);
    FOR(j, 1, sz/2+1){
        if(sz%j != 0) continue;
        bool f = 0;
        for(int i = j; i < sz && !f; i += j){
            for(int k = 0; k < j && !f; k++){
                if(s[i+k]!=s[k]){
                    f = 1;
                }
            }
        }
        if(!f){
            return j;
        }
    }
    return sz;
}

int sq(int i){
    return i*i;
}

int hungarian(){

	vector < int > u ( n + 1 ) , v ( m + 1 ) , p ( m + 1 ) , way ( m + 1 ) ;

	for ( int i = 1 ; i <= n ; ++ i ) {
		p [ 0 ] = i ;
		int j0 = 0 ;
		vector < int > minv ( m + 1 , INF ) ;
		vector < char > used ( m + 1 , false ) ;
		do {
			used [ j0 ] = true ;
			int i0 = p [ j0 ] ,  delta = INF,  j1 ;
			for ( int j = 1 ; j <= m ; ++ j )
				if ( ! used [ j ] ) {
					int cur = a [ i0 ] [ j ] - u [ i0 ] - v [ j ] ;
					if ( cur < minv [ j ] )
						minv [ j ] = cur,  way [ j ] = j0 ;
					if ( minv [ j ] < delta )
						delta = minv [ j ] ,  j1 = j ;
				}
			for ( int j = 0 ; j <= m ; ++ j )
				if ( used [ j ] )
					u [ p [ j ] ] += delta,  v [ j ] -= delta ;
				else
					minv [ j ] -= delta ;
			j0 = j1 ;
		} while ( p [ j0 ] != 0 ) ;
		do {
			int j1 = way [ j0 ] ;
			p [ j0 ] = p [ j1 ] ;
			j0 = j1 ;
		} while ( j0 ) ;
	}

	int cost = - v [ 0 ] ;
	return cost;
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ri(n);
    vi r, c;
    FOR(i,0,n){
        scanf("%s",s);
        r.pb(f(s));
    }
    FOR(i,0,n){
        scanf("%s",s);
        c.pb(f(s));
    }
    m = n;
    FOR(i,1,n+1) FOR(j,1,n+1) a[i][j] = sq(r[i-1]-c[j-1]);
    printf("%d\n", hungarian());
    return 0;
}