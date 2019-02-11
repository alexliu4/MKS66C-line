#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {
  time_t currentTime = time(NULL);
  srand(currentTime);

  screen s;
  color c;
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;

  int midX = XRES/2;
  int midY = YRES/2;


  clear_screen(s);

  // rainbow pyramid on top
  for (int x = 0, y = 0;x <= XRES && y <= YRES; x+=1, y+=1){
    c.red = rand()% (x + 20);
    c.green = rand()% (y + 20);
    c.blue = rand()%256;
    draw_line(midX - y, midY + x, midX + x, midY + y, s, c);
  }

  // random rays of light
  for (int x = 0, y = 0;x <= XRES && y <= YRES; x+=20, y+=20){

    draw_line(midX + 5, midY, midX + 155 + x, midY + y, s, c);
    draw_line(midX - 5, midY, midX - 155 + x, midY + y, s, c);
    draw_line(midX + 5, midY, midX + 155 - x, midY - y, s, c);
    draw_line(midX - 5, midY, midX - 155 - x, midY - y, s, c);

  }


  display(s);
  save_extension(s, "lines.png");
}
