#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

typedef struct {
    float slope;
    float intercept;
} LinearModel;

float calculate_mean(float *vector, int size);
float calculate_variance(float *vector, int size);
float calculate_covariance(float *vecA, float *vecB, int size);
LinearModel fit_model(float *vecX, float *vecY, int size);

#endif