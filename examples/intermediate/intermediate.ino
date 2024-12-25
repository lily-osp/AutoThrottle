#include <AutoThrottle.h>

// Create AutoThrottle instance with custom min/max throttle limits
AutoThrottle throttle(10, 200, Manual);

void setup() {
    Serial.begin(9600);

    // Set manual PID gains
    throttle.setManualGains(1.5, 0.8, 0.2);

    // Enable throttle smoothing with a ramp rate of 10 units per update
    throttle.enableThrottleSmoothing(true, 10.0);

    // Set target speed
    throttle.setTargetSpeed(75);
}

void loop() {
    // Simulate current speed from a sensor
    float currentSpeed = analogRead(A0) / 10.0;

    // Update the throttle control system
    throttle.updateCurrentSpeed(currentSpeed);

    // Compute the throttle output
    float throttleValue = throttle.computeThrottle();

    // Output throttle value to motor driver (e.g., PWM pin)
    analogWrite(9, throttleValue);

    // Debugging information
    Serial.print("Speed: ");
    Serial.print(currentSpeed);
    Serial.print(" | Throttle: ");
    Serial.println(throttleValue);

    delay(100);
}
