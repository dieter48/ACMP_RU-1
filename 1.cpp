#include<iostream>
using namespace std;
int main(){
	long a, b;
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	fscanf(inp, "%ld %ld", &a, &b);
	fprintf(outp, "%ld\n", a + b);
	return 0;
}