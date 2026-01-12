#include "linear_regression.h"
#include "statistics.h"

LinearModel fit_model(float *vecX, float *vecY, int size) {
    LinearModel model;
    float varX = calculate_variance(vecX, size);
    float covarXY = calculate_covariance(vecX, vecY, size);
    
    model.slope = covarXY / varX;
    model.intercept = calculate_mean(vecY, size) - (model.slope * calculate_mean(vecX, size));
    
    return model;
}