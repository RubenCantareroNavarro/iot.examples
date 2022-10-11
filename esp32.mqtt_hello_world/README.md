# Hello world con ESP32 y mqtt (AsyncMqttClient)

Este ejemplo está preparado para ser cargado y ejecutado en una placa ESP32. Consiste en subcribirse al canal `hello/wolrd` y publicar cada segundo el resultado de la operación `millis()`. 

Al estar subscrito al canal donde publica, recibirá también el evento (el cual será mostrado por el terminal serie).


## Requisitos
- Definir los requisitos en el fichero config.h con tu configuración.
- Tener un broker mqtt ejecutando y con un `MQTT_USER`/`MQTT_PWD` configurado. Además, es necesario conocer la ip  y el puerto del broker (`BROKER_IP`/`BROKER_PORT`).
- En función de la placa ESP32 empleada, puede ser necesario configurar el entorno de compilación en el archivo `platform.ini`

# Dependencias
- mosquitto (deb)


## Pruebas
Es posible probar con un subscriptor mediante `mosquitto_sub`:
```
mosquitto_sub -d -h BROKER_IP -p BROKER_PORT -t TOPIC -u MQTT_USER -P MQTT_PWD
```

Ejemplo:
```
mosquitto_sub -d -h 192.168.1.40 -p 1883 -t "hello/world" -u student -P 1234
```