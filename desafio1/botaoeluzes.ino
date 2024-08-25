int rled = 2;
int ogled = 3;  // definindo variaveis para cada porta dos pins
int botao = 4;

void setup(){
  pinMode(rled, OUTPUT);
  pinMode(ogled, OUTPUT);  // setup dos pins 
  pinMode(botao, INPUT);
}

void loop(){
int botaomode = digitalRead(botao); // botaomode armazena o estado do botao

  if(botaomode == LOW){
    digitalWrite(rled, LOW);  // condicional para ligar as luzes ao apertar o botao
    digitalWrite(ogled, LOW);
  }else{
    digitalWrite(rled, HIGH);
    digitalWrite(ogled, HIGH);
  } 
}
