#include <stdio.h>                                          // Standard input output library
#include <string.h>                                         // strstr() jaise string functions ke liye

#define MAX 100                                             // Maximum books ki limit

struct Book {                                               // Book ka structure
    int id;                                                 // Book ID
    char title[60];                                         // Kitab ka naam
    char author[40];                                        // Lekhak ka naam
    int issued;                                             // 0 = library mein hai, 1 = issue ho chuki
};                                                          // Structure end

int findBook(struct Book b[], int n, int id) {              // ID se book ka index dhundhne ka function
    for (int i = 0; i < n; i++) {                           // Har book check karo
        if (b[i].id == id) return i;                        // Mil gayi to index return
    }                                                       // for loop end
    return -1;                                              // Nahi mili to -1
}                                                           // findBook function end

int main() {                                                // Program yahin se start hota hai (main function)
    struct Book lib[MAX];                                   // Books ka array
    int count = 0, choice, id, idx;                         // Ginti, choice, ID, index

    do {                                                    // Menu baar baar dikhane ka loop
        printf("\n===== LIBRARY MANAGEMENT =====\n");       // Heading
        printf("1. Add Book\n2. Show Books\n3. Issue Book\n4. Return Book\n5. Search by Title\n6. Exit\n");   // Menu
        printf("Enter choice: ");                           // Choice maango
        scanf("%d", &choice);                               // Choice input lo

        switch (choice) {                                   // Choice ke hisaab se kaam
            case 1:                                         // Book add karna
                if (count >= MAX) {                         // Limit poori
                    printf("Library is full!\n");           // Message
                    break;                                  // switch se bahar
                }                                           // if block end
                printf("Enter book ID: ");                  // ID maango
                scanf("%d", &id);                           // Input lo
                if (findBook(lib, count, id) != -1) {       // Duplicate ID
                    printf("Book ID already exists!\n");    // Message
                    break;                                  // switch se bahar
                }                                           // if block end
                lib[count].id = id;                         // ID save karo
                printf("Enter title: ");                    // Title maango
                scanf(" %59[^\n]", lib[count].title);       // Spaces ke saath title input lo
                printf("Enter author: ");                   // Author maango
                scanf(" %39[^\n]", lib[count].author);      // Author input lo
                lib[count].issued = 0;                      // Nayi book library mein hai
                count++;                                    // Ginti badhao
                printf("Book added!\n");                    // Confirmation
                break;                                      // switch se bahar
            case 2:                                         // Saari books dikhana
                if (count == 0) printf("No books available.\n");     // Koi book nahi
                for (int i = 0; i < count; i++) {           // Har book par loop
                    printf("ID: %d | %s by %s | %s\n", lib[i].id, lib[i].title, lib[i].author,
                           lib[i].issued ? "Issued" : "Available");   // Status ke saath print karo
                }                                           // for loop end
                break;                                      // switch se bahar
            case 3:                                         // Book issue karna
                printf("Enter book ID to issue: ");         // ID maango
                scanf("%d", &id);                           // Input lo
                idx = findBook(lib, count, id);             // Book dhundho
                if (idx == -1) printf("Book not found!\n"); // Nahi mili
                else if (lib[idx].issued) printf("Book already issued!\n");   // Pehle se issue hai
                else {                                      // Available hai
                    lib[idx].issued = 1;                    // Issue mark karo
                    printf("Book issued successfully!\n");  // Confirmation
                }                                           // if-else end
                break;                                      // switch se bahar
            case 4:                                         // Book return karna
                printf("Enter book ID to return: ");        // ID maango
                scanf("%d", &id);                           // Input lo
                idx = findBook(lib, count, id);             // Book dhundho
                if (idx == -1) printf("Book not found!\n"); // Nahi mili
                else if (!lib[idx].issued) printf("This book was not issued!\n");   // Issue hi nahi thi
                else {                                      // Issue thi
                    lib[idx].issued = 0;                    // Wapas available mark karo
                    printf("Book returned successfully!\n");    // Confirmation
                }                                           // if-else end
                break;                                      // switch se bahar
            case 5: {                                       // Title se search
                char key[60];                               // Search keyword
                int found = 0;                              // Found flag
                printf("Enter title keyword: ");            // Keyword maango
                scanf(" %59[^\n]", key);                    // Keyword input lo
                for (int i = 0; i < count; i++) {           // Har book check karo
                    if (strstr(lib[i].title, key) != NULL) {    // Title mein keyword hai (strstr substring dhundhta hai)
                        printf("ID: %d | %s by %s\n", lib[i].id, lib[i].title, lib[i].author);   // Match print karo
                        found = 1;                          // Flag on
                    }                                       // if block end
                }                                           // for loop end
                if (!found) printf("No matching book.\n");  // Kuch nahi mila
                break;                                      // switch se bahar
            }                                               // case 5 block end
            case 6:                                         // Exit
                printf("Goodbye!\n");                       // Vida message
                break;                                      // switch se bahar
            default:                                        // Galat choice
                printf("Invalid choice!\n");                // Error message
        }                                                   // switch end
    } while (choice != 6);                                  // 6 dabane tak chalta rahega

    return 0;                                               // Program successfully khatam
}                                                           // main function end
