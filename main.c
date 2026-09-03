#include <stdio.h>

//Includes the Array structure and all statistics function declarations.
#include "statistics.h"

//Includes the output_array() function declaration.
#include "output_array.h"

//Max number of values the user may enter for one array.
#define MAX_SIZE 10

//Reads a valid array size and then reads that many values from the user.
void get_array_input(double values[], int *size, int array_number) {
    //Asks the user how many values they want in this array.
    printf("How many values are in array %d? ", array_number);

    //Keep asking until the user enters a size from 1 to MAX_SIZE.
    while (scanf("%d", size) != 1 || *size < 1 || *size > MAX_SIZE) {
        printf("Please enter a whole number from 1 to %d: ", MAX_SIZE);

        //Removes invalid characters left in the input buffer.
        while (getchar() != '\n') {
        }
    }

    //Asks for each decimal value in the array, and keeps asking until valid input
    for (int i = 0; i < *size; i++) {
        printf("Enter value %d: ", i + 1);

       
        while (scanf("%lf", &values[i]) != 1) {
            printf("Please enter a number: ");

            //Removes invalid characters before trying scanf again.
            while (getchar() != '\n') {
            }
        }
    }
}

//Prints the array and every requested calculation for one Array structure.
void print_results(const Array *array) {
    output_array(array);

    printf("the average is: %.2f\n", array_average(array));
    printf("the std is: %.2f\n", array_stddev(array));
    printf("the sum is: %.2f\n", array_sum(array));
    printf("the minimum is: %.2f\n", array_min(array));
    printf("the maximum is: %.2f\n", array_max(array));
    printf("the absolute difference between max and min is: %.2f\n\n",
           array_range(array));
}

int main(void) {
    //Reserves the space for up to MAX_SIZE decimal values in each array.
    double first_values[MAX_SIZE];
    double second_values[MAX_SIZE];
    double third_values[MAX_SIZE];

    //These variables will store the user-selected size of each array.
    int first_size;
    int second_size;
    int third_size;

    //Reads the sizes and values for all three arrays.
    get_array_input(first_values, &first_size, 1);
    get_array_input(second_values, &second_size, 2);
    get_array_input(third_values, &third_size, 3);

    //Puts each normal C array and its actual used size into an Array structure.
    Array first = {first_values, first_size};
    Array second = {second_values, second_size};
    Array third = {third_values, third_size};

    //Display each array and its statistics.
    printf("\nArray 1 results:\n");
    print_results(&first);

    printf("Array 2 results:\n");
    print_results(&second);

    printf("Array 3 results:\n");
    print_results(&third);

    return 0;
}
