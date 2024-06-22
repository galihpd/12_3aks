
# 12_3aks Keyboard
Handwired 12 keys 3 potentiometer macropad


![12_3aks](https://github.com/galihpd/12_3aks/blob/main/media/IMG_20240622_174521_2%20%281%29.jpg)

## Description
This Arduino project utilizes the HID-Project library to create a custom keyboard with media control functions and additional keys.

## Hardware Requirements
- Arduino board
- Keyboard keys/buttons
- Potentiometer (for volume control)

## Direct Pin Configuration

In this keyboard project, direct pin configuration refers to the use of microcontroller pins that are directly connected to each keyboard button without using matrix techniques. This means that each button on the keyboard has its own dedicated pin connected directly to an Arduino microcontroller pin.

The advantages of direct pin configuration include:
- **Simplicity in Programming**: Direct pin usage simplifies programming because each button has a separate pin that can be read directly using the `digitalRead()` function.
- **Readability of Configuration**: Pin configurations that are directly connected to hardware elements are easy to understand and implement in Arduino programs.

However, it's important to note that direct pin configuration is suitable for simple projects with a limited number of buttons. For more complex projects with many buttons, matrix techniques are often used to conserve the number of microcontroller pins utilized.

## Wiring diagram
![12_3aks wiring diagram](https://github.com/galihpd/12_3aks/blob/main/media/Untitled%20Sketch_bb.png)

## Uploading the Sketch
1. Clone or download the repository.
2. Open the Arduino IDE.
3. Install the HID-Project library if not already installed.
4. Connect your Arduino board to your computer.
5. Open the `12_3aks_keyboard.ino` file in the Arduino IDE.
6. Compile and upload the code to your Arduino board.

## Credits
- [HID-Project library](https://github.com/NicoHood/HID)
- Arduino community for resources and support
- [Scottokeebs](https://www.youtube.com/watch?v=hjml-K-pV4E) for provide me base casing design

## License
This project is licensed under the [MIT License](LICENSE.md).

Feel free to contribute and improve the code!
