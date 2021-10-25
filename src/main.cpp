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
const int PORT = 8284;

const int pinLed = 5; // pour LED nodeMCU 4 voies
const int pinRelay1 = 16; // pour nodeMCU 4 voies
const int pinRelay2 = 14; // pour nodeMCU 4 voies
const int pinRelay3 = 12; // pour nodeMCU 4 voies
const int pinRelay4 = 13; // pour nodeMCU 4 voies

// const int pinRelay = 16; // pour nodeMCU 4 voies pour debug

long startTime1 = 0; // the value returned from millis when the switch is pressed
int duration1 = 0;   // time to wait before setOff in millis
long startTime2 = 0;
int duration2 = 0;
long startTime3 = 0;
int duration3 = 0;
long startTime4 = 0;
int duration4 = 0;

String request = "";

bool isTimer1 = false;
bool isTimer2 = false;
bool isTimer3 = false;
bool isTimer4 = false;

bool isBlink1 = false;
bool isBlink2 = false;
bool isBlink3 = false;
bool isBlink4 = false;

int durationBlinkOn1 = 0;  // temps en position on
int durationBlinkOn2 = 0;  // temps en position on
int durationBlinkOn3 = 0;  // temps en position on
int durationBlinkOn4 = 0;  // temps en position on
int durationBlinkOff1 = 0; // temps en position off
int durationBlinkOff2 = 0; // temps en position off
int durationBlinkOff3 = 0; // temps en position off
int durationBlinkOff4 = 0; // temps en position off

ESP8266WebServer server(PORT); // instantiate server at port 8267 (http port)

////////////////////////////////////////////////////
///////////// FUNCTIONS ////////////////////////////
////////////////////////////////////////////////////

void setOff(int pinRelay)
{
  digitalWrite(pinRelay, LOW);
  if (pinRelay == 16) {
    startTime1 = 0;
    isTimer1 = false;
    isBlink1 = false;
  }
  else if (pinRelay == 14) {
    startTime2 = 0;
    isTimer2 = false;
    isBlink2 = false;
  }
  else if (pinRelay == 12) {
    startTime3 = 0;
    isTimer3 = false;
    isBlink3 = false;
  }  
  else if (pinRelay == 13) {
    startTime4 = 0;
    isTimer4 = false;
    isBlink4 = false;
  }
  Serial.println("off");
}


// void setOn(int pinRelay)
// {
//   setOff(pinRelay);
//   digitalWrite(pinRelay, HIGH);
//   Serial.println("on");
// }


void setTimer(int pinRelay)
{
  digitalWrite(pinRelay, HIGH);

  if (pinRelay == 16)
  {
    startTime1 = millis();
  }
  else if (pinRelay == 14)
  {
    startTime2 = millis();
  }  
  else if (pinRelay == 12)
  {
    startTime3 = millis();
  }  
  else if (pinRelay == 13)
  {
    startTime4 = millis();
  }
  Serial.println("timer - blink");
}

// pour debug
// void testPin(int pin)
// {
//   if (pin == 12) {digitalWrite(pinRelay1, !digitalRead(pinRelay1));}
//   if (pin == 13) {digitalWrite(pinRelay2, !digitalRead(pinRelay2));}
//   if (pin == 14) {digitalWrite(pinRelay3, !digitalRead(pinRelay3));}
//   if (pin == 16) {digitalWrite(pinRelay4, !digitalRead(pinRelay4));}

//   Serial.printf("pin test: %d\n", pin);
//   for (int i = 0; i < 17; i++)
//   {
//     Serial.printf("pin %d: %d\n", i, digitalRead(i));
//   }
//   Serial.println("----------------------------------");
// }

////////////////////////////////////////////////
//////////////////// SETUP /////////////////////
////////////////////////////////////////////////

