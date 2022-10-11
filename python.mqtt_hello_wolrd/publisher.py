#!/usr/bin/python3
# -*- coding: utf-8; mode: python -*-

import json
import time
import random
import paho.mqtt.client as mqtt
import mqtt_config as cfg

IDENTIFIER = 'sensor01'


def take_reading():
    return {
        'identifier': IDENTIFIER,
        'value': random.randint(20, 40),
        'unit': 'Celsius',
        'timestamp': time.time()
    }


def main():
    publisher = mqtt.Client(client_id='test_publisher', clean_session=False)
    publisher.username_pw_set(
        cfg.mqtt_credentials["user"], cfg.mqtt_credentials["pwd"])
    publisher.connect(
        host=cfg.mqtt_broker["host"], port=cfg.mqtt_broker["port"])

    while 1:
        read = take_reading()
        print("Publishing read: {}".format(read))

        publisher.publish(
            'temperature/{}'.format(IDENTIFIER),
            json.dumps(read)
        )

        time.sleep(2)


if __name__ == '__main__':
    main()

sys.exit(0)
