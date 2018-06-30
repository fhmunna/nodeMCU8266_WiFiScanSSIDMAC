/*
 *  Scanning WIFI With MAC ADRESS, PRINT MAC with NODEMCU 8266
 */
#include "ESP8266WiFi.h"

void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
}

void loop() {
  Serial.println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
    uint8* mac = WiFi.BSSID(i);
String APMAC;
      Serial.print(*mac, HEX);

        for (int i = 0; i <5; i++) {
            String digit = String(*mac, HEX);
            if (digit.length() < 2)
                APMAC += String("0") + digit;
            else
                APMAC += digit;
            mac++;
            Serial.print(":"); Serial.print(*mac, HEX);
        }
      
//      for(byte b=0; b<8; b++){
//      Serial.print(WiFi.BSSID(i)[b]);
//      }
      Serial.print(" (");
      Serial.print(WiFi.SSID(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
      delay(10);
    }
  }
  Serial.println("");

  // Wait a bit before scanning again
  delay(5000);
}
