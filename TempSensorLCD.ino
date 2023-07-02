
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

double temp_amb;
double temp_obj;


const uint8_t I2C_ADDRESS = 0x27;
const uint8_t LCD_CHAR = 16;
const uint8_t LCD_ROW = 2;
LiquidCrystal_I2C lcd(0x27, I2C_ADDRESS, LCD_CHAR, LCD_ROW);

int Tempsensor = 9;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(Tempsensor, OUTPUT);

    if (!mlx.begin())
  {
    lcd.print("MLX90614 failed");
    lcd.setCursor(0, 1);
    lcd.print("check wiring!");
    while (1);
  }
  
}

void loop() {
  Serial.print("TEMPERATURE : "); 
  Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("\n");

  lcd.clear();
  lcd.print("Thermometer");
  clearCharacters(LCD_ROW - 1, 0, LCD_CHAR - 1);
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");

  clearCharacters(1, 9, LCD_CHAR - 1 );
  lcd.setCursor (9, 1); //
  lcd.print(mlx.readObjectTempC());
  delay(500);
}
