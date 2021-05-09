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
lld binS(lld arr[] , lld l , lld r , lld x){
    if (r >= l) {
        lld mid = l +(r-l) / 2;
        if (arr[mid] == x) 
            return 1;
        if (arr[mid] >  x)
			return binS(arr, l, mid - 1, x);
			return binS(arr, mid + 1, r, x);
    }
    return 0;
}
int main (){
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",   stdin);
    freopen("outputf.in", "w",  stdout);
    #endif
    FastIO
    lld T;
    cin >> T;
    while (T!=0){
    	lld n, x;
    	cin >> n;
    	cin >> x;
    	lld A[n];
    	lld i, q;
    	lld r, f;
    	foi(i,n){
    		cin >> A[i];
    	}
    	set <lld> divid;
    	sort(A , A + n);
    	foi(i,n){
    		if (x%A[i] == 0){
    			divid.insert(x/A[i]);
    		}
    		else{
    			q = x/ A[i];
    			r = x% A[i];
    			if (binS(A,0,n-1,r)){
    				q = q+1;
    			}
    			else
    				q = q+2;
    				divid.insert (q);
    		}
    	}
    	set<lld>::iterator p;
    	p = divid.begin();
    	cout << *p <<"\n";
    	T-=1;
    }
    return 0;
}