# OTA Solutions
The purpose of this section is to offer a way to do OTA updates since we will try different solutions and services and to be able to use the same firmware for identically configured board+sensor setups.

The services will mainly be initially tested with 4 pcs of Lolin32 ESP 32 boards with a DTH11 sensor. 

Since there is 4 boards I will use 2 GPIO pins for setting the ID in the range 0-3.


 Since `GPIO: 36, 39, 34, 35 is` "`INPUT ONLY`", witch of Loloin32 only have `34 & 35` so we will use these for ID'ing our boards.
 
| Device |  ID0   |  ID1   |
|:------:|:------:|:------:|
|   nr   | GPIO34 | GPIO35 |
|    0   |  LOW   |  LOW   |
|    1   |  HIGH  |  LOW   |
|    2   |  LOW   |  HIGH  |
|    3   |  HIGH  |  HIGH  |


