#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

int bulb1=D0;
int bulb2=D1;

unsigned long channel1=2100354;
unsigned long channel2=2100356;

char* ssid="";
char* password="";

WiFiClient client;

void setup() {
  pinMode(bulb1,OUTPUT);
  pinMode(bulb2,OUTPUT);
  digitalWrite(bulb1,1);
  digitalWrite(bulb2,1);
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  Serial.println("Connecting...");
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Connected");
}

void loop() {
  unsigned int bulb1Status=ThingSpeak.readIntField(channel1,1);
  unsigned int bulb2Status=ThingSpeak.readIntField(channel2,1);
  Serial.print("Bulb1 Status: ");
  Serial.print(bulb1Status);
  Serial.print(",Bulb2 Status: ");
  Serial.println(bulb2Status);
  if(bulb1Status>0) {
    digitalWrite(bulb1,0);
  } else {
    digitalWrite(bulb1,1);
  }
  if(bulb2Status>0){
    digitalWrite(bulb2,0);
  } else {
    digitalWrite(bulb2,1);
  }
  delay(4000);
}
