/* Programa: Trena Digital */
/* Inclui a biblioteca do sensor. */
#include <Ultrasonic.h>
/* Define os pinos para o sensor. */
int pino_Trig = 13;
int pino_Echo = 12;
/* Especifica o nome e os pinos para o sensor. */
Ultrasonic Sensor(pino_Trig, pino_Echo);
/* Inclui a biblioteca de controle do LCD; */
#include <LiquidCrystal.h>
/* Define os pinos que serão utilizados para ligação ao
display; */
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
/* Variável que armazenará as medidas. */
int distancia;
void setup() {
/* Define o número de colunas e linhas do LCD; */
lcd.begin(16, 2);
}
void loop() {
/* Realiza a medição e armazena na variável “distancia” */
distancia = Sensor.read();
/* Posiciona o cursor na coluna 4, linha 0; */
lcd.setCursor(1, 0);
/*Envia o texto entre aspas para o LCD; */
lcd.print("Trena Digital");
/* Posiciona o cursor na coluna 5, linha 1; */
lcd.setCursor(2, 1);
/* Envia o texto entre aspas para o LCD; */
lcd.print("Medida: ");
/* Posiciona o cursor na coluna 5, linha 1; */
lcd.setCursor(9, 1);
/* Envia o texto entre aspas para o LCD; */
lcd.print(distancia);
/* Posiciona o cursor na coluna 5, linha 1; */
lcd.setCursor(12, 1);
/* Envia o texto entre aspas para o LCD; */
lcd.print("cm");
delay(500);
lcd.clear();
}