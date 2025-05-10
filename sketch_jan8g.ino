#include <LiquidCrystal.h>
#include "DHT.h" // Call the DHT library
#define DHTPIN 8 // Pin connected to DHT

#define DHTTYPE DHT11 // Define the type of DHT module
DHT dht(DHTPIN, DHTTYPE); // Command to the DHT.h library
void setup() {
 dht.begin(); // Start the sensor
 
 Serial.begin(9600);
}
void loop() {
 float h = dht.readHumidity(); // Value for humidity
 float t = dht.readTemperature(); // Value for temperature
 //t = t * 9 / 5 + 32; // Change reading from Celsius to Fahrenheit
 if (isnan(t) || isnan(h)) { // Check that DHT sensor is working
 
 Serial.print("Failed to read from DHT"); // If DHT is not working, 
 // display this
 } else { // Otherwise show the readings on the screen
 
 Serial.print("humidity is ");
 Serial.print(h);
 Serial.println("%");
 
 Serial.print("Temperature is");
 Serial.print(t);
 
 }
}
