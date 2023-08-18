#define UP_UNPRESSED	0b00000001
#define DN_UNPRESSED	0b00000010
#define LT_UNPRESSED	0b00000100
#define RT_UNPRESSED	0b00001000
#define FIRE_UNPRESSED	0b00010000

extern uint8_t joystick;
#pragma zpsym("joystick")

/* initializes the VIA for connecting an Atari style single button joystick on Port A*/
extern void joystick_init();

/* reads an Atari style single button joystick and stores as a byte in joystick*/
extern void joystick_read();