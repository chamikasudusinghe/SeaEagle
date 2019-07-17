//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// set firebase database.
#define FIREBASE_HOST "nodemcu-firebase-fbc49.firebaseio.com"
#define FIREBASE_AUTH "hUL2nMv4xxkWQEdrMKQSfMd2kzLI9AyidtzttUnR"
#define WIFI_SSID "Who Cares"
#define WIFI_PASSWORD "poiuylkjhg"
#define node "/boat/"

String id;
String count;
String begin;
String end;
String coordinates;

void setup() {
  
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  //Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    //Serial.print(".");
    delay(500);
  }
  //Serial.println();
  //Serial.print("connected: ");
  //Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
}

void loop() {

  getBoatDetails();
  delay(1000);
  sendBoatDetails();
  delay(3000);
  
}

void getBoatDetails(){
  
  FirebaseObject object = Firebase.get(node);

  id = object.getString("id");
  count = object.getString("count");
  begin = object.getString("begin");
  end = object.getString("end");

  Serial.println(id);
  Serial.println(count);
  Serial.println(begin);
  Serial.println(end);  
  
}

void sendBoatDetails(){
  
    Firebase.pushString("/boatR", id);
    Firebase.pushString("/boatR", count);
    Firebase.pushString("/boatR", begin);                                  
    Firebase.pushString("/boatR", end);
  
}
