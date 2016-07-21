# Fermentador

Projeto de um fermentador de cerveja artesanal usando um Arduino.

## Estrutura

## Controle de temperatura

Feito utilizando:
* Arduino
* Sensor de temperatura (ds18b20)
* Relé para controlar o estado da placa peltier
* Um visor de LCD com botões para controlar o target e exibir a temperatura atual

### Dados do visor de LCD

* Dimensões: 16x2

Botões
* Idle: 997
* Select: 620
* Left: 398
* Up: 97
* Down: 249
* Right: 0

### DS18B20

Lendo o sensor utilizando duas bibliotecas:

* [Dallas Temperatura](http://www.hacktronics.com/code/DallasTemperature.zip)
* [OneWire](http://www.pjrc.com/teensy/arduino_libraries/OneWire.zip)