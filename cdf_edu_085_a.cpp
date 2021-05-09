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
int main (){
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",   stdin);
    freopen("outputf.in", "w",  stdout);
    #endif
    FastIO
    lld T;
    cin >> T;
    while (T!=0){
    	lld n, i;
    	cin >> n;
    	lld P[n];
    	lld C[n];
    	foi(i,n){
    		cin >> P[i];
    		cin >> C[i];
    	}
    	if (P[0] < C[0])
    			cout <<  "No\n";
    	else{
    		lld f=1;
    		for(i=1; i<n; i+=1){
    			if (P[i]-P[i-1] >= 0 && C[i]-C[i-1] >= 0 && P[i]-P[i-1] >= C[i]-C[i-1]){

    			}
    			else{
    				f = 0;
    				break;
    			}
    		}
    		if (f == 1)
    			cout << "Yes\n";
    		else
    			cout <<  "No\n";
    	}
    	T-=1;
    }
    return 0;
}