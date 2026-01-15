#ifndef STATISTICS_H
#define STATISTICS_H

float calculate_mean(float *vector, int size);
float calculate_variance(float *vector, int size);
float calculate_covariance(float *vecA, float *vecB, int size);
float calculate_standard_deviation(float *vector, int size);

#endif