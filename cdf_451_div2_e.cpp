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
lld change (lld num)
{
	lld low = (lld)sqrt(num);
	lld upp = low+1;
	return min(abs(num-(low*low)),abs(num-(upp*upp)));
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      lld cnt = 0;
      for(lld i = 0; i < n; i += 1){
      	dbl x = sqrt(A[i]);
      	if (x == floor(x)){
      		cnt++;
      	}
      }
      if (cnt < (n/2)){
      	vector <lld> moves;
      	for(lld i = 0; i < n; i += 1){
      		dbl x = sqrt(A[i]);
      		if (x != floor(x)){
      			moves.pb(change(A[i]));
      		}
      	}
      	sort(moves.begin(),moves.end());
      	lld sum = 0;
      	for(lld i = 0; i < moves.size(); i += 1){
      		if (cnt == (n/2))
      			break;
      		sum += moves[i];
      		cnt++;
      	}
      	cout << sum;
      }
      else{
      	vector <lld> moves;
      	for(lld i = 0; i < n; i += 1){
      		dbl x = sqrt(A[i]);
      		if (x == floor(x)){
      			if (A[i]==0) moves.pb(2);
      			else moves.pb(1);
      		}
      	}
      	sort(moves.begin(),moves.end());
      	lld sum = 0;
      	for(lld i = 0; i < moves.size(); i += 1){
      		if (cnt == (n/2))
      			break;
      		sum += moves[i];
      		cnt--;
      	}
      	cout << sum;
      }
      return 0;
}