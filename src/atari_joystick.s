.zeropage
_joystick:			.res 1 ; first 2 bytes are controller button state and 3rd byte is connection status

.exportzp _joystick

.export _joystick_init ; prepend labels with _ so C can see them
.export _joystick_read

;
.include "rp6502.inc" 

; Wiring
; The joystick pulls each pin to ground when a control is actuated so each GPIO pin taking an input (pins 3, 5, 7, 9, and 11)
; will need a pullup resistor to 3.3 V, which is on GPIO pin 1.

; Joystick	GPIO
; 1(up)     3 (PA0)
; 2(down)   5 (PA1)
; 3(left)   7 (PA2)
; 4(right)  9 (PA3)
; 5         NC
; 6(fire)   11 (PA4)
; 7         NC
; 8(GND)    23 (GND)
; 9         NC

bit_up = $01 ; PA0 (GPIO pin 3): Up
bit_down = $02 ; PA1 (GPIO pin 5): Down
bit_left = $04 ; PA2 (GPIO pin 7):  Left
bit_right = $08 ; PA3 (GPIO pin 9): Right
bit_fire = $10 ; PA4 (GPIO pin 11): Fire

.code
.proc _joystick_init: near
    lda #$FF-bit_up-bit_down-bit_left-bit_right-bit_fire
    sta VIA_DDRA
    rts
.endproc

.proc _joystick_read: near
    lda VIA_PA1
    sta _joystick
    rts
.endproc