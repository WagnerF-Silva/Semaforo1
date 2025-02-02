#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos
const uint led_red = 13;
const uint led_yellow = 12;
const uint led_green = 11;

volatile int estado = 0; // Estado atual do semáforo

// Função callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    gpio_put(led_red, estado == 0);   // Liga vermelho no estado 0
    gpio_put(led_yellow, estado == 1);// Liga amarelo no estado 1
    gpio_put(led_green, estado == 2); // Liga verde no estado 2

    estado = (estado + 1) % 3; // Alterna entre 0, 1 e 2

    return true; // Mantém o timer rodando
}

int main() {
    stdio_init_all();
    gpio_init(led_red);
    gpio_set_dir(led_red, GPIO_OUT);
    gpio_init(led_yellow);
    gpio_set_dir(led_yellow, GPIO_OUT);
    gpio_init(led_green);
    gpio_set_dir(led_green, GPIO_OUT);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        printf("Semáforo rodando...\r\n");
        sleep_ms(1000); // Imprime mensagem a cada 1s
    }
}
