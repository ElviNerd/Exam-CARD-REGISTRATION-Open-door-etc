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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

// Card structure
typedef struct {
    int cardNumber;
    int hasAccess;
    time_t registrationDate;
} Card;

// Node structure for the linked list
typedef struct Node {
    Card card;
    struct Node *next;
} Node;

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
        if (selection >= 1 && selection <= 4 || selection == 9) {
            return selection;
        }
        printf("Invalid choice. Please try again.\n");
    }
}

// Function to load cards from files
Node *loadCards() {
    Node *head = NULL;
    Node *current = NULL;
    int cardNumber = 0;

    while (1) {
        char filename[64];
        snprintf(filename, sizeof(filename), "cards/card_%d.dat", cardNumber);
        FILE *file = fopen(filename, "rb");

        if (file) {
            Node *newNode = malloc(sizeof(Node));
            fread(&newNode->card, sizeof(Card), 1, file);
            newNode->next = NULL;
            if (current) {
                current->next = newNode;
            } else {
                head = newNode;
            }
            current = newNode;
            fclose(file);
            cardNumber++;
        } else {
            break;
        }
    }

    return head;
}

// Function to save a card to a file
void saveCardToFile(const Card *card) {
    char filename[64];
    snprintf(filename, sizeof(filename), "cards/card_%d.dat", card->cardNumber);
    FILE *file = fopen(filename, "wb");

    if (file) {
        fwrite(card, sizeof(Card), 1, file);
        fclose(file);
    }
}

// Function to add a card to the linked list
void addCard(Node **head, int cardNumber, int hasAccess) {
    Node *newNode = malloc(sizeof(Node));
    newNode->card.cardNumber = cardNumber;
    newNode->card.hasAccess = hasAccess;
    newNode->card.registrationDate = time(NULL);
    newNode->next = *head;
    *head = newNode;

    // Save the card to a file
    saveCardToFile(&newNode->card);
}

// Function to find a card in the linked list by card number
Node *findCard(Node *head, int cardNumber) {
    Node *current = head;
    while (current) {
        if (current->card.cardNumber == cardNumber) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function// Function to print a card's information
void printCardInfo(const Card *card) {
    printf("Card number: %d\n", card->cardNumber);
    printf("Has access: %s\n", card->hasAccess ? "Yes" : "No");
    printf("Registration date: %s", ctime(&card->registrationDate));
}

// Function to list all cards in the system
void listAllCards(Node *head) {
    Node *current = head;
    while (current) {
        printCardInfo(&current->card);
        current = current->next;
    }
}

// Function to free the memory of the linked list
void freeList(Node *head) {
    Node *current = head;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

// Function to add or remove access for a card
void addRemoveAccess(Node *head, int cardNumber, int hasAccess) {
    Node *cardNode = findCard(head, cardNumber);
    if (cardNode) {
        cardNode->card.hasAccess = hasAccess;
        saveCardToFile(&cardNode->card);
        printf("Card access updated.\n");
    } else {
        printf("Card not found.\n");
    }
}

// Function to check if a card is logged in
bool isLoggedIn(const LoggedInCardList *loggedInCardList, int cardNumber) {
    for (size_t i = 0; i < loggedInCardList->count; i++) {
        if (loggedInCardList->cardNumbers[i] == cardNumber) {
            return true;
        }
    }
    return false;
}

// Function to log in a card
void logInCard(LoggedInCardList *loggedInCardList, int cardNumber) {
    loggedInCardList->cardNumbers = realloc(loggedInCardList->cardNumbers, (loggedInCardList->count + 1) * sizeof(int));
    loggedInCardList->cardNumbers[loggedInCardList->count++] = cardNumber;
}

// Function to log out a card
void logOutCard(LoggedInCardList *loggedInCardList, int cardNumber) {
    for (size_t i = 0; i < loggedInCardList->count; i++) {
        if (loggedInCardList->cardNumbers[i] == cardNumber) {
            loggedInCardList->cardNumbers[i] = loggedInCardList->cardNumbers[--loggedInCardList->count];
            break;
        }
    }
    loggedInCardList->cardNumbers = realloc(loggedInCardList->cardNumbers, loggedInCardList->count * sizeof(int));
}

int main() {
    Node *head = loadCards();
    LoggedInCardList loggedInCardList = {NULL, 0};

    while (1) {
        int selection = getMenuSelection();
        switch (selection) {
            case 1:
                printf("Door opened remotely.\n");
                break;
            case 2:
                listAllCards(head);
                break;
            case 3: {
                int cardNumber;
                printf("Enter card number: ");
                scanf("%d", &cardNumber);
                getchar(); // Clear the input buffer
                Node *cardNode = findCard(head, cardNumber);
                if (cardNode) {
                    cardNode->card.hasAccess = !cardNode->card.hasAccess;
                    saveCardToFile(&cardNode->card);
                    printf("Card access updated.\n");
                } else {
                    printf("Card not found.\n");
                }
                break;
            }
            case 4:
                freeList(head);
                free(loggedInCardList.cardNumbers);
                return 0;
                default:
                printf("Invalid selection. Please try again.\n");
                break;
                }
                }
                return 0;
}