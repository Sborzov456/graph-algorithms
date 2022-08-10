#include "SecondaryFunctions.h"

int getInt(int* value)
{
    int n;
    do {
        n = scanf("%d", value);
        if (n < 0) {
            return 0;
        }
        if (n == 0){
            printf("%s\n", "Error! Repeat input");
            scanf("%*c");
        }
    } while (n == 0);
    return 1;
}

int dialog(char* msgs[])
{
    char *errorMessage = "";
    int option;
    do{
        puts(errorMessage);
        errorMessage = "You are wrong. Repeate, please!";
        for(int i = 0; i < OPTIONS_NUM; ++i){
            puts(msgs[i]);
        }
        puts("Make your choice: --> ");
        if (!getInt(&option)) {
            option = 0;
        }
    } while(option < 0 || option >= OPTIONS_NUM);
    return option;
}
