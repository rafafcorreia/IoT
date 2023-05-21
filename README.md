# Prótipo de Projeto IoT - Detecção de incêndio a partir de paredes compartilhadas

## Funcionamento
O projeto tem como objetivo medir a temperatura de uma parede compartilhada com outra residência e enviar esses dados constantemente para um dashboard na plataforma Adafruit IO na Web, via protocolo MQTT, alimentando um gráfico de linha com o histórico de temperaturas no decorrer do tempo. Além disso, está presente um buzzer para sinalizar sonoramente caso a temperatura medida seja maior que 60ºC, permitindo uma percepção mais acelerada de um potêncial incêndio e, consequentemente, tomando as ações necessárias para o controle da situação com maior rapidez.

## Recursos utilizados
### Hardware
- Plataforma NodeMCU ESP8266
- Sensor de Temperatura Infravermelho MLX90614
- Módulo Buzzer Ativo P19
- Breadboard
- Jumpers Macho-macho
- Jumpers Macho-fêmea
- Cabo Micro USB

### Software
- Arduino IDE
- Bibliotecas no Arduino IDE:
- 1. Adafruit IO Arduino
- 2. Adafruit MLX90614
- 3. Adafruit MQTT Library
- 4. ArduinoHTTPClient

## Instruções para uso
1. Crie, caso ainda não possua, uma conta na plataforma Adafruit IO (https://io.adafruit.com/)
2. Navegue para a seção "Dashboards" e clique em "New dashboard"
3. Coloque um nome de sua escolha e uma descrição caso deseje
4. Selecione o dashboard na lista e clique no ícone de configurações, indicado por uma pequena engrenagem na parte superior direita
5. Clique em "Create New Block"
6. Selecione a opção "Line chart"
7. Digite um nome para esse novo feed que representa o gráfico no campo "Enter new feed name" e selecione o botão "Create" ao lado. Caso escolha um nome diferente de "Celsius", será necessário alterar o parâmetro na linha 9 do arquivo "IoT_Sensor_Temp.ino" para o nome escolhido.
8. Selecione esse novo feed na lista e clique em "Next Step"
9. Clique em "Create block"
10. Selecione o ícone de chave na parte superior direita, ao lado do botão "New Device"
11. No arquivo config.h, substitua os asteriscos do IO_USERNAME e IO_KEY pelos respectivos valores "Username" e "Active Key" gerados pelo Adafruit IO
12. Ainda no arquivo config.h, substitua os asteriscos dos campos "WIFI_SSID" e "WIFI_PASS" respectivamente pelo nome e senha da sua rede Wi-Fi
13. Para conectar o ESP8266 no computador, no Arduino IDE, selecione a board "NodeMCU 0.9 (ESP-12 Module)" e a porta disponibilizada com a conexão via micro USB
14. Em seguida, selecione a opção "Verify" para compilar o projeto e verificar se há algum erro e, por fim, clique em "Upload" para salvar a programação no ESP8266
