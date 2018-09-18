# Data Logger (and using cool sensors!)

*A lab report by Hemanth Kondapalli Student.*

## In The Report

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**
 The values range from 0 to 1024. <br>
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**<br>
It has 10 bits, since 2^10 = 1024. 

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**
We connected the anode of the LED to 5V power source. Then connected each of the color pins to a resistor and connected the green to pin 10, blue to pin 9 and red to 11.

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**
We see values between 0 and 1000. We didnt see values up until 1024, wasn't able to press is hard enough!

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**
There is a positive correleation between voltage and force applied. As more force is applied the voltage number goes up the relationship could be linear (till 1024) or exponential with decay. 

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**
We can use the analogread function from pin A0. This will give us voltage values between 0 and 1024. We can then use this number as the brightness parameter in the analogWrite(led, brightness) function. <br>
[link to the video](https://youtu.be/bNC21NYjnT8) <br>
We can also use an if statement to map the force resitor values to a color displayed on the LED. This is done in the code example below. <br >
[link to the code] (/forceresistor_led.ino) <br>
**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**
The photocell resistor <br>
**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**<br>
The photocell resistor increases in voltage when it has more light and when it is covered up the voltage goes down. 
The soft cell resistor decreases in voltage the more its bent. 
### 2. Accelerometer
**a. Include your accelerometer read-out code in your write-up.**
<br>
If you are looking at the acclerometer straight on with the labeled pins. Rotating the accelerometer horizontally changes the X position values. Flipping the accelerometer changes the Y values. And moving the acclerometer up and down changes the Z position values. Likewise for increasing the rate of motion causes subsquent changes to the Axes's accleration values. <br>
[link to code] (/accle-led.ino) <br>
### 3. IR Proximity Sensor 

**a. Describe the voltage change over the sensing range of the sensor. A sketch of voltage vs. distance would work also. Does it match up with what you expect from the datasheet?** <br>
As you move your hand or an object closer to the sensor the proximity value increases and the ambient value decreases. When the field of view is clear, the values are fairly static. <br>
**b. Upload your merged code to your lab report repository and link to it here.**
[link to code](/accel_ir.ino)
## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**
The actions assigned to each of the 3 states (clearing, reading, writing) are turning on the built in LED to various brightnesses. The action of turning on the LED has nothing to do with what is going on with the memory, it is just a way 
to know whats going on, on the board. <br>
**b. Why is the code here all in the setup() functions and not in the loop() functions?**
<br >These functions cannot be called in a loop since we don't want to clear the memory or write to the memory indefinitely in a loop. 
<br>
**c. How many byte-sized data samples can you store on the Atmega328?** <br>
There are 1024 bytes of internal memory and 32KB of program memory or 32,000 bytes. <br>
**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**
The values coming from the analogread on the arduino is 10 bits ranges from 0 to 1023. 
We want the data to byte sized. So a byte has 8 bits. So the range of value would be from 0 to 255. We would use the map function. map(analogRead(sensorPin), 0, 1024, 0, 255);
We would have the same process for the I2C devices. We would figure out the range of values on the I2C devices and map them to the range of a byte which is 0 to 255. 
**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)** <br>
You can use the EEPROMPut function that allows you to write any data type or object to memory.
**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**<br>
[/accel_ir_byte.ino]
<br>
In question 3b we took sensor data and printed it in the serial monitor. I modified that code file to output data that is byte sized using the map function. Since the accleromter data is 16 bits we need to scale it down. <br>
### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 <br>
I connected an acclerometer to my neck and counted the # of times I bent my neck. I stored the # of bends and the magnitude of the change in the rotation of neck in the arduino hard drive. <br>
**a. Record and upload a short demo video of your logger in action.** 
https://youtu.be/wkVpKZ-rhBY
