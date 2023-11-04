# Arduino Abstract Library

## Introduction

This Arduino Abstract Library provides classes for common hardware components used in Arduino projects. The library includes classes for a Button, Joystick, and Potentiometer, making it easier to integrate these components into your projects.

## Classes

### Button

The `Button` class simplifies the use of pushbuttons in Arduino projects. It includes methods for initializing the button and retrieving its state.

#### Usage

```cpp
#include "ArduinoAbstract.hpp"

// Create a button instance with the specified pin number
Button myButton(2);

void setup() {
  // Initialize the button with the specified mode (INPUT or INPUT_PULLUP)
  myButton.init(INPUT_PULLUP);
}

void loop() {
  // Get the state of the button (0 or 1, considering the specified mode)
  int buttonState = myButton.getState();

  // Your code here based on the button state
}
```

### Joystick

The `Joystick` class provides an abstraction for joysticks, including methods to initialize the joystick and retrieve its readings.

#### Usage

```cpp
#include "ArduinoAbstract.hpp"

// Create a joystick instance with specified pin numbers and optional calibration values
Joystick myJoystick(A0, A1, 2);

void setup() {
  // Initialize the joystick with the specified mode for the select button (INPUT or INPUT_PULLUP)
  myJoystick.init(INPUT_PULLUP);
}

void loop() {
  // Get readings from the joystick
  int horizontalValue = myJoystick.getHorizontalRead();
  int verticalValue = myJoystick.getVerticalRead();
  int selectState = myJoystick.getSelectState();
  int joystickPos = myJoystick.getPos();

  // Your code here based on joystick readings and button state
}
```

### Potentiometer

The `Potentiometer` class simplifies the use of potentiometers in Arduino projects. It includes methods for initializing the potentiometer and retrieving its value.

#### Usage

```cpp
#include "ArduinoAbstract.hpp"

// Create a potentiometer instance with the specified pin number
Potentiometer myPotentiometer(A2);

void setup() {
  // Initialize the potentiometer
  myPotentiometer.init();
}

void loop() {
  // Get the value of the potentiometer (0 to 1023)
  int potValue = myPotentiometer.getValue();

  // Your code here based on the potentiometer value
}
```

## License

This project is licensed under the Apache License 2.0 - see the [LICENSE](LICENSE) file for details.

## Note

This project may or may not be always updated. It was created by the author to ease the process of writing code for new Arduino projects. Contributions, improvements, and suggestions are welcome. <i>Also thanks to ChatGPT by OpenAI for writing this documentation.</i>