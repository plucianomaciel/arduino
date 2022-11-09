#include <Ultrasonic.h> /*Inclui a biblioteca do sensor HC SR04.*/
#define TRIGGER   9 /*Define os pinos do Arduino D8 e D9 como porta do ECHO e TRIGGER.*/
#define ECHO      8
Ultrasonic Sensor(TRIGGER, ECHO); /*Inicializa o sensor usando os pinos TRIGGER and ECHO.*/
#include <LiquidCrystal.h>  /*Inclui a biblioteca do //Configuracoes LCD 16x2  display LCD*///Configuracoes LCD 16x2  
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); /* Define o objeto "lcd" para controlar o LCD nos pinos. 2 à 7 do Arduino.*/
int distancia;
byte smile[8] = {B00000,B00000,B01010,B01010,B00000,B10001,B01110,B00000};
int screenWidth = 16;  //Configuracoes LCD 16x2  
int screenHeight = 2;  //Configuracoes LCD 16x2  

String line1 = "Colegio Estadual Alberto Santos Dumont"; 

int stringStart, stringStop = 0;  
int scrollCursor = screenWidth;  
int tamanho =0;  
   

void setup () {
    Serial.begin(9600); /*Inicializa a porta serial do Arduino com 9600 de baud rate.*/
    lcd.begin(screenWidth,screenHeight);  
    // vai criar novo caracter bateria cheia
    lcd.createChar(1, smile);

}

void loop () {
    int distancia = Sensor.read(); 
    distancia = Sensor.read(); 
    Serial.println(distancia); 
    lcd.setCursor(2, 1); 
    lcd.print("Medida: "); 
    lcd.setCursor(9, 1); 
    lcd.print(distancia); 
    lcd.setCursor(12, 1); 
    lcd.print("cm"); 
    lcd.setCursor(0, 1); 
    lcd.write(1);
    lcd.setCursor(15, 1); 
    lcd.write(1);
    
  lcd.setCursor(scrollCursor, 0);  
  lcd.print(line1.substring(stringStart,stringStop));  
  lcd.setCursor(0, 1);  
  
  //Quanto menor o valor do delay, mais rapido o scroll  
  delay(250);  
  scroll_sup(); //Chama a rotina que executa o scroll  

  //Verifica o tamanho da string  
  tamanho = line1.length();  
  if (stringStart == tamanho)  
  {  
    stringStart = 0;  
    stringStop = 0;  
  }
    
}  
   
void scroll_sup()  
{  
  lcd.clear();  
  if(stringStart == 0 && scrollCursor > 0)
  {  
    scrollCursor--;  
    stringStop++;  
  } else if (stringStart == stringStop){  
    stringStart = stringStop = 0;  
    scrollCursor = screenWidth;  
  } else if (stringStop == line1.length() && scrollCursor == 0) {  
    stringStart++;  
  } else {  
    stringStart++;  
    stringStop++;  
  }  
}
