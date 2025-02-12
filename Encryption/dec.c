<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>

int decrypt(FILE *encrypted_file, FILE *key_files, FILE *decrypted_file) {
    int enc_c;
    while ((enc_c = fgetc(encrypted_file)) != EOF) {
        int keys_c = fgetc(key_files);
        if (keys_c == EOF) { // Ensure key file is valid
            break;
        }
        int dec_c = enc_c ^ keys_c;
        fputc(dec_c, decrypted_file);
    }
    return 0; // Return to indicate successful decryption
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Please provide both encrypted file and key file as inputs\n");
        return 1; // Exit with error code
    } else {
        FILE *encrypted_file = fopen(argv[1], "r");
        if (encrypted_file == NULL) {
            printf("Error opening encrypted file\n");
            return 1;
        }
        FILE *key_files = fopen(argv[2], "r");
        if (key_files == NULL) {
            printf("Error opening key file\n");
            fclose(encrypted_file); // Close opened file before returning
            return 1;
        }
        FILE *decrypted_file = fopen("decrypt.out", "w");
        if (decrypted_file == NULL) {
            printf("Error opening decrypted file\n");
            fclose(encrypted_file); // Close opened files before returning
            fclose(key_files);
            return 1;
        }

        decrypt(encrypted_file, key_files, decrypted_file);

        fclose(encrypted_file);
        fclose(key_files);
        fclose(decrypted_file);
    }
    return 0;
}
=======
#include<stdio.h>
#include<stdlib.h>

int decrypt(FILE *encrypted_file, FILE *key_files, FILE *decrypted_file) {
    int enc_c;
    while ((enc_c = fgetc(encrypted_file)) != EOF) {
        int keys_c = fgetc(key_files);
        if (keys_c == EOF) { // Ensure key file is valid
            break;
        }
        int dec_c = enc_c ^ keys_c;
        fputc(dec_c, decrypted_file);
    }
    return 0; // Return to indicate successful decryption
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Please provide both encrypted file and key file as inputs\n");
        return 1; // Exit with error code
    } else {
        FILE *encrypted_file = fopen(argv[1], "r");
        if (encrypted_file == NULL) {
            printf("Error opening encrypted file\n");
            return 1;
        }
        FILE *key_files = fopen(argv[2], "r");
        if (key_files == NULL) {
            printf("Error opening key file\n");
            fclose(encrypted_file); // Close opened file before returning
            return 1;
        }
        FILE *decrypted_file = fopen("decrypt.out", "w");
        if (decrypted_file == NULL) {
            printf("Error opening decrypted file\n");
            fclose(encrypted_file); // Close opened files before returning
            fclose(key_files);
            return 1;
        }

        decrypt(encrypted_file, key_files, decrypted_file);

        fclose(encrypted_file);
        fclose(key_files);
        fclose(decrypted_file);
    }
    return 0;
}
>>>>>>> 643dfa5 (Initial commit - Low-level programming)
