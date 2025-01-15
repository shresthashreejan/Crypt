#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* crypt(char input[], int shift, int space_pref) {
    int len = strlen(input);
    char *output = (char*) malloc((len + 1) * sizeof(char));

    if (output == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    int output_index = 0;
    for(int i = 0; input[i] != '\0'; i++) {
        char currentChar = input[i];

        if(isspace(currentChar)) {
            if(space_pref == 1) {
                output[output_index++] = currentChar;
            }
            continue;
        }

        // Check if currentChar is uppercase or lowercase
        if(currentChar >= 'A' && currentChar <= 'Z') {
            output[output_index++] = 'A' + (currentChar - 'A' + shift + 26) % 26;
        } else if(currentChar >= 'a' && currentChar <= 'z'){
            output[output_index++] = 'a' + (currentChar - 'a' + shift + 26) % 26;
        }
    }
    output[output_index] = '\0';
    return output;
}

int main() {
    int option, shift, space_pref;
    char *input = NULL;
    size_t input_size = 0;

    printf("Select\n1 > Encrypt\n2 > Decrypt\n");
    scanf("%d", &option);
    getchar();

    printf("Select\n1 > Include spaces\n2 > Ignore spaces\n");
    scanf("%d", &space_pref);
    getchar();

    printf("Input text\n");
    getline(&input, &input_size, stdin); // Reads the input length and assigns it to input_size
    input[strcspn(input, "\n")] = '\0';

    printf("Input shift\n");
    scanf("%d", &shift);

    if (input[0] != '\0') {
        char* output = crypt(input, (option == 2 ? -shift : shift), space_pref);
        if (output != NULL) {
            printf("%s\n", output);
            free(output);
        }
    }

    free(input);
    return 0;
}