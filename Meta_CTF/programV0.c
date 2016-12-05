#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#define USERDEF AAAAAA

typedef void (*funcp)();

typedef struct f {
    char c1;
    double d;
    char c2;
} mystruct;

char msg[] = \
"This insecure menu system takes a numeric input as an index to a function\n\
a 3-entry function table, only it doesn't validate the user's input to ensure\n\
it doesn't exceed the size of the table.  To solve this level, find the index\n\
that will go beyond the array of mystructs and invoke a function whose\n\
address happens to be located in the caller's stack frame.  To make this\n\
level easier, we have included the source code used to generate your binary.\n\
You will need to calculate the number of bytes on the stack that sit\n\
between the function table and the location of the function pointer fg\n\
in main.\n\n";

void print_msg() {
        printf("%s",msg);
}

void segv_handler(int sig) {
        printf("Segmentation fault.  Try again.\n");
        exit(0);
}

void print_good() {
    printf("Good Job.\n");
    exit(0);
}

void dogs_before(int a) {
	//if a==password()
	ferrets_before(b);
	//else segfault in a way to reveal a;
}
void ferrets_before(int b) {
	//if b==password()
	cats(c);
	//else segfault in a way to reveal a;
    printf("Hello world.\n");
}
void cats (int c) {
	//if a==password()
	print_good();
	//else segfault in a way to reveal c;
}
void try_command() {
    int i;
    mystruct m[USERDEF];
    printf("The password is three, comma seperated integers. Each portion of the password is hidden near a segmentation fault. Find the password, enter it correctly, and the program will run the next function which will segfault in a different way, dependent on the next integer in the password)\n");
    printf("Enter the password: ");
    sleep(2);
    scanf("%d",&i);//scanf("%d, %d, %d" &a, &b, &c)
    dogs_before(a);
}

main() {
    funcp fg=print_good;
    signal(SIGSEGV, segv_handler);
    print_msg();
    try_command();
    print_nogood();
    return 0;
}
