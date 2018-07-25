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

void Mi() {
	M();
	M();
	M();
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

void Ei() {
	E();
	E();
	E();
}

void S() {
	char temp;

	//middle edges 1
	temp = cube[0][3];
	cube[0][3] = cube[5][7];
	cube[5][7] = cube[1][5];
	cube[1][5] = cube[4][1];
	cube[4][1] = temp;

	//middle edges 2
	temp = cube[0][5];
	cube[0][5] = cube[5][1];
	cube[5][1] = cube[1][3];
	cube[1][3] = cube[4][7];
	cube[4][7] = temp;

	//middle middles
	temp = cube[0][4];
	cube[0][4] = cube[5][4];
	cube[5][4] = cube[1][4];
	cube[1][4] = cube[4][4];
	cube[4][4] = temp;
}

void Si() {
	S();
	S();
	S();
}

void u() {
	U();
	Ei();
}

void ui() {
	Ui();
	E();
}

void l() {
	L();
	M();
}

void li() {
	Li();
	Mi();
}

void f() {
	F();
	S();
}

void fi() {
	Fi();
	Si();
}

void r() {
	R();
	Mi();
}

void ri() {
	Ri();
	M();
}

void b() {
	B();
	Si();
}

void bi() {
	Bi();
	S();
}

void d() {
	D();
	E();
}

void di() {
	Di();
	Ei();
}

void X() {
	R();
	Li();
	Mi();
}

void Xi() {
	Ri();
	L();
	M();
}

void Y() {
	U();
	Di();
	Ei();
}

void Yi() {
	Ui();
	D();
	E();
}

void Z() {
	F();
	S();
	Bi();
}

void Zi() {
	Fi();
	Si();
	B();
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
				else if(ch2 == 'M') {
					printf("M\'\n");
					Mi();
					display();
				}
				else if(ch2 == 'E') {
					printf("E\'\n");
					Ei();
					display();
				}
				else if(ch2 == 'S') {
					printf("S\'\n");
					Si();
					display();
				}
				else if(ch2 == 'X') {
					printf("X\'\n");
					Xi();
					display();
				}
				else if(ch2 == 'Y') {
					printf("Y\'\n");
					Yi();
					display();
				}
				else if(ch2 == 'Z') {
					printf("Z\'\n");
					Zi();
					display();
				}
				else if(ch2 == 'u') {
					printf("u\'\n");
					ui();
					display();
				}
				else if(ch2 == 'l') {
					printf("l\'\n");
					li();
					display();
				}
				else if(ch2 == 'f') {
					printf("f\'\n");
					fi();
					display();
				}
				else if(ch2 == 'r') {
					printf("r\'\n");
					ri();
					display();
				}
				else if(ch2 == 'b') {
					printf("b\'\n");
					bi();
					display();
				}
				else if(ch2 == 'd') {
					printf("d\'\n");
					di();
					display();
				}
			}
			else if(ch1 == '2') {
				if(ch2 == 'U') {
					printf("U2\n");
					U();
					U();
					display();
				}
				else if(ch2 == 'L') {
					printf("L2\n");
					L();
					L();
					display();
				}
				else if(ch2 == 'F') {
					printf("F2\n");
					F();
					F();
					display();
				}
				else if(ch2 == 'R') {
					printf("R2\n");
					R();
					R();
					display();
				}
				else if(ch2 == 'B') {
					printf("B2\n");
					B();
					B();
					display();
				}
				else if(ch2 == 'D') {
					printf("D2\n");
					D();
					D();
					display();
				}
				else if(ch2 == 'M') {
					printf("M2\n");
					M();
					M();
					display();
				}
				else if(ch2 == 'E') {
					printf("E2\n");
					E();
					E();
					display();
				}
				else if(ch2 == 'S') {
					printf("S2\n");
					S();
					S();
					display();
				}
				else if(ch2 == 'X') {
					printf("X2\n");
					X();
					X();
					display();
				}
				else if(ch2 == 'Y') {
					printf("Y2\n");
					Y();
					Y();
					display();
				}
				else if(ch2 == 'Z') {
					printf("Z2\n");
					Z();
					Z();
					display();
				}
				else if(ch2 == 'u') {
					printf("u\n");
					u();
					u();
					display();
				}
				else if(ch2 == 'l') {
					printf("l\n");
					l();
					l();
					display();
				}
				else if(ch2 == 'f') {
					printf("f\n");
					f();
					f();
					display();
				}
				else if(ch2 == 'r') {
					printf("r\n");
					r();
					r();
					display();
				}
				else if(ch2 == 'b') {
					printf("b\n");
					b();
					b();
					display();
				}
				else if(ch2 == 'd') {
					printf("d\n");
					d();
					d();
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
			else if(ch1 == 'M') {
				printf("M\n");
				M();
				display();
			}
			else if(ch1 == 'E') {
				printf("E\n");
				E();
				display();
			}
			else if(ch1 == 'S') {
				printf("S\n");
				S();
				display();
			}
			else if(ch1 == 'X') {
				printf("X\n");
				X();
				display();
			}
			else if(ch1 == 'Y') {
				printf("Y\n");
				Y();
				display();
			}
			else if(ch1 == 'Z') {
				printf("Z\n");
				Z();
				display();
			}
			else if(ch1 == 'u') {
				printf("u\n");
				u();
				display();
			}
			else if(ch1 == 'l') {
				printf("l\n");
				l();
				display();
			}
			else if(ch1 == 'f') {
				printf("f\n");
				f();
				display();
			}
			else if(ch1 == 'r') {
				printf("r\n");
				r();
				display();
			}
			else if(ch1 == 'b') {
				printf("b\n");
				b();
				display();
			}
			else if(ch1 == 'd') {
				printf("d\n");
				d();
				display();
			}
		}
	}

	fclose(fp);

	return 0;
}