#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
   	lld t;
   	cin >> t;
   	while(t--)
   	{
   		string a;
   		string b;
   		cin >> a >> b;
   		set <string> vis;
   		lld a_len = a.size();
   		lld b_len = b.size();
   		for(lld i = 0; i < a_len; i += 1)
   		{
   			string temp = "";
   			for(lld j = i; j < a_len; j += 1)
   			{
   				temp += a[j];
   				vis.insert(temp);
   			}
   		}
   		lld ans = MIN;
   		for(lld i = 0; i < b_len; i += 1)
   		{
   			string temp = "";
   			for(lld j = i; j < b_len; j += 1)
   			{
   				temp += b[j];
   				if (vis.count(temp))
   				{
   					if ((j-i+1) > ans)
   						ans = j-i+1;
   				}
   			}
   		}
   		cout << (a_len-ans) + (b_len-ans) << "\n";
   	}
    return 0;
}