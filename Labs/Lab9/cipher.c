
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> /* open file */
#include <unistd.h> /* read file */

int decrypt(int orig, int key);
int error_die(char *str);

/* -------------------------------------------------------------------------- */
int main(int argc, char *argv[]) {

	int s, d;
	char *buf[1];
  /*char* buff = (char*)malloc (buff);*/
	char *buff = &buf[0];

	int key = 5;

	if (argc != 5) {
		printf("num args\n");
		return EXIT_FAILURE;
	}

	if ((s = open(argv[3], O_RDONLY)) == -1) {
		printf("src file\n");
		return EXIT_FAILURE;
	}
	if ((d = open(argv[4], O_WRONLY | O_CREAT)) == -1) {
		printf("dest file\n");
		return EXIT_FAILURE;
	}

	if (!strcmp(argv[1], "e") || strcmp(argv[1], "d")) {
		printf("bad d/e\n");
		return EXIT_FAILURE;
	}

	key = strcmp(argv[1], "e") ? atoi(argv[2]) : -atoi(argv[2]);

	while (read(s, buff, 1)) {
		buf[0] = (buf[0] + key) % 256,1);

		write(d, buff, 1);
	}

	close(s);
	close(d);

	return 0;

}

/* -------------------------------------------------------------------------- */
int decrypt(int orig, int key) {
	return (orig - key) % 256;
}

/* -------------------------------------------------------------------------- */
int error_die(char *str) {
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}
