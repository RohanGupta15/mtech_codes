/*
STACK IMPLEMENTATION IN C USING ARRAY 
TODO
- DONE define isFUll and isEmplty function
- Main logic
    PUSH
    - check overflow
    - increase top val
    - insert the value
    POP
    - check underflow
    - decrease the top val
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

//Simple array search
bool isFull(int size, int top);
bool isEmpty(int top);

int main(void) {
    int size=10;
    int arr[size], element, choice;

    // top = -1 is taken as an convention for stack being empty
    int top=-1;

    // Creating Test Case
    int lower = 10, upper = 100;

    // Use current time as seed for random generator
    srand(time(0));
	
    for (int i = 0; i < size-5; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        arr[i] = num;
        top++;
    }
  
    //Print Stack
    printf("\nGenerated half empty stack\n");
    for(int i = 0 ; i <= top ; i++){
        printf("%d ",arr[i]);
    }
    printf("\nValue of Top: %d", top);
    
    // Present choice to user to insert at their desired position
    printf("\n\nPlease choose an option\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. Any other key to exit\n");
    printf("Enter your choice:  ");
    if (scanf("%d", &choice) != 1) {
        printf("An error occured during input\nExiting the program...\n");
        exit(0);
    }

    // exit the code
    printf("%d", choice);
    if (choice != 1 && choice != 2) {
        printf("\n\nExiting the code...\n\n");
        exit(0);
    }

    switch (choice) {
    case 1:
        //PUSH
        //checking overflow
        if(isFull(size, top)){
            printf("\nStack is full cannot PUSH the element");
            exit(0);
        }
        else{
            printf("\nEnter the element: ");
            if (scanf("%d", &element) != 1) {
                printf("An error occured during input\nExiting the code...\n");
                exit(0);
            }
            arr[++top]=element; //not sure if top will be permamently will be incremented
        }
        break;
    case 2:
        //POP
        //checking underflow
        if(isEmpty(top)){
            printf("\nStack is empty cannot POP the element");
            exit(0);
        }
        else{
            --top; //not sure if top will be permamently decremented
        }
        break;
    default:
        printf("\n\n\tExiting the code...\n\n");
    }
   
   
    //Print Stack
    printf("\nUpdated Stack\n");
    for(int i = 0 ; i <=top;i++){
        printf("%d ",arr[i]);
    }
    printf("\nValue of Top: %d", top);

    return 0;
}

bool isFull(int size, int top){
    if((size-1) == top)
        return true;
    else
        return false;
}

bool isEmpty(int top){
    if(top == -1)
        return true;
    else
        return false;
}
