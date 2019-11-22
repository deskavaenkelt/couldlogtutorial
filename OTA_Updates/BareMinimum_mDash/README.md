# Bare minimum for OTA Updates
I used LOLIN32 for this project, if you use some other devices just change or add the board to `platformio.ini`.

## Links
* [LOLIN32][LOLIN32_wemos] at WEMOS
* [LOLIN32][LOLIN32_platformio] at PlatformIO

## Prerequisites
Libraries in PlatformIO
* [mDash][mDash] by Cesanta Software Limited
* or type `pio lib install "mDash"` in terminal

## Components
* ESP32 board

## How to use
Start by adding the libraries to PlatformIO in VSCode, then restart VSCode.

Download the code and unzip, open the folder in VSCode. Test to build the code to confirm that the libraries are imported correctly.
* Change your credentials in `auth.h`
* Connect your board to your computer
* In the left tab in VSCode click on The PlatformIO icon.
* Click Devices and copy the address that corresponds to your board (Windows `ComX`, Mac `/dev/cu.xxx`
* Replace the port address on row 18 in platformio.ini
* Then click `Upload and Monitor

The ESP32 should connect to the mDash service if your network credentials are valid.

If there is any errors, check the console for error messages to solve them.

[LOLIN32_wemos]: https://wiki.wemos.cc/products:lolin32:lolin32
[LOLIN32_platformio]: https://docs.platformio.org/en/latest/boards/espressif32/lolin32.html
[mDash]: https://platformio.org/lib/show/6366/mDash