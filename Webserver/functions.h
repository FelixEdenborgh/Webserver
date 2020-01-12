#include <ESP8266WiFi.h>

void initSerial(int baud) {
  Serial.begin(baud);
  delay(2000);
  Serial.println("Serial communication initiated.");
  
  
}


void initWiFi(char *ssid, char *pass) {
  Serial.printf("Wifi communication initiated. Please wait...");

  while(WiFi.status() != WL_CONNECTED){
    WiFi.begin(ssid, pass);
    delay(10000);
  }


  Serial.printf("Connected to WiFi Network %s \r\n", ssid);
  Serial.print("IP-Adress: ");
  Serial.println(WiFi.localIP());


}
