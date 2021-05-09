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
      lld n, k;
      cin >> n >> k;
      if (n >= 3*k){
      	map <lld, lld> val_mac;
      	if (n == 3*k){
      		lld start = 1, end = n;
      		for(lld nodes = 1; nodes <= k-2; nodes += 1){
      			val_mac[start] = val_mac[start+1] = val_mac[end] = nodes;
      			start+=2;
      			end -= 1;
      		}
      		val_mac[start] = val_mac[start+1] = val_mac[start+3] = k-1;
      		val_mac[start+2] = val_mac[start+4] = val_mac[start+5] = k;
      	}
      	else{
      		lld start = 1;
      		for(lld i = 1; i <= k; i += 1){
      			if (i%2 == 0){
      				val_mac[start] = val_mac[start+2] = val_mac[start+3] = i;
      				start += 4;
      			}
      			else{
      				val_mac[start] = val_mac[start+1] = val_mac[start+3] = i;
      				start += 2;
      			}
      		}
      		for(lld i = 1; i <= n; i += 1){
      			if (val_mac[i] == 0)
      				val_mac[i]= 1;
      		}
      	}
      	for(lld i = 1; i <= n; i += 1)
      		cout << val_mac[i] << " ";
      }
      else
      	cout << "-1";
      return 0;
}