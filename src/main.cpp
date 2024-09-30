#include <Arduino.h>
#include "DHTesp.h"

// Define the pin where the DHT22 is connected
#ifdef BOARD_ESP32_DOIT
  #define DHTPIN 23
#elif BOARD_ESP32_C3_CORE
  #define DHTPIN 0
#endif

// Initialize the DHT sensor
DHTesp dht;

void setup() {
  // Start the serial communication
  Serial.begin(115200);
  // Initialize the DHT sensor
  dht.setup(DHTPIN, DHTesp::DHT11);
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

// float humidity = 50.0;
// float temperature = 25.0;
  // Read humidity
  float humidity = dht.getHumidity();
  // // Read temperature as Celsius
  float temperature = dht.getTemperature();

  // Check if any reads failed and exit early (to try again)
  if (isnan(humidity) || isnan(temperature)) {
	Serial.println("Failed to read from DHT sensor!");
	return;
  }

  // Print the results to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
}
