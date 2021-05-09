// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA. For heaven's sake do
// not see standings in middle of the contest
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
      lld q;
      cin >> q;
      while(q--){
      	lld n;
      	string s, t;
      	cin >> n >> s >> t;
      	map <char, lld> cnt;
      	for(lld i = 0; i < n; i += 1){
      		if (s[i] != t[i])
      			{cnt[s[i]]++; cnt[t[i]]++;}
      	}
      	lld f = 1;
      	for(char a = 'a'; a <= 'z'; a++)
      		if (cnt[a]%2 != 0)
      			f = 0;
      	if (f == 0){
      		cout << "No\n";
      	}
      	else{
      		vector <pair <lld, lld> > orz;
      		for(lld i = 0; i < n; i += 1){
      			if (t[i] != s[i]){
      				lld pos = -1;
      				for(lld j = i+1; j < n; j += 1){
      					if (s[j] == s[i]){
      						pos=j;
      						break;
      					}
      				}
      				if (pos != -1){
      					orz.pb(make_pair(pos,i));
      					swap(s[pos],t[i]);
      				}
      				else
      				{
      					lld pos;
      					for(lld j = i; j < n; j += 1){
      						if (t[j] == s[i]){
      							pos=j;
      							break;
      						}
      					}
      					orz.pb(make_pair(i,i));
      					orz.pb(make_pair(i,pos));
      					swap(s[i],t[i]);
      					swap(s[i],t[pos]);
      				}
      			}
      		}
      		if (orz.size() <= (2*n))
      		{
      			cout <<"Yes\n";
      			cout << orz.size() << "\n";
      			for(lld i = 0; i < orz.size(); i += 1)
      				cout << orz[i].first+1 << " " << orz[i].second+1 << "\n";
      		}
      		else{
      			cout << "No\n";
      		}
      	}
      }
      return 0;
}