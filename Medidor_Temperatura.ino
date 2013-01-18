/*
#################################################################################
#Autor: Willian.A.Mayan
#Verso: 0.1
#Descriço: Programa que mede a temperatura com um sensor lrd e imprime o valor 
#na porta serial, este valor e lido por um programa em python "Medidor_Temperatura.py"
#################################################################################
circuito lrd:
pino 1 = 5v
pino 2 = Analogico 1
pino 3 = GND

Documentaço do circuito e fonte de pesquisa:
Exemplo para ligar o LM35 ao Arduino
13/12/2010
http://www.webtronico.com

Conversor Analógico->Digital de 10 bits (1024).

  O valor máximo que pode entrar no A/D é 5V.
  Sendo assim, quando entrar:
  -> 5V o valor lido será 1023
  -> 2.5V o valor lido será 511 ou (1023/2)
  -> 0V o valor lido será 0
  Resumindo, é uma regra de três normal onde:
  5V - 1023
  X  - Y
*/

int pinoSensor = 2; //pino que está ligado o terminal central do LM35 (porta analogica 0)
int valorLido = 0; //valor lido na entrada analogica
float temperatura = 0; //valorLido convertido para temperatura

void setup() {
  Serial.begin(9600); //Inicializa comunicação Serial
  pinMode(2, OUTPUT);
}

void loop() {
  
       valorLido = analogRead(pinoSensor);
       temperatura = (valorLido * 0.00488);  // 5V / 1023 = 0.00488 (precisão do A/D)
       temperatura = temperatura * 100; //Converte milivolts para graus celcius, lembrando que a cada 10mV equivalem a 1 grau celcius
       //Serial.print("Temperatura atual: ");
       Serial.println(temperatura);
       delay(5000); //espera 5 segundos para fazer nova leitura    
}

