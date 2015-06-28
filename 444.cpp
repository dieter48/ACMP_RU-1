#include<iostream>
#include<vector>
#include<algorithm>
#define vi vector<int>
using namespace std;

int main(){
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	int n, t;
	fscanf(inp, "%d", &n);
	vi a = vi(n);
	for (int i = 0; i < n; i++)
	{
		fscanf(inp, "%d", &t);
		a[i] = t;
	}
	sort(a.begin(), a.end());
	for (vi::iterator i = a.begin(); i != a.end();)
	{
		if (i != a.begin()) fprintf(outp, ", ");
		while ( (i+1) != a.end() && *i == *(i + 1)) i++;
		vi::iterator j = i;
		t = 0;
		while ((j + 1) != a.end() && ((*(j + 1) - *j) < 2)) {
			if (!(*(j + 1) == *j)) t++;
			j++;
		}
		if (t > 2 || t > 1 && (*(i + 1) > 999 || *(i + 1) < -99)){
			fprintf(outp, "%d, ..., %d", *i, *j);
			i = j + 1;
		}
		else fprintf(outp, "%d", *i++);
	}
	fclose(outp);
	return 0;
}