#include <stdio.h>
#include <string.h>

int n_7_2_1_1(char s[]) {
    int i = 0;
    while (s[i] != '\0') i++; 
    return i;
}

int n_7_2_1_2(char *s) {
    int i = 0;
    while (*s != '\0') { i++; s++; }
    return i;
}
int n_7_2_2_1(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}
int n_7_2_2_2(char *s1, char *s2) {

    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
void n_7_2_3(char s1[], char s2[]) {
    int i = 0;

    
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }

    
    s1[i] = '\0';
    printf("%s", s1);
}

void n_7_2_4(char* s1, char* s2) {
    char* start = s1; 
    while (*s1) {
        s1++;
    }
    while (*s1++ = *s2++);
    printf("%s\n", start);
}
void n_7_2_5_1(char s1[], char s2[], int n) {
    int i = 0;
    if (n < strlen(s1)) {
        while (i < n) {
            s1[i] = s2[i];
            i++;
        }
        s1[i] = '\0';
    }
    else printf("Ошибка, много хочешь");
    printf("%s", s1);
}
void n_7_2_5_2(char* s1, const char* s2, int n) {
    char* start = s1; 
    int i = 0;

    while (i < n && *s2 != '\0') {
        *s1 = *s2; 
        s1++;
        s2++;
        i++;
    }

    while (i < n) {
        *s1 = '\0';
        s1++;
        i++;
    }

    if (i == n && *(s1 - 1) != '\0') {
        *s1 = '\0';
    }

    printf("%s\n", start);
}
/*
void main() {
    char s[10] = "Nigger";
    char a[10] = "000";
    char b[20] = "XXXXXXXXXXXXXXX";
    char* l = "Hello, World!";
    //printf("len = %d\n", n_7_2_1_1(s));
    
    //printf("len = %d\n", n_7_2_1_2(s));
    
    printf("res = %d\n", n_7_2_2_1("ABC", "ABD"));
    printf("res = %d\n", n_7_2_2_1("ABC", "ABC"));
    
    
    printf("res = %d\n", n_7_2_2_2("ABC", "ABD"));
    printf("res = %d\n", n_7_2_2_2("ABC", "ABC"));
    
    
    //n_7_2_3(a, "abc");
    
    //n_7_2_4(s, a);
    
    //n_7_2_5_1(b, l, 5);
    //n_7_2_5_2(b, l, 5);
}*/
