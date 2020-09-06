#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void gpio_setup() {
    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);
}

int main() {
    gpio_setup();

    while (1) {
        /* Using API function gpio_toggle(): */
        gpio_toggle(GPIOA, GPIO5);    /* LED on/off */
        for (int i = 0; i < 5000000; i++) {    /* Wait a bit. */
            __asm__("nop");
        }
    }
}
