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
      lld n;
      string s;
      cin >> n >> s;
      vector <char> type;
      vector <pair <lld, lld> > med;
      for(lld i = 0; i < n; i += 1){
      	if (s[i] == 'G'){
      		lld start = i, end = n-1;
      		for(lld j = i; j < n; j += 1){
      			if (s[j] != 'G'){
      				end = j-1;
      				break;
      			}
      		}
      		med.pb(make_pair(start, end));
      		type.pb('G'); i = end;
      	}
      	else{
      		lld start = i, end = n-1;
      		for(lld j = i; j < n; j += 1){
      			if (s[j] != 'S'){
      				end = j-1;
      				break;
      			}
      		}
      		med.pb(make_pair(start, end));
      		type.pb('S'); i = end;
      	}
      }
      lld cnt_g = 0, cnt_s = 0;
      for(lld i = 0; i < med.size(); i += 1){
      	if (type[i] == 'G')
      		cnt_g ++;
      	if (type[i] == 'S')
      		cnt_s ++;
      }
      if (cnt_s == 0)
      	{cout << n; return 0;}
      if (cnt_g == 0)
      	{cout<<"0"; return 0;}

      lld ans = MIN;
      lld cnt = 0;
      lld L = med.size();
      for(lld i = 0; i < med.size(); i += 1){
      	if (type[i] == 'S'){
      		if (med[i].first == med[i].second){
      			if (i == 0){
      				lld len = med[i+1].second-med[i+1].first+1;
      				if (cnt_g > 1)
      					len++;
      				ans = max(ans, len);
      			}
      			else{
      				if (i == L-1){
      					lld len = med[i-1].second-med[i-1].first+1;
      					if (cnt_g > 1)
      						len++;
      					ans = max(ans, len);
      				}
      				else{
      					lld len1= med[i-1].second-med[i-1].first+1;
      					lld len2= med[i+1].second-med[i+1].first+1;
      					lld len = len1+len2;
      					if (cnt_g > 2)
      						len++;
      					ans = max(ans, len);
      				}
      			}
      		}
      		else{
      			lld len1, len2;
      			if (i == 0){
      				len1 = MIN;
      				len2 = med[i+1].second-med[i+1].first+1;
      			}
      			else{
      				if (i == L-1){
      					len2 = MIN;
      					len1 = med[i-1].second-med[i-1].first+1;
      				}
      				else{
      					len1 = med[i-1].second-med[i-1].first+1;
      					len2 = med[i+1].second-med[i+1].first+1;
      				}
      			}
      			lld len = max(len1, len2);
      			if (cnt_g > 1)
      				len++;
      			ans = max(ans, len);
      		}
      	}
      }
      cout << ans;
      return 0;
}