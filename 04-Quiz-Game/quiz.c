#include <stdio.h>                                          // Standard input output library

struct Question {                                           // Ek sawal ka structure
    char text[100];                                         // Sawal ka text
    char options[4][40];                                    // Chaar options
    int answer;                                             // Sahi option ka number (1 se 4)
};                                                          // Structure end

int main() {                                                // Program yahin se start hota hai (main function)
    struct Question q[5] = {                                // 5 sawalon ka array
        {"Who developed the C language?",                   // Sawal 1
         {"Dennis Ritchie", "James Gosling", "Guido van Rossum", "Bjarne Stroustrup"}, 1},   // Options aur sahi jawab
        {"Which symbol is used to end a statement in C?",   // Sawal 2
         {"Colon (:)", "Semicolon (;)", "Comma (,)", "Period (.)"}, 2},   // Options aur sahi jawab
        {"Which header is needed for printf()?",            // Sawal 3
         {"stdlib.h", "string.h", "stdio.h", "math.h"}, 3}, // Options aur sahi jawab
        {"What is the size of int (usually) in bytes?",     // Sawal 4
         {"1", "2", "8", "4"}, 4},                          // Options aur sahi jawab
        {"Which loop runs at least once?",                  // Sawal 5
         {"do-while", "for", "while", "none"}, 1}           // Options aur sahi jawab
    };                                                      // Array initialization end

    int score = 0, choice;                                  // Score aur user ka jawab

    printf("=== C Programming Quiz ===\n");                 // Quiz ka heading
    printf("Enter option number (1-4) for each question.\n\n");   // Rules batao

    for (int i = 0; i < 5; i++) {                           // Har sawal ke liye loop
        printf("Q%d. %s\n", i + 1, q[i].text);              // Sawal dikhao
        for (int j = 0; j < 4; j++) {                       // Chaaron options dikhane ka loop
            printf("   %d) %s\n", j + 1, q[i].options[j]);  // Option print karo
        }                                                   // inner for loop end
        printf("Your answer: ");                            // Jawab maango
        scanf("%d", &choice);                               // Jawab input lo

        if (choice == q[i].answer) {                        // Agar jawab sahi hai
            printf("Correct!\n\n");                         // Sahi ka message
            score++;                                        // Score badhao
        } else {                                            // Galat jawab
            printf("Wrong! Correct answer: %s\n\n", q[i].options[q[i].answer - 1]);   // Sahi jawab bata do
        }                                                   // if-else end
    }                                                       // for loop end

    printf("Your final score: %d/5\n", score);              // Final score dikhao
    if (score == 5) printf("Excellent!\n");                 // Sab sahi hone par
    else if (score >= 3) printf("Good job!\n");             // 3 ya 4 sahi hone par
    else printf("Keep practicing!\n");                      // Kam score par
    return 0;                                               // Program successfully khatam
}                                                           // main function end
