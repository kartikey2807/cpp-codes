// didn't get the problem right, whenever you sort you put the elements in their correct positions so they can be forgotten
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
      lld pos = 1, cnt = 0;
      stack <lld> stk;
      for(lld i = 0; i < (2*n); i += 1){
      	string s;
      	cin >> s;
      	if (s == "add"){
      		lld x;
      		cin >> x;
      		stk.push(x);
      	}
      	else{
      		if (!stk.empty()){
      			if (stk.top() == pos){
      				stk.pop();
      			}
      			else{
      				cnt++;
      				while(!stk.empty())
      					stk.pop();
      			}
      		}
      		pos++;
      	}
      }
      cout << cnt;
      return 0;
}