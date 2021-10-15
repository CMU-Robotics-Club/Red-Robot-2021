#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "controller_values.h"
#include "controller_html.h"

AsyncWebServer server(80);

void setup()
{
  // Setup stuff
  Serial.begin(19200);

  // Print MAC Address
  Serial.print("\n\nMAC Address (Add me to CMU-DEVICE): ");
  Serial.println(WiFi.macAddress());

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);


  // Connect to WiFi
  WiFi.begin("CMU-DEVICE");
  if (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.println("WiFi Connect Failed! Rebooting...");
    delay(1000);
    ESP.restart();
  }


  // Main route
  server.on("/", [](AsyncWebServerRequest * request)
  {
    request->send_P(200, "text/html", html);
  });

  // API routes
  server.on("/update", HTTP_POST, [](AsyncWebServerRequest * request)
  {
    if (request->hasParam("x", true) && request->hasParam("y", true))
    {
      request->getParam("x", true)->value().toCharArray(joystickX, 7);
      request->getParam("y", true)->value().toCharArray(joystickY, 7);
    }
    if (request->hasParam("x2", true) && request->hasParam("y2", true))
    {
      request->getParam("x2", true)->value().toCharArray(joystickX2, 7);
      request->getParam("y2", true)->value().toCharArray(joystickY2, 7);
    }

    if (request->hasParam("btn1", true))
      btn1 = request->getParam("btn1", true)->value().equals("true");
    if (request->hasParam("btn2", true))
      btn2 = request->getParam("btn2", true)->value().equals("true");
    if (request->hasParam("btn3", true))
      btn3 = request->getParam("btn3", true)->value().equals("true");
    if (request->hasParam("btn4", true))
      btn4 = request->getParam("btn4", true)->value().equals("true");
    if (request->hasParam("btn5", true))
      btn5 = request->getParam("btn5", true)->value().equals("true");
    if (request->hasParam("btn6", true))
      btn6 = request->getParam("btn6", true)->value().equals("true");
    if (request->hasParam("btn7", true))
      btn7 = request->getParam("btn7", true)->value().equals("true");
    if (request->hasParam("btn8", true))
      btn8 = request->getParam("btn8", true)->value().equals("true");
    if (request->hasParam("btn9", true))
      btn9 = request->getParam("btn9", true)->value().equals("true");
    if (request->hasParam("up1", true))
      up1 = request->getParam("up1", true)->value().equals("true");
    if (request->hasParam("up2", true))
      up2 = request->getParam("up2", true)->value().equals("true");
    if (request->hasParam("up3", true))
      up3 = request->getParam("up3", true)->value().equals("true");
    if (request->hasParam("down1", true))
      down1 = request->getParam("down1", true)->value().equals("true");
    if (request->hasParam("down2", true))
      down2 = request->getParam("down2", true)->value().equals("true");
    if (request->hasParam("down3", true))
      down3 = request->getParam("down3", true)->value().equals("true");

    digitalWrite(LED_BUILTIN, (
                   btn1 || btn2 || btn3 ||
                   btn4 || btn5 || btn6 ||
                   btn7 || btn8 || btn9 ||
                   up1 || up2 || up3 ||
                   down1 || down2 || down3)
                 ? HIGH
                 : LOW);

    request->send(200, "text/plain", "OK");
  });

  // Start server
  server.begin();

  // Print IP Address
  Serial.print("Open http://");
  Serial.print(WiFi.localIP());
  Serial.println("/ in your browser to control the robot!");
}

// Handle serial events
String inputString = "";
String newString = "";
volatile bool stringComplete = false;
void readSerial() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
      newString = inputString;
      inputString = "";
    }
  }
}

// Send response back to Arduino client
void sendResponse() {
  stringComplete = false;
  switch (newString.charAt(0)) {
    case 'j':
      Serial.print(joystickX);
      Serial.print(",");
      Serial.println(joystickY);
      break;
    case 'k':
      Serial.print(joystickX2);
      Serial.print(",");
      Serial.println(joystickY2);
      break;
    case '1':
      Serial.println((uint8_t)btn1);
      break;
    case '2':
      Serial.println((uint8_t)btn2);
      break;
    case '3':
      Serial.println((uint8_t)btn3);
      break;
    case '4':
      Serial.println((uint8_t)btn4);
      break;
    case '5':
      Serial.println((uint8_t)btn5);
      break;
    case '6':
      Serial.println((uint8_t)btn6);
      break;
    case '7':
      Serial.println((uint8_t)btn7);
      break;
    case '8':
      Serial.println((uint8_t)btn8);
      break;
    case '9':
      Serial.println((uint8_t)btn9);
      break;
    case 'a':
      Serial.println((uint8_t)up1);
      break;
    case 'b':
      Serial.println((uint8_t)down1);
      break;
    case 'c':
      Serial.println((uint8_t)up2);
      break;
    case 'd':
      Serial.println((uint8_t)down2);
      break;
    case 'e':
      Serial.println((uint8_t)up3);
      break;
    case 'f':
      Serial.println((uint8_t)down3);
      break;
  }
}

//long x = micros();
void loop()
{
  readSerial();
  if (stringComplete)
    sendResponse();
//  Serial.println(micros() - x);
//  x = micros();
}