void setup(void)
{
  // make the relay pin output and initially turned off
  pinMode(pinRelay1, OUTPUT);
  digitalWrite(pinRelay1, LOW);
  pinMode(pinRelay2, OUTPUT);
  digitalWrite(pinRelay2, LOW);  
  pinMode(pinRelay3, OUTPUT);
  digitalWrite(pinRelay3, LOW);  
  pinMode(pinRelay4, OUTPUT);
  digitalWrite(pinRelay4, LOW);

  delay(1000);
  Serial.begin(115200);
  WiFi.begin(SSID, PASSWORD); // begin WiFi connection
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
    // mode on
    if (server.arg("relay") == "on")
    {
      // setOn(server.arg("pin").toInt());
      setOff(server.arg("pin").toInt());
      digitalWrite(server.arg("pin").toInt(), HIGH);
      Serial.println("on");
    }

    // mode off
    if (server.arg("relay") == "off")
    {
      setOff(server.arg("pin").toInt());
    }

    // mode timer
    if (server.arg("relay") == "timer")
    {
      if (server.arg("pin").toInt() == 16) // relai 1
      {
        duration1 = server.arg("duration").toInt() * 1000;
        isTimer1 = true;
        setTimer(16);
      }
            
      if (server.arg("pin").toInt() == 14) // relai 2
      {
        duration2 = server.arg("duration").toInt() * 1000;
        isTimer2 = true;
        setTimer(14);
      }

      if (server.arg("pin").toInt() == 12) // relai 3
      {
        duration3 = server.arg("duration").toInt() * 1000;
        isTimer3 = true;
        setTimer(12);
      }      
      
      if (server.arg("pin").toInt() == 13) // relai 4
      {
        duration4 = server.arg("duration").toInt() * 1000;
        isTimer4 = true;
        setTimer(13);
      }
    }

    
    // mode blink      
    if (server.arg("relay") == "blink")
    {
      if (server.arg("pin").toInt() == 16)
      {
        isBlink1 = true;
        isTimer1 = false;
        durationBlinkOn1 = server.arg("durationBlinkOn").toInt() * 1000;
        durationBlinkOff1 = server.arg("durationBlinkOff").toInt() * 1000;
        setTimer(server.arg("pin").toInt());
      }
      if (server.arg("pin").toInt() == 14)
      {
        isBlink2 = true;
        isTimer2 = false;
        durationBlinkOn2 = server.arg("durationBlinkOn").toInt() * 1000;
        durationBlinkOff2 = server.arg("durationBlinkOff").toInt() * 1000;
        setTimer(server.arg("pin").toInt());
      }      
      if (server.arg("pin").toInt() == 12)
      {
        isBlink3 = true;
        isTimer3 = false;
        durationBlinkOn3 = server.arg("durationBlinkOn").toInt() * 1000;
        durationBlinkOff3 = server.arg("durationBlinkOff").toInt() * 1000;
        setTimer(server.arg("pin").toInt());
      }
      if (server.arg("pin").toInt() == 13)
      {
        isBlink4 = true;
        isTimer4 = false;
        durationBlinkOn4 = server.arg("durationBlinkOn").toInt() * 1000;
        durationBlinkOff4 = server.arg("durationBlinkOff").toInt() * 1000;
        setTimer(server.arg("pin").toInt());
      }
    }

    // test pin
    // else if (server.arg("testPin"))
    // {
    //   testPin(server.arg("pin").toInt());
    // }

    request = "";
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "text/html", page);
    // server.send(200, "text/html", "hello page"); 
    });

  server.begin();
  Serial.println("Web server started!");
}

/////////////////////////////////////////////////////
////////////////// LOOP /////////////////////////////
/////////////////////////////////////////////////////

void loop(void)
{
  // test des modes timer des 4 relais
  if (isTimer1 && startTime1 > 0) // mode timer relai 1
  {
    if (millis() - startTime1 > duration1)
    {
      setOff(16);
    }
  }

  if (isTimer2 && startTime2 > 0) // mode timer relai 2
  {
    if (millis() - startTime2 > duration2)
    {
      setOff(14);
    }
  }

  if (isTimer3 && startTime3 > 0) // mode timer relai 3
  {
    if (millis() - startTime3 > duration3)
    {
      setOff(12);
    }
  }

  if (isTimer4 && startTime4 > 0) // mode timer 4
  {
    if (millis() - startTime4 > duration4)
    {
      setOff(13);
    }
  }

 ///////////////////////////////////////////////
  // test des modes clignotant des 4 relais
  if (isBlink1) // mode clignotant relai 1
  {
    if (digitalRead(16) == LOW && millis() - startTime1 > durationBlinkOff1)
    {
      digitalWrite(16, HIGH);
      startTime1 = millis();
    }
    if (digitalRead(16) == HIGH && millis() - startTime1 > durationBlinkOn1)
    {
      digitalWrite(16, LOW);
      startTime1 = millis();
    }
  }

  if (isBlink2) // mode clignotant relai 2
  {
    if (digitalRead(14) == LOW && millis() - startTime2 > durationBlinkOff2)
    {
      digitalWrite(14, HIGH);
      startTime2 = millis();
    }
    if (digitalRead(14) == HIGH && millis() - startTime2 > durationBlinkOn2)
    {
      digitalWrite(14, LOW);
      startTime2 = millis();
    }
  }  
  
  if (isBlink3) // mode clignotant relai 3
  {
    if (digitalRead(12) == LOW && millis() - startTime3 > durationBlinkOff3)
    {
      digitalWrite(12, HIGH);
      startTime3 = millis();
    }
    if (digitalRead(12) == HIGH && millis() - startTime3 > durationBlinkOn3)
    {
      digitalWrite(12, LOW);
      startTime3 = millis();
    }
  }  
  
  if (isBlink4) // mode clignotant relai 4
  {
    if (digitalRead(13) == LOW && millis() - startTime4 > durationBlinkOff4)
    {
      digitalWrite(13, HIGH);
      startTime4 = millis();
    }
    if (digitalRead(13) == HIGH && millis() - startTime4 > durationBlinkOn4)
    {
      digitalWrite(13, LOW);
      startTime4 = millis();
    }
  }

  server.handleClient();
}