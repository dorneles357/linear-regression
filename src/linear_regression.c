#include "linear_regression.h"
#include "statistics.h"
#include <math.h>

LinearModel fit_model(float *vecX, float *vecY, int size) {
    LinearModel model;
    float varX = calculate_variance(vecX, size);
    float covarXY = calculate_covariance(vecX, vecY, size);
    
    model.slope = covarXY / varX;
    model.intercept = calculate_mean(vecY, size) - (model.slope * calculate_mean(vecX, size));
    
    return model;
}

float r2_score(float *vecX, float *vecY, LinearModel model, int size) {
    float meanY = calculate_mean(vecY, size);
    float ssTotal = 0.0f;
    float ssResidual = 0.0f;

    for (int i = 0; i < size; i++) {
        float predictedY = model.slope * vecX[i] + model.intercept;
        ssTotal += (vecY[i] - meanY) * (vecY[i] - meanY);
        ssResidual += (vecY[i] - predictedY) * (vecY[i] - predictedY);
    }

    return 1.0f - (ssResidual / ssTotal);
}

float standard_error(float *vecX, float *vecY, LinearModel model, int size) {
    float ssResidual = 0.0f;

    for (int i = 0; i < size; i++) {
        float predictedY = model.slope * vecX[i] + model.intercept;
        ssResidual += (vecY[i] - predictedY) * (vecY[i] - predictedY);
    }

    float variance = ssResidual / (size - 2);

    return (variance);
}