# AutoThrottle Library

## Overview
**AutoThrottle** is an Arduino library designed to provide a dynamic and adaptive throttle control system. It is particularly useful in applications where precise control of speed or motor output is critical, such as robotics, drones, or motorized vehicles. The library integrates the **AutoTunePID** system to offer both automatic and manual PID tuning, along with advanced features like throttle smoothing, stability checks, and flexible configuration options.

---

## Key Features

1. **PID-Based Throttle Control**
   - Leverages PID (Proportional-Integral-Derivative) control to achieve precise speed or output regulation.
   - Supports automatic tuning using **AutoTunePID** with multiple methods:
     - Ziegler-Nichols
     - Cohen-Coon
     - Relay Feedback
     - Internal Model Control (IMC)
   - Allows manual tuning for custom PID gains.

2. **Throttle Smoothing**
   - Gradual ramping of throttle to avoid sudden spikes or dips.
   - Adjustable ramp rate for fine control over throttle response.

3. **Dynamic Target Adjustment**
   - Update the target speed or desired output dynamically during runtime.

4. **Real-Time Stability Monitoring**
   - Built-in functionality to assess system stability based on error tolerance.
   - Enables monitoring and debugging in real-world scenarios.

5. **Flexible Input and Output Limits**
   - Configurable throttle limits to match the hardware and application constraints.

6. **Real-World Ready**
   - Designed for seamless integration into robotics, motorized systems, and other projects requiring precise motor control.

---

## Installation

1. **Download the Library**
   - Download the AutoThrottle library from the GitHub repository or as a .zip file.

2. **Add to Arduino IDE**
   - Open Arduino IDE.
   - Go to **Sketch** > **Include Library** > **Add .ZIP Library...**
   - Select the downloaded .zip file and import it.

3. **Verify Installation**
   - Navigate to **File** > **Examples** > **AutoThrottle** to see example sketches included with the library.

---

## API Documentation

### Constructor
```cpp
AutoThrottle(float minThrottle, float maxThrottle, TuningMethod method = ZieglerNichols);
```
- **minThrottle**: Minimum allowable throttle value.
- **maxThrottle**: Maximum allowable throttle value.
- **method**: Tuning method used by AutoTunePID (default: ZieglerNichols).

### Methods

#### Configuration
1. **setTargetSpeed(float targetSpeed)**
   - Sets the desired speed or output for the throttle system.
   - **Parameters:**
     - `targetSpeed`: Target speed value in the desired unit.

2. **setTuningMethod(TuningMethod method)**
   - Updates the tuning method for AutoTunePID.
   - **Parameters:**
     - `method`: Tuning method (ZieglerNichols, CohenCoon, RelayFeedback, IMC).

3. **setManualGains(float kp, float ki, float kd)**
   - Manually sets PID gains for the system.
   - **Parameters:**
     - `kp`: Proportional gain.
     - `ki`: Integral gain.
     - `kd`: Derivative gain.

4. **setThrottleLimits(float minThrottle, float maxThrottle)**
   - Updates the minimum and maximum allowable throttle values.
   - **Parameters:**
     - `minThrottle`: Minimum throttle value.
     - `maxThrottle`: Maximum throttle value.

#### Real-Time Operation
5. **updateCurrentSpeed(float currentSpeed)**
   - Updates the current speed or input value to the throttle system.
   - **Parameters:**
     - `currentSpeed`: Measured speed or input value.

6. **computeThrottle()**
   - Computes the new throttle value based on the current speed and target speed.
   - **Returns:**
     - `float`: Computed throttle value.

7. **reset()**
   - Resets the PID and throttle system to initial state.

#### Smoothing
8. **enableThrottleSmoothing(bool enable, float rampRate = 5.0)**
   - Enables or disables throttle smoothing.
   - **Parameters:**
     - `enable`: Enable (true) or disable (false) smoothing.
     - `rampRate`: Rate of change for throttle adjustments.

#### Monitoring and Debugging
9. **getThrottle()**
   - Retrieves the current throttle value.
   - **Returns:**
     - `float`: Current throttle value.

10. **isStable(float tolerance = 0.1)**
    - Checks if the system is stable within a given error tolerance.
    - **Parameters:**
      - `tolerance`: Acceptable error margin for stability.
    - **Returns:**
      - `bool`: True if stable, false otherwise.

---

## Integration with AutoTunePID
The **AutoThrottle** library is built on top of the **AutoTunePID** library, offering advanced tuning methods and features:

1. **Automatic Tuning**
   - Choose from Ziegler-Nichols, Cohen-Coon, Relay Feedback, or IMC methods.
   - Tuning adjusts PID gains dynamically during operation.

2. **Manual Override**
   - Manually set PID gains for custom control.

3. **Input and Output Filtering**
   - Smoothens noisy input or output signals.

---

## Notes on Usage
- **Throttle Smoothing:**
  - Use smoothing in applications where sudden throttle changes can cause instability (e.g., drones, robots).
  - Adjust the ramp rate to suit the system's response time.

- **Tuning Methods:**
  - For systems with high inertia, consider using the IMC method for better performance.
  - Relay Feedback is ideal for oscillatory systems.

- **Error Tolerance:**
  - Set the `tolerance` value in `isStable()` based on your system's precision requirements.

---

## Contributing
Contributions to this library are welcome! To contribute:
1. Fork the repository on GitHub.
2. Create a new branch for your feature or bug fix.
3. Submit a pull request with detailed explanations of your changes.

---
