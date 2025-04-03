#include <stdio.h>
#include <stdbool.h>
#include "temperature.h"

// main function
int main() {
    // declare float variables for temp and converted_temp
    float temp, converted_temp;
    // declare char variables
    char input_scale, target_scale;
    char choice;
    // while true run program
    while (1) {
        // user inputs starting temp
        printf("Enter temperature value: ");
        // error handling for invalid inputs
        while (scanf("%f", &temp) != 1) {
            printf("Input invalid. Please enter a number: ");
            // clear input buffer
            while (getchar() != '\n');
        }
        // user input scale for starting temp
        printf("Enter input scale (C, F, K): ");
        // check if input was valid 
        while (scanf(" %c", &input_scale) != 1 || (input_scale != 'C' && input_scale != 'F' && input_scale != 'K')) {
            // print error if invalid
            printf("Input scale invalid. Please enter scale (C, F, K): ");
            // clear input buffer
            while (getchar() != '\n'); 
        }
        // user input for scale to convert to 
        printf("Enter target scale (C, F, K): ");
        // check if input was valid, including whether it is the same scale 
        while (scanf(" %c", &target_scale) != 1 || (target_scale != 'C' && target_scale != 'F' && target_scale != 'K') || target_scale == input_scale) {
            // print error if invalid
            printf("Invalid or same target scale. Please enter (C, F, K): ");
            // clear input buffer
            while (getchar() != '\n'); 
        }
        // convert temperature; go through all possible conversions
        if (input_scale == 'F' && target_scale == 'C') {
            converted_temp = fahrenheit_to_celsius(temp);
        } else if (input_scale == 'F' && target_scale == 'K') {
            converted_temp = fahrenheit_to_kelvin(temp);
        } else if (input_scale == 'C' && target_scale == 'F') {
            converted_temp = celsius_to_fahrenheit(temp);
        } else if (input_scale == 'C' && target_scale == 'K') {
            converted_temp = celsius_to_kelvin(temp);
        } else if (input_scale == 'K' && target_scale == 'F') {
            converted_temp = kelvin_to_fahrenheit(temp);
        } else if (input_scale == 'K' && target_scale == 'C') {
            converted_temp = kelvin_to_celsius(temp);
        }
        // print converted temp
        printf("\nConverted Temperature: %.2f %c\n", converted_temp, target_scale);
        // call categorize_temp function
        categorize_temp(converted_temp);

        // ask user if they would like to do another conversion
        printf("Would you like to do another conversion? (Y/N): ");
        // check if invalid
        while (scanf(" %c", &choice) != 1 || (choice != 'Y' && choice != 'N' && choice != 'y' && choice != 'n')) {
            printf("Choice invalid. Enter Y to continue or N to exit: ");
            // clear input buffer
            while (getchar() != '\n'); 
        }
        // end program if user entered 'n'
        if (choice == 'N' || choice == 'n') {
            break;
        }
    } return 0;
}
