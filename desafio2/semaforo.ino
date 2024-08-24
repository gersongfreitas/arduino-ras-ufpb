int gled = 2;
int yled = 3;
int rled = 4;
int botao = 5;
int botaostate = 0;
int gledgap = 10000;  // definindo as diversas variaveis que irao ser usadas ao longo do programa
int yledgap = 2000;
int rledgap = 10000;
int pedestriangap = 3000;
int lightstate = 0;
unsigned long int amillis, oldmillis = 0;

void setup() {
	pinMode(gled, OUTPUT);
	pinMode(yled, OUTPUT);  // setup dos led e botao na placa
	pinMode(rled, OUTPUT);
	pinMode(botao, INPUT);
}

void loop() {

	botaostate = digitalRead(botao); // configurando a variavel resposta do botao
	amillis = millis();

	if (botaostate == HIGH && lightstate != 3) { //se o botao for apertado e o semaforo ja nao estiver esperando por pedestres, ele mudara para lightstate 3 (botao do pedestre)
		lightstate = 3;

	} else {

		if (lightstate == 0) {
			digitalWrite(gled, HIGH);
			digitalWrite(yled, LOW);
			digitalWrite(rled, LOW);
			if (amillis - oldmillis >= gledgap) { // mudanca do sinal pra verde e para amarelo apos o intervalo
				lightstate = 1;
				oldmillis = amillis;
			}
		}

		if (lightstate == 1) {
			digitalWrite(gled, LOW);
			digitalWrite(yled, HIGH);
			digitalWrite(rled, LOW);
			if (amillis - oldmillis >= yledgap) { // mudanca do sinal pra amarelo e para vermelho apos o intervalo
				lightstate = 2;
				oldmillis = amillis;
			}
		}

		if (lightstate == 2) {
			digitalWrite(gled, LOW);
			digitalWrite(yled, LOW);
			digitalWrite(rled, HIGH);
			if(amillis - oldmillis >= rledgap) { // mudanca do sinal pra vermelho e para verde apos o intervalo
				lightstate = 0;
				oldmillis = amillis;
			}
		}

		if (lightstate == 3) {
			digitalWrite(gled, LOW);
			digitalWrite(yled, LOW);
			digitalWrite(rled, HIGH);
			if (amillis - oldmillis >= pedestriangap) { // definicao do sinal para vermelho apos a condicao do botao ser atendida
				lightstate = 0;
				oldmillis = amillis;
			}
		}
	}
}
