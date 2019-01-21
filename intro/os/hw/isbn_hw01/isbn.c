#include <stdio.h>
#include <string.h>
#include <ctype.h>

//exits the program depending on exit code
void error(int code);

int main(int argc, char* argv[]) {

	if (argc == 1) {
		//no args passed
		error(0);
		return 0;
	}
    else if (argc > 2) {
		//more than one arg passed
        error(1);
		return 0;
    }
	
	//pointer to the isbn part of argv
	char* isbn = argv[1];
	
	int len = strlen(isbn); //got strlen from stack
	
	//validates the length of the isbn
	if (len < 9 || len == 11 || len > 13) {
		error(2);
		return 0;
	}

	for (int i=0; i<len-1; i++) {
		
		//check for invalid characters except for the x
		if (!isdigit(isbn[i])) {
			error(3);
			return 0;
		}
	}

	//if the last digit is not a number make sure the isbn length is definitely 10 and that the last char is definitely X
	if(!isdigit(isbn[len-1])) {

		if (len!=10 || isbn[len-1]!=88) {
			error(3);
			return 0;
		}
	}

	//now that all the error checking is out of the way we can work with the isbn

	int lastDigit; //what the last digit should be
	int sum = 0; //the checksum of all the digits

	if(len<11) { //for 9 and 10 digit isbns
	
		sum += 10*(isbn[0] - 48);
		sum += 9*(isbn[1] - 48);
		sum += 8*(isbn[2] - 48);
		sum += 7*(isbn[3] - 48);
		sum += 6*(isbn[4] - 48);
		sum += 5*(isbn[5] - 48);
		sum += 4*(isbn[6] - 48);
		sum += 3*(isbn[7] - 48);
		sum += 2*(isbn[8] - 48);
		//the sum currently has all 9 digits, now need to calculate the last digit
		lastDigit = 11-(sum % 11);

		
		if(lastDigit==10) printf("Check digit is X\n");
		else {
			printf("Check digit is ");
			printf("%i", lastDigit);
			printf("\n");
		}

		if (len==10) { //compare to the actual last digit
			int n = isbn[9] - 48;
			
			//if the last digit is an X
			if(n==40) {
				if(lastDigit==10) printf("ISBN is valid\n");//valid
				else printf("ISBN is invalid\n");
				return 0;
			}
			
			if (lastDigit == n) {
				printf("ISBN is valid\n");
			}
			else printf("ISBN is invalid\n");
			return 0;
		}
	}
	else {
		sum += isbn[0] - 48;
		sum += 3*(isbn[1] - 48);
		sum += isbn[2] - 48;
		sum += 3*(isbn[3] - 48);
		sum += isbn[4] - 48;
		sum += 3*(isbn[5] - 48);
		sum += isbn[6] - 48;
		sum += 3*(isbn[7] - 48);
		sum += isbn[8] - 48;
		sum += 3*(isbn[9] - 48);
		sum += isbn[10] - 48;
		sum += 3*(isbn[11] - 48);
		//all 12 digits are summed now, calculate last
		lastDigit = 10-(sum % 10);

		printf("Check digit is ");
		printf("%i", lastDigit);
		printf("\n");

		if (len==13) {
			int n = isbn[12] - 48;
			if (lastDigit == n) {
				printf("ISBN is valid\n");
			}
			else printf("ISBN is invalid\n");
			return 0;
		}
	}

	return 0;
}

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
			printf("Invalid input. Must be numberical or have \"X\" as the last digit of 10.\n");
			break;

		default:
			printf("you should not be here\n");
	}
}