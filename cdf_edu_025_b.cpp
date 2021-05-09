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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      // READ UPPER CLAUSE
      lld n = 10;
      char dda[n][n];
      for(lld i = 0; i < n; i += 1){
      	for(lld j = 0; j < n; j += 1){
      		cin >> dda[i][j];
      	}
      }
      lld f = 0;
      for(lld i = 0; i < n; i += 1){
      	for(lld j = 0; j < n; j += 1){
      		if (dda[i][j] != '.')
      			continue;
      		dda[i][j] = 'X';
      		for(lld temp_i = 0; temp_i < n; temp_i += 1){
      			for(lld temp_j = 0; temp_j < n; temp_j += 1){
      				// temp_i, temp_j
      				lld ans = 0;
      				lld cnt = 0;
      				for(lld start = temp_j; start < min((lld)n,temp_j+5); start += 1){
      					if (dda[temp_i][start] == 'X')
      						cnt++;
      				}
      				ans = max(ans,cnt);
      				cnt = 0;
      				for(lld start = temp_j; start >= max(temp_j-4,(lld)0);start -= 1){
      					if (dda[temp_i][start] == 'X')
      						cnt++;
      				}
      				ans = max(ans,cnt);
      				cnt = 0;
      				for(lld start = temp_i; start < min(temp_i+5,(lld)n); start += 1){
      					if (dda[start][temp_j] == 'X')
      						cnt++;
      				}
      				ans = max(ans,cnt);
      				cnt = 0;
      				for(lld start = temp_i; start >= max(temp_i-4,(lld)0);start -= 1){
      					if (dda[start][temp_j] == 'X')
      						cnt++;
      				}
      				ans = max(ans,cnt);
      				// -----------*----------------------
      				cnt = 0;
      				lld start_x = temp_i;
      				lld start_y = temp_j;
      				while(start_x < min(temp_i+5,(lld)n) && start_y <min(temp_j+5,n)){
      					if (dda[start_x][start_y] == 'X')
      						cnt++;
      					start_x+= 1;
      					start_y+= 1;
      				}
      				ans = max(ans,cnt);
      				cnt = 0;
      				start_x = temp_i;
					start_y = temp_j;
      				while(start_x < min(temp_i+5,n) && start_y>=max((lld)0,temp_j-4)){
      					if (dda[start_x][start_y] == 'X')
      						cnt++;
      					start_x+= 1;
      					start_y-= 1;
      				}
      				ans = max(ans,cnt);
      				cnt = 0;
      				start_x = temp_i;
					start_y = temp_j;
      				while(start_x>=max(temp_i-4,(lld)0) && start_y < min(temp_j+5,n)){
      					if (dda[start_x][start_y] == 'X')
      						cnt++;
      					start_x-= 1;
      					start_y+= 1;
      				}
      				ans = max(ans,cnt);
      				cnt = 0;
      				start_x = temp_i;
					start_y = temp_j;
					while(start_x>= max(temp_i-4,(lld)0) && start_y>=max(temp_j-4,(lld)0)){
						if (dda[start_x][start_y] == 'X')
							cnt++;
						start_x-= 1;
						start_y-= 1;
					}
					ans = max(ans,cnt);
					if (ans >= 5)
						f = 1;
      			}
      		}
      		dda[i][j] = '.';
      	}
      }
      if (f == 1) cout << "YES";
      else cout << "NO";
      return 0;
}