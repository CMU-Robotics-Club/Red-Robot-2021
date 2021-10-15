#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "controller_values.h"
#include "controller_html.h"

//#ifndef PASSWORD
//#define PASSWORD "changeme"
//#endif

ESP8266WebServer server(80);

//const char *www_username = "redrobot";
//const char *www_password = PASSWORD;

void setup()
{
  // Setup stuff
  Serial.begin(19200);

  // Print MAC Address
  Serial.print("\n\nMAC Address (Add me to CMU-DEVICE): ");
  Serial.println(WiFi.macAddress());

  //  Serial.setTimeout(0);
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
  server.on("/", []()
  {
    //    if (!server.authenticate(www_username, www_password))
    //    {
    //      return server.requestAuthentication();
    //    }
    server.send(200, "text/html", html);
  });

  // API routes
  server.on("/update", HTTP_POST, []()
  {
    //    if (!server.authenticate(www_username, www_password))
    //    {
    //      return server.requestAuthentication();
    //    }
    // Check and read request body for args x and y, error if not found
    if (server.hasArg("x") && server.hasArg("y"))
    {
      server.arg("x").toCharArray(joystickX, 7);
      server.arg("y").toCharArray(joystickY, 7);
    }
    if (server.hasArg("x2") && server.hasArg("y2"))
    {
      server.arg("x2").toCharArray(joystickX2, 7);
      server.arg("y2").toCharArray(joystickY2, 7);
    }

    if (server.hasArg("btn1"))
      btn1 = server.arg("btn1").equals("true");
    if (server.hasArg("btn2"))
      btn2 = server.arg("btn2").equals("true");
    if (server.hasArg("btn3"))
      btn3 = server.arg("btn3").equals("true");
    if (server.hasArg("btn4"))
      btn4 = server.arg("btn4").equals("true");
    if (server.hasArg("btn5"))
      btn5 = server.arg("btn5").equals("true");
    if (server.hasArg("btn6"))
      btn6 = server.arg("btn6").equals("true");
    if (server.hasArg("btn7"))
      btn7 = server.arg("btn7").equals("true");
    if (server.hasArg("btn8"))
      btn8 = server.arg("btn8").equals("true");
    if (server.hasArg("btn9"))
      btn9 = server.arg("btn9").equals("true");
    if (server.hasArg("up1"))
      up1 = server.arg("up1").equals("true");
    if (server.hasArg("up2"))
      up2 = server.arg("up2").equals("true");
    if (server.hasArg("up3"))
      up3 = server.arg("up3").equals("true");
    if (server.hasArg("down1"))
      down1 = server.arg("down1").equals("true");
    if (server.hasArg("down2"))
      down2 = server.arg("down2").equals("true");
    if (server.hasArg("down3"))
      down3 = server.arg("down3").equals("true");

    digitalWrite(LED_BUILTIN, (
                   btn1 || btn2 || btn3 ||
                   btn4 || btn5 || btn6 ||
                   btn7 || btn8 || btn9 ||
                   up1 || up2 || up3 ||
                   down1 || down2 || down3)
                 ? HIGH
                 : LOW);

    server.send(200, "text/plain", "OK");
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

void loop()
{
  long x = micros();
  server.handleClient();
  readSerial();
  if (stringComplete)
    sendResponse();
  Serial.println(micros() - x);
}
