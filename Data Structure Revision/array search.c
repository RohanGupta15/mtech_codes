#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Simple array search
int array_search(int arr[], int upper_bound, int search_value);

int main(void) {
    int size=100;
    int arr[size], upper_bound=50;
    int search_value, result=-1;
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
    
   // Ask user the value they want to find
    printf("\nEnter value you want to find: ");
    if(scanf("%d",&search_value) != 1){
        printf("An error occured during input\nExiting the program...\n");
        exit(0);
    }

    // Simple array search
    result = array_search(arr, upper_bound, search_value);
    if(result != -1){
        printf("\n\nValue found is present at %d position\n", result);
    }
    else{
        printf("\n\nValue not found in the array\n");
    }

    return 0;
}

int array_search(int arr[], int upper_bound ,int search_value){
    for(int i = 0 ; i<upper_bound;i++){
        if(search_value == arr[i])
            return (i+1);
    }
}