#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

float temperature;
float humidity;
DHT dht14(D4,DHT11);

LiquidCrystal_I2C lcd(0x27,16,2);

// ฟังก์ชัน setup()
void setup() {
  // ตั้งค่าพอร์ตการสื่อสาร Serial
  Serial.begin(9600);

  // กำหนดค่า LCD
  lcd.begin();

  // เริ่มต้นทำงาน Sensor
  dht14.begin();

  // ตั้งค่าตำแหน่งเคอร์เซอร์
  lcd.setCursor(0, 0);

}

// ฟังก์ชัน loop()
void loop() {

  humidity = (dht14.readHumidity());
  temperature = (dht14.readTemperature( ));

  // ตรวจสอบค่าอุณหภูมิและความชื้น
  if (isnan(temperature) || isnan(humidity)) {
    // ค่าผิดพลาด
    lcd.print("Err");
  } else {
    // ค่าถูกต้อง

    // พิมพ์ค่าอุณหภูมิ
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    // lcd.print(temperature);
    lcd.print("C");

    // พิมพ์ค่าความชื้น
    lcd.setCursor(5, 1);
    lcd.print("Humi: ");
    lcd.print(humidity);
    lcd.print(" %");
  }

  // หน่วงเวลา 1 วินาที
  delay(1000);
}