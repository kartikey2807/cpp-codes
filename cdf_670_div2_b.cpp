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
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld n;
      	cin >> n;
      	lld A[n];
      	for(lld i = 0; i < n; i += 1){
      		cin >> A[i];
      	}
      	sort(A,A+n);
      	vector <lld> neg, pos;
      	for(lld i = 0; i < n; i += 1){
      		if (A[i] < 0)
      			neg.pb(A[i]);
      		else  pos.pb(A[i]);
      	}
      	// 5,0// 4,1 // 3,2
     		lld x = 5;
     		lld y = 0;
     		vector <lld> ans;
     		while(x > -1){
     			if (pos.size() >= x && neg.size() >= y){
     				lld prod = 1;
     				lld cnt1 = 0;
     				lld cnt2 = 0;
     				lld cnt3 = 0;
     				for(lld i = pos.size()-1; i >= 0; i -= 1){
     					if (cnt1 == x)
     						break;
     					prod*=pos[i];
     					cnt1++;
     				}
     				lld prod_n1 = 1;
     				lld prod_n2 = 1;
     				for(lld i = neg.size()-1; i >= 0; i -= 1){
     					if (cnt2 == y)
     						break;
     					prod_n1*=neg[i];
     					cnt2++;
     				}
     				for(lld i = 0; i < neg.size(); i += 1){
     					if (cnt3 == y)
     						break;
     					prod_n2*=neg[i];
     					cnt3++;
     				}
     				ans.pb(prod*max(prod_n2,prod_n1));
     			}
     			x--;
     			y++;
     		}
     		lld poop = MIN;
     		for(lld i = 0; i < ans.size(); i += 1){
     			poop = max(poop,ans[i]);
     		}
     		cout << poop << "\n";
      }
      return 0;
}