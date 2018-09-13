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
[link to the code] (/forceresistor_led.ino)
**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

### 3. IR Proximity Sensor

**a. Describe the voltage change over the sensing range of the sensor. A sketch of voltage vs. distance would work also. Does it match up with what you expect from the datasheet?**

**b. Upload your merged code to your lab report repository and link to it here.**

## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

**c. How many byte-sized data samples can you store on the Atmega328?**

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
