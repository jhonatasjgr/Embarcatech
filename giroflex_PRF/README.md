# Documentação do Código para Raspberry Pi Pico W

## Objetivo
O código desenvolvido para a placa BitDogLab tem como objetivo controlar dois LEDs (vermelho e azul) e responder ao aperto de botões para acionar os LEDs. O código implementa uma funcionalidade de piscar os LEDs de acordo com a velocidade configurada e desliga os LEDs quando nenhum botão está sendo pressionado.

## Pinos Utilizados
- **LED_RED_PIN (Pino 12):** Controle do LED vermelho.
- **LED_BLUE_PIN (Pino 13):** Controle do LED azul.
- **BUTTON_PIN_5 (Pino 5):** Botão que altera a velocidade de piscar dos LEDs.
- **BUTTON_PIN_6 (Pino 6):** Outro botão que também altera a velocidade dos LEDs.

## Função `blink_led(int speed)`
A função `blink_led` alterna os LEDs de forma intercalada.

### Como funciona:
- A variável `delay_time` é calculada dividindo 500 por `speed`, o que determina o tempo entre cada mudança de estado dos LEDs.
- O LED vermelho é aceso e o LED azul é apagado, depois alterna.

### Parâmetro:
- **speed:** Define a velocidade do piscar dos LEDs. Valores maiores resultam em uma troca mais rápida entre os LEDs.

## Estrutura do `main`
O código entra em um loop infinito que observa o estado dos botões e alterna o comportamento dos LEDs conforme os botões pressionados.

### Comportamento:
- Se o **botão 5** for pressionado, a função `blink_led(1)` é chamada, fazendo os LEDs piscarem com velocidade baixa.
- Se o **botão 6** for pressionado, a função `blink_led(2)` é chamada, fazendo os LEDs piscarem com velocidade maior.
- Quando **nenhum botão** é pressionado, os LEDs são apagados.

## Considerações Finais
Este código é simples e demonstra como utilizar entradas e saídas digitais na Placa BitDogLab para controlar LEDs e responder a botões. Ele pode ser expandido para outras funcionalidades, como controlar mais LEDs, um display ou implementar comportamentos diferentes baseados nas entradas.

## Requisitos de Hardware
- Placa **BitDogLab**
- Dois LEDs (vermelho e azul)
- Dois botões


