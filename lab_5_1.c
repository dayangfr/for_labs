#include <stdio.h>


void test_long() {
	printf("test() start!\n");

	unsigned long long  l = 1;
	int i = 0;
	while (l > 0) {
		printf("<%llu (%d)>\n", l, i);
		l *= 2;
		i += 1;
	}
	l--;
	printf("<!!!!%llu (%d)!!!!>\n", l, i);

	printf("test() finish!\n");
}

void test_short() {
	printf("test() start!\n");

	short  s = 1;
	int i = 0;
	while (s > 0) {
		printf("<%d (%d)>\n", s, i);
		s *= 2;
		i += 1;
	}
	s--;
	printf("<!!!!%d (%d)!!!!>\n", s, i);

	printf("test() finish!\n");
}

void test_f_char() {
	printf("test() start!\n");

	int n = 1;
	char 		fact = 1, prevFact = 1;

	while (n < 100) {
		fact = 1;
		int i = 1;
		do {
			fact = fact * i;
			i = i + 1;
		} while (i <= n);

		printf("<%hhi (%d!) %d>\n", fact, n, (fact / prevFact));

		prevFact = fact;

		n += 1;
	}

	printf("test() finish!\n");
}

void test_f_short() {
	printf("test() start!\n");

	int n = 1;
	short 		fact = 1, prevFact = 1;

	while (n < 100) {
		fact = 1;
		int i = 1;
		do {
			fact = fact * i;
			i = i + 1;
		} while (i <= n);

		printf("<%hi (%d!) %d>\n", fact, n, (fact / prevFact));

		prevFact = fact;

		n += 1;
	}

	printf("test() finish!\n");
}

void test_f_int() {
	printf("test() start!\n");

	int n = 1;
	int 			fact = 1, prevFact = 1;

	while (n < 100) {
		fact = 1;
		int i = 1;
		do {
			fact = fact * i;
			i = i + 1;
		} while (i <= n);

		printf("<%i (%d!) %d>\n", fact, n, (fact / prevFact));

		prevFact = fact;

		n += 1;
	}

	printf("test() finish!\n");
}

void test_f_long() {
	printf("main() start!\n");

	int n = 1;
	long 		fact = 1, prevFact = 1;

	while (n < 100) {
		fact = 1;
		int i = 1;
		do {
			fact = fact * i;
			i = i + 1;
		} while (i <= n);

		printf("<%li (%d!) %d>\n", fact, n, (fact / prevFact));

		prevFact = fact;

		n += 1;
	}

	printf("main() finish!\n");
}

void test_f_long_long() {
	printf("main() start!\n");

	int n = 1;
	long long	fact = 1, prevFact = 1;

	while (n < 100) {
		fact = 1;
		int i = 1;
		do {
			fact = fact * i;
			i = i + 1;
		} while (i <= n);

		printf("<%lli (%d!) %d>\n", fact, n, (fact / prevFact));

		prevFact = fact;

		n += 1;
	}

	printf("main() finish!\n");
}
