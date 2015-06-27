#include<iostream>
#define N 101
using namespace std;

int main(){
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	int n, t, mx = 0;
	int a[N], l[N];
	for (int i = 0; i < N; i++) {
		a[i] = -1;
		l[i] = 0;
	}
	fscanf(inp, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(inp, "%d", &t);
		if (a[t] >= 0 && l[t] < (i - a[t])) {
			l[t] = i - a[t];
			if (l[t] > mx) mx = l[t];
		}
		a[t] = i;
	}
	fprintf(outp, "%d\n", mx);
	fclose(outp);
	return 0;
}