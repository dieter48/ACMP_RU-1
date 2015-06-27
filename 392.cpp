#include<iostream>
using namespace std;

int main(){
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	int n, a[100000], s;
	fscanf(inp, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(inp, "%d", a + i);
		if (a[i] == 1) s = i;
	}
	for (int i = 0; i < n; i++) fprintf(outp, "%d ", a[(s + i) % n]);
	fprintf(outp, "\n");
	fclose(outp);
	return 0;
}