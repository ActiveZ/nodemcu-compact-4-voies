#include <Arduino.h>

#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
#include <ESP8266WebServer.h>
//#include <Arduino_JSON.h>

#include "index.h"
String page = MAIN_page;

// Replace with your network credentials
const char *SSID = "Alcyon";
const char *PASSWORD = "Jamin-26";
const int PORT = 8282;

// const int pinRelay = 0; // pour nodeMCU Bulles
const int pinRelay = 5; // pour nodeMCU compact
//const int pinLed = 16; // pour LED nodeMCU compact


long startTime = 0; // the value returned from millis when the switch is pressed
int duration = 0;   // time to wait before setOff in millis
int value = LOW; // relai off on startup
String request = "";
bool isBlink = false;
int durationBlinkOn = 0;  // temps en position on
int durationBlinkOff = 0; // temps en position off

ESP8266WebServer server(PORT); //instantiate server at port 8267 (http port)

////////////////////////////////////////////////////
///////////// FUNCTIONS ////////////////////////////
////////////////////////////////////////////////////

void setOn()
{
  digitalWrite(pinRelay, HIGH);
  value = HIGH;
  startTime = 0;
  Serial.println("on");
}

void setOff()
{
  digitalWrite(pinRelay, LOW);
  value = LOW;
  startTime = 0;
  Serial.println("off");
}

void setTimer()
{
  digitalWrite(pinRelay, HIGH);
  value = HIGH;
  startTime = millis();
  Serial.println("timer - blink");
}

////////////////////////////////////////////////
//////////////////// SETUP /////////////////////
////////////////////////////////////////////////

void setup(void)
{
  //make the relay pin output and initially turned off
  pinMode(pinRelay, OUTPUT);
  digitalWrite(pinRelay, LOW);

  delay(1000);
  Serial.begin(115200);
  WiFi.begin(SSID, PASSWORD); //begin WiFi connection
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(SSID);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", []()
            {
              isBlink = false;

              // mode on
              if (server.arg("relay") == "on")
              {
                setOn();
              }

              // mode off
              else if (server.arg("relay") == "off")
              {
                setOff();
              }

              // mode timer
              else if (server.arg("relay") == "timer")
              {
                duration = server.arg("duration").toInt() * 1000;
                setTimer();
              }

              // mode blink
              else if (server.arg("relay") == "blink")
              {
                isBlink = true;
                durationBlinkOn = server.arg("durationBlinkOn").toInt()* 1000;
                durationBlinkOff = server.arg("durationBlinkOff").toInt()* 1000;
                // durationBlinkOn = 1;
                // durationBlinkOff = 5;
                setTimer();
              }

              request = "";
              server.sendHeader("Access-Control-Allow-Origin", "*");
              server.send(200, "text/html", page);
            });

  server.begin();
  Serial.println("Web server started!");
}

/////////////////////////////////////////////////////
////////////////// LOOP /////////////////////////////
/////////////////////////////////////////////////////

void loop(void)
{
  if (!isBlink && startTime > 0) // mode timer
  {
    if (millis() - startTime > duration)
    {
      setOff();
    }
  }
  else if (isBlink) // mode clignotant
  {
    if (value == LOW && millis() - startTime > durationBlinkOff)
    {
      setOn();
      startTime = millis();
    }
    if (value == HIGH && millis() - startTime > durationBlinkOn)
    {
      setOff();
      startTime = millis();
    }
  }
  server.handleClient();
}