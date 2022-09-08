#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
    int size=100;
    int arr[size], upper_bound=50;
    int delete_at, delete_count;
    int choice, input_check;
    // Creating Test Case
    int lower = 10, upper = 100;
    // Use current time as seed for random generator
    srand(time(0));
	
    for (int i = 0; i < upper_bound-1; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        arr[i] = num;
    }
  
    //Print Array
    printf("\nGenerated array\n");
    for(int i = 0 ; i < upper_bound-1;i++){
        printf("%d ",arr[i]);
    }

    // Present choice to user to delete at their desired position
    printf("\n\nPlease choose an option\n");
    printf("1. Delete element at start of array\n");
    printf("2. Delete element at end of array\n");
    printf("3. Delete element at a specific index of array\n");
    printf("4. Enter any other key to exit\n");
    printf("Enter your choice:  ");
    if(scanf("%d", &choice) != 1){
        printf("An error occured during input\nExiting the program...\n");
        exit(0);
    }

    //exit the code
    printf("%d",choice);
    if(choice != 1 && choice != 2 && choice != 3){
        printf("\n\nExiting the code...\n\n");
        exit(0);
    }
	
    //Number of elements to delete
    printf("\nHow many elements you want to delete?\n");
    if(scanf("%d",&delete_count) != 1){
        printf("An error occured during input\nExiting the program...\n");
        exit(0);
    }
    if(delete_count>(upper_bound-1)){
        printf("You wish to delete more number of elements then actually present in the array\nCurrent array length: %d",upper_bound-1);
        exit(0);
    }
	
    switch(choice){
        case 1: 
            // Travesing & shifting the array 
            for(int i = 0; i<=upper_bound-(delete_count+2) ;i++)
                arr[i] = arr[i+delete_count];
            upper_bound-= delete_count;
            break;
        case 2:
            /*
                Deleting elements at the end of array
                We delete by simply reducing the last element
            */
            upper_bound-= delete_count;
            break;
        case 3:
            printf("\nAt what index you want to start deletion?\n");
            if(scanf("%d", &delete_at) != 1){
                printf("An error occured during input\nExiting the program...\n");
                exit(0);
            }
            if(delete_at>upper_bound){
                printf("Deletion position exeed upper bound of the array!\nExiting the code...\n");
                exit(0);
            }
            for(int i = delete_at ; i <=upper_bound-2 ; i++){
                arr[i] = arr[i+delete_count];
            }
            upper_bound-= delete_count;
            break;
        default:
            printf("\n\n\tExiting the code...\n\n");
    }
    //Print Array
    printf("\nNew array\n");
    for(int i = 0 ; i < upper_bound-1;i++){
        printf("%d ",arr[i]);
    }
	//show array length
	printf("\nNew array length: %d\n",upper_bound);
    return 0;
}