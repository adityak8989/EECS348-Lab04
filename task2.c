#include <stdio.h>

int main() {
    float temp;
    char original_scale;
    char conv_scale;
    float temp_in_celsius;
    float converted_temp;

    printf("Enter the temperature value: ");
    scanf("%f", &temp);

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &original_scale);

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &conv_scale);

    if (original_scale == 'C' || original_scale == 'c') {
        temp_in_celsius = temp;
    } else if (original_scale == 'F' || original_scale == 'f') {
        temp_in_celsius = (temp - 32.0f) * (5.0f / 9.0f);
    } else if (original_scale == 'K' || original_scale == 'k') {
        temp_in_celsius = temp - 273.15f;
    } else {
        printf("Invalid original scale entered.\n");
        return 1;
    }

    if (conv_scale == 'C' || conv_scale == 'c') {
        converted_temp = temp_in_celsius;
    } else if (conv_scale == 'F' || conv_scale == 'f') {
        converted_temp = (temp_in_celsius * 9.0f / 5.0f) + 32.0f;
    } else if (conv_scale == 'K' || conv_scale == 'k') {
        converted_temp = temp_in_celsius + 273.15f;
    } else {
        printf("Invalid target scale entered.\n");
        return 1;
    }

    printf("Converted temperature: %.2f %c\n", converted_temp, conv_scale);

    if (temp_in_celsius < 0.0f) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay indoors !\n");
    } else if (temp_in_celsius >= 0.0f && temp_in_celsius < 10.0f) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (temp_in_celsius >= 10.0f && temp_in_celsius < 25.0f) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Weather is pleasant!\n");
    } else if (temp_in_celsius >= 25.0f && temp_in_celsius < 35.0f) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors due to high heat\n");
    }

    return 0;
}