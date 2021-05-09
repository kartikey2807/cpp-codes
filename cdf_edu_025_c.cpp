// NEVER USE STRING DIRECTLY. IF THERE ARE CHARACTERS
// USE CHAR ARRAY OTHERWISE CHANGE IT INTO NUMBER
// ARRAY. IT SPAWNS TRAGEDY, IT HAS ALREADY HAPPENED
// TWICE. PLEASE NEVER AGAIN. :(
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
#define val 1000000000
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      // READ UPPER CLAUSE
      lld n, k;
      cin >> n >> k;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      sort(A,A+n);
      lld cnt = 0;
      for(lld i = 0; i < n; i += 1){
      	if (A[i]%2){
      		if (k >= (A[i]/2)+1){
      			k= max(k,A[i]);
      		}
      		else{
      			while(k < (A[i]/2)+1){
      				k*= 2;
      				cnt++;
      			}
      			k= max(k,A[i]);
      		}
      	}
      	else{
      		if (k >= (A[i]/2)+0){
      			k= max(k,A[i]);
      		}
      		else{
      			while(k < (A[i]/2)+0){
      				k*= 2;
      				cnt++;
      			}
      			k= max(k,A[i]);
      		}
      	}
      }
      cout << cnt;
      return 0;
}