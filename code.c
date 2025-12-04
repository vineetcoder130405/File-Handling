#include <stdio.h>

#define FILENAME "data.txt"

void writeToFile();
void readFromFile();
void displayFile();

int main() {
    int choice;

    while (1) {
        printf("\n===== FILE OPERATIONS MENU =====\n");
        printf("1. Write to File (%s)\n", FILENAME);
        printf("2. Read First Line from File (%s)\n", FILENAME);
        printf("3. Display Entire File (%s)\n", FILENAME);
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear leftover newline

        switch (choice) {
            case 1:
                writeToFile();
                break;

            case 2:
                readFromFile();
                break;

            case 3:
                displayFile();
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;   // instead of exit()

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void writeToFile() {
    char data[500];

    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("Error: Cannot open file for writing.\n");
        return;
    }

    printf("Enter data to write:\n");
    fgets(data, sizeof(data), stdin);

    if (fputs(data, fp) == EOF) {
        printf("Error writing to file.\n");
    } else {
        printf("Data written successfully.\n");
    }

    fclose(fp);
}

void readFromFile() {
    char buffer[500];

    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Error: File not found or not readable.\n");
        return;
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("\nFirst line:\n%s\n", buffer);
    } else {
        printf("File is empty or cannot read.\n");
    }

    fclose(fp);
}

void displayFile() {
    char ch;

    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Error: File not found or not readable.\n");
        return;
    }

    printf("\n--- File Contents ---\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    printf("\n----------------------\n");

    fclose(fp);
}
