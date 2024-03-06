#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include "data.h"

esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status)
{
  printf("\r\nLast Packet Send Status:\t");
  printf(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup()
{
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK)
  {
    printf("Error initializing ESP-NOW\n");
    return;
  }

  esp_now_register_send_cb(OnDataSent);

  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK)
  {
    printf("Failed to add peer\n");
    return;
  }
}

void loop()
{
  MessageA msgA;
  strcpy(msgA.a, "THIS IS A CHAR");
  msgA.b = random(1, 20);

  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *)&msgA, sizeof(msgA));
  if (result == ESP_OK)
  {
    printf("Sent (mgA) with success: %s and %d\n", msgA.a, msgA.b);
  }
  else
  {
    printf("Error sending (mgA)\n");
  }

  delay(1000);

  MessageB msgB;
  msgB.c = random(1, 20) + 0.5;
  msgB.d = random(0, 2);

  result = esp_now_send(broadcastAddress, (uint8_t *)&msgB, sizeof(msgB));
  if (result == ESP_OK)
  {
    printf("Sent (mgB) with success: %f and %d\n", msgB.c, msgB.d);
  }
  else
  {
    printf("Error sending (mgB)\n");
  }

  delay(1000);
}