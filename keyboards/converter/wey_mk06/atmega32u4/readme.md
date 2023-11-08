# WeyTec MK06 Converter - ATmega32u4 version

Hardware serial on pro micro board with MAX3232.

Tested on keyboard with :
Main Module Firmware      V1.25
Interface Module Firmware V2.01
Mainboard HW PCB0320.6 rev 09
The RS232-capable / DLINK ports may vary from versions to versions, check in your settings menu.

Using [USART](https://github.com/AndersKaloer/ATmega-UART/tree/master) and [ringbuffer](https://github.com/AndersKaloer/Ring-Buffer/tree/2f6ed0e514e56b69dac6d1d28df88ae77ea1d27c) library from [Anders Kalør](anderskaloer.net)

# Disclaimer

This code & keymap has only been tested working for an ISO Weytec MK06 with the ADD04 module on the left and and ADD09 module on the right, with a Weytec firmware version of 1.25. 
If your keyboard has different pads and or a different firmware version, you might have to patch the KCT file and rewrite the keymaps and vial json according to your needs.

## Background

The Weytec MK06 originally uses an external converter box that is unobtainium. [MMcM on Deskthority did the hard work of reverse engineering](https://deskthority.net/viewtopic.php?f=7&t=27319) the protocol and pinout for that keyboard, this is the code ported to an Arduino Pro Micro and using vial. All the relevant information about connector, pinout, port names, etc... are from the above link.

## Connector

If you want to do an external conversion, the Weytec uses a 36 pins MDR connector.
[Those have been tested working](https://fr.aliexpress.com/item/1005003461743920.html) (choose the 36 pin version).
For an internal conversion, you can just solder wires to the exposed connector leads and pads.

## Power

The keyboard needs a 12V wall wart to work. I used a cheap 12V@2A wall wart I had laying around.

| PSU | WeyTec / HPCN36 |
|---|---|
| +12V | VCC / 18 & 36 |
| GND | GND / 1 & 19 |

## Wiring

I used a cheap [MAX3232 breakout boards](https://fr.aliexpress.com/item/1005004893579002.html) for the wiring :
The markings on those boards are confusing, so I might have messed up the pinout below. Try to invert the RX/TX wires on both sides if you get nothing.
If your MAX3232 gets really hot, it might be because you wired the RS232 side to the arduino. Don't ask me how I know.

| Pro Micro | MAX3232 TTL Side | MAX3232 RS232 Side | WeyTec / HPCN36
|---|---|---|---|
| TX / PD3 | Arrow IN  | Arrow OUT | EXT_RXD / 28 |
| RX / PD2 | Arrow OUT | Arrow IN | EXT_TXD / 10 |
| GND (any) | - | -| GND / 11 |
| VCC | + | NC | |

Alternative wiring notation

| Pro Micro | MAX3232 | WeyTec / HPCN36
|---|---|---|
| RX / PD2 | R2OUT | |
| TX / PD3 | T2IN | |
| VCC | VCC | |
| GND | GND | GND / 11 |
| | T2OUT | EXT RXD / 28 |
| | R2IN | EXT TX  / 10 |

## KCT File

The Weytec MK06 uses config files that you can upload and download from a USB flash drive in order to configure the keycodes.
Use the file KCTS_ADD04_ADD09_v1.25.DL1 for a keyboard using an ADD04 module on the left and an ADD09 module on the right.

## Weytec Configuration

Dlink port is configured as EXT, with the default 9600 8N1 serial config.
I've put all the WS as using the QMK149 keycode table, and outputting on DLink port with address 10.

## Building

```make converter/wey_mk06/atmega32u4:vial```

## References

https://deskthority.net/viewtopic.php?f=7&t=27319 
https://github.com/MMcM/qmk_firmware/tree/mmcm/keyboards/converter/wey_mk06
https://gist.github.com/MMcM/5d6533032dbb828c7582f9622f1caec0
