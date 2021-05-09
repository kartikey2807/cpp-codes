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
void no () {cout << "NO\n";}
void yes() {cout << "YES\n";}
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
      	lld n, q;
      	cin >> n >> q;
      	lld A[n];
      	for(lld i = 0; i < n; i += 1){
      		cin >> A[i];
      	}
      	if (n == 1) {cout << A[0] << "\n"; continue;}
      	vector <lld> v;
      	for(lld i = 1; i < n; i += 1){
      		if (A[i] > A[i-1]){
      			lld j;
      			for(j = i; j < n; j += 1){
      				if (A[j] < A[j-1])
      					break;
      			}
      			v.pb(A[j-1]);
      			i = j;
      			i-= 1;
      		}
      		else{
      			lld j;
      			for(j = i; j < n; j += 1){
      				if (A[j] > A[j-1])
      					break;
      			}
      			if (v.empty())
      				v.pb(A[0]);
      			v.pb(A[j-1]);
      			i = j;
      			i-= 1;
      		}
      	}
      	if (v.size() == 1){
      		cout << v[0];
      	}
      	else{
      		lld sum = 0;
      		lld len = v.size();
      		if (v[len-1] > v[len-2]){
      			for(lld i = 0; i < len; i += 1){
      				if (i%2 == 0)
      					sum += v[i];
      				else
      					sum -= v[i];
      			}
      		}
      		else{
      			for(lld i = 0; i<len-1; i += 1){
      				if (i%2 == 0)
      					sum += v[i];
      				else
      					sum -= v[i];
      			}
      		}
      		cout << sum;
      	}
      	cout << "\n";
      }
      return 0;
}