# ESP32 Servo Motor Web Server

This project demonstrates how to control a servo motor using an ESP32 through a web interface. The project is structured in a modular way, separating the code into different files for better readability and maintainability.

## Project Structure
```
ESP32ServoWebServer/
├── include/
│ ├── WiFiHandler.h
│ ├── WebServerHandler.h
│ ├── ServoController.h
├── src/
│ ├── main.cpp
│ ├── WiFiHandler.cpp
│ ├── WebServerHandler.cpp
│ ├── ServoController.cpp
├── platformio.ini
└── README.md
```

## Components

- **WiFiHandler**: Handles the connection to the WiFi network.
- **WebServerHandler**: Manages the web server and processes incoming HTTP requests.
- **ServoController**: Controls the servo motor.

## Requirements

- [PlatformIO](https://platformio.org/) installed in your IDE (e.g., VS Code)
- ESP32 development board
- Servo motor
- Jumper wires
- Breadboard

## Installation

1. Clone this repository:
    ```sh
    git clone https://github.com/yourusername/ESP32ServoWebServer.git
    cd ESP32ServoWebServer
    ```

2. Open the project folder in your preferred IDE with PlatformIO support.

3. Update the WiFi credentials in `src/WiFiHandler.cpp`:
    ```cpp
    const char* ssid = "REPLACE_WITH_YOUR_SSID";
    const char* password = "REPLACE_WITH_YOUR_PASSWORD";
    ```

4. Connect your servo motor to the ESP32:
    - Signal pin to GPIO 13 (you can change this pin in `ServoController.cpp`)
    - Power (VCC) to 5V
    - Ground (GND) to GND

5. Build and upload the project to your ESP32 board.

## Usage

1. Once uploaded, open the Serial Monitor in your IDE to see the connection status.
2. The ESP32 will connect to your WiFi network and display its IP address.
3. Open a web browser and navigate to the displayed IP address.
4. Use the slider on the web page to control the servo motor's position.

## Code Overview

### `src/main.cpp`

The entry point of the application. It initializes the WiFi connection, starts the web server, and handles incoming client requests.

### `src/WiFiHandler.h` and `src/WiFiHandler.cpp`

Handles connecting to the WiFi network.

### `src/WebServerHandler.h` and `src/WebServerHandler.cpp`

Manages the web server, serves the web page, and processes HTTP GET requests to control the servo motor.

### `src/ServoController.h` and `src/ServoController.cpp`

Controls the servo motor, providing methods to attach the servo and set its position.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- This project is based on tutorials by Rui Santos & Sara Santos - [Random Nerd Tutorials](https://RandomNerdTutorials.com/)