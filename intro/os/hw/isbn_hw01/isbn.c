#include <stdio.h>

void error(int code);

int main(int argc, char* argv[]) {

	if (argc==1) {
		//no args passed
		error(0);
		return 0;
	}

    if(argc>=2) { 
        printf("\nNumber Of Arguments Passed: %d",argc); 
        printf("\n----Following Are The Command Line Arguments Passed----"); 
    } 
	return 0;
}

//exits the program depending on exit code
void error(int code) {

	switch (code) {
		
		case 0: //no args passed
			printf("No arguments passed.\n");
			break;

		case 1: //wrong number of args passed
			printf("Incorrect number of arguments. Only one argument should be passed.\n");
			break;

		case 2: //wrong number of digits
			printf("Incorrect number of digits. Must be 9, 10, 12, or 13 digits.\n");
			break;

		case 3: //non digit in argc
			printf("Invalid input. Must be numberical or have X as the last digit of 10.\n");
			break;

		default:
			printf("you should not be here\n");
	}
}