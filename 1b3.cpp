#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 1000

// Structure to hold a word and its frequency
typedef struct {
    char word[50];
    int count;
} WordFreq;

void to_lowercase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    char paragraph[MAX_LEN];
    WordFreq words[MAX_WORDS];
    int word_count = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, MAX_LEN, stdin);

    // Replace punctuation with spaces and convert to lowercase
    for (int i = 0; paragraph[i]; i++) {
        if (ispunct(paragraph[i])) {
            paragraph[i] = ' ';
        }
    }
    to_lowercase(paragraph);

    // Tokenize the paragraph into words
    char* token = strtok(paragraph, " \t\n");
    while (token != NULL) {
        int found = 0;

        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found && word_count < MAX_WORDS) {
            strcpy(words[word_count].word, token);
            words[word_count].count = 1;
            word_count++;
        }

        token = strtok(NULL, " \t\n");
    }

    // Print word frequencies
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
