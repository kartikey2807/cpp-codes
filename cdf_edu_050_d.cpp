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
      lld n, m;
      cin >> n; lld A[n];
      lld sum1 = 0, sum2 = 0;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	sum1+= A[i];
      }
      cin >> m; lld B[m];
      for(lld i = 0; i < m; i += 1){
      	cin >> B[i];
      	sum2+= B[i];
      }
      if (sum1 != sum2)
      	{cout << "-1";return 0;}
      lld i = 0, j = 0, acc1 = 0, acc2 = 0, cnt = 0;
      while(true){
      	if (acc1 == 0 && acc2 == 0){
      		acc1+= A[i];
      		acc2+= B[j];
      		i++; j++;
      	}
      	if (acc1 == acc2){
      		cnt++;
      		acc1 = 0;
      		acc2 = 0;
      		if (i == n && j == m)
      			break;
      	}
      	else{
      		if (acc1 < acc2){
      			while(acc1 < acc2){
      				acc1+= A[i];
      				i++;
      			}
      		}
      		else{
      			while(acc2 < acc1){
      				acc2+= B[j];
      				j++;
      			}
      		}
      	}
      }
      cout << cnt;
      return 0;
}