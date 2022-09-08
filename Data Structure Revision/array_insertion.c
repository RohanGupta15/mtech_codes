#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int size = 100;
  int arr[size], upper_bound = 50;
  int insert_at, insert_count;
  int choice, input_check;
  // Creating Test Case
  int lower = 10, upper = 100;

  // DONE Creating an example array
  // Use current time as seed for random generator
  srand(time(0));

  for (int i = 0; i < upper_bound - 1; i++) {
    int num = (rand() % (upper - lower + 1)) + lower;
    arr[i] = num;
  }

  // Print Array
  printf("\nGenerated array\n");
  for (int i = 0; i < upper_bound - 1; i++) {
    printf("%d ", arr[i]);
  }

  // DONE Present choice to user to insert at their desired position
  printf("\n\nPlease choose an option\n");
  printf("1. Insert element at start of array\n");
  printf("2. Insert element at end of array\n");
  printf("3. Insert element at a specific index of array\n");
  printf("Enter your choice:  ");
  if (scanf("%d", &choice) != 1) {
    printf("An error occured during input\nExiting the program...\n");
    exit(0);
  }

  // exit the code
  printf("%d", choice);
  if (choice != 1 && choice != 2 && choice != 3) {
    printf("\n\nExiting the code...\n\n");
    exit(0);
  }
  // Number of elements to enter
  printf("\nHow many elements you want to insert?\n");
  if (scanf("%d", &insert_count) != 1) {
    printf("An error occured during input\nExiting the program...\n");
    exit(0);
  }
  if (insert_count > (size - upper_bound)) {
    printf("Number of elements will exceed the max length of the array please "
           "choose a number smaller then %d to prevent data loss\n",
           size - upper_bound);
    exit(0);
  }
  switch (choice) {
  case 1:
    // Travesing & shifting the array
    for (int i = upper_bound - 1; i >= 0; i--) {
      arr[i + insert_count] = arr[i];
    }
    // Inserting the numbers
    printf("Please enter the values you want\n");
    for (int i = 0; i < insert_count; i++) {
      printf("\nEnter Number %d\n", i + 1);
      if (scanf("%d", &arr[i]) != 1) {
        printf("An error occured during input\nExiting the program...\n");
        exit(0);
      }
    }
    upper_bound += insert_count;
    break;
  case 2:
    // Adding elements at the end of array
    printf("Please enter the values you want\n");
    for (int i = 0; i < insert_count; i++) {
      printf("\nEnter Number %d\n", i + 1);

      if (scanf("%d", &arr[(upper_bound - 1) + i]) != 1) {
        printf("An error occured during input\nExiting the program...\n");
        exit(0);
      }
    }
    upper_bound += insert_count;
    break;
  case 3:
    printf("\nAt what index you want to start insertion?\n");

    if (scanf("%d", &insert_at) != 1) {
      printf("An error occured during input\nExiting the program...\n");
      exit(0);
    }
    if (insert_at > upper_bound) {
      printf("Insert position exeed upper bound of the array!\nExiting the "
             "code...\n");
      exit(0);
    }
    for (int i = upper_bound - 1; i >= insert_at; i--) {
      arr[i + insert_count] = arr[i];
    }
    // Inserting the numbers
    printf("Please enter the values you want\n");
    for (int i = insert_at; i < (insert_at + insert_count); i++) {
      printf("\nEnter number at index %d\n", i);

      if (scanf("%d", &arr[i]) != 1) {
        printf("An error occured during input\nExiting the program...\n");
        exit(0);
      }
    }
    upper_bound += insert_count;
    break;
  default:
    printf("\n\n\tExiting the code...\n\n");
  }
  // Print Array
  printf("\nNew array\n\n");
  for (int i = 0; i < upper_bound - 1; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
