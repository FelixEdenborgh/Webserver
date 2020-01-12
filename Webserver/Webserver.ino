#include <ESP8266WebServer.h>
#include "functions.h"
#include "websites.h"
#include "Config.h"

void setup() {
  initSerial(115200);
  initWiFi("IoT", "IoT2018!");
  
  WebServer.on("/", login);
  WebServer.on("/Login", HTTP_POST, validateLogin); 
  WebServer.on("/", overview);
  WebServer.begin();
}

void loop() {
  WebServer.handleClient();

}
