#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char* CreateNewStringP(char* s1);
/*
void main() {
    char s1[100];

    printf("s1=");
    fgets(s1, _countof(s1), stdin);

    char* s2 = CreateNewStringP(s1);

    printf("s1=%s", s1);
    printf("s2=%s\n", s2);

    free(s2);
}
*/

char* CreateNewStringP(char* s1) {
    char* ptr = s1; 

    while (*ptr != '\0' && !isdigit((unsigned char)*ptr)) {
        ptr++;
    }

    int len = ptr - s1;
    char* s2 = (char*)malloc((len + 1) * sizeof(char));
    char* dest = s2;
    char* src = s1;

    while (src < ptr) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
    return s2;
}
