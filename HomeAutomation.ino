#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
 
/* Set these to your desired credentials. */
const char *ssid = "JioFi_1011EEB";  //ENTER YOUR WIFI SETTINGS
const char *password = "64qrqgbvom";
 
//Web/Server address to read/write from 
const char *host = "http://maffystudios.000webhostapp.com";   //https://circuits4you.com website or IP address of server
 
//=======================================================================
//                    Power on setup
//=======================================================================
 WiFiClient client;
void setup() {
  delay(1000);
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
 
  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}
 
//=======================================================================
//                    Main Program Loop
//=======================================================================
void loop() {
  HTTPClient http;    //Declare object of class HTTPClient
 
  //String ADCData, station, postData;
  //int adcvalue = 5;  //Read Analog value of LDR
  //ADCData = String(adcvalue);   //String to interger conversion
  //station = "A";
 
  //Post Data
  //postData = "status=" + ADCData + "&station=" + station ;
  
  //http.begin("http://192.168.15.173/sql_arduino/postdemo.php");              //Specify request destination
  //http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header 
  //int httpCode = http.POST(postData);   //Send the request
  //String payload = http.getString();    //Get the response payload 
  //Serial.println(httpCode);   //Print HTTP return code
  //Serial.println(payload);    //Print request response payload 
  //http.end();  //Close connection

  http.begin("http://maffystudios.000webhostapp.com/user1/getdemo.php");  
  int httpCode = http.GET();
  String payload = http.getString();
  Serial.println(payload);
  Serial.println("Finish");
  http.end();
  
  delay(1000);  //Post Data at every 5 seconds
}
