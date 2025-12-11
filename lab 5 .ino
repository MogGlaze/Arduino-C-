// Pins
const int SENSOR_PIN   = A0;   // Photoresistor or potentiometer
const int LED_MAIN_PIN = 13;   // Main LED
const int LED_2_PIN    = 12;   // Second LED
const int BUZZER_PIN   = 11;   // Buzzer (active buzzer recommended)

// Thresholds
const int LOW_THRESHOLD  = 300;
const int HIGH_THRESHOLD = 700;

// Function that returns a value from the sensor
int readSensor() {
    int value = analogRead(SENSOR_PIN);
    return value;  // send value back
}

void setup() {
    pinMode(LED_MAIN_PIN, OUTPUT);
    pinMode(LED_2_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    // Step 1: Read the sensor using a function that returns a value
    int sensorValue = readSensor();

    // Optional: print value to Serial Monitor
    Serial.println(sensorValue);

    // Step 2: Use two thresholds (actually three ranges):
    // < 300  -> LED off
    // 300-700 -> LED blinking
    // > 700 -> LED on steadily

    if (sensorValue < LOW_THRESHOLD) {
        // LED off
        digitalWrite(LED_MAIN_PIN, LOW);

        // Second LED off
        digitalWrite(LED_2_PIN, LOW);

        // Buzzer off
        digitalWrite(BUZZER_PIN, LOW);

    } else if (sensorValue >= LOW_THRESHOLD && sensorValue <= HIGH_THRESHOLD) {
        // LED blinking
        digitalWrite(LED_MAIN_PIN, HIGH);
        delay(200);
        digitalWrite(LED_MAIN_PIN, LOW);
        delay(200);

        // Second LED: maybe slow blink or opposite phase
        digitalWrite(LED_2_PIN, HIGH);
        delay(200);
        digitalWrite(LED_2_PIN, LOW);
        delay(200);

        // Buzzer: short beeps
        digitalWrite(BUZZER_PIN, HIGH);
        delay(100);
        digitalWrite(BUZZER_PIN, LOW);
        delay(100);

    } else { // sensorValue > HIGH_THRESHOLD
        // LED on steadily
        digitalWrite(LED_MAIN_PIN, HIGH);

        // Second LED also on steadily
        digitalWrite(LED_2_PIN, HIGH);

        // Buzzer on steadily (you can change this to a pattern if it's annoying)
        digitalWrite(BUZZER_PIN, HIGH);

        // Small delay to avoid spamming Serial too fast
        delay(50);
    }
}
