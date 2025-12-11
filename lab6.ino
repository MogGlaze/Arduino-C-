// Glob variables
const int SENSOR_PIN = A0;     // Sensor input (photoresistor or potentiometer)
const int LED_PIN    = 13;     // LED output pin

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);        // Optional: for debugging
}

void loop() {
    // Read sensor value using a function
    int sensorValue = readSensor();

    // if statement
    if (sensorValue > 500) {
        digitalWrite(LED_PIN, HIGH);  // Turn LED on
    } else {
        digitalWrite(LED_PIN, LOW);   // Turn LED off
    }

    // print value to Serial Monitor
    Serial.println(sensorValue);

    delay(100); // Small delay to stabilize readings
}

// Function that returns the sensor value
int readSensor() {
    int value = analogRead(SENSOR_PIN);
    return value;
}
