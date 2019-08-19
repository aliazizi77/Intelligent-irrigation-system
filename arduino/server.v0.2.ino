#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "Login.h"
//#include "Logout.h"
//#include "Header.h"
//#include "Home.h"

//const char* ssid = "TP-LINK_C3E6FB";
//const char* password = "123456789";

//const char* ssid = "TP-LINK_A25DF7";
//const char* password = "34180012";

const char* ssid= "AndroidAP";
const char* password = "123456789";

//const char* ssid = "InterNet-SabaNet";
//const char* password = "Saba@2627282930#Net";

String pass    = "admin";
String USERNAME ="ali";
String USERNAME1 ="esmaeil";
bool   authentified = false;
String a,b,Graph1,Graph2;
int c=0,d=0;
int value=0;
int value1=0;
String adc[3];
//const char* esi="123";
bool state=0;
ESP8266WebServer server(80);

const int led = LED_BUILTIN;

void handleRoot() {
  
  //server.send(200, "text/plain", "Hello from esp8266!");
  if(authentified == false){
     server.send(200, "text/html", Login);
      digitalWrite(led, 1);
           }
           if (server.hasArg("USERNAME") && server.hasArg("PASSWORD")){
                if (server.arg("USERNAME") == USERNAME &&  server.arg("PASSWORD") == pass ){  
                     authentified = true;
                     digitalWrite(led,1);
                        
               }
          }
                   if(authentified == true){
                           //     server.send(200, "text/html", Header);
String Home1=
                           
       "  <html>  "   
 "       <head>  "   
 "           <meta charset=\"utf-8\">  "   
 "           <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">  "   
 "     "   
 "         "   
 "           <title>سیستم ابیاری هوشمند</title>  "   
 "     "   
 "     <style type=\"text/css\">  "   
 "     #test {  "   
 "     background-image: url(\"https://cdn.dribbble.com/users/1315300/screenshots/3556675/untitled-1.gif\");  "   
 "     width: 50%;  "   
 "       "   
 "     float: left;  "   
 "     background-attachment: fixed;}  "   
 "       .login_page{margin: auto; width: 70%; border: 1px solid rgb(0, 0, 0);overflow: auto;position: relative;border-radius: 50px;}  "   
 "       .login_col_left{background-color:#FFD700;width:50%;float:left;}  "   
 "       .login_col_right{background-color:#FFD700;width:50%;float:left;}  "   
 "       .login_col_rightb{  width:50%;float:left;}  "   
    
 "       body {font-family: \"Arial\";}  "   
 "       .login {margin: 50px auto;padding: 18px 20px;width: 200px;  "   
 "       background-clip: padding-box;}  "   
 "       .login > h1 {font-family: \"B Titr\";margin-bottom: 20px;font-size: 20px;font-weight: bold;color: rgb(221, 0, 0);text-align: center;text-shadow: 0 -1px rgba(0, 0, 0, 0.4);}  "   
 "       .login-input {display: block;width: 100%;height: 37px;margin-bottom: 20px; font-family: \"Arial\"; font-size: 26px; text-align: center; padding: 0 9px;color: white;text-shadow: 0 1px black;"   
 "       background: #2b3e5d;box-shadow: inset 0 1px 2px rgba(0, 0, 0, 0.3), 0 0 4px 1px rgba(255, 255, 255, 0.6);}  "   
 "       .login-submit {display: block;width: 100%;height: 37px;margin-bottom: 15px;font-size: font-family: \"Arial\"; 14px;  "   
 "       font-weight: bold;color: #294779;text-align: center;text-shadow: 0 1px rgba(255, 255, 255, 0.3);}  "   
 "     </style>  "   
 "     </head>  "   
 "     <body>  "   
 "           <div class=\"login_page\">  "   
 "               <div class=\"login_col_left\">  "   
 "                   <form method=\"POST\" class=\"login\">  "   
 "                   <h1>صفحه دوم</h1>  "   
  "                   <input type=\"user\" name=\"value\" class=\"login-input\" placeholder=\""+adc[0]+"\">  "
 "                   <input type=\"user\" name=\"USERNAME1\" class=\"login-input\" placeholder=\"نام کاربری\">  "   
 "                   <input type=\"user\" name=\"PASSWORD\" class=\"login-input\" placeholder=\"رمز عبور\">  " 
 "                    <input type='submit' name='SUBMIT' value='ورود' class='login-submit'></form>"
   
 "     "   
 "                     "   
 "     "   
 "               </div>  "   
 "               <div class=\"login_col_rightb\">  "   
 "                       <img src=\"https://cdn.dribbble.com/users/1315300/screenshots/3556675/untitled-1.gif\" alt=\"Flowers in Chania\" style=\"display: block;margin-left: auto;margin-right: auto;width: 100%;\">  "   
 "     "   
 "     "   
 "               </div>  "   
 "           </div>  "   
 "           <h1 style=\"text-align: center\">طراحی و توسعه توسط اسماعیل جلالی و علی عزیزی</h1>  "  
 "           <h2 style=\"text-align: center\">ver : 0.2 - feb 2019</h1>  "   
 "     "   
 "                    "   
 "     "   
 "   </body>  "   
 "  </html>  " ;
 server.send(200,"text/html",Home1);
 
                    }
                                  if (server.hasArg("USERNAME1") && server.hasArg("PASSWORD")){
                                      if (server.arg("USERNAME1") == USERNAME1 &&  server.arg("PASSWORD") == pass ){  
                                              authentified = false;                                 
                                               digitalWrite(led,0);
                                             
                                              
                                      }
                                  }
     
    
    }
    
          

    

void handleNotFound(){
  digitalWrite(13, 1);
  String message = "File Not Foundnn";
  message += "URI: ";
  message += server.uri();
  message += "nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "nArguments: ";
  message += server.args();
  message += "n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(13, 0);
}

void setup(void){
  pinMode(led, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(led, 0);
  adc[0]=10;
  Serial.begin(4800);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
//  delay(5000);
  //value1=value+1;
  //char(valu1);
  
  
}

void serialEvent(){
c++;
d++;
 if(c==1){
      if(d==1440){
         Graph1= Serial.readString();
         Serial.print("Graph1=");         
         Serial.println(Graph1);       
          }
      if(d!=1440){       
        a= Serial.readString();
        Serial.print("sensor1=");
        Serial.println(a);
    }
 }
if(c==2){
      if(d==1441){
         Graph2= Serial.readString();
         Serial.print("Graph2=");         
         Serial.println(Graph2);       
          }  
      if(d!=1441){
        b=Serial.readString();
        Serial.print("sensor2=");
         Serial.println(b);
      }
      c=0;
      d=0;
 }
}
