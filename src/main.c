#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 125
#define countof(arr) (sizeof(arr) / sizeof((arr)[0]))

char any_parts[][125] = {"Do you actualy have any parts?",
                         "Is there anything in stock at all?"};
char user_input[INPUT_SIZE];

const char inventory[][64] = {"hydraulic pump", "PLC module", "servo motor"};

int main(void) {

  puts("Hej. Welcome to the spare parts inventory!");

  while (1) {

    puts("\nWhich part do you need?");
    scanf(" %100[^\n]", user_input); // User input

    // Checking if user input one of the sentences in any_parts
    // If true the inventory is printed
    if (strcmp(user_input, any_parts[0]) == 0 ||
        strcmp(user_input, any_parts[1]) == 0) {
      printf("We have 3 part(s)!\n");

      for (int i = 0; i < countof(inventory); i++) {
        printf("%s\n", inventory[i]);
      }
    } else {
      // Searching the inventory
      // If the user input matches with an item
      // in the inventory the program will end.
      for (int i = 0; i < countof(inventory); i++) {

        if (strcmp(user_input, inventory[i]) == 0) {
          printf("\nI've got %s here for you", user_input);
          return 0;
        }
      }
      printf("I am afraid we don't have any >>> %s <<< in the inventory.\n\n",
             user_input);
    }
  }
}
