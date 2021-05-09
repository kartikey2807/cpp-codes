// Always prefer arrays over data structures
// Code style can go to hell
// Make strong test cases if doubtful
// Read the code atleast once before submitting.
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define foi(i,n) for(lld i = 0; i < n; i+=1)
#define fod(i,n) for(lld i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define LEN 3000
lld dda[LEN][LEN];
vector <lld> calc (lld n)
{
    lld row_min[10];
    lld row_max[10];
    for(lld i = 0; i <=9; i += 1){
    	row_min[i] = MAX;
    	row_max[i] = MIN;
    }
    for(lld i = 0; i < n; i += 1){
    	for(lld j = 0; j < n; j += 1){
    		if (i<row_min[dda[i][j]])
    			row_min[dda[i][j]]=i;
    		if (i>row_max[dda[i][j]])
    			row_max[dda[i][j]]=i;
    	}
    }
    vector <lld> val(10);
    for(lld x = 0; x <=9; x += 1){
    	if (row_min[x] == MAX)
    		continue;
    	for(lld i = 0; i < n; i += 1){
    		lld col_min = MAX;
    		lld col_max = MIN;
    		for(lld j = 0; j < n; j += 1){
    			if (dda[i][j] == x){
    				if (j <col_min)
    					col_min=j;
    				if (j >col_max)
    					col_max=j;
    			}
    		}
    		if (col_min != MAX){
    			lld base = MIN;
    			for(lld j = 0; j < n; j += 1)
    				base = max(base,max(abs(col_min-j),abs(col_max-j)));
    			lld height = max(abs(row_min[x]-i),abs(row_max[x]-i));
    			val[x] = max(val[x],base*height);
    		}
    	}
    }
    return val;
}
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld t;
    cin >> t;
    while(t--){
    	lld n;
    	cin >> n;
    	for(lld i = 0; i < n; i += 1){
    		for(lld j = 0; j < n; j += 1){
    			char c;
    			cin >> c;
    			dda[i][j] = (lld)c-48;
    		}
    	}
    	vector <lld> a = calc(n);
    	for(lld i = 0; i < n; i += 1){
    		for(lld j = 0; j < i; j += 1){
    			swap(dda[i][j],dda[j][i]);
    		}
    	}
    	vector <lld> b = calc(n);
    	for(lld i = 0; i <=9; i += 1)
    		cout << max(a[i],b[i]) << " ";
    	cout << "\n";
    }
    return 0;
}