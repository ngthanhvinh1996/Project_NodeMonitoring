#include <MQ135.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include <SPI.h>
#include <LoRa.h>


#define LORA_FREQ 433E6
#define LORA_SF 12
#define LORA_CR 4
#define LORA_BW 125E3
#define LORA_PREAMBLE_LENGTH 8

#define BAUD_RATE 115200

#define LIGHT 2

#define DHTPIN 4
#define DHTTYPE DHT22

#define SRPIN 3

#define PIN_MQ135 A0
