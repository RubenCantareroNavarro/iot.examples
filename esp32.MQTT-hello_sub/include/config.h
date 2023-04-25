// const char* ssid     = "ssid";
// const char* password = "password";
// const char *ssid = "Titi-network-movil";
const char *ssid = "Iot-ruben";
const char *password = "RuAn1234";
const char *hostname = "ESP32_2";

IPAddress ip(192, 168, 33, 69);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

const IPAddress MQTT_HOST(10, 42, 0, 1);
const int MQTT_PORT = 1883;
const char *MQTT_USER = "student";
const char *MQTT_PASSWORD = "1234";
const char *MQTT_TOPIC = "esp32/test";

bool buzzer_state = false;