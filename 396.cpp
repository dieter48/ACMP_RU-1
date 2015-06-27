#include<iostream>
#include<algorithm>
#include<vector>
#define vi vector<int>
#define pii pair<int,int> 
#define vpi vector<pii> 
#define ivi vi::iterator 
#define ivp vpi::iterator 
using namespace std;

int main(){
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	int n, m, r1, r2;
	fscanf(inp, "%d %d\n", &n, &m);
	n *= 2;
	vpi points = vpi(m + n);
	vi ans = vi(m);
	for (int i = 1; i <= n; i++){
		fscanf(inp, "%d %d ", &r1, &r2);
		if (r1 > r2) swap(r1, r2);
		points[i - 1] = pii(r1, -1);
		points[i++] = pii(r2 + 1, -2);
	}
	for (int i = 0; i < m; i++){
		fscanf(inp, "%d", &r1);
		points[i + n] = pii(r1,i);
	}
	fclose(inp);
	sort(points.begin(), points.end());
	n = 0;
	for (ivp i = points.begin(); i != points.end(); i++){
		switch (i->second)
		{
		case -1: n++; break;
		case -2: n--; break;
		default: ans[i->second] = n;
			break;
		}
	}
	for (ivi i = ans.begin(); i != ans.end(); i++) fprintf(outp, "%d ", *i);
	fprintf(outp, "\n");
	fclose(outp);
	return 0;
}