# Control de Motor basado en Temperatura

Este proyecto consiste en un sistema que controla el encendido y apagado de un motor en función de la temperatura ambiente medida por un sensor de temperatura. El sistema utiliza un Arduino, un LCD, un relé, un motor y un sensor de temperatura.

## Componentes necesarios

- Arduino Uno (u otro modelo compatible)
- LCD (preferiblemente de 16x2)
- Sensor de temperatura (DHT11, DHT22 u otro compatible)
- Relé
- Motor
- Resistencias y cables de conexión

## Instalación y configuración

1. Conecta el sensor de temperatura al pin analógico A0 del Arduino.
2. Conecta el LCD al Arduino según la configuración de pines utilizada en el código.
3. Conecta el relé al pin 12 y el motor al pin 13 del Arduino.
4. Sube el código proporcionado al Arduino utilizando el IDE de Arduino.
5. Asegúrate de tener instaladas las bibliotecas necesarias, como LiquidCrystal.h.

## Uso

- El sistema mostrará la temperatura actual en el LCD y en el puerto serial.
- Si la temperatura medida supera los 36 grados Celsius, el motor se encenderá y se mostrará un mensaje de "TEMP ALTA" en el LCD.
- Si la temperatura es igual o menor a 36 grados Celsius, el motor se apagará y se mostrará un mensaje de "TEMP NORMAL" en el LCD.
- Puedes ajustar el umbral de temperatura modificando el valor en el código según tus necesidades.

### Instrucciones para Adaptar el Proyecto

Para adaptar este proyecto a tus necesidades específicas o configuraciones de hardware particulares, sigue los siguientes pasos:

1. **Selecciona y Configura el Sensor de Temperatura:**
   - Si estás utilizando un sensor de temperatura diferente al DHT11, como el DHT22 o un LM35, asegúrate de ajustar el pin al que está conectado y la forma en que se realiza la lectura de la temperatura en el código. Podrías necesitar utilizar una biblioteca diferente dependiendo del sensor que estés utilizando.

2. **Configura los Pines de Conexión:**
   - Si deseas utilizar pines diferentes en el Arduino para conectar los componentes (sensor de temperatura, LCD, relé y motor), modifica las asignaciones de pines en el código según sea necesario. Asegúrate de cambiar tanto las definiciones de constantes como la configuración en la función `setup()`.

3. **Ajusta el Umbral de Temperatura:**
   - El umbral de temperatura para encender o apagar el motor se establece en 36 grados Celsius en el código proporcionado. Si deseas cambiar este umbral, simplemente modifica el valor en la condición `if (temp > 36)` en la función `loop()`.

4. **Personaliza la Lógica de Control:**
   - Si deseas implementar una lógica de control diferente, como utilizar un control PID o ajustar los tiempos de encendido y apagado del motor en función de la temperatura, modifica la sección del código donde se realiza el control del motor en la función `loop()`.


## Contribuciones

¡Las contribuciones son bienvenidas! Si deseas mejorar este proyecto, por favor, siéntete libre de enviar pull requests o abrir issues para discutir nuevas ideas.

## Licencia

Este proyecto está bajo la Licencia [MIT](LICENSE).
