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

struct time{
    int h, m, s;

    void sum(int hh, int mm, int ss){
        s += ss;
        m += mm + s/60;
        s %= 60;
        h += hh + m/60;
        m %= 60;
    }

    void sub(int hh, int mm, int ss){
        s -= ss;
        if(s < 0){
            m--;
            s = 60 + s;
        }
        m -= mm;
        if(m<0){
            h--;
            m = 60 + m;
        }
        h -= hh;
    }
};

struct time t;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    t.h = 0, t.m = 0, t.s = 0;
    int n, c;
    rii(n,c);
    int m,s;
    FOR(i,0,n){
        scanf("%d:%d", &m, &s);
        t.sum(0,m,s);
    }
    c *= (n-1);
    s = c%60;
    c /= 60;
    m = c%60;
    c /= 60;
    t.sub(c,m,s);
    printf("%0*d:%0*d:%0*d\n",2,t.h,2,t.m,2,t.s);
    return 0;
}