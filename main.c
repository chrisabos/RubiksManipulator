#include<stdio.h>

FILE *fp;

char cube[6][9] = {
	{'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},//up
	{'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'},//down
	{'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'},//front
	{'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},//back
	{'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},//right
	{'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'} //left
};

void U() {
	char temp;

	//upper corners
	temp = cube[0][0];
	cube[0][0] = cube[0][6];
	cube[0][6] = cube[0][8];
	cube[0][8] = cube[0][2];
	cube[0][2] = temp;

	//upper edges
	temp = cube[0][1];
	cube[0][1] = cube[0][3];
	cube[0][3] = cube[0][7];
	cube[0][7] = cube[0][5];
	cube[0][5] = temp;

	//sides corner 1
	temp = cube[3][0];
	cube[3][0] = cube[5][0];
	cube[5][0] = cube[2][0];
	cube[2][0] = cube[4][0];
	cube[4][0] = temp;

	//sides corner 2
	temp = cube[3][2];
	cube[3][2] = cube[5][2];
	cube[5][2] = cube[2][2];
	cube[2][2] = cube[4][2];
	cube[4][2] = temp;

	//sides edges
	temp = cube[3][1];
	cube[3][1] = cube[5][1];
	cube[5][1] = cube[2][1];
	cube[2][1] = cube[4][1];
	cube[4][1] = temp;
}

void Ui() {
	U();
	U();
	U();
}

void L() {
	char temp;

	//upper corners
	temp = cube[5][0];
	cube[5][0] = cube[5][6];
	cube[5][6] = cube[5][8];
	cube[5][8] = cube[5][2];
	cube[5][2] = temp;

	//upper edges
	temp = cube[5][1];
	cube[5][1] = cube[5][3];
	cube[5][3] = cube[5][7];
	cube[5][7] = cube[5][5];
	cube[5][5] = temp;

	//sides corner 1
	temp = cube[0][0];
	cube[0][0] = cube[3][8];
	cube[3][8] = cube[1][0];
	cube[1][0] = cube[2][0];
	cube[2][0] = temp;

	//sides corner 2
	temp = cube[0][6];
	cube[0][6] = cube[3][2];
	cube[3][2] = cube[1][6];
	cube[1][6] = cube[2][6];
	cube[2][6] = temp;

	//sides edges
	temp = cube[0][3];
	cube[0][3] = cube[3][5];
	cube[3][5] = cube[1][3];
	cube[1][3] = cube[2][3];
	cube[2][3] = temp;
}

void Li() {
	L();
	L();
	L();
}

void F() {
	char temp;
	
	//front corners
	temp = cube[2][0];
	cube[2][0] = cube[2][6];
	cube[2][6] = cube[2][8];
	cube[2][8] = cube[2][2];
	cube[2][2] = temp;

	//front edges
	temp = cube[2][1];
	cube[2][1] = cube[2][3];
	cube[2][3] = cube[2][7];
	cube[2][7] = cube[2][5];
	cube[2][5] = temp;

	//sides corner 1
	temp = cube[0][6];
	cube[0][6] = cube[5][8];
	cube[5][8] = cube[1][2];
	cube[1][2] = cube[4][0];
	cube[4][0] = temp;

	//sides corner 2
	temp = cube[0][8];
	cube[0][8] = cube[5][2];
	cube[5][2] = cube[1][0];
	cube[1][0] = cube[4][6];
	cube[4][6] = temp;

	//sides edge
	temp = cube[0][7];
	cube[0][7] = cube[5][5];
	cube[5][5] = cube[1][1];
	cube[1][1] = cube[4][3];
	cube[4][3] = temp;
}

void Fi() {
	F();
	F();
	F();
}

void R() {
	char temp;
	
	//right corners
	temp = cube[4][0];
	cube[4][0] = cube[4][6];
	cube[4][6] = cube[4][8];
	cube[4][8] = cube[4][2];
	cube[4][2] = temp;

	//right edges
	temp = cube[4][1];
	cube[4][1] = cube[4][3];
	cube[4][3] = cube[4][7];
	cube[4][7] = cube[4][5];
	cube[4][5] = temp;

	//sides corner 1
	temp = cube[0][2];
	cube[0][2] = cube[2][2];
	cube[2][2] = cube[1][2];
	cube[1][2] = cube[3][6];
	cube[3][6] = temp;

	//sides corner 2
	temp = cube[0][8];
	cube[0][8] = cube[2][8];
	cube[2][8] = cube[1][8];
	cube[1][8] = cube[3][0];
	cube[3][0] = temp;

	//sides edges
	temp = cube[0][5];
	cube[0][5] = cube[2][5];
	cube[2][5] = cube[1][5];
	cube[1][5] = cube[3][3];
	cube[3][3] = temp;
}

void Ri() {
	R();
	R();
	R();
}

void B() {
	char temp;

	//back corners
	temp = cube[3][0];
	cube[3][0] = cube[3][6];
	cube[3][6] = cube[3][8];
	cube[3][8] = cube[3][2];
	cube[3][2] = temp;

	//back edges
	temp = cube[3][1];
	cube[3][1] = cube[3][3];
	cube[3][3] = cube[3][7];
	cube[3][7] = cube[3][5];
	cube[3][5] = temp;

	//sides corner 1
	temp = cube[0][0];
	cube[0][0] = cube[4][2];
	cube[4][2] = cube[1][8];
	cube[1][8] = cube[5][6];
	cube[5][6] = temp;

	//sides corner 2
	temp = cube[0][2];
	cube[0][2] = cube[4][8];
	cube[4][8] = cube[1][6];
	cube[1][6] = cube[5][0];
	cube[5][0] = temp;

	//sides edges
	temp = cube[0][1];
	cube[0][1] = cube[4][5];
	cube[4][5] = cube[1][7];
	cube[1][7] = cube[5][3];
	cube[5][3] = temp;
}

void Bi() {
	B();
	B();
	B();
}

void D() {
	char temp;

	//back corners
	temp = cube[1][0];
	cube[1][0] = cube[1][6];
	cube[1][6] = cube[1][8];
	cube[1][8] = cube[1][2];
	cube[1][2] = temp;

	//back edges
	temp = cube[1][1];
	cube[1][1] = cube[1][3];
	cube[1][3] = cube[1][7];
	cube[1][7] = cube[1][5];
	cube[1][5] = temp;

	//sides corner 1
	temp = cube[2][6];
	cube[2][6] = cube[5][6];
	cube[5][6] = cube[3][6];
	cube[3][6] = cube[4][6];
	cube[4][6] = temp;

	//sides corner 2
	temp = cube[2][8];
	cube[2][8] = cube[5][8];
	cube[5][8] = cube[3][8];
	cube[3][8] = cube[4][8];
	cube[4][8] = temp;

	//sides edges
	temp = cube[2][7];
	cube[2][7] = cube[5][7];
	cube[5][7] = cube[3][7];
	cube[3][7] = cube[4][7];
	cube[4][7] = temp;
}

void Di() {
	D();
	D();
	D();
}

void M() {
	char temp;

	//middle edges 1
	temp = cube[0][1];
	cube[0][1] = cube[3][7];
	cube[3][7] = cube[1][1];
	cube[1][1] = cube[2][1];
	cube[2][1] = temp;

	//middle edges 2
	temp = cube[0][7];
	cube[0][7] = cube[3][1];
	cube[3][1] = cube[1][7];
	cube[1][7] = cube[2][7];
	cube[2][7] = temp;

	//middle middles
	temp = cube[0][4];
	cube[0][4] = cube[3][4];
	cube[3][4] = cube[1][4];
	cube[1][4] = cube[2][4];
	cube[2][4] = temp;
}

void E() {
	char temp;

	//middle edges 1
	temp = cube[2][3];
	cube[2][3] = cube[5][3];
	cube[5][3] = cube[3][3];
	cube[3][3] = cube[4][3];
	cube[4][3] = temp;

	//middle edges 2
	temp = cube[2][5];
	cube[2][5] = cube[5][5];
	cube[5][5] = cube[3][5];
	cube[3][5] = cube[4][5];
	cube[4][5] = temp;

	//middle middles
	temp = cube[2][4];
	cube[2][4] = cube[5][4];
	cube[5][4] = cube[3][4];
	cube[3][4] = cube[4][4];
	cube[4][4] = temp;
}

void S() {
	char temp;

	//middle edges 1
	temp = cube[0][3];
	cube[0][3] = cube[][];
	cube[][] = cube[][];
	cube[][] = cube[][];
	cube[][] = temp;

	//middle edges 2
	temp = cube[0][5];
	cube[0][5] = cube[][];
	cube[][] = cube[][];
	cube[][] = cube[][];
	cube[][] = temp;

	//middle middles
	temp = cube[0][4];
	cube[0][4] = cube[][4];
	cube[][4] = cube[][4];
	cube[][4] = cube[][4];
	cube[][4] = temp;
}

void Z() {
	char top[9];
	int i;

	for(i = 0; i < 9; i++) {
		top[i] = cube[0][i];
	}

	cube[0][0] = cube[5][6];
	cube[0][1] = cube[5][3];
	cube[0][2] = cube[5][0];
	cube[0][3] = cube[5][7];
	cube[0][4] = cube[5][4];
	cube[0][5] = cube[5][1];
	cube[0][6] = cube[5][8];
	cube[0][7] = cube[5][5];
	cube[0][8] = cube[5][2];

	cube[5][0] = cube[1][6];
	cube[5][1] = cube[1][3];
	cube[5][2] = cube[1][0];
	cube[5][3] = cube[1][7];
	cube[5][4] = cube[1][4];
	cube[5][5] = cube[1][1];
	cube[5][6] = cube[1][8];
	cube[5][7] = cube[1][5];
	cube[5][8] = cube[1][2];

	cube[1][0] = cube[4][6];
	cube[1][1] = cube[4][3];
	cube[1][2] = cube[4][0];
	cube[1][3] = cube[4][7];
	cube[1][4] = cube[4][4];
	cube[1][5] = cube[4][1];
	cube[1][6] = cube[4][8];
	cube[1][7] = cube[4][5];
	cube[1][8] = cube[4][2];

	cube[4][0] = top[6];
	cube[4][1] = top[3];
	cube[4][2] = top[0];
	cube[4][3] = top[7];
	cube[4][4] = top[4];
	cube[4][5] = top[1];
	cube[4][6] = top[8];
	cube[4][7] = top[5];
	cube[4][8] = top[2];
}

void display() {
	printf("###########################\n");
	printf("\n");
	printf("    %c%c%c\n", cube[0][0], cube[0][1], cube[0][2]);
	printf("    %c%c%c\n", cube[0][3], cube[0][4], cube[0][5]);
	printf("    %c%c%c\n", cube[0][6], cube[0][7], cube[0][8]);
	printf("\n");
	printf("%c%c%c %c%c%c %c%c%c %c%c%c\n", cube[5][0], cube[5][1], cube[5][2],   cube[2][0], cube[2][1], cube[2][2],   cube[4][0], cube[4][1], cube[4][2],   cube[3][0], cube[3][1], cube[3][2]);
	printf("%c%c%c %c%c%c %c%c%c %c%c%c\n", cube[5][3], cube[5][4], cube[5][5],   cube[2][3], cube[2][4], cube[2][5],   cube[4][3], cube[4][4], cube[4][5],   cube[3][3], cube[3][4], cube[3][5]);
	printf("%c%c%c %c%c%c %c%c%c %c%c%c\n", cube[5][6], cube[5][7], cube[5][8],   cube[2][6], cube[2][7], cube[2][8],   cube[4][6], cube[4][7], cube[4][8],   cube[3][6], cube[3][7], cube[3][8]);
	printf("\n");
	printf("    %c%c%c\n", cube[1][0], cube[1][1], cube[1][2]);
	printf("    %c%c%c\n", cube[1][3], cube[1][4], cube[1][5]);
	printf("    %c%c%c\n", cube[1][6], cube[1][7], cube[1][8]);
	printf("\n");
}

int main(int argc, char *argv[]) {
	printf("%s\n", argv[1]);
	fp = fopen(argv[1], "r");

	if(fp == NULL) {
		printf("Cannot open file\n");
		return 0;
	}

	char ch2;
	char ch1;
	char ch;

	while(!feof(fp)) {
		ch2 = ch1;
		ch1 = ch;
		ch = fgetc(fp);

		if(ch == ' ' || feof(fp)) {
			if(ch1 == '\'') {
				if(ch2 == 'U') {
					printf("U\'\n");
					Ui();
					display();
				}
				else if(ch2 == 'L') {
					printf("L\'\n");
					Li();
					display();
				}
				else if(ch2 == 'F') {
					printf("F\'\n");
					Fi();
					display();
				}
				else if(ch2 == 'R') {
					printf("R\'\n");
					Ri();
					display();
				}
				else if(ch2 == 'B') {
					printf("B\'\n");
					Bi();
					display();
				}
				else if(ch2 == 'D') {
					printf("D\'\n");
					Di();
					display();
				}
			}
			else if(ch1 == 'U') {
				printf("U\n");
				U();
				display();
			}
			else if(ch1 == 'L') {
				printf("L\n");
				L();
				display();
			}
			else if(ch1 == 'F') {
				printf("F\n");
				F();
				display();
			}
			else if(ch1 == 'R') {
				printf("R\n");
				R();
				display();
			}
			else if(ch1 == 'B') {
				printf("B\n");
				B();
				display();
			}
			else if(ch1 == 'D') {
				printf("D\n");
				D();
				display();
			}
		} 
	}

	fclose(fp);

	display();
	E();
	display();

	return 0;
}