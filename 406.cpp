#include<iostream>
#define N 26
using namespace std;

int main(){
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	int n, m;
	double p[N];
	int q[N];
	for (int i = 0; i < N; i++) q[i] = 0;
	char ans[N];
	fscanf(inp, "%d %d\n", &n, &m);
	for (int i = 0; i < n; i++) fscanf(inp, "%*c %lf\n", p + i);
	for (int i = 0; i < m; i++) q[getc(inp) - 'a']++;
	for (int i = 0; i < n; i++){
		int mxp = 0, mxq = 0;
		for (int j = 0; j < n; j++) 
			if (p[j] > p[mxp]) mxp = j;
		p[mxp] = -1;
		for (int j = 0; j < N; j++) 
			if (q[j] > q[mxq]) mxq = j;
		q[mxq] = -1;
		ans[mxp] = (char)mxq + 'a';
	}
	for (int i = 0; i < n; i++) fprintf(outp, "%c\n", ans[i]);
	fclose(outp);
	return 0;
}