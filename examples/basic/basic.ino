#include <AutoThrottle.h>

// Create AutoThrottle instance with default Ziegler-Nichols tuning
AutoThrottle throttle(0, 255, ZieglerNichols);

void setup() {
    Serial.begin(9600);

    throttle.setTargetSpeed(50); // Set target speed
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

    // Print throttle and current speed
    Serial.print("Speed: ");
    Serial.print(currentSpeed);
    Serial.print(" | Throttle: ");
    Serial.println(throttleValue);

    delay(100);
}
