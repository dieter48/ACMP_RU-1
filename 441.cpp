#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef unsigned long long  ll;
typedef vector<long> vi;
typedef vector<pair<long,long>> vp;
typedef vector<pair<long, long>>::iterator vpi;
typedef vector<long>::iterator it;

ll inv(const it b, const it e){
	if (distance(b, e) <= 1) return 0;
	it q = b + (distance(b, e)) / 2;
	ll cnt = 0;
	cnt = inv(b, q);
	cnt += inv(q, e);
	vi L(b, q);
	vi R(q, e);
	it l = L.begin();
	it r = R.begin();
	for (it i = b; i != e; i++){
		if (l == L.end())  *i = *r++; else 
		if (r == R.end() || *l <= *r)   *i = *l++; else
		{
			cnt += distance(l, L.end());
			*i = *r++;
		}
	}
	return cnt;
}

vpi bin_s(const vpi b, const vpi e, long s){
	vpi l = b, r = e;
	while (l != r){
		vpi q = l + (distance(l, r)) / 2;
		if (q->first < s || q->first == s && q->second == -1) l = q + 1; else
		if (q->first > s || q->first == s && q->second != -1) r = q;
	}
	if (l != e && l->first == s) return l;
	return e;
}
int main(){
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	long n, t;
	ll ans;
	vpi q;
	fscanf(inp, "%d", &n);
	vp a = vp(n);
	vi b = vi(n);
	for (int i = 0; i < n; i++)
	{
		fscanf(inp, "%d", &t);
		a[i] = pair<long,long>(t,i);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		fscanf(inp, "%d", &t);
		q = bin_s(a.begin(), a.end(), t);
		if (q == a.end()) { fprintf(outp, "-1"); return 0;}
		b[i] = q->second;
		q->second = -1;
	}
	ans = inv(b.begin(), b.end());
	fprintf(outp, "%llu\n", ans);
	return 0;
}