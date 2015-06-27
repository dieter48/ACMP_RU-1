#include<iostream>
using namespace std;

int main(){
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	int n, k, l = 0, in = 1, ik = 1;
	fscanf(inp, "%d %d", &n, &k);
	for (; in <= n; in *= 10); in /= 10;
	for (; ik <= k; ik *= 10); ik /= 10;
	for (int t = ik; t < in; t *= 10) k *= 10;
	if (k > n) l += n - in + 1;
	else l += k - ik;
	k /= 10;
	in /= 10;
	while (k){
		l += k - in + (in < ik);
		k /= 10;
		in /= 10;
	}
	fprintf(outp, "%d\n", l+1);
	fclose(outp);
	return 0;
}