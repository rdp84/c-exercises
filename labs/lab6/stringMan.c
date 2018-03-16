
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

void function1(char* str);
void function2(char* str, char drop, char sub);
int function3(char* str);

int main(void)
{
    char user_str[MAXLEN + 1];
    printf("Please enter a string below:\n");
    scanf("%s", user_str);
    user_str[MAXLEN] = '\0';
    printf("Thanks. You entered the string %s\n", user_str);
    
    int option;
    printf("\n\nPlease enter your choice as to which function to use:\n"
           "1 - to reverse the string you entered\n"
           "2 - to replace characters in the string you entered\n"
           "3 - to check if the string you entered is a palindrome\n");
    scanf("%d", &option);

    switch (option) {

        case 1:
            function1(user_str);
            printf("\nThe reverse of the string you entered is: %s\n", user_str);
            break;
        case 2:
            printf("Will call function2\n");
            break;
        case 3:
            printf("Will call function3\n");
            break;
        default:
            printf("Invalid option. Run the program again.\n");
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


void function1(char* str)
{
    int length = strlen(str);
    int last = length - 1;
    char tmp;

    int i;
    for (i = 0; i < length / 2; ++i) {

        tmp = *(str + i);
        *(str + i) = *(str + last - i);
        *(str + last - i) = tmp;
    }
}
