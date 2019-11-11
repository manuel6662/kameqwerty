#include "webconnector.h"

const char* ssid = "MINIKAME";
const char* password = "manuel1974";
WiFiServer server(80);

void WebConnector::init() {
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  server.begin();
  activeCommand = 12;
}

void WebConnector::handleConnection() {
  WiFiClient client = server.available();
  while (client.connected()) {
    if (client.available()) {
      while(client.available()) {
        input = client.readStringUntil('\n');
        if (input.startsWith("GET")) {
          // this is our get request, check if we have a parameter
          int commandPosition = input.indexOf("?command=");
          if (commandPosition > -1) {
            // a command, how exciting.
            activeCommand = input.substring(commandPosition+9, commandPosition+11);
            Serial.println("The active command is: " + activeCommand);
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println("Connection: close");
            client.println();
            client.println("<!DOCTYPE HTML><html></html>");
            client.stop();
          } else {
            // give back the ajax page with commands
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println("Connection: close");
            client.println();
           // client.println("<!DOCTYPE HTML><!doctype html> <html> <head> <meta charset=\"utf-8\">  <script type=\"text/javascript\"> function fireCommand(value) { document.getElementById(value).style.background = \"black\"; var xhttp = new XMLHttpRequest(); xhttp.onreadystatechange = function() { if (xhttp.readyState == 4) { document.getElementById(value).style.background = ''; }}; xhttp.open(\"GET\", \"cmd.html?command=\"+value, true); xhttp.send(); } </script> </head> )\">Right</div> <div class=\"cB\" id=\"09\" onclick=\"fireCommand('09')\">Cross</div> <div class=\"cBDir\" id=\"10\" onclick=\"fireCommand('10')\">Back</div> <div class=\"cB\" id=\"08\" onclick=\"fireCommand('08')\">Jump</div> <div class=\"cB\" id=\"11\" onclick=\"fireCommand('11')\">Dance</div> <div class=\"cB\" id=\"12\" onclick=\"fireCommand('12')\">Fetch</div> <div class=\"cB\" id=\"13\" onclick=\"fireCommand('13')\">Auto</div> </div> </body> </html>");
            client.stop();
          }
        }
      }
    }
  }
}

String WebConnector::getActiveCommand() {
  return activeCommand;
}
