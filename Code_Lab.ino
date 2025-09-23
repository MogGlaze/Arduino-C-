const int analog_pin = A0;
const int LED = 7;
int ADC_val = 0; 
int digital_map_LED = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(analog_pin, INPUT);
}

void loop() {
  ADC_val = analogRead(analog_pin);
  Serial.println(ADC_val);

  if (ADC_val < 470) {
    // Below threshold: LED off
    digital_map_LED = 0;
  } 
  else if (ADC_val >= 470 && ADC_val < 600) {
    // Mid range: map ADC_val between 470 and 600 to 0-255 brightness
    digital_map_LED = map(ADC_val, 470, 600, 0, 255);
  } 
  else {
    // Above 600: full brightness
    digital_map_LED = 255;
  }

  // Ensure value stays within 0-255 range (optional but safe)
  digital_map_LED = constrain(digital_map_LED, 0, 255);

  analogWrite(LED, digital_map_LED);

  delay(100); // small delay for readability in Serial monitor
}
