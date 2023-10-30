#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Replace with your ssid";
const char* password = "Replace with you password";

ESP8266WebServer server(80);
const int ledPin1 = 4; // GPIO 2
const int ledPin2 = 0; // GPIO 0
const int ledPin3 = 2 ; // GPIO 4

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  Serial.println("Local IP: " + WiFi.localIP().toString());

  server.on("/get_data", HTTP_GET, handleGetData);

  server.begin();

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  server.handleClient();

}

void handleGetData() {
  String query1 = server.arg("led1State");
  String query2 = server.arg("led2State");
  String query3 = server.arg("led3State");

  if (query1 == "0" && query2 == "0" && query3 == "0") {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }

  if (query1 == "1" && query2 == "0" && query3 == "0") {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }
  
  if (query1 == "0" && query2 == "1" && query3 == "0") {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
  }
  
  if (query1 == "0" && query2 == "0" && query3 == "1") {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
  }

  if (query1 == "1" && query2 == "1" && query3 == "0") {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
  }

  if (query1 == "1" && query2 == "0" && query3 == "1") {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
  }

  if (query1 == "0" && query2 == "1" && query3 == "1") {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  }

  if (query1 == "1" && query2 == "1" && query3 == "1") {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  }

  Serial.println("LED1 State: " + query1);
  Serial.println("LED2 State: " + query2);
  Serial.println("LED3 State: " + query3 + "\n");

}