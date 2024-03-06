#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include "data.h"

void format_mac_Address(const uint8_t *macAddr, char *mac_str)
{
  snprintf(mac_str, 18, "%02x:%02x:%02x:%02x:%02x:%02x", macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);
}

uint8_t get_msg_type(const uint8_t *incoming_data)
{
  return incoming_data[0];
}

void OnDataRecv(const uint8_t *mac, const uint8_t *incoming_data, int len)
{
  MessageA *msgA;
  MessageB *msgB;
  char mac_str[18];

  format_mac_Address(mac, mac_str);
  uint8_t msg_type = get_msg_type(incoming_data);

  switch (msg_type)
  {
  case MESSAGE_TYPE_A:
    printf("Message A received from %s\n", mac_str);

    // Here it is a good idea to send the data for more processing to a queue and then process it in another task
    msgA = (MessageA *)incoming_data;
    printf("Data: %s and %d\n", msgA->a, msgA->b);

    break;
  case MESSAGE_TYPE_B:
    printf("Message B received from %s\n", mac_str);

    // Here it is a good idea to send the data for more processing to a queue and then process it in another task
    msgB = (MessageB *)incoming_data;
    printf("Data: %f and %d\n", msgB->c, msgB->d);

    break;
  default:
    printf("Message type not recognized from %s\n", mac_str);
    break;
  }
}

void setup()
{
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK)
  {
    printf("Error initializing ESP-NOW\n");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);

  printf("ESP-NOW initialized. Waiting for messages... \n");
}

void loop()
{
}