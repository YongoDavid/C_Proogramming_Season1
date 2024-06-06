#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define LENGTH_OF_CODE 4
#define MAX_AMOUNT_OF_TRIES 10
int Guess__Vlid(const char *guess);
void Valuate_The_Guess(const char *code, const char *guess, int *wellPlaced, int *misplaced);
int main(int argc, char *argv[]) {
    srand(time(NULL));
    char The_Secret_CODE[LENGTH_OF_CODE + 1] = "";
    char guess[LENGTH_OF_CODE + 1] = ""; 
    int Num_Attemps = MAX_AMOUNT_OF_TRIES;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
            strncpy(The_Secret_CODE, argv[i + 1], LENGTH_OF_CODE);
            The_Secret_CODE[LENGTH_OF_CODE] = '\0';
            i++;
        } else if (strcmp(argv[i], "-t") == 0 && i + 1 < argc) {
            Num_Attemps = atoi(argv[i + 1]);
            i++;
        }
    }
    if (strlen(The_Secret_CODE) == 0) {
        for (int i = 0; i < LENGTH_OF_CODE; i++) {The_Secret_CODE[i] = '0' + rand() % 9;}
        The_Secret_CODE[LENGTH_OF_CODE] = '\0';
    }
    printf("Will you find the secret code?\nPlease enter a valid guess\n");
    for (int round = 0; round < Num_Attemps; round++) {
        printf("---\nRound %d\n>", round);
        int bytesRead = 0; char c;
        while (read(0, &c, 1) > 0 && c != '\n' && bytesRead < LENGTH_OF_CODE ) 
        {
            {guess[bytesRead++] = c;}
        }
        guess[bytesRead] = '\0';
        if (bytesRead == 0) {
            printf("\nEnd of file reached. Exiting...\n");
            return 0;
        }
        if (!Guess__Vlid(guess)) {
            // printf("Wrong input!\n");
            printf("Invalid input! Guess must be %d characters long.\n", LENGTH_OF_CODE);
            round--;
            continue;
        }
        int wellPlaced = 0, misplaced = 0;
        Valuate_The_Guess(The_Secret_CODE, guess, &wellPlaced, &misplaced);
        if (wellPlaced == LENGTH_OF_CODE) {
            printf("Congratz! You did it!\n");
            return 0;
        } else {printf("Well placed pieces: %d\nMisplaced pieces: %d\n", wellPlaced, misplaced);}
    }
    printf("---\nOut of attempts! The secret code was: %s\n", The_Secret_CODE);
    return 0;
}
int Guess__Vlid(const char *guess) {
    if (strlen(guess) != LENGTH_OF_CODE) {
        printf("Invalid guess length. Guess must be %d characters long.\n", LENGTH_OF_CODE);
        return 0;
    }
    for (int i = 0; i < LENGTH_OF_CODE; i++) {
        if (guess[i] < '0' || guess[i] > '8') {
            printf("Invalid guess. Guess must consist of digits from 0 to 8.\n");
            return 0;
        }
    }
    return 1;
}
void Valuate_The_Guess(const char *code, const char *guess, int *wellPlaced, int *misplaced) {
    int codeCount[10] = {0}; int guessCount[10] = {0};
    *wellPlaced = 0; *misplaced = 0;
    for (int i = 0; i < LENGTH_OF_CODE; i++) {
        if (guess[i] == code[i]) {
            (*wellPlaced)++;
        } else {
            codeCount[code[i] - '0']++; guessCount[guess[i] - '0']++;
        }
    }
    for (int i = 0; i < 10; i++) {*misplaced += (codeCount[i] < guessCount[i]) ? codeCount[i] : guessCount[i];}
}