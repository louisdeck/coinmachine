#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CIPHER_CODE 573927
#define MODULUS 1638289
#define EXPONENT 0x10001
#define PRIV_KEY ??? :--)


int modpow(long long a, long long b, int c) { //no trick here, don't overthink it !
	int res = 1;

	while(b > 0) {
		if(b & 1) { //b is odd
			res = (res * a) % c;
		}
		b = b >> 1; //b = b/2
		a = (a * a) % c;
	}
	return res;
}

int decrypt(long long c, long long d, long long n) {
	return modpow(c,d,n);
}

void auth() {
	int input, key;
	long long c = CIPHER_CODE;
	long long d = PRIV_KEY;
	long long n = MODULUS;

	key = decrypt(c,d,n);

	printf("Hold-on operator.. what is the code?\n");
	scanf("%d", &input);

	if(input == key) {
	}

	else {
		printf("Nah..\n");
		exit(EXIT_FAILURE);
	}
}

void func(int key) {
	char overflow[32];

	printf("Shoot with a GUN, that's what the bullets are for !!!\n");
	gets(overflow);

	if(key == 0xc0cac01a) {
		printf("That is private property\n");
		setuid(0);
		system("/bin/sh");
	}
	else {
		printf("Nah..\n");
		exit(EXIT_FAILURE);
	}
}


int main(void) {
	printf("Colonel this 0xc0cac01a machine, i want you to shoot the lock off it\n");
	auth();
	getchar();
	func(0xcafebabe);
	return 0;
}
