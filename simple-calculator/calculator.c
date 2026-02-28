#include <stdio.h>

/**
 * main - Simple Calculator (skeleton)
 *
 * Return: 0
 */
int main (void) 
{
    int choice;
    int A;
    int B;
    int Result;
    
    do {

    printf("Simple Calculator\n");
    printf("1) Add\n");
    printf("2) Subtract\n");
    printf("3) Multiply\n");
    printf("4) Divide\n");
    printf("0) Quit\n");
    printf("Choice: ");
    scanf("%d", &choice);

      if(choice > 4 || choice < 0) {
        printf("Invalid choice\n");
    }


     if(choice > 0 && choice <= 4){
        printf("A: ");
        scanf("%d", &A);
        printf("B: ");
        scanf("%d", &B);
        if(choice ==1){
        Result = A + B;
        printf("Result: %d\n", Result);

        }
        else if(choice == 2){
        Result = A - B;
        printf("Result: %d\n", Result);
        
    }
   
    }
  
    }
    while(choice != 0);

    printf("Bye!\n");

   

   
     
    return (0);
}