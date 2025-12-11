// Global variables
const int LED_PIN = 13;
const unsigned long TOGGLE_INTERVAL = 1000;  // Desired toggle interval
const unsigned long BLINK_DURATION  = 200;   // LED on/off duration
const unsigned long WARNING_LIMIT   = 1500;  // Time threshold for warning/error

unsigned long lastToggleTime = 0;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Step 1: Toggle LED and get status
    bool LED_sys_status = timedToggle();

    // Step 2: Get timing error status
    unsigned long system_timing_error_status = getTooMuchTimePassed();

    // Step 3: Print LED status and timing error
    Serial.print("LED Status: ");
    Serial.println(LED_sys_status);
    Serial.print("Time Overrun: ");
    Serial.println(system_timing_error_status);

    // Step 4: Handle warning/error
    system_warning_error(system_timing_error_status);

    delay(50); // Small delay to stabilize loop
}

// Toggles LED based on time and returns LED state
bool timedToggle() {
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - lastToggleTime;

    if (elapsedTime >= TOGGLE_INTERVAL) {
        // Start new toggle cycle
        digitalWrite(LED_PIN, HIGH);
        delay(BLINK_DURATION);
        digitalWrite(LED_PIN, LOW);
        lastToggleTime = currentTime;
        return true;
    }
    return false;
}

// Returns how much time has passed beyond the toggle interval
unsigned long getTooMuchTimePassed() {
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - lastToggleTime;

    if (elapsedTime > TOGGLE_INTERVAL) {
        return elapsedTime - TOGGLE_INTERVAL;
    }
    return 0;
}

// Reports warning or error based on time overrun
void system_warning_error(unsigned long tooMuchTime) {
    if (tooMuchTime > 0 && tooMuchTime <= WARNING_LIMIT) {
        Serial.println("WARNING: Loop is running slightly late.");
    } else if (tooMuchTime > WARNING_LIMIT) {
        Serial.println("ERROR: Loop is running too slow!");
    }
}
