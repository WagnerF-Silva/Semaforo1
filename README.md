# README - Semáforo com Raspberry Pi Pico

## Descrição
Este projeto implementa um semáforo utilizando um **Raspberry Pi Pico**. O código controla três LEDs representando as cores do semáforo (vermelho, amarelo e verde) e alterna entre eles a cada 3 segundos.

## Componentes Necessários
- Raspberry Pi Pico
- 3 LEDs (vermelho, amarelo e verde)
- 3 resistores (220Ω)
- Jumpers para conexões
- Protoboard

## Conexões
Os LEDs devem ser conectados aos seguintes pinos:

| Cor do LED | Pino GPIO |
|------------|----------|
| Vermelho   | 13       |
| Amarelo    | 12       |
| Verde      | 11       |

Cada LED deve estar em série com um resistor de 220Ω para limitar a corrente.

## Como Funciona
1. O código inicializa os pinos dos LEDs como saída.
2. Um temporizador é configurado para alterar o estado do semáforo a cada 3 segundos.
3. O callback do temporizador alterna entre os estados:
   - Estado 0: LED vermelho ligado.
   - Estado 1: LED amarelo ligado.
   - Estado 2: LED verde ligado.
4. O loop principal imprime "Semáforo rodando..." a cada segundo.

## Compilando e Executando
Para compilar e rodar o código no Raspberry Pi Pico:

1. Instale o **SDK do Raspberry Pi Pico**.
2. Compile o código utilizando CMake:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```
3. Converta o binário gerado para UF2 e carregue no Pico.

## Possíveis Melhorias
- Ajustar o tempo de troca das cores para simular melhor um semáforo real.
- Adicionar um botão para controle manual.
- Utilizar PWM para controlar a intensidade dos LEDs.

## Autor
Este código foi desenvolvido para aprendizado e experimentação com o Raspberry Pi Pico.

