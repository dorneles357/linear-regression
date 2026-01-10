#include "linear_regression.h"

static float calculate_sum(float *vector, int size) {
    float total = 0.0;
    for(int i = 0; i < size; i++) {
        total += vector[i];
    }
    return total;
}

float calculate_mean(float *vector, int size) {
    return calculate_sum(vector, size) / size;
}

float calculate_variance(float *vector, int size) {
    float mean = calculate_mean(vector, size);
    float var = 0.0;
    for(int i = 0; i < size; i++) {
        var += (vector[i] - mean) * (vector[i] - mean);
    }
    return var / size;
}

float calculate_covariance(float *vecX, float *vecY, int size) {
    float meanX = calculate_mean(vecX, size);
    float meanY = calculate_mean(vecY, size);
    float covar = 0.0;
    for(int i = 0; i < size; i++) {
        covar += (vecX[i] - meanX) * (vecY[i] - meanY);
    }
    return covar / size;
}

LinearModel fit_model(float *vecX, float *vecY, int size) {
    LinearModel model;
    float varX = calculate_variance(vecX, size);
    float covarXY = calculate_covariance(vecX, vecY, size);
    
    model.slope = covarXY / varX;
    model.intercept = calculate_mean(vecY, size) - (model.slope * calculate_mean(vecX, size));
    
    return model;
}