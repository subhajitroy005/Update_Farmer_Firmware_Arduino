#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

char* ssid = "Prabhat-Wifi"; // The SSID (name) of the Wi-Fi network
char* password = "proy@683"; // The password of the Wi-Fi
const char* getHost = "192.168.0.101"; // The data receiver host name (not URL)
const int httpGetPort = 3000; // The data receiver host port
String getReceiverURL = "/arduino"; // The data receiver script



void setup() {
        Serial.begin(115200); // Start the Serial communication to send messages to the computer
        delay(10);
        Serial.println('\n');
        //WiFi.hostname("ESPboard-counter"); // Hostname of the board
        WiFi.begin(ssid, password); // Connect to the network
        Serial.print("Wifi credential: ");
        Serial.print(ssid);
        Serial.print("\t");
        Serial.println(password);
        while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
                delay(500);
                Serial.print('.');
        }
        Serial.println('\n');
        Serial.println("Connection established!");
        Serial.print("IP address:\t");
        Serial.println(WiFi.localIP()); // Send the IP address of the ESP8266 to the computer

}
