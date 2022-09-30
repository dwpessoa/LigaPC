// Define o pino do relé como D8
int PinoRele = 8;
volatile bool EstadoSaida = LOW;
volatile bool ExecutouPulso = LOW;

// Variaveis de tempo
long AtrasoLigar_Ultimo = 0;  
long TempoPulso_Ultimo = 0;  

long AtrasoLigar = 10000; //10 segundos
long TempoPulso = 1000; //1 segundo

void setup() 
{
  //Ajusta a saída
  pinMode(PinoRele, OUTPUT);
  digitalWrite(PinoRele, HIGH); //Saida trabalha invertida

  //Reseta o timer inicial
  AtrasoLigar_Ultimo = millis();
  
  //Inicializa a serial para debug
  Serial.begin(9600);

  Serial.println("INICIANDO");
}

void loop() 
{
  //Liga a saída após um tempo
  if((millis() - AtrasoLigar_Ultimo) > AtrasoLigar && !EstadoSaida && !ExecutouPulso)
  {
    digitalWrite(PinoRele, LOW);
    EstadoSaida = HIGH;
    TempoPulso_Ultimo = millis();
    Serial.println("Ligando Rele");
  }

  //Desliga a saida após mais um tempo
  if((millis() - TempoPulso_Ultimo) > TempoPulso && EstadoSaida == HIGH && !ExecutouPulso)
  {
    digitalWrite(PinoRele, HIGH);
    EstadoSaida = LOW;
    ExecutouPulso = HIGH;
    Serial.println("Desligando Rele");
  }
  
  delay(50);
}
