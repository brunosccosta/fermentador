#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>  

// Porta do pino de sinal do DS18B20
#define ONE_WIRE_BUS 3
 
// Define uma instancia do oneWire para comunicacao com o sensor
OneWire oneWire(ONE_WIRE_BUS);
 
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;
  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  

int fermentador;
float target, atual;
bool ligar_peltier;

void setup()   
{
  fermentador = 1;
  target = atual = 0;
  ligar_peltier = false;

  Serial.begin(9600);

  lcd.begin(16, 2);  
  lcd.clear();
  lcd_titulo();
  
  sensors.begin();
  // Localiza e mostra enderecos dos sensores
  Serial.println("Localizando sensores DS18B20...");
  Serial.print("Foram encontrados ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" sensores.");
  if (!sensors.getAddress(sensor1, 0)) 
     Serial.println("Sensores nao encontrados !"); 
  // Mostra o endereco do sensor encontrado no barramento
  Serial.print("Endereco sensor: ");
  mostra_endereco_sensor(sensor1);
  Serial.println();
  Serial.println();
}
 
void mostra_endereco_sensor(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    // Adiciona zeros se necessário
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
} 

void loop()  
{ 
  processar_sensor();
  
  int botao = analogRead (0);  //Leitura do valor da porta analógica A0

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

  lcd_titulo();
  lcd_status();

  delay(1000);
}

void processar_sensor()
{
  sensors.requestTemperatures();
  atual = sensors.getTempC(sensor1);

  ligar_peltier = atual > target;
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

void btn_up()
{
  target += 1;
}

void btn_down()
{
  target -= 1;
}

void btn_right()
{
}

void btn_left()
{
}

void btn_select()
{
}

