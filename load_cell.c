/*
    Project name : Load Cell
    Modified Date: 11-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-load-cell
*/

const int loadCellDataPin = A0; // Analog pin connected to the load cell
const float calibrationFactor = 1.0; // Calibration factor for load cell

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the voltage from the load cell
  int sensorValue = analogRead(loadCellDataPin);
  
  // Convert sensor value to weight in grams
  float weight = convertToGrams(sensorValue);
  
  // Print the weight to the Serial Monitor
  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" grams");
  
  // Add a small delay to avoid spamming the Serial Monitor
  delay(1000);
}

float convertToGrams(int sensorValue) {
  // Convert sensor value to weight using calibration factor
  float weight = sensorValue * calibrationFactor;
  return weight;
}
