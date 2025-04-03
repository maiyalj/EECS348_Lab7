#include <stdio.h>
#include "football.h"

// function to count all the possible combinations
int count_combinations(int points) {
    // declare count variable 
    int count = 0;
    // nested loops that goes through all combinations 
    for (int td2pt = 0; td2pt * 8 <= points; td2pt++) {
        for (int tdFg = 0; tdFg * 7 + td2pt * 8 <= points; tdFg++) {
            for (int td = 0; td * 6 + tdFg * 7 + td2pt * 8 <= points; td++) {
                for (int fg = 0; fg * 3 + td * 6 + tdFg * 7 + td2pt * 8 <= points; fg++) {
                    for (int safety = 0; safety * 2 + fg * 3 + td * 6 + tdFg * 7 + td2pt * 8 <= points; safety++) {
                        if (safety * 2 + fg * 3 + td * 6 + tdFg * 7 + td2pt * 8 == points) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count;
}
// function to print combinations
void print_combinations(int points) {
    // print number of combinations
    printf("\nPossible combinations of scoring plays if a team's score is %d:\n\n", points);
    int count = 0;
    for (int td2pt = 0; td2pt * 8 <= points; td2pt++) {
        for (int tdFg = 0; tdFg * 7 + td2pt * 8 <= points; tdFg++) {
            for (int td = 0; td * 6 + tdFg * 7 + td2pt * 8 <= points; td++) {
                for (int fg = 0; fg * 3 + td * 6 + tdFg * 7 + td2pt * 8 <= points; fg++) {
                    for (int safety = 0; safety * 2 + fg * 3 + td * 6 + tdFg * 7 + td2pt * 8 <= points; safety++) {
                        if (safety * 2 + fg * 3 + td * 6 + tdFg * 7 + td2pt * 8 == points) {
                            // format output of all the combinations
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, tdFg, td, fg, safety);
                            count++;
                        }
                    }
                }
            }
        }
    }
    // check if count is 0 and print error
    if (count == 0) {
        printf("There are no combinations for this score.\n");
    } else {
        // otherwise print total
        printf("\nTotal combinations found: %d\n", count);
    }
}
