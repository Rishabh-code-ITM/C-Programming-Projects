#include <stdio.h>                                          // Standard input output library
#include <string.h>                                         // strcmp, strstr jaise functions ke liye

#define MAX 100                                             // Maximum contacts ki limit
#define FILENAME "contacts.dat"                             // Data save karne wali file ka naam

struct Contact {                                            // Contact ka structure
    char name[40];                                          // Naam
    char phone[15];                                         // Phone number (string, kyunki leading zero ho sakta hai)
    char email[40];                                         // Email
};                                                          // Structure end

int loadContacts(struct Contact c[]) {                      // File se contacts padhne ka function
    FILE *fp = fopen(FILENAME, "rb");                       // Binary read mode mein file kholi
    if (fp == NULL) return 0;                               // File nahi hai to 0 contacts
    int n = (int)fread(c, sizeof(struct Contact), MAX, fp); // Jitne contacts mile utne padh liye
    fclose(fp);                                             // File band karo
    return n;                                               // Contacts ki ginti return karo
}                                                           // loadContacts function end

void saveContacts(struct Contact c[], int n) {              // Contacts ko file mein save karne ka function
    FILE *fp = fopen(FILENAME, "wb");                       // Binary write mode mein file kholi
    if (fp == NULL) {                                       // File nahi khuli
        printf("Error saving contacts!\n");                 // Error message
        return;                                             // Function se bahar
    }                                                       // if block end
    fwrite(c, sizeof(struct Contact), n, fp);               // Saare contacts ek saath file mein likh diye
    fclose(fp);                                             // File band karo
}                                                           // saveContacts function end

int main() {                                                // Program yahin se start hota hai (main function)
    struct Contact list[MAX];                               // Contacts ka array
    int count = loadContacts(list);                         // Shuru mein purane contacts load karo
    int choice;                                             // Menu choice

    do {                                                    // Menu baar baar dikhane ka loop
        printf("\n===== CONTACT MANAGEMENT =====\n");       // Heading
        printf("1. Add\n2. Show All\n3. Search by Name\n4. Delete\n5. Exit\n");   // Menu
        printf("Enter choice: ");                           // Choice maango
        scanf("%d", &choice);                               // Choice input lo

        switch (choice) {                                   // Choice ke hisaab se kaam
            case 1:                                         // Contact add karna
                if (count >= MAX) {                         // Limit poori
                    printf("Contact list is full!\n");      // Message
                    break;                                  // switch se bahar
                }                                           // if block end
                printf("Enter name: ");                     // Naam maango
                scanf(" %39[^\n]", list[count].name);       // Spaces ke saath naam input lo
                printf("Enter phone: ");                    // Phone maango
                scanf(" %14s", list[count].phone);          // Phone input lo
                printf("Enter email: ");                    // Email maango
                scanf(" %39s", list[count].email);          // Email input lo
                count++;                                    // Ginti badhao
                saveContacts(list, count);                  // Turant file mein save karo
                printf("Contact saved!\n");                 // Confirmation
                break;                                      // switch se bahar
            case 2:                                         // Saare contacts dikhana
                if (count == 0) printf("No contacts yet.\n");    // Khali list
                for (int i = 0; i < count; i++) {           // Har contact par loop
                    printf("%d. %s | %s | %s\n", i + 1, list[i].name, list[i].phone, list[i].email);   // Print karo
                }                                           // for loop end
                break;                                      // switch se bahar
            case 3: {                                       // Naam se search
                char key[40];                               // Search keyword
                int found = 0;                              // Found flag
                printf("Enter name to search: ");           // Keyword maango
                scanf(" %39[^\n]", key);                    // Keyword input lo
                for (int i = 0; i < count; i++) {           // Har contact check karo
                    if (strstr(list[i].name, key) != NULL) {    // Naam mein keyword mila
                        printf("%s | %s | %s\n", list[i].name, list[i].phone, list[i].email);   // Print karo
                        found = 1;                          // Flag on
                    }                                       // if block end
                }                                           // for loop end
                if (!found) printf("No contact found.\n");  // Kuch nahi mila
                break;                                      // switch se bahar
            }                                               // case 3 block end
            case 4: {                                       // Contact delete karna
                int num;                                    // Kaunsa contact delete karna hai
                printf("Enter contact number to delete: "); // Number maango
                scanf("%d", &num);                          // Input lo
                if (num < 1 || num > count) {               // Galat number
                    printf("Invalid number!\n");            // Message
                    break;                                  // switch se bahar
                }                                           // if block end
                for (int i = num - 1; i < count - 1; i++) { // Delete hue contact ke baad wale sab ek step aage khiskao
                    list[i] = list[i + 1];                  // Agla contact current ki jagah copy
                }                                           // for loop end
                count--;                                    // Ginti ghatao
                saveContacts(list, count);                  // File update karo
                printf("Contact deleted!\n");               // Confirmation
                break;                                      // switch se bahar
            }                                               // case 4 block end
            case 5:                                         // Exit
                printf("Goodbye!\n");                       // Vida message
                break;                                      // switch se bahar
            default:                                        // Galat choice
                printf("Invalid choice!\n");                // Error message
        }                                                   // switch end
    } while (choice != 5);                                  // 5 dabane tak chalta rahega

    return 0;                                               // Program successfully khatam
}                                                           // main function end
