#include<stdio.h>
#include<stdlib.h>

int encrypt(FILE* secret_file, FILE* encrypted_file, FILE* key_files) {
    int c;
    while ((c = fgetc(secret_file)) != EOF) {  // Corrected the condition in while loop
        int key = rand();
        int encrypted_c = c ^ key;  // Corrected the XOR operation
        fputc(key, key_files);
        fputc(encrypted_c, encrypted_file);
    }
    return 0;  // Added return statement
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Please Provide valid Files\n");
    } else {
        char* secret_file_name = argv[1];
        FILE* secret_file = fopen(secret_file_name, "r");
        FILE* encrypted_file = fopen("enc.out", "w");
        FILE* key_files = fopen("keys.out", "w");

        if (secret_file == NULL || encrypted_file == NULL || key_files == NULL) {
            printf("Error opening file(s)\n");
            return 1;
        }

        encrypt(secret_file, encrypted_file, key_files);

        fclose(secret_file);
        fclose(encrypted_file);
        fclose(key_files);
    }
    return 0;
}
