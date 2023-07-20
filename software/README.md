# Software Guide

This guide will walk you through how to upload the `wur_pic12lf1552_main.c` program to your PIC12LF1552 microcontroller using a PicKit3 programmer and MPLAB X IDE.

## Prerequisites 

Before starting, ensure that you have the following:

1. **MPLAB X IDE** installed on your computer. If you don't have it, you can download it from the [Microchip website](https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-x-ide).

2. **PicKit3** programmer. This is the tool we'll use to transfer the program onto your microcontroller.

3. **wur_pic12lf1552_main.c** file. This is the program that will run on your PIC12LF1552 microcontroller.

## Steps 

Follow the steps below to upload the software:

1. **Connect Your PicKit3 Programmer**: Connect the PicKit3 programmer to your computer via USB. Then, connect the PicKit3 to your PIC12LF1552 microcontroller on your breadboard or PCB, ensuring that the ICSP (In-Circuit Serial Programming) pins line up correctly.

2. **Open MPLAB X IDE**: Launch the MPLAB X IDE software on your computer.

3. **Create a New Project**: Go to `File -> New Project`. Choose `Microchip Embedded -> Standalone Project` and click `Next`.

4. **Select Device**: In the dropdown menu, select `PIC12LF1552` and click `Next`.

5. **Select Tool**: Choose `PicKit3` in the dropdown menu and click `Next`.

6. **Select Compiler**: Choose the compiler you have installed. If you have none, download and install the `XC8` compiler from Microchip's website. Once installed, select it and click `Next`.

7. **Name and Choose Project Location**: Give your project a name and choose a location on your computer to save it. Click `Finish`.

8. **Add Your Source Code File**: Right-click on `Source Files` in the Project Window and choose `New -> main.c`. Copy the contents of `wur_pic12lf1552_main.c` into this new file. Save the file.

9. **Build the Project**: Click on the `Build` button (hammer icon) to compile your code. If the build is successful, you should see a `BUILD SUCCESSFUL` message in the Output Window.

10. **Program the MCU**: Click on the `Make and Program Device Main Project` button (the icon with an arrow pointing towards the chip) to upload the compiled program onto your PIC12LF1552 microcontroller.

If you encounter any issues, refer to the MPLAB X IDE's troubleshooting guide or Microchip's support forums.

## Understanding the Software
In this program, we're using a simple two-channel system to handle our wake-up signals that are connected to the `RA0` pin (data) and `RA2` pin (preamble). The first channel, `RA2`, is used to detect when a signal starts - this is called the preamble. When `RA2` detects a signal, it activates the second channel, `RA0`.

`RA0` is where we receive the actual data of the signal. Once `RA2` has detected a signal and activated `RA0`, the program starts measuring the time between signals on `RA0`. This is our data - specifically, it's an 'address' that tells the microcontroller whether it should wake up or ignore the signal.

## Adapting the code
Keeping the program simple is critical because we're working with a small 8-bit microcontroller. This microcontroller isn't very powerful, so if the program gets too complex, it might start to slow down or experience delays. That's why we're just using these two channels and a timer to handle our wake-up signals.
