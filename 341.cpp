#include<iostream>
using namespace std;

int main(){
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	int n;
	int def[] = {0,1,2,3,4,5,6,7,8,9,10,22,30,41,50,61,70,81,90,111};
	fscanf(inp, "%d", &n);
	
	if (n <= 20) fprintf(outp, "%d\n", def[n - 1]);
	else {
		n -= 21;
		fprintf(outp, "%d",n % 8 + 2);
		for (int i = 0; i < (n / 8 + 2); i++)
			fprintf(outp, "%d", n % 2);
	}
	fclose(outp);
	return 0;
}