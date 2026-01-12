#include "statistics.h"

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