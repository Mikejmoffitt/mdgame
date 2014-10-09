#include "mpad.h"
// Read from a Sega Mega Drive controller port.
// Returns a bitfield - SCBARLDU (EX: bit0, LSB, is 0 when "up" is held);
unsigned char pad_read(unsigned char pl)
{
	// Controller data register, offset by player number
	volatile unsigned char *ctrlr = (unsigned char *)VDP_GAMEPAD + (2 * pl);
	*ctrlr |= (0x40); // Set bit 6 to read B,C,etc
	// Needed to account for some propagation delay on older pads
	asm("nop");
	asm("nop");
	unsigned char ret = *ctrlr & 0xF; // Grab U,D,L,R
	ret |= (*ctrlr & 0x30) << 1; // Grab B,C
	*ctrlr = *ctrlr & ~(0x40); // Clear bit 6 to get A and Start
	asm("nop");
	asm("nop");
	ret |= (*ctrlr & 0x10); // Grab A
	ret |= (*ctrlr & 0x20) << 2; // Grab Start
	return ret;
}