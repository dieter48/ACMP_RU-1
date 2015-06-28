#include<iostream>
#include<vector>
#include<algorithm>
#define vi vector<int>
using namespace std;

int main(){
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	int n, l, t;
	fscanf(inp, "%d %d", &l, &n);
	vi a = vi(n);
	for (int i = 0; i < n; i++)
	{
		fscanf(inp, "%d", &t);
		a[i] = t;
	}
	sort(a.begin(), a.end());
	for (vi::iterator i = a.begin(); i != a.end();)
	{
		t = *i + 2 * l;
		while (i != a.end() && *i <= t) {
			n--;
			i++;
		}
		n++;
	}
	fprintf(outp, "%d\n", n);
	fclose(outp);
	return 0;
}