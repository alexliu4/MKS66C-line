#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

  // for quadrants on the left side (moving right to left) 3, 4, 5, and 6
  if (x1 < x0){
    draw_line(x1, y1, x0, y0, s, c);
  }
  else {

    // for quadrants on the right side (moving left to right) 1, 2, 7, 8
    int curx = x0;
    int cury = y0;
    // A = y, B = -x, C = x * b
    int A = y1 - y0;
    int B = -(x1 - x0);

    //octant 1
    if (A >= 0 && A <= -B){
      int d = 2*A + B;
      while (curx <= x1){
        plot(s, c, curx, cury);
        curx++;
        d += 2*A;
        if(d >= 0){
  	       cury++;
  	       d += 2*B;
        }
      }
    }

    //octant 2
    else if(A >= 0 && A >= -B){
      int d = A + 2*B;
      while (cury <= y1){
        plot(s, c, curx, cury);
        cury++;
        d += 2*B;
        if(d <= 0){
  	       curx++;
  	       d += 2*A;
        }
      }
    }

    //octant 7
    else if (A <= 0 && A <=B){
      int d = A - 2*B;
      while (cury >= y1){
        plot(s, c, curx, cury);
        cury--;
        d -= 2*B;
        if (d >= 0){
  	       curx++;
  	       d += 2*A;
        }
      }
    }

    //octant 8
    else if (A <= 0 && A >= B){
      int d = 2*A - B;
      while (curx <= x1){
        plot(s, c, curx, cury);
        curx++;
        d += 2*A;
        if (d <= 0){
  	       cury--;
  	       d -= 2*B;
        }
      }
    }

  }
}
