#include <AutoThrottle.h>

// Create AutoThrottle instance with IMC tuning
AutoThrottle throttle(0, 255, IMC);

void setup() {
    Serial.begin(9600);

    // Enable throttle smoothing with a fine ramp rate
    throttle.enableThrottleSmoothing(true, 5.0);

    // Set target speed
    throttle.setTargetSpeed(100);

    Serial.println("Throttle system initialized!");
}

void loop() {
    // Simulate current speed from a sensor
    float currentSpeed = analogRead(A0) / 10.0;

    // Update the throttle control system
    throttle.updateCurrentSpeed(currentSpeed);

    // Compute the throttle output
    float throttleValue = throttle.computeThrottle();

    // Output throttle value to motor driver
    analogWrite(9, throttleValue);

    // Check if the system is stable
    if (throttle.isStable(0.5)) {
        Serial.println("System is stable!");
    } else {
        Serial.println("Adjusting throttle...");
    }

    // Debugging information
    Serial.print("Speed: ");
    Serial.print(currentSpeed);
    Serial.print(" | Throttle: ");
    Serial.println(throttleValue);

    delay(100);
}
