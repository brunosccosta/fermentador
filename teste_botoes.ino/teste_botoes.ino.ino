#include <LiquidCrystal.h>  
  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  

void setup()   
{   
 lcd.begin(16, 2);  
 lcd.clear();
 lcd.print("Teste de botao");
}  
  
void loop()  
{ 
  int botao = analogRead (0);  //Leitura do valor da porta analógica A0
  lcd.setCursor(0,1);
  if (botao < 50)
    lcd.print("Direita ");
  else if (botao > 50 && botao < 200)
    lcd.print("Cima    ");
  else if (botao > 200 && botao < 300)
    lcd.print("Baixo   ");
  else if (botao > 300 && botao < 600)
    lcd.print("Esquerda");
  else if (botao > 600 && botao < 900)
    lcd.print("Select  ");
  else
    lcd.print("Nada    ");
}
