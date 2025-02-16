#include "pico/stdlib.h"

// Definindo os pinos
#define LED_RED_PIN 12
#define LED_BLUE_PIN 13

#define BUTTON_PIN_5 5
#define BUTTON_PIN_6 6

// Função para controlar os LEDs intercalados

void blink_led(int speed) {
    int delay_time = 500 / speed; // Define o tempo de atraso com base na velocidade
   
        gpio_put(LED_RED_PIN, 1); // LED vermelhoo aceso
        gpio_put(LED_BLUE_PIN, 0); // LED azul apagado
        sleep_ms(delay_time);

        gpio_put(LED_RED_PIN, 0); // LED vermelhoo apagado
        gpio_put(LED_BLUE_PIN, 1); // LED azul aceso
        sleep_ms(delay_time);
  
}



int main() {
    gpio_init(BUTTON_PIN_5);
    gpio_set_dir(BUTTON_PIN_5, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_5);

    gpio_init(BUTTON_PIN_6);
    gpio_set_dir(BUTTON_PIN_6, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_6);

    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);

    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);

    while (1) {
        while (gpio_get(BUTTON_PIN_5) == 0) {
            blink_led(1);
            sleep_ms(50);
        }

        while (gpio_get(BUTTON_PIN_6) == 0) {
            blink_led(2);
            sleep_ms(50); 
        }
        gpio_put(LED_BLUE_PIN, 0);
        gpio_put(LED_RED_PIN, 0);
    }

    return 0;
}
