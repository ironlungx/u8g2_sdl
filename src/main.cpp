#include <cstdio>
#include <u8g2.h>

int main(const int argc, const char **argv) {
  u8g2_t disp;
  bool quit = false;
  u8g2_SetupBuffer_SDL_128x64(&disp, &u8g2_cb_r0);

  while (!quit) {
    u8g2_ClearBuffer(&disp);
    u8g2_SetFont(&disp, u8g2_font_ncenB08_tr);
    u8g2_DrawStr(&disp, 0, 15, "Hello World!");
    u8g2_SendBuffer(&disp);

    int key = u8g_sdl_get_key();

    if (key == 'q') quit = true;
  }
}
