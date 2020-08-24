#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "Login.h"


//const char* ssid = "TP-LINK_C3E6FB";
//const char* password = "123456789";

//const char* ssid = "TP-LINK_A25DF7";
//const char* password = "34180012";

//const char* ssid= "AndroidAP";
//const char* password = "123456789";


//Static IP address configuration
IPAddress staticIP(192, 168, 1,82); //ESP static ip
IPAddress gateway(192, 168, 1,1 );   //IP Address of your WiFi Router (Gateway)
IPAddress subnet(255, 255, 255, 0);  //Subnet mask
IPAddress dns(8, 8, 8, 8);  //DNS

const int AirValue = 825; //you need to replace this value with Value_1
const int WaterValue = 400; //you need to replace this value with Value_2
int intervals = (AirValue - WaterValue)/3,i=0;
int soilMoistureValue = 0,value1=0;
String value;


//const char* ssid= "D-Link";
//const char* password = "123456789";


//const char* ssid= "ali";
//const char* password = "123456789";

//const char* ssid= "esmaeil";
//const char* password = "esmaeiljalali76@gmail";

//const char* ssid = "InterNet-SabaNet";
//const char* password = "Saba@2627282930#Net";
//String ssid ="aa";
//String password="bb";
String ssid,password;
String pass   = "ali";
String USERNAME ="ali";
bool   authentified = false;

bool state=0,Typeofirrigation=0;//Typeofirrigation abyary auto ormanual
ESP8266WebServer server(80);

const int led = LED_BUILTIN;

         

