//Kendra Chalkley
//Assignment 6 Meta

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#define USERDEF 158

typedef void (*funcp)();

typedef struct node{
	char * contents;
	struct node * next;
} node;

char msg[] = \
"This level is an excersise in finding seg faults in linked lists. Without the right password, the final next pointer in the list will never be set to NULL, and the program will seg fault trying to traverse the list. Run GDB to find the segmentation fault. Once you've done so, run the program again enter the address of penultimate node of the list as the password. Given the correct address, the program will then print the password before seg faulting. Run the program one more time wth the correct password to recieve the message 'good job'\n";

node* dogs_before(int a) ;
void ferrets_before(node* pointer, int a, unsigned long b) ;
void cats (node* pointer, unsigned long b) ;


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


node* dogs_before(int a) {
	node * curr;
	curr=malloc(sizeof(node)*(a+1));

	for(int i=1;i<a;i++){
//		strcpy(curr->contents,"niceTry");

		curr->next=&curr[i];
		curr=curr->next;
	}
}
void ferrets_before(node* pointer, int a, unsigned long b) {
	int password=USERDEF;

	if((int)b==password){
		pointer[a-1].next=NULL;
	}
	cats(pointer,b);

    printf("Hello world.\n");
}
void cats (node* pointer, unsigned long b) {

	while(pointer!=NULL){
		if(b==(unsigned long)&pointer){
			printf("%ul",USERDEF);
		}
		pointer=pointer->next;

	}
	print_good();
}
void try_command() {
    int i, a=5;
	unsigned long b;
	
    printf("Enter the password: ");


    scanf("%lu",&b);
	
	node* pointer=dogs_before(a);
	ferrets_before(pointer,a, b);

	
}

int main() {
    funcp fg=print_good;
//	printf("%i\n\n", USERDEF);
    signal(SIGSEGV, segv_handler);
    print_msg();
    try_command();
    return 0;
}





















