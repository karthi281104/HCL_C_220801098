#include <stdio.h>
#include <stdlib.h>

void str_cpy(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int main() {
    char *str1 = malloc(100 * sizeof(char));
    char *str2 = malloc(100 * sizeof(char));

    printf("Enter first string: ");
    fgets(str1, 100, stdin);

    printf("Enter second string: ");
    fgets(str2, 100, stdin);

    printf("Before swapping:\n");
    printf("String 1: %s", str1);
    printf("String 2: %s", str2);

    str_cpy(&str1, &str2);

    printf("After swapping:\n");
    printf("String 1: %s", str1);
    printf("String 2: %s", str2);

    free(str1);
    free(str2);

    return 0;
}