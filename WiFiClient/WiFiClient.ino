#include <ESP8266WiFi.h>
#include  <ESP8266WebServer.h>

const char* ssid = "LEB_EVO_COM";
const char* password = "satuduatiga";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.println();
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  ESP8266WebServer Server(80);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", [](){
    server.send(200,"text/html", "<html>\
    <head>\
    <title>BERANDA</title>\
    <style>\
    h1 { color:red }\
    </style>\
    </head>\
    <body>\
    <h1>BERANDA</h1>\
    <a href='/'>BERANDA</a>|<a href='/profil'>PROFIL</a>\
    </body>\
    </html>");
  });
   server.on("/profil", [](){
    server.send(200,"text/html", "<html>\
    <head>\
    <title>PROFIL</title>\
    <style>\
     h1 { color:red }\
    </style>\
    </head>\
    <body>\
    <h1>PROFIL</h1>\
    <a href='/'>BERANDA</a>|<a href='/profil'>PROFIL</a>\
    </body>\
    </html>");
  });

  server.begin();
}

void loop() {
    server.handleClient();
  }

  