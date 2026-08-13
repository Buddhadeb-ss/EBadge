// File: webportal.cpp
#include "webportal.h"
#include <WiFi.h>
#include <WebServer.h>
#include "storage.h"

WebServer server(80);
bool configActive = true;
unsigned long configStartTime = 0;
const unsigned long CONFIG_TIMEOUT_MS = 60000;

String escapeHTML(String s) {
  s.replace("&", "&amp;");
  s.replace("<", "&lt;");
  s.replace(">", "&gt;");
  s.replace("\"", "&quot;");
  return s;
}

void handleRoot() {
  String name = escapeHTML(loadName());
  String dept = escapeHTML(loadDept());

  String html = "<html><body>"
    "<h2>Badge Config</h2>"
    "<form action='/save' method='POST'>"
    "Name: <input name='name' maxlength='18' value='" + name + "'><br>"
    "Dept: <input name='dept' maxlength='18' value='" + dept + "'><br>"
    "<input type='submit' value='Save'>"
    "</form></body></html>";
  server.send(200, "text/html", html);
}

void handleSave() {
  if (server.hasArg("name")) {
    String n = server.arg("name");
    if (n.length() > 18) n = n.substring(0, 18);
    saveName(n);
  }
  if (server.hasArg("dept")) {
    String d = server.arg("dept");
    if (d.length() > 18) d = d.substring(0, 18);
    saveDept(d);
  }
  server.send(200, "text/html", "<html><body>Saved. Starting badge...</body></html>");
  configActive = false;
}

void webInit() {
  WiFi.mode(WIFI_AP);
  WiFi.setTxPower(WIFI_POWER_8_5dBm);
  bool apStarted = WiFi.softAP("eBadge-Setup", "12345678");
  Serial.println(apStarted ? "AP start: SUCCESS" : "AP start: FAILED");
  Serial.println("Config window open. AP IP: " + WiFi.softAPIP().toString());

  server.on("/", HTTP_GET, handleRoot);
  server.on("/save", HTTP_POST, handleSave);
  server.begin();
  configStartTime = millis();
}

void webHandle() {
  if (!configActive) return;
  server.handleClient();
  if (millis() - configStartTime > CONFIG_TIMEOUT_MS) {
    Serial.println("Config window timed out.");
    configActive = false;
  }
}

void webShutdown() {
  server.stop();
  WiFi.softAPdisconnect(true);
  WiFi.mode(WIFI_OFF);
  Serial.println("Radio off. Config phase complete.");
}

bool isConfigActive() { return configActive; }