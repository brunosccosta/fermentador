#include <LiquidCrystal.h>  
  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  

int fermentador;
int target, atual;
bool pressed;

void setup()   
{
  fermentador = 1;
  atual = 21;
  
  lcd.begin(16, 2);  
  lcd.clear();
 
  lcd_titulo();

  pressed = false;
}  

void loop()  
{ 
  int botao = analogRead (0);  //Leitura do valor da porta analógica A0

  if (!pressed)
  {
    if (botao < 900)
      pressed = true;
    
    if (botao < 50)
      btn_right();
    else if (botao > 50 && botao < 200)
      btn_up();
    else if (botao > 200 && botao < 300)
      btn_down();
    else if (botao > 300 && botao < 600)
      btn_left();
    else if (botao > 600 && botao < 900)
      btn_select();
  }

  if (botao > 900)
    pressed = false;

  lcd_titulo();
  lcd_status();
}

void lcd_titulo()
{
  String str_fermentador(fermentador);
  str_fermentador += ") Target  Atual";

  lcd.setCursor(0,0);
  lcd.print(str_fermentador);
}

void lcd_status()
{
  String str_target(target);
  String str_atual(atual);

  String str_status = "    ";
  str_status += str_target;
  str_status += "o     ";
  str_status += str_atual;
  str_status += "o  ";
  
  lcd.setCursor(0,1); 
  lcd.print(str_status);
}

void btn_right()
{
  fermentador++;
  if (fermentador >= 10)
    fermentador = 9;
}

void btn_up()
{
  target += 1;
}

void btn_down()
{
  target -= 1;
}

void btn_left()
{
  fermentador--;
  if (fermentador <= 0)
    fermentador = 1;
}

void btn_select()
{
}

