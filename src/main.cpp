#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libepd/libepd.hpp>

#include "managers.h"


static void gpio_setup() {
    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);
}

void delay(int duration) {
    int cycles = duration * 1000;
    for (int i = 0; i < cycles; i++) {    /* Wait a bit. */
        __asm__("nop");
    }
}

int main() {
    gpio_setup();

    SPI spi1 = SPI();
    GPIO led_pin = GPIO(GPIOA, GPIO5);

    libepd::EPaper epd = libepd::EPaper(led_pin, led_pin, spi1, delay);

    epd.reset();
}
