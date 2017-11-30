
#ifndef SSD1306_DOUBLEWIDTH_H
#define SSD1306_DOUBLEWIDTH_H

#include <stdbool.h>
#include <stdio.h>

bool iota_gfx_init(void);
void iota_gfx_task(void);
bool iota_gfx_off(void);
bool iota_gfx_on(void);
void iota_gfx_flush(void);
void iota_gfx_write_char(uint16_t c);
void iota_gfx_write(const char *data);
void iota_gfx_write_P(const char *data);
void iota_gfx_clear_screen(void);
void iota_gfx_qmk_logo(void);
void iota_gfx_invader(void);

#endif