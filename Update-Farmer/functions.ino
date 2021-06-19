
void postData() 
{
        WiFiClient clientGet;
        String getReceiverURLtemp = getReceiverURL + "?temp=20.01&hum=30.22";

        Serial.println("-------------------------------");
        Serial.print(">>> Connecting to host: ");
        Serial.println(getHost);

        if(!clientGet.connect(getHost, httpGetPort)) {
                Serial.print("Connection failed: ");
                Serial.print(getHost);
        } else {
                /*
                 * GET /hello.htm HTTP/1.1
                   User-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)
                   Host: www.tutorialspoint.com
                   Accept-Language: en-us
                   Accept-Encoding: gzip, deflate
                   Connection: Keep-Alive/close\r\n\r\n
                */
                clientGet.println("GET " + getReceiverURLtemp + " HTTP/1.1");
                clientGet.print("Host: ");
                clientGet.println(getHost);
                clientGet.println("User-Agent: ESP8266/1.0");
                clientGet.println("Connection: close\r\n\r\n");

                unsigned long timeoutP = millis();
                while (clientGet.available() == 0) {
                        if (millis() - timeoutP > 10000) {
                                Serial.print(">>> Client Timeout: ");
                                Serial.println(getHost);
                                clientGet.stop();
                                return;
                        }
                }

                //just checks the 1st line of the server response. Could be expanded if needed.
                while(clientGet.available()){
                        String retLine = clientGet.readStringUntil('\r');
                        Serial.print(">>> Host returned: ");
                        Serial.println(retLine);
                        // reset counter if successully connected
                        if (retLine == "HTTP/1.1 200 OK") {
                                Serial.println(">>> Communication successful");
                        } else {
                                Serial.println(">>> Communication failed!!!");
                        }
                }

        } //end client connection if else

        Serial.print(">>> Closing host: ");
        Serial.println(getHost);

        clientGet.stop();
}
