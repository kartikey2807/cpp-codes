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
      lld n, m;
      cin >> n >> m;
      lld dda[n][m];
      for(lld i = 0; i < n; i += 1){
      	for(lld j = 0; j < m; j += 1){
      		cin >> dda[i][j];
      	}
      }
      lld val = 0;
      for(lld i = 0; i < n; i += 1){
      	val = val xor dda[i][0];
      }
      if (val != 0){
      	cout << "TAK\n";
      	for(lld i = 0; i < n; i += 1){
      		cout << "1 ";
      	}
      }
      else{
      	for(lld i = 0; i < n; i += 1){
      		lld temp  = val xor dda[i][0];
      		for(lld j = 0; j < m; j += 1){
      			if ((temp xor dda[i][j]) > 0){
      				cout << "TAK\n";
      				for(lld k = 0; k < n; k += 1){
      					if (k == i) cout << j+1 << " ";
      					else cout << "1 ";
      				}
      				return 0;
      			}
      		}
      	}
      	cout << "NIE\n";
      }
      return 0;
}