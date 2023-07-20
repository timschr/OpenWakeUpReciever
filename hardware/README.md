# Hardware Guide

This guide will walk you through the hardware aspects of creating your wake-up receiver, from understanding impedance matching, to ordering and assembling your PCB.

## Background: Impedance Matching

Impedance matching is a crucial concept in electronics that helps ensure maximum power transfer between components. In the context of our wake-up receiver, we need to ensure that the antenna and the circuitry on the PCB have the same impedance to prevent signal reflection and loss.  Trace width for the transmission line can be calculated with the [JLCPCB Impedance Caclulator](https://jlcpcb.com/pcb-impedance-calculator/) for different materials.

The need for accurate impedance matching is why there isn't much room for variations in the PCB design. Trace width, PCB material, thickness, and the number of layers all play a part in determining the overall impedance. We've chosen a 4-layer PCB as it offers easier impedance control.

## Transmitter

While our wake-up receiver (WuR) is all about listening for specific signals, it's important to remember that we also need a device to send these wake-up signals. 

Any device that supports On-Off Keying (OOK) at 868MHz could be used as a transmitter. In my project, I opted for the RFM95W module. What's really neat about this module is its support for LoRa, a low-power, long-range communication protocol. This could open up some fascinating possibilities, such as setting up a remote sensor network miles away via LoRa, and using WuRs for local communication.

Specifically, I used the [RFM95W shield for the Arduino Uno by Draguino](https://github.com/jgromes/RadioLib), which worked perfectly. This shield integrates well with the Arduino Uno, making it easy to create and transmit signals to our WuR.

An added bonus of the RFM95W module is that it's supported by the RadioLib library. If you're interested in doing more radio work with Arduino, I highly recommend checking out [RadioLib](https://github.com/jgromes/RadioLib). It's an incredibly helpful resource, packed full of tools and examples for various types of radio communication.

## Ordering Your PCB
With that said, let's start building. You will first need to order your PCB based on the provided [production files](production/). This guide will walk you through how to order it from JLCPCB, but you can also choose a different manufacturer as long as they have similar material characteristics.

### How to Order from JLCPCB:

1. Go to the [JLCPCB website](https://jlcpcb.com/)
2. Click on "Quote Now" or "Order Now"
3. In the new page, click on "Add your Gerber file" and upload the provided Gerber file
4. Scroll down to the "High-spec Options" and choose "Impedance Control: Yes"
5. Under "Layer stackup", select "JLC04161H-7628"

Then proceed with your order following the website's instructions.

## Ordering Parts

Next, you will need to order the other parts required for this project. These can be found at vendors like [Mouser](https://www.mouser.com/) or [Digikey](https://www.digikey.com/). The list of parts needed will be provided.

#### Parts List for 1 WuR
For the PCB:
Number of parts. Describtion, Spezification, Package
- 1 Inductor 2.2nH 0805
- 1 Inductor 3.3nH 0805
- 1 Capacitor 3.7pF 0805
- 1 Capacitor 5pF 0805
- 1 Capacitor 22pF 0805
- 1 Diode SMS7630-005LF
- 1 Diode XXX SMA
- 1 Resistor 2.2k 0805
- 1 Resistor XXX 0805
- 1 Capacitor 100n
- 1 Comparator TLV7031 SOT-23-5

For the breadboard:
- breadboard
- jumper wires
- PIC12LF1552

## Assembly

If you don't already have an 868MHz OOK transmitter, you'll need to purchase one. Once you have all your parts and your PCB, you can begin to put everything together on the breadboard.

Now, with your hardware assembled, you can move on to flashing the software onto your microcontroller. Please refer to the [Software Guide](../software/README.md) for instructions on how to do this.
