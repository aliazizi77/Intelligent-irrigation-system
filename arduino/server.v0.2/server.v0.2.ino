#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "Login.h"


//const char* ssid = "TP-LINK_C3E6FB";
//const char* password = "123456789";

//const char* ssid = "TP-LINK_A25DF7";
//const char* password = "34180012";

const char* ssid= "AndroidAP";
const char* password = "123456789";

//const char* ssid= "ali";
//const char* password = "123456789";

//const char* ssid = "InterNet-SabaNet";
//const char* password = "Saba@2627282930#Net";

String pass   = "ali";
String USERNAME ="ali";
bool   authentified = false;
String a,b,Graph1[7],Graph2[7];
int c=0,d=0,s2,s1,s,humidity1;//humidity1=Humidity1(String)to int

String p, Humidity1, Humidity2;
String Ih,Mh,Th;//Ih=Ideal humidity(off pump),Mh=Min humidity(on pump in night),Th=Threshold humidity(on pump): reed from front end
int ih,mh,th;//ih=Ideal humidity(off pump),mh=Min humidity(on pump in night),th=Threshold humidity(on pump):Ih,Mh,Th=>convert to int
bool state=0,Typeofirrigation=0;//Typeofirrigation abyary auto ormanual
ESP8266WebServer server(80);

const int led = LED_BUILTIN;

void handleRoot() {
  
  //server.send(200, "text/plain", "Hello from esp8266!");
  if(authentified == false){
     server.send(200, "text/html", Login);
      digitalWrite(led, 1);
           }
     //      if (server.hasArg("USERNAME") && server.hasArg("PASSWORD")){
                if (server.arg("USERNAME") == USERNAME &&  server.arg("PASSWORD") == pass ){  
                     // server.send(200,"text/html",Header);
                     authentified = true;
                    digitalWrite(led,1);
                }                                         
               
          
                   if (authentified == true){
                          //     server.send(200, "text/html", Header);
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
"                                           <input type=\"text\" class=\"form-control\" disabled placeholder=\"60\" aria-label=\"Username\" aria-describedby=\"addon-wrapping\">  " 
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
"           data: ["+Graph1[0]+","+Graph1[1]+", "+Graph1[2]+","+Graph1[3]+", "+Graph1[4]+", "+Graph1[5]+", "+Graph1[6]+"],  " 
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
"           data: ["+23+","+30+", "+62+","+45+", "+36+", "+41+", "+39+"],  " 
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

server.send(200,"text/html",Home1);
 
                    }
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
  WiFi.begin(ssid, password);
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
  ih=Ih.toInt();
  mh=Mh.toInt();
  th=Th.toInt();
  humidity1=Humidity1.toInt();
  if(humidity1<mh||humidity1<th||Typeofirrigation==1){
    digitalWrite(13,1);
    }
  if(humidity1>ih||Typeofirrigation==0){
    digitalWrite(13,0);
    }
  
}

void serialEvent(){
  p=Serial.readString();
if(p=="sensor")
  s=1;  
if(p=="Graph") 
   s=2;
if(s==1){   
     s1++;
     if(s1==1){        
         Humidity1= Serial.readString();   
       }

      if(s1==2){        
         Humidity2= Serial.readString(); 
         s=0;  
         s1=0;
       }
       }
if(s==2){
  s2++;
    switch(s2){
       case 1:
        Graph1[0]= Serial.readString();
        break;       
       case 2:
        Graph1[1]=Serial.readString();
        break;
       case 3:
        Graph1[2]= Serial.readString();       
        break;
       case 4:
        Graph1[3]=Serial.readString();
        break;
       case 5:
         Graph1[4]= Serial.readString();       
         break;
       case 6:
         Graph1[5]=Serial.readString();
         break;
       case 7:
         Graph1[6]= Serial.readString();       
         break;
       case 8:
        Graph2[0]=Serial.readString();
        break;
       case 9:
        Graph2[1]=Serial.readString();
        break;
       case 10:  
        Graph2[2]=Serial.readString();
        break;
       case 11:
        Graph2[3]=Serial.readString();
        break;
       case 12:
        Graph2[4]=Serial.readString();
        break;
       case 13:
        Graph2[5]=Serial.readString();
        break;
       case 14:
        Graph2[6]=Serial.readString();
        s2=0;
        break;
   }
   
}
}
