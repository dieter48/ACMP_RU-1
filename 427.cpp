#include<iostream>
#include<algorithm>
#include<vector>
#define vi vector<unsigned long long>
#define it vi::iterator
using namespace std;

int main(){
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	unsigned long long int n;
	fscanf(inp, "%llu", &n);
	vi nmb = vi(n);
	for (it i = nmb.begin(); i != nmb.end(); i++) {
		fscanf(inp, "%lu", &n);
		*i = n;
	}
	sort(nmb.begin(), nmb.end());
	n = 1;
	for (it i = nmb.begin(); i != nmb.end();) {
		if (*i != n) { fprintf(outp, "%llu\n", n); return 0;}
		while (i != nmb.end() && *i <= n) {
			n += *i;
			i++;
		}
	}
	fprintf(outp, "%llu\n",n);
	fclose(outp);
	return 0;
}