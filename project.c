// Online Quiz System

#include <stdio.h>
#include <string.h>

void startQuiz();
int askQuestion(char *question, char *opt1, char *opt2, char *opt3, char *opt4, int correctOpt);

int main() {
    char name[50];
    FILE *file = fopen("project.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open.\n");
        return 1;
    }

    fgets(name, sizeof(name), file);
    fclose(file);
    name[strcspn(name, "\n")] = 0;

    printf("=== Welcome to the Online Quiz System ===\n\n");
    printf("Welcome, %s! Let's start the quiz.\n\n", name);

    startQuiz();
    return 0;
}

void startQuiz() {
    int score = 0;
    int totalQuestions = 5;

    score += askQuestion("a. What is the capital of Paris?",
                         "1. Berlin", "2. Paris", "3. Madrid", "4. Rome", 2);

    score += askQuestion("b. Who developed the C programming language?",
                         "1. Dennis", "2. James", "3. John", "4. Charls", 1);

    score += askQuestion("c. What is the value of Pi?",
                         "1. 2.14", "2. 3.14", "3. 4.15", "4. 2.15", 2);

    score += askQuestion("d. What is the smallest prime number?",
                         "1. 0", "2. 1", "3. 2", "4. 3", 3);

    score += askQuestion("e. Who is our national poet?",
                         "1. Najrul", "2. Jashimuddin", "3. Rabindranath", "4. Madhusudon", 1);

    printf("\n=== Quiz Completed ===\n");
    printf("You scored %d out of %d.\n", score, totalQuestions);

    if (score == totalQuestions) {
        printf("Excellent! You got all the answers correct!\n");
    } else if (score >= totalQuestions / 2) {
        printf("Good job! You passed the quiz.\n");
    } else {
        printf("Try for the next time!\n");
    }
}

int askQuestion(char *question, char *opt1, char *opt2, char *opt3, char *opt4, int correctOpt) {
    int userAnswer;

    printf("%s\n", question);
    printf("%s\n", opt1);
    printf("%s\n", opt2);
    printf("%s\n", opt3);
    printf("%s\n", opt4);
    printf("Your answer (1-4): ");
    scanf("%d", &userAnswer);

    if (userAnswer == correctOpt) {
        printf("Correct!\n\n");
        return 1;
    } else {
        printf("Incorrect. The correct answer was option %d.\n\n", correctOpt);
        return 0;
    }
}

