#include <stdio.h>

#include "output_array.h"// Includes the output_array function declaration and Array structure.

//Prints every value in an Array in a readable list format.
void output_array(const Array *array) {

    printf("Array: [");

    //Print each value from the array.
    for (int i = 0; i < array->size; i++) {

        printf("%.2f", array->values[i]);

        //Print a comma after every value except the last one.
        if (i < array->size - 1) {
            printf(", ");
        }
    }


    printf("]\n");
}

