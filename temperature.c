#include <stdio.h>
#include <stdbool.h>
#include "temperature.h"

// function to convert c to f
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}
// function to convert f to c
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}
// convert c to k
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}
// convert k to c
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}
// convert f to k
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}
// convert k to f
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// function to categorize the temperatures
void categorize_temp(float celsius) {
    printf("Advisory: \n");
    // if the temp is less than 0, print freezing advisory 
    if (celsius < 0) {
        printf("Freezing: Dress warm & stay indoors.\n");
    // if the temp is between 0 - 10, print cold advisory
    } else if (celsius >= 0 && celsius < 10) {
        printf("Cold: Wear a jacket.\n");
    // if the temp is between 10 - 25, print comfortable advisory
    } else if (celsius >= 10 && celsius < 25) {
        printf("Comfortable: Go outside & enjoy the weather!\n");
    // if the temp is between 25 - 35, print hot advisory
    } else if (celsius >= 25 && celsius < 35) {
        printf("Hot: Dress light & stay hydrated.\n");
    // when temp is greater than 35, print extreme heat advisory
    } else {
        printf("Extreme Heat: Cool off indoors & void outdoor activites.\n");
    }
}

// function for handling extreme cases 
static bool temp_errorHandling(float temp, char scale) {
    // kelvin temps cannot be negative 
    if (scale == 'K' && temp < 0) {
        printf("Error: Temperature in Kelvin cannot be negative.\n");
        return false;
    }
    // celsius temp at absolute 0
    if (scale == 'C' && temp < -273.15) {
        printf("Error: Temperature is below absolute zero.\n");
        return false;
    }
    // fahrenheit temp at absolute 0
    if (scale == 'F' && temp < -460) {
        printf("Error: Temperature is below absolute zero.\n");
        return false;
    }
    return true;
}
