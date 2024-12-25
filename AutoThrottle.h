#ifndef AUTOTHROTTLE_H
#define AUTOTHROTTLE_H

#include <Arduino.h>
#include "AutoTunePID.h"

class AutoThrottle {
public:
    // Constructor
    AutoThrottle(float minThrottle, float maxThrottle, TuningMethod method = ZieglerNichols);

    // Configuration methods
    void setTargetSpeed(float targetSpeed);
    void updateCurrentSpeed(float currentSpeed);
    float computeThrottle();
    void reset(); // Reset PID and throttle

    // Advanced Configuration
    void setTuningMethod(TuningMethod method);
    void setManualGains(float kp, float ki, float kd);
    void enableThrottleSmoothing(bool enable, float rampRate = 5.0);

    // Status and debugging
    float getThrottle() const;
    bool isStable(float tolerance = 0.1) const;

private:
    // AutoTunePID instance
    AutoTunePID _pid;

    // Throttle and speed parameters
    float _input, _output, _setpoint;
    float _minThrottle, _maxThrottle;

    // Smoothing settings
    bool _smoothingEnabled;
    float _rampRate;
    float _currentThrottle;

    // Helper methods
    float applyThrottleSmoothing(float desiredThrottle);
};

#endif
