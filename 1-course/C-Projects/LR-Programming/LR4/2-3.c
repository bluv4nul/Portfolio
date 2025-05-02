#include <stdio.h>
#include <ctype.h>

int main(void){
    char srting[] = "A1b2 C3d4!E5f, G6?";

    for(int i = 0; srting[i] != '\0'; i++){
        printf("Symbol: %c\n", srting[i]);
        printf("isalnum: %s", (isalnum(srting[i]) == 0 ? "No\n" : "Yes\n" ));
        printf("isaplha: %s", (isalpha(srting[i]) == 0 ? "No\n" : "Yes\n" ));
        printf("islower: %s", (islower(srting[i]) == 0 ? "No\n" : "Yes\n" ));
        printf("isupper: %s", (isupper(srting[i]) == 0 ? "No\n" : "Yes\n" ));
        printf("isdigit: %s", (isdigit(srting[i]) == 0 ? "No\n" : "Yes\n" ));
        printf("isxdigit: %s", (isxdigit(srting[i]) == 0 ? "No\n" : "Yes\n" ));
        printf("iscntrl: %s", (iscntrl(srting[i]) == 0 ? "No\n" : "Yes\n" ));
        printf("isgraph: %s", (isgraph(srting[i]) == 0 ? "No\n" : "Yes\n" ));
        printf("isspace: %s", (isspace(srting[i]) == 0 ? "No\n" : "Yes\n" ));
        printf("isblank: %s", (isblank(srting[i]) == 0 ? "No\n" : "Yes\n" ));
        printf("isprint: %s", (isprint(srting[i]) == 0 ? "No\n" : "Yes\n" ));
        printf("ispunct: %s", (ispunct(srting[i]) == 0 ? "No\n\n" : "Yes\n\n" ));
    }
}   