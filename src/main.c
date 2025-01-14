#include <stdio.h>
#include <string.h>
#include <ctype.h>

void crypt(char input[], int shift) {
    for(int i = 0; input[i] != '\0'; i++) {
        char currentChar = input[i];
        int index;

        if(isspace(currentChar)) {
            continue;
        }
        // Check if currentChar is uppercase or lowercase
        if(currentChar >= 'A' && currentChar <= 'Z') {
            index = currentChar - 'A';
        } else if(currentChar >= 'a' && currentChar <= 'z'){
            index = currentChar - 'a';
        }
        if(index) {
            printf("Current character: %c  | Index: %d\n", currentChar, index);
        }
    }
}

int main() {
    int option;
    int shift;
    char input[200];
    char output[sizeof(input)];

    printf("Select\n1 > Encrypt\n2 > Decrypt\n");
    scanf("%d", &option);
    getchar();

    printf("Input text\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Input shift\n");
    scanf("%d", &shift);

    if(input[0] != '\0') {
        if(option == 1) {
            crypt(input, shift);
        } else if(option == 2) {
            crypt(input, -shift);
        }
    }
}