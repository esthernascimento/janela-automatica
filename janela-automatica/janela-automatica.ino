#define sensorChuva A0
#define FimdeCursoJanelaFechada 12
#define FimdeCursoJanelaAberta 13
#define BotaoManualAutomatico 5
#define BotaoFechaManual 6
#define BotaoAbreManual 7
#define LedAutomatico 8
#define LedManual 9
#define IN1 3  // Entrada da ponte H
#define IN2 2  // Entrada da ponte H

bool modoAutomatico = true;
bool botaoModoAnterior = LOW;

void setup() {
  pinMode(sensorChuva, INPUT);
  pinMode(FimdeCursoJanelaFechada, INPUT_PULLUP);
  pinMode(FimdeCursoJanelaAberta, INPUT_PULLUP);
  pinMode(BotaoManualAutomatico, INPUT_PULLUP);
  pinMode(BotaoFechaManual, INPUT_PULLUP);
  pinMode(BotaoAbreManual, INPUT_PULLUP);

  pinMode(LedAutomatico, OUTPUT);
  pinMode(LedManual, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int leituraChuva = analogRead(sensorChuva);
  bool janelaFechada = digitalRead(FimdeCursoJanelaFechada) == LOW;
  bool janelaAberta = digitalRead(FimdeCursoJanelaAberta) == LOW;

  Serial.print("Chuva: ");
  Serial.print(leituraChuva);
  Serial.print(" | Fechada: ");
  Serial.print(janelaFechada);
  Serial.print(" | Aberta: ");
  Serial.print(janelaAberta);
  Serial.print(" | Modo: ");
  Serial.println(modoAutomatico ? "AUTO" : "MANUAL");

  // Alternar modo
  bool botaoModoAtual = digitalRead(BotaoManualAutomatico) == LOW;
  if (botaoModoAtual && !botaoModoAnterior) {
    modoAutomatico = !modoAutomatico;
    delay(300);  // Debounce
  }
  botaoModoAnterior = botaoModoAtual;

  // LEDs de indicação
  digitalWrite(LedAutomatico, modoAutomatico ? HIGH : LOW);
  digitalWrite(LedManual, modoAutomatico ? LOW : HIGH);

  if (modoAutomatico) {
    if (leituraChuva < 800 && !janelaFechada) {
      Serial.println(">> AUTO: FECHANDO JANELA");
      fecharJanela();
    } else if (leituraChuva >= 800 && !janelaAberta) {
      Serial.println(">> AUTO: ABRINDO JANELA");
      abrirJanela();
    } else {
      Serial.println(">> AUTO: PARANDO MOTOR");
      pararMotor();
    }

  } else {
    if (digitalRead(BotaoAbreManual) == LOW && !janelaAberta) {
      Serial.println(">> MANUAL: ABRINDO JANELA");
      abrirJanela();
    } else if (digitalRead(BotaoFechaManual) == LOW && !janelaFechada) {
      Serial.println(">> MANUAL: FECHANDO JANELA");
      fecharJanela();
    } else {
      Serial.println(">> MANUAL: PARANDO MOTOR");
      pararMotor();
    }
  }

  delay(500);
}

void abrirJanela() {
  digitalWrite(IN1, LOW);   // Gira motor para abrir
  digitalWrite(IN2, HIGH);
}

void fecharJanela() {
  digitalWrite(IN1, HIGH);  // Gira motor para fechar
  digitalWrite(IN2, LOW);
}

void pararMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}