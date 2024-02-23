#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 10, 9, 8, 7, 6); // Inicialización del objeto LCD

const int tempPin = A0; // Pin analógico para el sensor de temperatura
const int relePin = 12; // Pin para controlar el relé
const int motorPin = 13; // Pin para controlar el motor

void setup() {
  lcd.begin(16, 2); // Inicialización del LCD (16 columnas, 2 filas)
  Serial.begin (9600); // Inicialización del puerto serial para depuración
  pinMode(tempPin, INPUT); // Configuración del pin del sensor de temperatura como entrada
  pinMode(relePin, OUTPUT); // Configuración del pin del relé como salida
  pinMode(motorPin, OUTPUT); // Configuración del pin del motor como salida
}

void loop() {
  // Lectura de la temperatura desde el sensor
  int val = analogRead(tempPin); // Lectura del valor analógico del sensor
  float mv = (val / 1024.0) * 5000.0; // Conversión del valor a milivoltios
  float temp = mv / 10; // Conversión de milivoltios a grados Celsius

  // Mostrar la temperatura en el LCD y en el puerto serial
  lcd.clear(); // Borrar el contenido anterior en el LCD
  lcd.setCursor(0, 0); // Establecer el cursor en la primera fila, primera columna
  lcd.print("Temp C: "); // Mostrar etiqueta de temperatura en el LCD
  lcd.print(temp); // Mostrar el valor de temperatura en el LCD
  Serial.print ("Temperatura = "); // Imprimir etiqueta de temperatura en el puerto serial
  Serial.println(temp); // Imprimir el valor de temperatura en el puerto serial

  // Verificar si la temperatura supera un umbral
  if (temp > 36) { // Si la temperatura es mayor que 36 grados Celsius
    // Encender el motor
    digitalWrite(relePin, HIGH); // Encender el relé
    digitalWrite(motorPin, HIGH); // Encender el motor
    lcd.setCursor(0, 1); // Establecer el cursor en la segunda fila, primera columna
    lcd.print("TEMP ALTA"); // Mostrar mensaje de temperatura alta en el LCD
  } else {
    // Apagar el motor
    digitalWrite(relePin, LOW); // Apagar el relé
    digitalWrite(motorPin, LOW); // Apagar el motor
    lcd.setCursor(0, 1); // Establecer el cursor en la segunda fila, primera columna
    lcd.print("TEMP NORMAL"); // Mostrar mensaje de temperatura normal en el LCD
  }

  delay(1000); // Esperar un segundo antes de la siguiente lectura
}
