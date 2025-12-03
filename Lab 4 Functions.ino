// ============================================================================
// Source: STEAM Clown - www.steamclown.org 
// GitHub: https://github.com/jimTheSTEAMClown/Robots-Rovers-Arduino-Code
// Hacker: Jim Burnham - STEAM Clown, Engineer, Maker, Propmaster & Adrenologist 
// This example code under the GNU Lesser General Public License v3.0
// and any docs and lesson examples is licensed under the CC BY-NC-SA 3.0.
// https://creativecommons.org/licenses/by-nc-sa/3.0/
// Create Date:			2025-10-17 
// Design Name:			arduino-function-lab3.ino
// Description:     adaptation of blink on http://arduino.cc/
// Dependencies: 
// Target Board: Arduino Uno / Arduino R4 Wifi
// IDE used: 
// Revision: 
// Revision 0.02 - Updated from template to Function Lab1: 2025-10-19
// Revision 0.01 - Created: 2025-10-17
// Additional Comments: 
//
// ============================================================================

// Libraries:

// Global Pins
// Global Pins
const int LED1 = 13;	// define as constant integer on pin 13 
const int LED2 = 7;
const int LED3 = 6;
const int LED4 = 5;

// Global Variables
int delay_time = 1000;

// Function Declarations & Global Variable associated with Functions
void blink(int led_pin, int blink_delay);
void print_delay(int ms);

// ============================================================================
// The setup routine runs once when you load the sketch or press reset:
// This is where you define pin directions
void setup()
{
	// initialize Serial Communication
  	Serial.begin(115200);
 	// initialize the pins used in this sketch
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
	pinMode(LED4, OUTPUT);
}

// ============================================================================
void loop()
{
	delay_time = 1000;
  	blink(LED1, delay_time);
  	blink(LED4, 500);
	delay_time = 250;
	blink(LED2, delay_time);
  	delay_time = 100;
	blink(LED1, delay_time);
  	delay_time = random(100, 1000);
	blink(LED4, delay_time);
}

// Functions 
void blink(int led_pin, int blink_delay)
{
  	digitalWrite(led_pin, HIGH);
print_delay(blink_delay);
  delay(blink_delay);	//Wait for blink_delay
	
  digitalWrite(led_pin, LOW);
	print_delay(blink_delay);
  delay(blink_delay);	//Wait for blink_delay
}

void print_delay(int ms)
{
  	Serial.print("delay = ");
  	Serial.println(ms);	
}

//
