#include <math.h>

#include "statistics.h"// Includes the Array structure and function declarations for this library.


//Adds every value in the array and returns the total.
double array_sum(const Array *array) {
    double sum = 0.0;

    for (int i = 0; i < array->size; i++) {
        sum += array->values[i];
    }

    return sum;
}

//Finds and returns the average of the array values.
double array_average(const Array *array) {
    return array_sum(array) / array->size;
}

/*Calculates and returns the population standard deviation by finding each value's from the average,squaring it, then adding it.
 After, dividing  by the number of values and taking the dquare root of that.*/
double array_stddev(const Array *array) {
    double average = array_average(array);
    double squared_differences = 0.0;


    for (int i = 0; i < array->size; i++) {
        double difference = array->values[i] - average;
        squared_differences += difference * difference;
    }


    return sqrt(squared_differences / array->size);
}
//Finds and returns the smallest value in the array by using the first value as the current minimum and then comparing it o every remaining value.
double array_min(const Array *array) {

    double minimum = array->values[0];


    for (int i = 1; i < array->size; i++) {
        if (array->values[i] < minimum) {
            minimum = array->values[i];
        }
    }

    return minimum;
}

//Finds and returns the largest value in the array by using the first value as the current max and comparing it to the remaing values
double array_max(const Array *array) {

    double maximum = array->values[0];


    for (int i = 1; i < array->size; i++) {
        if (array->values[i] > maximum) {
            maximum = array->values[i];
        }
    }

    return maximum;
}

//Calculates the positive difference between the maximum and minimum values.
double array_range(const Array *array) {
    return fabs(array_max(array) - array_min(array));
}
