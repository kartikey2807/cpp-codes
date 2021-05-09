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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld m = (n-1)/2;
      lld dda[n][n];
      if (m % 2 == 0){
      	for(lld i = 0; i < n; i += 1){
      		for(lld j = 0; j < n; j += 1){
      			dda[i][j] = -1;
      		}
      	}
      	lld k = n*n;
      	for(lld j = 0; j < n; j += 1){
      		dda[n/2][j] = k;
      		k -= 2;
      	}
      	for(lld i = 0; i < n; i += 1){
      		if (dda[i][0] == -1){
      			dda[i][0] = k;
      			k -= 2;
      		}
      	}
      	lld a = n/2-1, b = n/2+1;
      	while((k+1)/2 >= n){
      		for(lld j = 1; j < n; j += 1){
      			dda[a][j] = k;
      			k -= 2;
      		}
      		for(lld j = 1; j < n; j += 1){
      			dda[b][j] = k;
      			k -= 2;
      		}
      		a--;
      		b++;
      	}
      	for(lld j = n-1; j > n/2; j -= 1) {dda[0][j] = k; k -= 2;}
      	for(lld j = n-1; j > n/2; j -= 1) {dda[n-1][j]=k; k -= 2;}
      	lld x = 2;
      	for(lld i = 0; i < n; i += 1){
      		for(lld j = 0; j < n; j += 1){
      			if (dda[i][j] == -1){
      				dda[i][j] = x;
      				x += 2;
      			}
      		}
      	}
      }
      else{
      	for(lld i = 0; i < n; i += 1){
      		for(lld j = 0; j < n; j += 1){
      			dda[i][j] = -1;
      		}
      	}
      	lld k = n*n;
      	for(lld j = 0; j < n; j += 1){
      		dda[n/2][j] = k;
      		k -= 2;
      	}
      	lld a = n/2-1, b = n/2+1;
      	while((k+1)/2 >= n){
      		for(lld j = 0; j < n; j += 1){
      			dda[a][j] = k;
      			k -= 2;
      		}
      		for(lld j = 0; j < n; j += 1){
      			dda[b][j] = k;
      			k -= 2;
      		}
      		a--;
      		b++;
      	}
      	for(lld i = 0; i < n; i += 1){
      		if (dda[i][n/2]  == -1){
      			dda[i][n/2] = k;
      			k -= 2;
      		}
      	}
      	lld x = 2;
      	for(lld i = 0; i < n; i += 1){
      		for(lld j = 0; j < n; j += 1){
      			if (dda[i][j] == -1){
      				dda[i][j] = x;
      				x += 2;
      			}
      		}
      	}
      }
      foi(i,n){
      	foi(j,n){
      		cout << dda[i][j] << " ";
      	}
      	cout << "\n";
      }
      return 0;
}