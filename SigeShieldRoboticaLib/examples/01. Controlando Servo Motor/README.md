# Knob.ino

Programa que movimenta um servo motor pelo acionamento proporcional do potenciômetro.

## Análise do código

- Importa a biblioteca *Servo.h* para utilização no nosso código.

```
#include <Servo.h>
```

- Declara uma variável chamada *myservo* representando a biblioteca *Servo.h*

```
Servo myservo;
```

- Declarando duas variáveis:
    - *potpin* que recebe a porta onde o potenciômetro está ligado
    - *val* que recebe o valor do potenciômetro

```
int potpin = 1;
int val;
```

> **int** é um modificador de tipo de variável que indica que a váriável é do tipo inteiro, ou seja aceita caracteres numéricos com sinal, por exemplo: -15, 20, -30000, 50, 60 etc.

- Na função *setup()* chamamos um método da biblioteca *Servo* chamada *attach()*, passando como parâmetro a porta onde o servo motor está ligado, no nosso caso é a porta 6.

```
void setup() {
  myservo.attach(6);
}
```

> **void setup() {}** é uma função de configuração do código, ela roda uma vez quando o Arduino é ligado. As instruções da função *setup()* ficam dentro de chaves {}.

- Na função *loop* escrevemos o código que vai rodar enquanto o Arduino estiver ligado: 
    - Pegando o valor da porta do potenciômetro, através da função *analogRead()* 
    - Mapeando o valor lido para um valor que o servo motor entenda, com a função *map()*
    - E depois escrevendo esse valor no servo motor, para ele se movimentar, chamando o método *write()* da biblioteca *Servo*. 
    - No final utilizamos a função *delay()* para atrasar um pouco a próxima execução do laço principal.

```
void loop() {
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 120);
  myservo.write(val);
  delay(15);
}
```

> **void loop() {}** é a função principal do código, ela fica rodando enquanto o Arduino estiver ligado. Quando executa a última instrução dentro das chaves {}, começa tudo de novo pela primeira instrução, e fica assim repetindo até o Arduino ser desligado.
