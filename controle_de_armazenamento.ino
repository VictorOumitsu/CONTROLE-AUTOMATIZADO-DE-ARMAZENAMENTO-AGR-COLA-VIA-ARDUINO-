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
}

void loop() {
  peso = random(0, 1001);

  Serial.print("Peso atual: ");
  Serial.print(peso);
  Serial.println(" kg");

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

  delay(500);
}
