#!/usr/bin/python3
# -*- coding: utf-8; mode: python -*-

# import ssl
import sys
import json
import paho.mqtt.client as mqtt
import mqtt_config as cfg


TOPIC = 'temperature/+'


def on_connect(client, userdata, flags, rc):
    print('connected ({})'.format(client._client_id))
    client.subscribe(topic=TOPIC, qos=2)


def on_message(client, userdata, message):
    print('------------------------------')
    decoded = json.loads(message.payload.decode())
    print("topic: {}, msg: {}".format(
        message.topic, decoded))

    print(decoded["value"])


def main():
    subscriber = mqtt.Client(client_id='test_subscriber', clean_session=False)
    subscriber.on_connect = on_connect
    subscriber.on_message = on_message
    subscriber.username_pw_set(
        cfg.mqtt_credentials["user"], cfg.mqtt_credentials["pwd"])
    subscriber.connect(
        host=cfg.mqtt_broker["host"], port=cfg.mqtt_broker["port"])
    subscriber.loop_forever()


if __name__ == '__main__':
    main()

sys.exit(0)
