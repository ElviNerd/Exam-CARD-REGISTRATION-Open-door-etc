#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
/*
//***********************************G MALLOC REALLOC VERSION****************************
// Card structure
typedef struct {
    int cardNumber;
    int hasAccess;
    time_t registrationDate;
} Card;

// Card list structure
typedef struct {
    Card *cards;
    size_t count;
} CardList;

// Logged-in card list structure
typedef struct {
    int *cardNumbers;
    size_t count;
} LoggedInCardList;

// Function to display the menu and get the user's choice
int getMenuSelection() {
    int selection;
    while (1) {
        printf("\nAdmin menu:\n");
        printf("1. Remote open door\n");
        printf("2. List all cards in system\n");
        printf("3. Add/remove access\n");
        printf("4. Exit\n");
        printf("9. FAKE TEST SCAN CARD\n");
        printf("Enter your choice: ");
        scanf("%d", &selection);
        getchar(); // Clear the input buffer
        if (selection >= 1 && selection <= 5 || selection == 9) {
            return selection;
        }
        printf("Invalid choice. Please try again.\n");
    }
}

// Function to add a card to the card list
void addCard(CardList *cardList, int cardNumber, int hasAccess) {
    Card newCard = {cardNumber, hasAccess, time(NULL)};
    cardList->cards = realloc(cardList->cards, (cardList->count + 1) * sizeof(Card));
    cardList->cards[cardList->count] = newCard;
    cardList->count++;
}

// Function to find a card in the card list by card number
Card *findCard(CardList *cardList, int cardNumber) {
    for (size_t i = 0; i < cardList->count; i++) {
        if (cardList->cards[i].cardNumber == cardNumber) {
            return &cardList->cards[i];
        }
    }
    return NULL;
}

// Function to add a logged-in card to the logged-in card list
void addLoggedInCard(LoggedInCardList *loggedInCardList, int cardNumber) {
    loggedInCardList->cardNumbers = realloc(loggedInCardList->cardNumbers, (loggedInCardList->count + 1) * sizeof(int));
    loggedInCardList->cardNumbers[loggedInCardList->count] = cardNumber;
    loggedInCardList->count++;
}

// Function to check if a card is logged in
bool isLoggedIn(LoggedInCardList *loggedInCardList, int cardNumber) {
    for (size_t i = 0; i < loggedInCardList->count; i++) {
        if (loggedInCardList->cardNumbers[i] == cardNumber) {
            return true;
        }
    }
    return false;
}

// Function to wait for a specified number of seconds
void waitFor(unsigned int secs) {
    unsigned int end = time(0) + secs;
    while (time(0) < end);
}

int main() {
    CardList cardList = {NULL, 0};
    LoggedInCardList loggedInCardList = {NULL, 0};

    addCard(&cardList, 1212, 1);
    addCard(&cardList, 1213, 0);

    int choice;
    while((choice = getMenuSelection()) != 4) {
switch (choice) {
case 1:
printf("CURRENTLY LAMP IS: Green\n");
waitFor(3);
break;
case 2:
printf("Registered cards:\n");
for (size_t i = 0; i < cardList.count; i++) {
printf("Card %d: %s Access, Added to system: %s",
cardList.cards[i].cardNumber,
cardList.cards[i].hasAccess ? "" : "No",
ctime(&cardList.cards[i].registrationDate));
}
printf("Press any key to go back to menu.\n");
getchar();
break;
case 3: {
int subChoice;
while (1) {
printf("1. Register new card\n");
printf("2. Add/remove access\n");
printf("3. Back\n");
scanf("%d", &subChoice);
getchar(); // Clear the input buffer
  if (subChoice == 1) {
                    int cardNumber, hasAccess;
                    printf("Enter card number: ");
                    scanf("%d", &cardNumber);
                    getchar(); // Clear the input buffer
                    printf("Enter 1 for access and 0 for no access: ");
                    scanf("%d", &hasAccess);
                    getchar(); // Clear the input buffer
                    addCard(&cardList, cardNumber, hasAccess);
                    printf("Card %d registered.\n", cardNumber);
                } else if (subChoice == 2) {
                    int cardNumber;
                    printf("Enter card number: ");
                    scanf("%d", &cardNumber);
                    getchar(); // Clear the input buffer
                    Card *card = findCard(&cardList, cardNumber);
                    if (card) {
                        printf("Card %d %s access.\n", cardNumber, card->hasAccess ? "has" : "does not have");
                        printf("Enter 1 for access and 0 for no access: ");
                        int access;
                        scanf("%d", &access);
                        getchar(); // Clear the input buffer
                        card->hasAccess = access == 1 ? 1 : 0;
                        printf("Card %d access updated.\n", cardNumber);
                    } else {
                        printf("Card not found.\n");
                    }
                } else if (subChoice == 3) {
                    break;
                } else {
                    printf("Invalid choice. Please try again.\n");
                }
            }
            break;
        }
        case 9: {
            printf("Please scan card to enter or x to exit.\n");
            printf("CURRENTLY LAMP IS: Off\n");
            while (1) {
                char input[10];
                scanf("%s", input);
                getchar(); // Clear the input buffer
                if (strcmp(input, "x") == 0) {
                    break;
                }
                int cardNumber = atoi(input);
                Card *card = findCard(&cardList, cardNumber);
                if (card) {
                    printf("CURRENTLY LAMP IS: %s\n", card->hasAccess ? "Green" : "Red");
                    if (card->hasAccess) {
                        if (!isLoggedIn(&loggedInCardList, cardNumber)) {
                            addLoggedInCard(&loggedInCardList, cardNumber);
                        }
                    }
                } 
                else {
                    printf("Card not found.\n");
                }
            }
            break;
        }
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

// Free allocated memory
free(cardList.cards);
free(loggedInCardList.cardNumbers);
return 0;
}
*/

