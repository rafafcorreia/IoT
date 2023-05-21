#include "config.h"
#include <Adafruit_MLX90614.h>

#define pinBuzzer 0
#define tempoAtualizacao 500

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

AdafruitIO_Feed *celsius = io.feed("Celsius");

void configuraMQTT();

unsigned long controleTempo = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };

  Serial.print("Emissivity = "); Serial.println(mlx.readEmissivity());
  Serial.println("================================================");

  pinMode(pinBuzzer, OUTPUT);

  Serial.println("Adafruit MLX90614 test");

  configuraMQTT();

  Serial.println("Fim Setup");
}

void loop() {
  io.run();

  if (millis() > controleTempo + tempoAtualizacao) {
    Serial.print("Ambiente = "); Serial.print(mlx.readAmbientTempC());
    Serial.print("*C\tObjeto = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
    Serial.print("Ambiente = "); Serial.print(mlx.readAmbientTempF());
    Serial.print("*F\tObjeto = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

    
    if(mlx.readObjectTempC() > 60) {
      digitalWrite(pinBuzzer, HIGH);
    } else {
      digitalWrite(pinBuzzer, LOW);
    }

    celsius->save(mlx.readObjectTempC());

    Serial.println();
    delay(500);

    controleTempo = millis();
  }
  
}

void configuraMQTT() {
  Serial.print("Conectando ao Adafruit IO");
  io.connect();

  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println(io.statusText());
}
