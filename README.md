# Power-Assisted RotaTruck

A RotaTruck LITE hand trolley fitted with two hub motors and a controller, so the motors amplify what the operator is already doing. Push and it helps you push; ease off and the help fades; pull back and it slows the trolley. There is no throttle: the operator holds a switch on the handle, and the trolley weighs its own load on the toe plate and sizes the assist to suit.

Firmware delivered by **OmniPros (DMMS Team 4)** for **Omnia Wheel**, UTS DMMS capstone (P102), November 2026.

## Current build

| Part | What it is |
|---|---|
| Controller | STM32F407G-DISC1 (STM32F407VGT6, 168 MHz) |
| Motor control | Two ODrive S1 controllers over CAN (250 kbit/s), one per rear hub motor |
| Operator input | Handle switch: hold to assist, click to accept the load, triple-click to zero |
| Sensors | ISM330DHCX IMU (pose and slope); strain-gauge load plate with an HX711 (middle strip) |
| Display | 16x2 LCD on its own I2C bus |
| Power | 24 V battery for the motors; USB power bank for the controller |

## Repository layout

```
Power_Assisted_Rotatruck/
├── README.md                     you are here
└── code/STM_RotaTruck/           the firmware (PlatformIO project)
    ├── platformio.ini            build targets: disco_f407vg (the cart), imu_test, loadcell_test
    ├── src/, include/            firmware source; pins in include/board.h, tuning in include/assist_tuning.h
    ├── host/                     PC tools: live load log, calibration and drift GUIs, calibration record
    ├── tools/                    RTT server and terminal scripts
    └── monitor/                  PlatformIO monitor filter for the RTT console
```

## Build and flash

The firmware is a [PlatformIO](https://platformio.org/) project. Connect the DISC1 with its mini-USB (ST-LINK) cable.

```sh
pio run -d code/STM_RotaTruck                 # build the cart firmware
pio run -d code/STM_RotaTruck -t upload       # flash
pio device monitor -d code/STM_RotaTruck      # console over RTT
```

The DISC1 has no serial port to the PC, so the console runs over SEGGER RTT through the ST-LINK. Only one program can use the ST-LINK at a time: close the monitor before uploading. The bench bring-up programs are built with `-e imu_test` or `-e loadcell_test`.

## Documentation

- **Handover documents** (Technical Document, User Manual, Wiring Diagrams and Hardware Records, Known Issues and Next Steps, ODrive S1 Setup Guide) are delivered separately as Word / PDF files. Start with the Technical Document to maintain or extend the cart.
- **Authoritative settings:** [include/board.h](code/STM_RotaTruck/include/board.h) (pins, options, calibration lock) and [include/assist_tuning.h](code/STM_RotaTruck/include/assist_tuning.h) (tuning constants). Where a document and the code disagree, the code wins.

## Project

- Client: Omnia Wheel
- Team: OmniPros (DMMS Team 4): Hayden Choo, Steven Lilin, Ethan Mam, Kaung Myat Thu, Dang Khoa Tran, Declan Wijaya
- Course: University of Technology Sydney (UTS), DMMS capstone
