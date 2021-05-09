// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA.
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
      	for(lld i = 0; i < n; i += 1){
      		cin >> A[i];
      	}
      	lld f = 1;
      	lld cnt = 1;
      	for(lld i = 1; i < n; i += 1){
      		if (A[i] > A[i-1]){
      			cnt++;
      		}
      		else{
      			if (A[i]-cnt>= 0){
      				cnt++;
      			}
      			else{
      				for(lld j = i; j < n; j += 1){
      					A[j]=min(A[j],A[j-1]-1);
      					if (A[j] < 0){
      						f = 0;
      						break;
      					}
      				}
      				break;
      			}
      		}
      	}
      	if (f == 1) cout << "Yes\n";
      	else cout << "No\n";
      }
      return 0;
}