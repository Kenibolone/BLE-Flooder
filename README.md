# BLE Flooder

This project implements a simple BLE (Bluetooth Low Energy) flooder using the ESP32-C6 to randomly advertise BLE devices with different names at regular intervals.

## Overview

This code creates a BLE flooder that continuously advertises randomly generated names to simulate multiple BLE devices in the vicinity. It uses the ESP32-C6's Bluetooth capabilities to broadcast the advertisements with no connection requirement. This can be useful for testing purposes, simulating BLE environments, or understanding BLE advertisement behavior.

## Features

- **Random BLE Name Generation**: Each advertisement broadcasts a randomly generated name (ASCII characters).
- **Non-connectable Advertising**: The advertisements are non-connectable, meaning they cannot be used for establishing a connection, but only for scanning purposes.
- **Continuous Advertising**: The code runs in a loop, advertising different names every second.

## Dependencies

- ESP32 development environment (Arduino IDE with ESP32 board support).
- ESP32 Bluetooth stack (`esp_bt.h`, `esp_gap_ble_api.h`).

## Setup

### 1. Install the ESP32 board in Arduino IDE
If you haven't already, add the ESP32 board to your Arduino IDE. Follow these steps:
- Open Arduino IDE.
- Go to **File** → **Preferences**.
- In the **Additional Boards Manager URLs** field, add the following URL: `https://dl.espressif.com/dl/package_esp32_index.json`.
- Go to **Tools** → **Board** → **Boards Manager**, search for ESP32, and install the package.

### 2. Select the Board
- Go to **Tools** → **Board** and select your ESP32-C6 board (e.g., `XIAO ESP32C6`).

### 3. Upload the Code
- Copy and paste the code provided into the Arduino IDE.
- Click the **Upload** button to upload the code to your ESP32-C6.

## Code Explanation

1. **Advertising Parameters**:
   - `adv_params` configures the advertising behavior, including advertisement interval, advertisement type, and filter policies.
   
2. **Random Name Generation**:
   - The function `advertiseRandomName()` generates a random name using ASCII characters and adds it to the advertising data. The name is sent as part of the BLE advertisement payload.

3. **GAP Callback**:
   - The `gapCallback` function handles BLE events. When the advertisement data is successfully set, it starts advertising with the configured parameters.

4. **Advertising Loop**:
   - In the `loop()` function, the device continually advertises a new random name every second.

## Usage

Once the code is uploaded to the ESP32-C6, the device will start advertising with a random name every second. Use a BLE scanner (such as a mobile app or `bluetoothctl` on Linux) to scan for the advertisements. You'll see devices with randomly generated names.

## Customization

- **Advertisement Interval**: You can change the advertisement interval by adjusting the `adv_int_min` and `adv_int_max` values in `adv_params`. The values are in 0.625 ms units.
  
- **Advertising Payload**: You can modify the advertisement payload to include more information, such as the device’s MAC address or custom data.

## Troubleshooting

- **No Advertisements**: Ensure that your ESP32 board is correctly selected in the Arduino IDE. Verify that the ESP32 Bluetooth stack is properly initialized.
  
- **Advertising Interval Too Fast**: If the interval is too fast, the BLE scanner may miss some advertisements. Try increasing the `adv_int_max` and `adv_int_min` values.

## Upcoming Improvements

- **Multiple Advertising Types**: Add support for different types of BLE advertisements (e.g., connectable, scannable).
- **Custom Data in Advertisements**: Allow users to include additional custom data in the advertisement payload, such as device-specific information or sensor data.
- **Configurable Advertising Interval**: Provide a way to dynamically configure the advertisement interval via serial input or configuration file.
- **MAC Address Spoofing**: Implement the ability to spoof different MAC addresses to simulate more unique devices.
- **Advertisement Frequency Control**: Allow for adjusting the frequency of advertisements via external input, like a button or serial command.
- **Logging and Debugging**: Implement enhanced logging to help debug BLE communication and advertising issues.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.