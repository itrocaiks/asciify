#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(const char* str) {
	for (int i = 0; i < strlen(str); ++i) {
		printf("%d", str[i]);
	}
}

void decrypt(char* str) {
	while (strlen(str) > 1) {
		char tmp_str[strlen(str)];
		strcpy(tmp_str, str);

		if (strlen(tmp_str) > 2) {
			tmp_str[3] = '\0';
			int tmp_num = atoi(tmp_str);

			if (tmp_num < 127) {
				printf("%c", tmp_num);
				memmove(str, str + 3, strlen(str) - 2);
				continue;
			}
			strcpy(tmp_str, str);
		}

		tmp_str[2] = '\0';
		int tmp_num = atoi(tmp_str);
		
		if (tmp_num > 31) {
			printf("%c", tmp_num);
		} else {
			printf("(null)");
		}
		memmove(str, str + 2, strlen(str) - 1);
	}
}

void print_usage() {printf("Usage: asciify [OPTION] [MESSAGE]\n  -e\tencrypts the input\n  -d\tdecrypts the input\n");} 

int main(int argc, char* argv[]) {
	if (argc != 3) {
		print_usage();
		exit(1);
	}

	if (strcmp(argv[1], "-e") == 0) {
		printf("Encrypted: ");
		encrypt(argv[2]);
		printf("\n");
	} else if (strcmp(argv[1], "-d") == 0) {
                printf("Decrypted: ");
                decrypt(argv[2]);
                printf("\n");
	} else {
		print_usage();
		exit(1);
	}


	return 0;
}
