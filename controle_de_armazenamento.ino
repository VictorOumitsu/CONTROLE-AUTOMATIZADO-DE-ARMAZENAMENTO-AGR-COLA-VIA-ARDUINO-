#include <Wire.h>  // A biblioteca Wire é necessária para a comunicação I2C
#include <LiquidCrystal_I2C.h>  // Incluindo a biblioteca correta para LCD I2C

// Endereço I2C do LCD (padrão 0x27 no Wokwi)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 16 colunas, 2 linhas

#define PINO_R 9
#define PINO_G 10
#define PINO_B 11

int peso = 0;

void setup() {
  Serial.begin(9600);

  pinMode(PINO_R, OUTPUT);
  pinMode(PINO_G, OUTPUT);
  pinMode(PINO_B, OUTPUT);

  digitalWrite(PINO_R, LOW);
  digitalWrite(PINO_G, LOW);
  digitalWrite(PINO_B, LOW);

  randomSeed(analogRead(A1)); 

  // Inicializa o LCD
  lcd.begin(16, 2);  // Inicializa o LCD com 16 colunas e 2 linhas
  lcd.setBacklight(true);  // Liga a luz de fundo do LCD
  lcd.print("Peso e Armazenamento");
  delay(2000); // Exibe a mensagem por 2 segundos
}

void loop() {
  peso = random(0, 1001);  // Peso aleatório entre 0 e 1000 kg

  // Calcula a porcentagem de armazenamento baseado no peso
  float porcentagem = (peso / 1000.0) * 100;

  // Exibe o peso e a porcentagem no LCD
  lcd.clear();  // Limpa a tela do LCD
  lcd.setCursor(0, 0);  // Coloca o cursor na linha 0, coluna 0
  lcd.print("Peso: " + String(peso) + "kg");  // Exibe o peso

  lcd.setCursor(0, 1);  // Coloca o cursor na linha 1, coluna 0
  lcd.print("Uso: " + String(porcentagem, 1) + "%");  // Exibe a porcentagem

  // Controle dos LEDs com base no peso
  if (peso >= 800 && peso <= 1000) {
    digitalWrite(PINO_R, HIGH);
    digitalWrite(PINO_G, LOW);
    digitalWrite(PINO_B, LOW);
  }
  else if (peso >= 400 && peso < 800) {
    digitalWrite(PINO_R, HIGH);
    digitalWrite(PINO_G, HIGH);
    digitalWrite(PINO_B, LOW);
  }
  else if (peso >= 0 && peso < 400) {
    digitalWrite(PINO_R, LOW);
    digitalWrite(PINO_G, HIGH);
    digitalWrite(PINO_B, LOW);
  }

  delay(1500);  // Pausa de 1500 ms (1.5 segundos)
}
