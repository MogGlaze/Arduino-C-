const int LED1 = 13;        // define as constant integer on pin 13 

// Global Variables

// Function Declarations & Global Variable associated with Functions
void blink();

// ============================================================================
// The setup routine runs once when you load the sketch or press reset:
// This is where you define pin directions
void setup()
{
    // initialize Serial Communication
    Serial.begin(115200);
    // initialize the pins used in this sketch
    pinMode(LED1, OUTPUT);
}

// ============================================================================
// this "main" loop routine runs over and over again forever:
void loop()
{
    blink();
}

// ============================================================================
// Functions (I like to instantiate functions at the bottom below loop())
void blink()
{
    // Turn LED on
    digitalWrite(LED1, HIGH);
    Serial.println("LED is ON");   // <-- prints to Serial Monitor
    delay(1000);                   // wait 1 second

    // Turn LED off
    digitalWrite(LED1, LOW);
    Serial.println("LED is OFF");  // <-- prints to Serial Monitor
    delay(1000);                   // wait 1 second
}
