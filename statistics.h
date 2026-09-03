#ifndef STATISTICS_H
#define STATISTICS_H

//Custom data type that keeps an array and its size together.
typedef struct {
    double *values;  //Pointer to the first number in the array.
    int size;        //Number of values stored in the array.
} Array;

/*The next lines of code all will in order return the, total off all the values in the array, average, population standard deviation,smalles value,
largest value, and the absolute difference between the min and max*/
double array_sum(const Array *array);

double array_average(const Array *array);

double array_stddev(const Array *array);

double array_min(const Array *array);

double array_max(const Array *array);

double array_range(const Array *array);

#endif
