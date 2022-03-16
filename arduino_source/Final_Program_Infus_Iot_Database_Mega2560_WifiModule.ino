#include "WiFiEsp.h"
#include <ArduinoJson.h>
#ifndef HAVE_HWSERIAL1
#include "SoftwareSerial.h"
SoftwareSerial Serial1(6, 7);
#endif
char ssid[] = "SAWALA";
char pass[] = "tanyapaksatpam";
char server[] = "192.168.1.16";
int status = WL_IDLE_STATUS;
WiFiEspClient client;
unsigned long lastConnectionTime = 0;
const unsigned long postingInterval = 5000L;
String namapasien;
String ruangpasien;

#include "HX711.h"
#define DOUT  A0
#define CLK  A1
HX711 scale(DOUT, CLK);
float calibration_factor = -344.10;
int GRAM;
int ML;

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte ledhijau = 2;
byte ledmerah = 3;
byte buzzer = 4;

int count;
int count1;
int count2;
int count3;
String KET;

void printWifiStatus() {
  WiFi.init(&Serial1);
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);
  }
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
  }
  Serial.println("You're connected to the network");
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

void setup() {
  Serial.begin(9600);
  lcd.begin();

  pinMode(ledhijau, OUTPUT);
  pinMode(ledmerah, OUTPUT);
  pinMode(buzzer, OUTPUT);
  scale.set_scale();
  scale.tare();
  
  Serial1.begin(115200);
  printWifiStatus();
}

void loop() {
  scale.set_scale(calibration_factor);
  GRAM = scale.get_units(), 4;
  ML = map(GRAM, 0, 550, 0, 500);
  Serial.println(ML);

  if (ML > 500) {
    ML = 500;
  }
  if (ML < 1) {
    ML = 0;
  }

  if (ML > 151 & ML < 550) {
    KET = "Masih%20Penuh";
    count1++;
    count2 = 0;
    count3 = 0;
    digitalWrite(ledhijau, HIGH);
    digitalWrite(ledmerah, LOW);
    digitalWrite(buzzer, LOW);
    delay(300);
    if (count1 == 1) {
      count = 1;
    }
  }

  if (ML < 151 & ML > 51) {
    KET = "Tinggal%20Setengah";
    count1 = 0;
    count2++;
    count3 = 0;
    digitalWrite(ledhijau, LOW);
    digitalWrite(ledmerah, HIGH);
    digitalWrite(buzzer, LOW);
    delay(300);
    if (count2 == 1) {
      count = 1;
    }
  }

  if (ML < 51) {
    KET = "Kosong";
    count1 = 0;
    count2 = 0;
    count3++;
    digitalWrite(ledhijau, LOW);
    digitalWrite(ledmerah, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    delay(150);
    if (count3 == 1) {
      count = 1;
    }
  }



  //...................................................

  else {
//    lcd.setCursor(0, 0);
//    lcd.print("  no Connected  ");
//    lcd.setCursor(0, 1);
//    lcd.print("   To Server   ");
  }



  lcd.setCursor(0, 0);
  lcd.print(namapasien);
  lcd.print("     ");
  lcd.setCursor(0, 1);
  lcd.print(ruangpasien);
  lcd.print("      ");
  lcd.setCursor(11,1);
  lcd.print(ML);
  lcd.print("ml  ");
  delay(50);

  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
    AMBILDATA();
  }


}

//*****************************HTTP REQUEST********************//
void httpRequest() {
  Serial.println();
  client.stop();
  if (client.connect(server, 80)) {
    if (count == 1) {
      client.print("GET /infus/data.php?");
      client.print("ml=");
      client.print(ML);
      client.print("&ket=");
      client.print(KET);
      client.println(" HTTP/1.1");
      client.print("Host: ");
      client.println(server);
      client.println("Connection: close");
      client.println();
      count = 0;
    }
    lastConnectionTime = millis();
  }
  else {
    Serial.println("Connection failed");
  }
}

//***************************AMBIL DATA******************//
void AMBILDATA() {
  client.stop();
  Serial.println(F("Connecting..."));

  WiFiEspClient client;
  client.setTimeout(10000);
  if (!client.connect(server, 80)) {
    Serial.println(F("Connection failed"));
    return;
  }

  Serial.println(F("Connected!"));

  client.println(F("GET /infus/parser.php HTTP/1.0"));
  client.println(F("Host:  192.168.1.7"));
  client.println(F("Connection: close"));

  if (client.println() == 0) {
    Serial.println(F("Failed to send request"));
    return;
  }

  char status[32] = {0};
  client.readBytesUntil('\r', status, sizeof(status));
  if (strcmp(status, "HTTP/1.1 200 OK") != 0) {
    Serial.print(F("Unexpected response: "));
    Serial.println(status);
    return;
  }

  char endOfHeaders[] = "\r\n\r\n";
  if (!client.find(endOfHeaders)) {
    Serial.println(F("Invalid response"));
    return;
  }

  const size_t capacity = JSON_OBJECT_SIZE(3) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);

  JsonObject& root = jsonBuffer.parseObject(client);
  if (!root.success()) {
    Serial.println(F("Parsing failed!"));
    return;
  }


  Serial.println(F("Response:"));
  namapasien = root["namapasien"].as<char*>();
  ruangpasien = root["ruangpasien"].as<char*>();

  lastConnectionTime = millis();
}

