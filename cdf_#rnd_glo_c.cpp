#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 998244353
void pairSort (lld B[], lld A[], lld n){
	pair <lld, lld>  part[n];
	lld i;
	foi(i, n){
		part[i].first = A[i];
		part[i].second= B[i];
	}
	sort(part, part + n);
	foi(i, n){
		A[i] = part[i].first;
		B[i] =part[i].second;
	}
}
int main (){
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",   stdin);
    freopen("outputf.in", "w",  stdout);
    #endif
    FastIO
    lld n, k;
    cin >> n;
    cin >> k;
    lld i, s;
    lld j, f;
    lld A[n];
    lld B[n];
    lld C[n];
    lld D[n];
    foi(i,n){
    	cin >> A[i];
    	B[i] = A[i];
    	C[i] =  i+1;
    }
    s = 0;
    set <lld> index; 
    pairSort(C,B,n);
    set <lld>::iterator ps;
    fod(i,n){
    	if (k == 0)
    		break ;
    	s = s+B[i];
    	index.insert(C[i]);
    	k-=1;
    }
    j = 0;
    for(ps = index.begin(); ps!=index.end(); ps++){
    	D[j] = *ps;
    	j++;
    }
    f = 1;
    for(i = 1; i < j; i++){
    f *= (D[i]-D[i-1])%MOD;
    f %= MOD;
    }
    cout << s << " "  << f;
    return 0;
}