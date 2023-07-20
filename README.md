# README - Open Wake-Up Receiver (WuR) Platform

## Table of Contents
1. [Introduction](#introduction)
2. [Getting Started](#getting-started)
3. [Documentation](#documentation)
4. [Usage](#usage)
5. [Contributing](#contributing)
6. [FAQ](#faq)
7. [License](#license)
8. [Acknowledgments](#acknowledgments)

## Introduction

Welcome to the world of Wake-up Receivers (WuRs)! 

Have you ever wished to have a tiny, ultra-low power device that can awaken your sensor nodes from sleep mode only when needed, saving power and reducing latency? WuR is the game-changer you've been waiting for!
The wake-up receiver's job is to keep a power-hungry device asleep and only wake it up when it's needed, saving energy.

This technology can be the brain of your next IoT project, enabling wireless sensor networks to function efficiently, conserve energy, and respond swiftly. From setting up a smart home system that wakes up when you're near, to implementing precision agriculture that responds to real-time changes in the environment, WuR opens up a world of possibilities.

![WuR_Mac](https://github.com/timschr/OpenWakeUpReciever/assets/56300785/1c0a9c46-251d-4546-9450-63c9c716b967)

## How to get started
Just head over to the [Hardware Guide](hardware/README.md) and go step by step from there.


## How to get done

#### 1. Order Your PCB

The first step is to order your PCB (Printed Circuit Board). This will serve as the base for your wake-up receiver, where you'll attach and connect all your components. 

#### 2. Acquire Necessary Parts

Next, you'll need to gather all the other parts required for this project. This includes an 868MHz antenna a nano power comparator, and the PIC12LF1552 Microcontroller Unit (MCU). You can refer to the [Hardware Guide](hardware/README.md) for a more detailed list and where to get these parts.

#### 3. Assemble Your Receiver

Once you have your PCB and all the necessary parts, you can start putting your receiver together. Attach the components to your PCB and connect them according to the circuit design. Remember to double-check all your connections to ensure they're correct and secure.

#### 4. Program the MCU

With your circuit assembled, it's time to program your MCU. You'll need to flash the provided software onto the PIC12LF1552 using suitable PIC microcontroller programming software. More details on how to do this can be found in the [Software Guide](software/README.md).

#### 5. Acquire a Transmitter

Finally, you'll need a transmitter capable of sending OOK (On-Off Keying) signals at 868MHz. This will be used to send the wake-up signal to your receiver. The only requirements are that the transmitter can operate at this frequency and use OOK modulation.

### Prerequisites

#### Hardware:
  - PCB (Printed Circuit Board)
  - All the parts
  - 868 OOK Tranceiver
  - Breadboard
    
#### Tools:
- PICKit3: Programming to for PIC microcontroller. With some effort you can also use a simple arduino for this. Explaine e.g. here [https://github.com/jaromir-sukuba/a-p-prog])
- Soldering iron: You'll need this to attach components to your PCB. Not needed when you order the PCB preassembled.
- (Oscilloscope: This is optional but recommended for analyzing the signals in your circuit.)
- (NanoVNA: This is optional but handy to analyze the quality of the mathching network)

## Contributing

We warmly welcome contributions to this project. If you'd like to contribute, please fork the repository and make your changes. Then create a Pull Request to get your changes merged and reviewed.

We have a few guidelines for contributing, please check them out here: [CONTRIBUTING.md](./CONTRIBUTING.md)



## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

I'd like to acknowledge the contributions of my academic advisors and the open-source community that has been pivotal in making this project what it is.

---

To create a detailed `CONTRIBUTING.md` file, include sections like:

1. Code of Conduct
2. How to report bugs or request features
3. How to set up the development environment
4. Code style guides
5. How to submit a Pull Request
6. What to expect after a Pull Request is submitted

In the `LICENSE.md` file, provide the full text of the license. If you're using MIT, you can find that [here](https://choosealicense.com/licenses/mit/).

The FAQ section should be updated as users interact with your project. Start with questions you think will be common, then add more as they come up.

Remember, READMEs are often the first thing people see when they come to your project, so make it engaging, informative, and welcoming.
