// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA. Double cannot be used
// for comparisons use div and mod instead. 
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
#define PI 3.14159265358979323
#define foi(i,n) for(lld i = 0; i < n; i+=1)
#define fod(i,n) for(lld i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define auth set <lld> :: iterator
#define pb push_back
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld n;
      	cin >> n;
      	lld A[n];
      	set <lld> vis;
      	for(lld i = 0; i < n; i += 1){
      		cin >> A[i];
      		vis.insert(A[i]);
      	}
      	sort(A,A+n);
      	if (n%2){
      		lld prod = A[n/2]*A[n/2];
      		lld f = 1;
      		for(lld i = 0; i < n/2; i += 1){
      			if (A[i]*A[n-i-1]!= prod){
      				f = 0;
      				break;
      			}
      		}
      		if (f == 0){
      			cout << "-1\n";
      		}
      		else{
      			lld g = 1;
      			for(lld i = 2; i <= sqrt(prod); i += 1){
      				if (prod%i == 0){
      					if (vis.count(i) && vis.count(prod/i)){
      						// do nothing
      					}
      					else
      						g = 0;
      				}
      			}
      			if (g == 0) cout << "-1\n";
      			else cout << prod<< "\n";
      		}
      	}
      	else{
      		lld prod = A[0]*A[n-1];
      		lld f = 1;
      		for(lld i = 0; i < n/2; i += 1){
      			if (A[i]*A[n-i-1]!= prod){
      				f = 0;
      				break;
      			}
      		}
      		if (f == 0){
      			cout << "-1\n";
      		}
      		else{
      			lld g = 1;
      			for(lld i = 2; i <= sqrt(prod); i += 1){
      				if (prod%i == 0){
      					if (vis.count(i) && vis.count(prod/i)){
      						// do nothing
      					}
      					else
      						g = 0;
      				}
      			}
      			if (g == 0) cout << "-1\n";
      			else cout << prod<< "\n";
      		}
      	}
      }
      return 0;
}