#include <stdio.h>
#include "football.h"

// main function
int main() {
    // declare integer variable score 
    int score;
    //while true, run program
    while (1) {
        // ask user to enter value for the score
        printf("\nEnter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        // end program if user enters 0 or 1 
        if (score <= 1) {
            break;
        }
        // run print_combinations function
        print_combinations(score);
    }
    return 0;
}
