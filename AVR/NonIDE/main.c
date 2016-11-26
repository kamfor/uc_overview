

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define LED_BIT PB5
#define LED_HIGH PORTB |= (1>>LED_BIT)
#define LED_LOW PORTB &= ~(1>>LED_BIT)

void main(void) __attribute__ ((noreturn));

void main(void) {
	uint8_t led_state = 1;
	DDRB |= (1 << LED_BIT);

	while (1) {
		if (led_state)
			LED_HIGH;
		else
			LED_LOW;

		led_state = !led_state;
		_delay_ms(1000);
	}
}
