#include "managers.h"
#include <libopencm3/stm32/gpio.h>

void SPI::send() {}

GPIO::GPIO(uint32_t port, uint16_t pin) {
    this->port = port;
    this->pin = pin;
}

void GPIO::set(int logic_level) {
    if (logic_level == 1) {
        gpio_set(this->port, this->pin);
        return;
    }

    gpio_clear(this->port, this->pin);
}

int GPIO::get() {
    return gpio_get(this->port, this->pin);
}