void handleRoot() {


  
 if(authentified==false){
     server.send(200, "text/html", Login);
     delay(50);
    //  digitalWrite(led, 1);
           }  
                  // while(authentified == false){
       // if (server.hasArg("USERNAME") && server.hasArg("PASSWORD"))
    /*    
      while(server.arg("PASSWORD") !=pass)
      {
       delay(200);
        }
          */
   /* delay(500);
    state=!state;
    digitalWrite(led,state);
          */
      //   }
     while(authentified==false){
                if (server.arg("USERNAME") == USERNAME &&  server.arg("PASSWORD") == pass ){  
                     // server.send(200,"text/html",Header);
                     authentified = true;
                    digitalWrite(led,1);
                    delay(20);
                }
                delay(30);                              
        }
           

String Home1=
                           
"   <!doctype html>  " 
"   <html dir=\"rtl\" lang=\"fa\">  " 
"     <head>  " 
"       <!-- Required meta tags -->  " 
"       <meta charset=\"utf-8\">  " 
"       <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">  " 
"     " 
"       <!-- Font Awesome -->  " 
"   <link rel=\"stylesheet\" href=\"https://use.fontawesome.com/releases/v5.8.2/css/all.css\">  " 
"   <!-- Bootstrap core CSS -->  " 
"   <link href=\"https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.3.1/css/bootstrap.min.css\" rel=\"stylesheet\">  " 
"   <!-- Material Design Bootstrap -->  " 
"   <link href=\"https://cdnjs.cloudflare.com/ajax/libs/mdbootstrap/4.8.7/css/mdb.min.css\" rel=\"stylesheet\">  " 
"       <!-- Bootstrap CSS -->  " 
"       <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css\" integrity=\"sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T\" crossorigin=\"anonymous\">  " 
"       <script type=\"text/javascript\">  " 
"         function autoRefresh(t)  " 
"         {  " 
"           setTimeout('location.reload(true)', t);  " 
"         }  " 
"       </script>  " 
"       <style>  " 
"       .card  " 
"       {  " 
"         margin-bottom: 10px !important;  " 
"       }  " 
"       </style>  " 
"       <title>سیستم آبیاری هوشمند</title>  " 
"     </head>  " 
"     <body onload=\"autoRefresh(120000);\">  " 
"         <!--start top menu-->  " 
"           " 
"         <nav class=\"navbar navbar-expand-lg navbar-light bg-light\">  " 
"               <a class=\"navbar-brand\" href=\"#\">سیستم آبیاری هوشمند</a>  " 
"               <button class=\"navbar-toggler\" type=\"button\" data-toggle=\"collapse\" data-target=\"#navbarNavAltMarkup\" aria-controls=\"navbarNavAltMarkup\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">  " 
"                 <span class=\"navbar-toggler-icon\"></span>  " 
"               </button>  " 
"               <div class=\"collapse navbar-collapse\" id=\"navbarNavAltMarkup\">  " 
"                 <div class=\"navbar-nav\">  " 
"                   <a class=\"nav-item nav-link active\" href=\"#\">داشبورد <span class=\"sr-only\">(current)</span></a>  " 
"                   <a class=\"nav-item nav-link\" href=\"#\">تنظیمات</a>  " 






 

"                   <a class=\"nav-item nav-link\" href=\"#\">درباره ما</a>  "
 
"                   <a class=\"nav-item nav-link disabled\" href=\"#\" tabindex=\"-1\" aria-disabled=\"true\">خرید</a>  " 
"                 </div>  " 
"               </div>  " 
"             </nav>  " 
"             <div id=\"header\"></div>  " 
"             <!--END top menu-->  " 
"           <div class=\"container\">  " 
"     " 
"                   " 
"                   <!-- Columns start at 50% wide on mobile and bump up to 33.3% wide on desktop -->  " 
"                   <div class=\"row\" style=\"margin-bottom: 20px;margin-top: 20px;\">  " 
"                     <div class=\"col-12 col-md-4\">  " 
"                           <div class=\"card\">  " 
"                                   <h5 class=\"card-header\" style=\"text-align: right;\">میزان دما</h5>  " 
"                                   <div class=\"card-body\">  " 
"                                       <div class=\"input-group flex-nowrap\" style=\"direction: ltr;\">  " 
"                                           <div class=\"input-group-prepend\">  " 
"                                             <span class=\"input-group-text\" id=\"addon-wrapping\">سیلیسیوس</span>  " 
"                                           </div>  " 
"                                           <input type=\"text\" class=\"form-control\"  disabled placeholder=\"28\" aria-label=\"Username\" aria-describedby=\"addon-wrapping\">  " 
"                                         </div>  " 
"                                   </div>  " 
"                                 </div>  " 
"                     </div>  " 
"                     <div class=\"col-12 col-md-4\">  " 
"                           <div class=\"card\">  " 
"                                   <h5 class=\"card-header\" style=\"text-align: right;\">میزان رطوبت</h5>  " 
"                                   <div class=\"card-body\">  " 
"                                       <div class=\"input-group flex-nowrap\" style=\"direction: ltr;\">  " 
"                                           <div class=\"input-group-prepend\">  " 
"                                             <span class=\"input-group-text\" id=\"addon-wrapping\">درصد</span>  " 
"                                           </div>  " 
"                                           <input type=\"text\" class=\"form-control\" disabled placeholder=\""+value+"\" aria-label=\"Username\" aria-describedby=\"addon-wrapping\">  " 
"                                         </div>                                    </div>  " 
"                                 </div>  " 
"                     </div>  " 
"                     <div class=\"col-12 col-md-4\">  " 
"                           <div class=\"card\">  " 
"                                   <h5 class=\"card-header\" style=\"text-align: right;\">وضعیت پمپ</h5>  " 
"                                   <div class=\"card-body\" style=\"text-align: center\">  " 
"                                       <h2><span class=\"badge badge-success\">فعال</span>/<span class=\"badge badge-danger\">غیر فعال</span></h2>  " 
"                                   </div>  " 
"                                 </div>  " 
"     " 
"                     </div>  " 
"                   </div>  " 
"                   " 
"                   <!-- Columns are always 50% wide, on mobile and desktop -->  " 
"                   <div class=\"row\">  " 
"                     <div class=\"col-12 col-md-6\">  " 
"                           <div class=\"card\">  " 
"                                   <h5 class=\"card-header\" style=\"text-align: right;\">نمودار رطوبت</h5>  " 
"                                   <div class=\"card-body\">  " 
"                                           <canvas id=\"myChart\" style=\"max-width: 500px;\"></canvas>  " 
"                                   </div>  " 
"                                 </div>  " 
"                     </div>  " 
"                     <div class=\"col-12 col-md-6\">  " 
"                           <div class=\"card\">  " 
"                                   <h5 class=\"card-header\" style=\"text-align: right;\">نمودار دما</h5>  " 
"                                   <div class=\"card-body\">  " 
"                                       <canvas id=\"lineChart\"></canvas>  " 
"                                   </div>  " 
"                                 </div>  " 
"                       </div>  " 
"                   </div>  " 
"                 </div>  " 
"     " 
"       <!-- Optional JavaScript -->  " 
"       <!-- jQuery first, then Popper.js, then Bootstrap JS -->  " 
"       <!-- JQuery -->  " 
"   <script type=\"text/javascript\" src=\"https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js\"></script>  " 
"   <!-- Bootstrap tooltips -->  " 
"   <script type=\"text/javascript\" src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.4/umd/popper.min.js\"></script>  " 
"   <!-- Bootstrap core JavaScript -->  " 
"   <script type=\"text/javascript\" src=\"https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.3.1/js/bootstrap.min.js\"></script>  " 
"   <!-- MDB core JavaScript -->  " 
"   <script type=\"text/javascript\" src=\"https://cdnjs.cloudflare.com/ajax/libs/mdbootstrap/4.8.7/js/mdb.min.js\"></script>  " 
"       <script>  " 
"       //line  " 
"   var ctxL = document.getElementById(\"lineChart\").getContext('2d');  " 
"   var myLineChart = new Chart(ctxL, {  " 
"     type:\"line\",  " 
"     data: {  " 
"       labels: [\"شنبه\", \"یکشنبه\", \"دوشنبه\", \"سه شنبه\", \"چهارشنبه\", \"پنج شنبه\", \"جمعه\"],"
"       datasets: [{  " 
"           label: \"My First dataset\",  " 
"           data: [\"+10\",\"+20+\", \"30+\",\"+40+\", \"+50+\", \"+60+\", \"+70+\"],  " 
"           backgroundColor: [  " 
"           \" rgba(105, 0, 132, .2)\",  " 
"           ],  " 
"           borderColor: [  " 
"            \"rgba(200, 99, 132, .7)\",  " 
"           ],  " 
"           borderWidth: 2  " 
"         },  " 
"         {  " 
"           label: \"My Second dataset\" , " 
"           data: [\"+23+\",\"+30+\", \"+62+\",\"+45+\", \"+36+\", \"+41+\", \"+39+\"],  " 
"           backgroundColor: [  " 
"            \"rgba(105, 0, 132, .2)\",  " 
"           ],  " 
"           borderColor: [  " 
"            \"rgba(200, 99, 132, .7)\",  " 
"           ],  " 
"           borderWidth: 2  " 
"         }  " 
"       ]  " 
"     },  " 
"     options: {  " 
"       responsive: true  " 
"     }  " 
"   });  " 
"     " 
"         " 
"         " 
"       var ctx = document.getElementById(\"myChart\").getContext('2d');  " 
"           var myChart = new Chart(ctx, {  " 
"             type:\"bar\",  " 
"             data: {  " 
"                   labels: [\"شنبه\", \"یکشنبه\", \"دوشنبه\", \"سه شنبه\", \"چهارشنبه\", \"پنج شنبه\", \"جمعه\"],  " 
"               datasets: [{  " 
"                 label:\'# of Votes\',  " 
"                 data: [12, 19, 3, 5, 2, 3],  " 
"                 backgroundColor: [  " 
"                  \'rgba(255, 99, 132, 0.2)\',  " 
"                  \'rgba(54, 162, 235, 0.2)\',  " 
"                  \'rgba(255, 206, 86, 0.2)\',  " 
"                  \'rgba(75, 192, 192, 0.2)\',  " 
"                  \'rgba(153, 102, 255, 0.2)\',  " 
"                  \'rgba(255, 159, 64, 0.2)\'  " 
"                 ],  " 
"                 borderColor: [  " 
"                  \'rgba(255,99,132,1)\',  " 
"                  \'rgba(54, 162, 235, 1)\',  " 
"                  \'rgba(255, 206, 86, 1)\',  " 
"                  \'rgba(75, 192, 192, 1)\',  " 
"                  \'rgba(153, 102, 255, 1)\',  " 
"                  \'rgba(255, 159, 64, 1)\'  " 
"                 ],  " 
"                 borderWidth: 1  " 
"               }]  " 
"             },  " 
"             options: {  " 
"               scales: {  " 
"                 yAxes: [{  " 
"                   ticks: {  " 
"                     beginAtZero: true  " 
"                   }  " 
"                 }]  " 
"               }  " 
"             }  " 
"           });</script>  " 
"               <script src=\"https://code.jquery.com/jquery-3.3.1.slim.min.js\" integrity=\"sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo\" crossorigin=\"anonymous\"></script>  " 
"               <script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js\" integrity=\"sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1\" crossorigin=\"anonymous\"></script>  " 
"               <script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js\" integrity=\"sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM\" crossorigin=\"anonymous\"></script>  " 
"               <script>$(function () {$(\"#header\").load(\"_header.html\");$(\"#footer\").load(\"_footer.html\");});</script>  " 
"     " 
"     </body>  " 
"  </html> " ; 

  
  //server.send(200, "text/plain", "Hello from esp8266!");
  
           
digitalWrite(led,0);
           
        
                  
                          //     server.send(200, "text/html", Header);
if(authentified == true)
           server.send(200,"text/html",Home1);
                          
}
     
    
          

    

