#include<iostream>
#define N 201
using namespace std;

int main(){
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	int n, cnt, mx = 0;
	int a[N], b[N];
	for (int i = 0; i < N; i++) a[i] = 0;
	fscanf(inp, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(inp, "%d", b + i);
		a[b[i] + 100]++;
		if (a[mx] < a[b[i] + 100] || a[mx] == a[b[i] + 100] && (b[i] + 100) < mx) mx = b[i] + 100;
	}
	mx -= 100;
	cnt = 0;
	for (int i = 0; i < n; i++) 
	if (b[i] == mx) cnt++;
	else fprintf(outp, "%d ", b[i]);
	while (cnt--) fprintf(outp, "%d ", mx);
	fclose(outp);
	return 0;
}