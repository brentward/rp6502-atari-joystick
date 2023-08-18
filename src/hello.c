#include <rp6502.h>
#include <stdio.h>
#include <stdint.h>
#include "atari_joystick.h"

void main()
{
    uint8_t last_joystick = 0xFF;
    joystick_init();
    puts("Hello, world!");
    while(1)
    {
        joystick_read();
        if (((last_joystick & UP_UNPRESSED) != ((joystick & UP_UNPRESSED))) && !(joystick & UP_UNPRESSED)) // True when button is first pressed
        {
            puts("Joystick Up pressed");
        }
        if (((last_joystick & DN_UNPRESSED) != ((joystick & DN_UNPRESSED))) && !(joystick & DN_UNPRESSED))
        {
            puts("Joystick Down pressed");
        }
        if (((last_joystick & LT_UNPRESSED) != ((joystick & LT_UNPRESSED))) && !(joystick & LT_UNPRESSED))
        {
            puts("Joystick Left pressed");
        }
        if (((last_joystick & RT_UNPRESSED) != ((joystick & RT_UNPRESSED))) && !(joystick & RT_UNPRESSED))
        {
            puts("Joystick Right pressed");
        }
        if (((last_joystick & FIRE_UNPRESSED) != ((joystick & FIRE_UNPRESSED))) && !(joystick & FIRE_UNPRESSED))
        {
            puts("Joystick Fire pressed");
        }

        // if (!(joystick & UP_UNPRESSED)) // True whenever button pressed
        // {
        //     puts("Joystick Up");
        // }
        // if (!(joystick & DN_UNPRESSED))
        // {
        //     puts("Joystick Down");
        // }
        // if (!(joystick & LT_UNPRESSED))
        // {
        //     puts("Joystick Left");
        // }
        // if (!(joystick & RT_UNPRESSED))
        // {
        //     puts("Joystick Right");
        // }
        // if (!(joystick & FIRE_UNPRESSED))
        // {
        //     puts("Joystick Fire");
        // }

        last_joystick = joystick;
    }
}
