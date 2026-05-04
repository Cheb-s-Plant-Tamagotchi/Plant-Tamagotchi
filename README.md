# Plant-Tamagotchi
## Description
A Tamagotchi-inspired, Arduino-powered device that displays different animations based on soil moisture.

[Click Here To Watch The Demo!](https://youtu.be/Qjhv4IliMa0)

<img width="260" height="462" alt="aqu2n0" src="https://github.com/user-attachments/assets/45fdaab7-e0ed-473d-abfc-011be673b337" />

## How To Run
### Adding Animations
At the top of the .ino file, include the header files that contain the desired animations.

EX) `#include "happy_animation.h"  //includes happy sprites for good soil`

### PNG To C Byte Array
In the header file, each image of the animation is represented through an array. 

To go from an image to a C byte array, use the following website and settings.


[Image to C Byte Array Website](https://notisrac.github.io/FileToCArray/)
<img width="741" height="733" alt="image" src="https://github.com/user-attachments/assets/2289a93b-4108-4ca7-b447-fcc5b1997408" />

**NOTE:** The resize setting is specifically for a 1.69 Waveshare LCD; resize to your LCD size

### Adjusting Moisture For Different Plants
`Dirt = analogRead(CS);`
Variable Dirt represents the moisture level read from the sensor. 

For specific plants, change the condition to the desired value.
