#include<stdio.h>

FILE *fp;

char cube[6][9] = {
	{'W', 'W', 'W', 'W', 'W', 'W'},//top
	{'Y', 'Y', 'Y', 'Y', 'Y', 'Y'},//bottom
	{'R', 'R', 'R', 'R', 'R', 'R'},//front
	{'O', 'O', 'O', 'O', 'O', 'O'},//back
	{'B', 'B', 'B', 'B', 'B', 'B'},//right
	{'G', 'G', 'G', 'G', 'G', 'G'} //left
};

int main(int argc, char *argv[]) {
	printf("%s\n", argv[1]);
	fp = fopen(argv[1], "r");

	if(fp == NULL) {
		printf("Cannot open file\n");
		return 0;
	}

	char ch;

	while(!feof(fp)) {
		ch = fgetc(fp);

		if(ch == ' ' || feof(fp)) {

		} 

		printf("%c", ch);
	}

	fclose(fp);
	return 0;
}