const char* ssid     = "ssid";
const char* password = "password";
const char *hostname = "ESP32_1";

IPAddress ip(192, 168, 1, 200);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

const IPAddress MQTT_HOST(192, 168, 1, 40);
const int MQTT_PORT = 1883;
const char *MQTT_USER = "student";
const char *MQTT_PASSWORD = "1234";