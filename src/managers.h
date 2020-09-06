#ifndef QLOCK_MANAGERS_H
#define QLOCK_MANAGERS_H

#include <libopencm3/stm32/gpio.h>
#include <libepd/libepd.hpp>


class SPI : public libepd::SPIManager {
public:
    void send() override;
};


class GPIO : public libepd::GPIOManager {
private:
    uint32_t port;
    uint16_t pin;

public:
    GPIO(uint32_t port, uint16_t pin);

    void set(int logic_level) override;
    int get() override;
};

#endif //QLOCK_MANAGERS_H
