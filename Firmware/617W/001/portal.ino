



class CaptiveRequestHandler : public AsyncWebHandler {
public:
  CaptiveRequestHandler() {}
  virtual ~CaptiveRequestHandler() {}

  bool canHandle(AsyncWebServerRequest *request){
    request->addInterestingHeader("ANY");
    Serial.println("request");
    return true;
  }

  void handleRequest(AsyncWebServerRequest *request) {
    AsyncResponseStream *response = request->beginResponseStream("text/html");
    response->print("<!DOCTYPE html><html><head><title>Captive Portal</title></head><body>");
    response->print("<p>This is out captive portal front page.</p>");
    response->printf("<p>You were trying to reach: http://%s%s</p>", request->host().c_str(), request->url().c_str());
    response->printf("<p>Try opening <a href='http://%s'>this link</a> instead</p>", WiFi.softAPIP().toString().c_str());
    response->print("</body></html>");
    request->send(response);
  }
};


//*********************************************************
void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

void portal(){
  //your other setup stuff...
  //Serial.print("Setting soft-AP configuration ... ");
 // Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

  //Serial.print("Setting soft-AP ... ");
 // Serial.println(WiFi.softAP("ESPsoftAP_01") ? "Ready" : "Failed!");

  Serial.print("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());
  //dnsServer.start(53, "*", WiFi.softAPIP());
  /*
  server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);//only when requested from AP
  
  server.on("/rand", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", String(random(1000)));
  });
 
    server.onNotFound(notFound);
  
  //more handlers...
  server.begin();
  
  while(1==1){
    //dnsServer.processNextRequest();
    yield();
  }
  */
}
