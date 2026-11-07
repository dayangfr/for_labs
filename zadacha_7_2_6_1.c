#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char* CreateNewString(char* s1);
/*
void main() {
    char s1[100];

    printf("s1=");
    fgets(s1, _countof(s1), stdin);

    char* s2 = CreateNewString(s1);

    printf("s1=%s", s1);
    printf("s2=%s\n", s2);

    free(s2);
}
*/

char* CreateNewString(char* s1) {
    int len = 0;

    while (s1[len] != '\0' && !isdigit((unsigned char)s1[len])) {
        len++;
    }

    char* s2 = (char*)malloc((len + 1) * sizeof(char));
    
    for (int i = 0; i < len; i++) {
        s2[i] = s1[i];
    }
    s2[len] = '\0';

    return s2;
}
