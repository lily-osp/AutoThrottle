#include "AutoThrottle.h"

AutoThrottle::AutoThrottle(float minThrottle, float maxThrottle, TuningMethod method)
    : _minThrottle(minThrottle), _maxThrottle(maxThrottle),
      _pid(minThrottle, maxThrottle, method),
      _smoothingEnabled(false), _rampRate(5.0), _currentThrottle(0) {
    _pid.setSetpoint(0); // Default target speed
}

void AutoThrottle::setTargetSpeed(float targetSpeed) {
    _setpoint = targetSpeed;
    _pid.setSetpoint(targetSpeed);
}

void AutoThrottle::updateCurrentSpeed(float currentSpeed) {
    _input = currentSpeed;
    _pid.update(currentSpeed);
}

float AutoThrottle::computeThrottle() {
    float desiredThrottle = _pid.getOutput();

    if (_smoothingEnabled) {
        desiredThrottle = applyThrottleSmoothing(desiredThrottle);
    }

    _currentThrottle = desiredThrottle;
    return _currentThrottle;
}

void AutoThrottle::reset() {
    _pid.setManualGains(0, 0, 0); // Reset gains
    _currentThrottle = 0;
}

void AutoThrottle::setTuningMethod(TuningMethod method) {
    _pid.setTuningMethod(method);
}

void AutoThrottle::setManualGains(float kp, float ki, float kd) {
    _pid.setManualGains(kp, ki, kd);
}

void AutoThrottle::enableThrottleSmoothing(bool enable, float rampRate) {
    _smoothingEnabled = enable;
    _rampRate = rampRate;
}

float AutoThrottle::applyThrottleSmoothing(float desiredThrottle) {
    // Ramp up or down smoothly based on the ramp rate
    if (desiredThrottle > _currentThrottle) {
        _currentThrottle += min(_rampRate, desiredThrottle - _currentThrottle);
    } else if (desiredThrottle < _currentThrottle) {
        _currentThrottle -= min(_rampRate, _currentThrottle - desiredThrottle);
    }
    return _currentThrottle;
}

float AutoThrottle::getThrottle() const {
    return _currentThrottle;
}

bool AutoThrottle::isStable(float tolerance) const {
    // Check if the system is within the target tolerance
    return abs(_setpoint - _input) <= tolerance;
}
