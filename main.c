#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const uint LED_PIN = 25;

int main() {
  bi_decl(bi_program_description("This is a test binary."));
  bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"));

  stdio_init_all();

  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  for (;;) {
    for (int i = 0; i < 3; i++) {
      gpio_put(LED_PIN, 0);
      sleep_ms(100);
      gpio_put(LED_PIN, 1);
      sleep_ms(100);
    }
    for (int i = 0; i < 3; i++) {
      gpio_put(LED_PIN, 0);
      sleep_ms(500);
      gpio_put(LED_PIN, 1);
      sleep_ms(500);
    }
    sleep_ms(1000);
  }
}
