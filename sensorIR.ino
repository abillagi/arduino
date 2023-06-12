
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid = "ADRWIRE";
// const char* password =  "jangandigunakan123";
String server = "http://172.30.0.218/sendhitungbrgplastik.php";

WiFiClient client;

int p = 0;
int x = 0;
int y = 0;
int a = 0;
int b = 0;
int z = 0;
int c;
int q;
int r = 0;


void setup() {
  // put your setup code here, to run once:
pinMode (12, INPUT);
pinMode (16, INPUT);
pinMode (4, INPUT);
Serial.begin(115200);
 
WiFi.disconnect();
delay(10);
WiFi.begin(ssid);

Serial.println();
Serial.println();
Serial.print("Menghubungkan ke-");
Serial.println(ssid);

WiFi.begin(ssid);
while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
  }
  Serial.println("");
  Serial.print("Node MCU Terhubung ke WiFi-");
  Serial.println(ssid);
 // Serial.print("Dengan IP :");
  //Serial.println(WiFi.localIP);
  Serial.println();


}

void loop() {
  // put your main code here, to run repeatedly:
int baca = digitalRead(12);
int resetangka = digitalRead(16);


if (resetangka == 0){
  p++;
  
}
if (resetangka !=0){
  if (p !=0 ){
    y = 0;
  Serial.print("Barang Ke-");
  getReq();

  // Serial.print("Jumlah Barang Direset");
  Serial.println(y);
  p = 0;
  }
}
  //Serial.println(baca);
  // Serial.println(baca);
if (baca == 0){
    x++;
}

if (baca != 0){ 
if (x != 0){
  y= y + 1;
  
  Serial.print("Barang Ke- ");
  Serial.println(y);
  x = 0;
  getReq();
}else {
  y = y;

}

}


}


void jumlahbarang(){
  Serial.print("Barang Ke- ");
  Serial.println(y);
}

void getReq(){
  if (WiFi.status()== WL_CONNECTED){
    WiFiClient client;
    HTTPClient http;
    //Serial.println("Connected");
    String serverPath = server + "?hitungbrg=" + y;
    http.begin(client, serverPath.c_str());
   
    //Send HTTP GET Request
    int httpResponseCode = http.GET();

    Serial.println("Data Terkirim Ke Database");
    
  }
  else{
    Serial.println("Data Gagal Terkirim");
  }
}