//*****************************VG FILES VERSION********************************

// Card structure with necessary fields and a pointer to the next Card
typedef struct Card {
    int id;
    int access;
    char date[11];
    int logged_in;
    struct Card *next;
} Card;

int getMenuSelection() {
    int choice;
    while (1) {
        printf("\nAdmin menu\n");
        printf("1. Remote open door\n");
        printf("2. List all cards in system\n");
        printf("3. Add/remove access\n");
        printf("4. Exit\n");
        printf("9. FAKE TEST SCAN CARD\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4 || choice == 9) {
            return choice;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
}

// Function to add a card to the linked list of cards
Card *addCard(Card *head, int id, int access) {
    // Allocate memory for the new card and set its values
    Card *newCard = (Card *)malloc(sizeof(Card));
    newCard->id = id;
    newCard->access = access;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(newCard->date, sizeof(newCard->date), "%Y-%m-%d", tm);
    newCard->logged_in = 0;
    // Set the new card's next pointer to the current head and return the new card as the new head
    newCard->next = head;
    return newCard;
}

// Function to find a card in the linked list by ID
Card *findCard(Card *head, int id) {
    Card *current = head;
    // Traverse the linked list and return the card if the ID matches
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    // Return NULL if the card is not found
    return NULL;
}

// Function to remove a card from the linked list by ID
Card *removeCard(Card *head, int id) {
    Card *current = head;
    Card *prev = NULL;

    // Traverse the linked list, find the card by ID, and remove it
    while (current != NULL) {
        if (current->id == id) {
            // If the card is the head, update the head pointer
            if (prev == NULL) {
                head = current->next;
            } else {
                // Otherwise, update the previous card's next pointer
                prev->next = current->next;
            }
            // Free the memory of the removed card
            free(current);
            return head;
        }
        // Move to the next card
        prev = current;
        current = current->next;
    }
    return head;
}

// Function to print all cards in the linked list
void printCards(Card *head) {
    Card *current = head;
    // Traverse the linked list and print each card's information
    while (current != NULL) {
        printf("Card ID: %d, Access: %s, Registered: %s\n", current->id, current->access ? "Yes": "No", current->date);
        current = current->next;
    }
}
// Function to print all logged-in cards in the linked list
void printLoggedInCards(Card *head) {
    Card *current = head;// Traverse the linked list and print the ID of each logged-in card
    while (current != NULL) {
        if (current->logged_in) {
            printf("Card ID: %d\n", current->id);
        }
        current = current->next;
    }
}
// Function to print the lamp status with a given status string and duration in seconds
void printLampStatus(const char *status, int duration) {
    printf("CURRENTLY LAMP IS: %s\n", status);
    fflush(stdout);
    sleep(duration);
}

int main() {
    Card *head = NULL;    // Initialize the linked list with two cards
    head = addCard(head, 1212, 1);
    head = addCard(head, 1213, 1);

    int choice, subchoice, id;
    Card *card;
    while ((choice = getMenuSelection()) != 4) {
        switch (choice) {
            case 1:
                printLampStatus("Green", 3);
                break;
            case 2:   
                printCards(head);
                break;
            case 3:
                while (1) {
                    printf("\nCURRENTLY LAMP IS: Orange\n");
                    printf("1. Remote open door\n");
                    printf("2. List all logged in\n");
                    printf("3. List all\n");
                    printf("4. Add/remove access\n");
                    printf("5. Back\n");

                    printf("Enter your sub-choice: ");
                    scanf("%d", &subchoice);

                    if (subchoice == 1) {
                        printLampStatus("Green", 3);
                    } else if (subchoice == 2) {
                        printLoggedInCards(head);
                    } else if (subchoice == 3) {
                        printCards(head);
                    } else if (subchoice == 4) {
                        printf("Enter the card ID: ");
                        scanf("%d", &id);
                        card = findCard(head, id);
                        if (card == NULL) {
                            printf("Card not found. Do you want to add a new card? (y/n): ");
                            char addNew;
                            scanf(" %c", &addNew);
                            if (addNew == 'y' || addNew == 'Y') {
                                printf("Enter access (1 for access, 0 for no access): ");
                                int access;
                                scanf("%d", &access);
                                head = addCard(head, id, access);
                                printf("Card added successfully.\n");
                            }
                        } else {
                            printf("Card ID: %d, Access: %s\n", card->id, card->access ? "Yes" : "No");
                            printf("Enter new access (1 for access, 0 for no access): ");
                            int newAccess;
                            scanf("%d", &newAccess);
                            card->access = newAccess;
                            printf("Access updated successfully.\n");
                        }
                    } else if (subchoice == 5) {
                        break;
                    } else {
                        printf("Invalid sub-choice, please try again.\n");
                    }
                }
                break;
            case 9:
                printf("Please scan card to enter or x to exit.\n");
                printf("CURRENTLY LAMP IS: Off\n");
                while (1) {
                    printf("Enter card ID or x to exit: ");
                    char input[10];
                    scanf("%s", input);
                    if (strcmp(input, "x") == 0 || strcmp(input, "X") == 0) {
                        break;
                    }
                    id = atoi(input);
                    card = findCard(head, id);
                    if (card != NULL && card->access) {
                        printLampStatus("Green", 3);
                        card->logged_in = 1;
                    } else {
                        printLampStatus("Red", 3);
                    }
                }
                break;
        }
    }

    // Free memory
    Card *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
              