void handleNotFound(){
  
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
  
}
           
void setup(void){
  pinMode(led, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(9600);
  
  Serial.print("ssid:");
while(Serial.available()==0){}
  if(Serial.available()>0){
ssid=Serial.readString();
i=ssid.length();
ssid.remove(i-1);
i=0;
Serial.println(ssid);

  }
  Serial.print("password:");
  while(Serial.available()==0){}
  if(Serial.available()>0){
password=Serial.readString();
i=password.length();
password.remove(i-1);
Serial.println(password);
  }
  Serial.print(ssid);
  
  Serial.print(password);
  
  WiFi.begin(ssid, password);
  //
  
  // WiFi.disconnect();

    // WiFi.begin(ssid, password);
  WiFi.config(staticIP, subnet, gateway, dns);

   WiFi.mode(WIFI_STA);
   //
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    state=!state;
    Serial.print(".");
    digitalWrite(led,state);

  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

       
/*if(authentified==false){
     server.send(200, "text/html", Login);
     delay(10);
      digitalWrite(led, 1);
           }    
    
                    while(authentified == false){
       // if (server.hasArg("USERNAME") && server.hasArg("PASSWORD"))
                if (server.arg("USERNAME") == USERNAME &&  server.arg("PASSWORD") == pass ){  
                     // server.send(200,"text/html",Header);
                     authentified = true;
                    digitalWrite(led,1);
                }                            
           }*/
  server.on("/", handleRoot);

  server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
/////
soilMoistureValue = analogRead(A0); //put Sensor insert into soil
value1=soilMoistureValue;
delay(50);
value1-=827;
delay(50);
value1/=(-4.25);
Serial.print("A0:");
 Serial.println(soilMoistureValue);
Serial.print("String A0:");
 Serial.println(value1); 
 value=value1;
if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals))
{
 Serial.println("Very Wet");
}
else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
{
 Serial.println("Wet");
}
else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
{
 Serial.println("Dry");
}
delay(10000);


 ///// 
  server.handleClient();
    }
  
