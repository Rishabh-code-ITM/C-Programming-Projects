#include <stdio.h>                                          // Standard input output library
#include <stdlib.h>                                         // rand() aur srand() ke liye
#include <time.h>                                           // time() ke liye (random seed banane mein kaam aata hai)

int main() {                                                // Program yahin se start hota hai (main function)
    int secret, guess, attempts = 0;                        // Secret number, user ka guess, aur koshishon ki ginti
    const int MAX_ATTEMPTS = 7;                             // Kitni koshish milengi (const: change nahi hoga)
    char again;                                             // Dobara khelna hai ya nahi

    srand((unsigned)time(NULL));                            // Seed set kiya taaki har baar alag random number aaye

    do {                                                    // Game dobara khelne ke liye loop
        secret = rand() % 100 + 1;                          // 1 se 100 ke beech random number
        attempts = 0;                                       // Naye game mein attempts reset

        printf("\n=== Number Guessing Game ===\n");         // Game ka heading
        printf("I have picked a number between 1 and 100.\n");   // Rules batao
        printf("You have %d attempts.\n", MAX_ATTEMPTS);    // Kitni chances hain

        while (attempts < MAX_ATTEMPTS) {                   // Jab tak chances bache hain
            printf("Attempt %d - Enter your guess: ", attempts + 1);   // Guess maango
            scanf("%d", &guess);                            // Guess input lo
            attempts++;                                     // Ek chance use hua

            if (guess == secret) {                          // Agar guess sahi hai
                printf("Correct! You won in %d attempts!\n", attempts);   // Jeet ka message
                break;                                      // Loop se bahar
            } else if (guess < secret) {                    // Guess chhota hai
                printf("Too low! Go higher.\n");            // Hint: upar jao
            } else {                                        // Guess bada hai
                printf("Too high! Go lower.\n");            // Hint: neeche jao
            }                                               // if-else end
        }                                                   // while loop end

        if (guess != secret) {                              // Agar saare chances ke baad bhi sahi nahi hua
            printf("Game over! The number was %d\n", secret);   // Haar ka message aur sahi number
        }                                                   // if block end

        printf("Play again? (y/n): ");                      // Dobara khelna hai?
        scanf(" %c", &again);                               // Jawab lo
    } while (again == 'y' || again == 'Y');                 // y dabane par naya game

    printf("Thanks for playing!\n");                        // Vida message
    return 0;                                               // Program successfully khatam
}                                                           // main function end
