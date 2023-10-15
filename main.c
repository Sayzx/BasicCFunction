#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int my_strlen(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

const char *my_strchr(const char* str, char character) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == character) {
            return &str[i];
        }
        i++;
    }
    return NULL;
}


char *my_strcpy(char *destination, const char *source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i]; // Copier le caractère de la source dans la destination
        i++;
    }
    return destination;
}

char *my_strcat(char *destination, const char *source) {
    int i = 0;
    int j = 0;
    while (destination[i] != '\0') { // Tant que le caractère \0 n'est pas rencontré
        i++;
    }
    while (source[j] != '\0') { // Tant que le caractère \0 n'est pas rencontré
        destination[i] = source[j];
        i++;
        j++;
    }
    destination[i] = '\0'; // Ajouter le caractère \0 à la fin de la chaîne de caractère
    return destination;
}

int my_strcmp(const char *str_a, const char *str_b) {
    int i = 0;
    while (str_a[i] != '\0' && str_b[i] != '\0') { // Tant que le caractère \0 n'est pas rencontré
        if (str_a[i] != str_b[i]) {
            return str_a[i] - str_b[i]; // Retourner la différence entre les deux caractères
        }
        i++;
    }
    return str_a[i] - str_b[i]; // Si les deux chaînes sont identiques, retourne 0
}

const char *my_strstr(const char* haystack, const char* needle) {
    int i = 0;
    int j = 0;
    while (haystack[i] != '\0') { // Tant que le caractère \0 n'est pas rencontré
        if (haystack[i] == needle[j]) {
            while (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (needle[j] == '\0') { // Si le caractère \0 est rencontré
                return &haystack[i - j]; // Retourner la position de la chaîne de caractère
            }
        }
        i++;
    }
    return NULL;
}

int my_getnbr(char *str) {
    int i = 0;
    for (i = 0; str[i] != '\0'; i++) { // Tant que le caractère \0 n'est pas rencontré
        if (str[i] < '0' || str[i] > '9') {
            break;
        }
    }
    if (i == 0) {
        return 0;
    }
    char *number = (char *)malloc(sizeof(char) * i); // Allouer de la mémoire pour la chaîne de caractère
    for (int j = 0; j < i; j++) { // Tant que le compteur j est inférieur au compteur i
        number[j] = str[j]; // Copier le caractère de la source dans la destination
    }
    return atoi(number);
}

char *my_nbrtostr(int number) {
    int i = 0;
    int temp = number;
    while (temp != 0) { // Tant que l'entier n'est pas égal à 0
        temp /= 10; // Diviser l'entier par 10
        i++;
    }
    char *numberStr = (char *)malloc(sizeof(char) * i); // Allouer de la mémoire pour la chaîne de caractère pour i caractères
    itoa(number, numberStr, 10);
    return numberStr;
    free(numberStr);
}

char *my_rot13(char *source) {
    int i = 0;
    while (source[i] != '\0') { // Tant que le caractère \0 n'est pas rencontré
        if (source[i] >= 'a' && source[i] <= 'z') { // Si le caractère est compris entre 'a' et 'z'
            source[i] = (source[i] - 'a' + 13) % 26 + 'a'; // Appliquer le ROT13
        } else if (source[i] >= 'A' && source[i] <= 'Z') {
            source[i] = (source[i] - 'A' + 13) % 26 + 'A';
        }
        i++;
    }
    return source;
}

int main() {
    // Test de my_strlen
    const char *testStr = "Hello, World!";
    int len = my_strlen(testStr);
    printf("Length of '%s' is: %d\n", testStr, len);

    // Test de my_strchr
    const char *searchStr = "Hello, World!";
    char searchChar = 'o';
    const char *resultChar = my_strchr(searchStr, searchChar);
    if (resultChar != NULL) {
        printf("'%c' found at position: %ld\n", searchChar, resultChar - searchStr);
    } else {
        printf("'%c' not found.\n", searchChar);
    }

    // Test de my_strcpy
    char destStr[20];
    const char *sourceStr = "Copy this string.";
    my_strcpy(destStr, sourceStr);
    printf("Copied string: %s\n", destStr);

    // Test de my_strcat
    char destCatStr[30] = "Hello, ";
    const char *sourceCatStr = "World!";
    my_strcat(destCatStr, sourceCatStr);
    printf("Concatenated string: %s\n", destCatStr);

    // Test de my_strcmp
    const char *str1 = "Hello";
    const char *str2 = "Hella";
    int cmpResult = my_strcmp(str1, str2);
    if (cmpResult < 0) {
        printf("'%s' < '%s'\n", str1, str2);
    } else if (cmpResult > 0) {
        printf("'%s' > '%s'\n", str1, str2);
    } else {
        printf("'%s' == '%s'\n", str1, str2);
    }

    // Test de my_strstr
    const char *haystack = "This is a simple example.";
    const char *needle = "simple";
    const char *resultStr = my_strstr(haystack, needle);
    if (resultStr != NULL) {
        printf("'%s' found at position: %ld\n", needle, resultStr - haystack);
    } else {
        printf("'%s' not found.\n", needle);
    }

    // Test de my_getnbr
    char *strNum = "12345";
    int num = my_getnbr(strNum);
    printf("Integer from string: %d\n", num);

    // Test de my_nbrtostr
    int number = 1234;
    char *numStr = my_nbrtostr(number);
    printf("String from integer: %s\n", numStr);
    free(numStr); // N'oubliez pas de libérer la mémoire allouée

    // Test de my_rot13
    char rot13Str[] = "Hello, World!";
    printf("Avant : %s\n", rot13Str);
    printf("Apres : %s\n", my_rot13(rot13Str));
    return 0;
}
