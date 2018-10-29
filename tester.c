#include <stdio.h>
#include "ifttt.h"

int main(int argc, char *argv[])
{
/*
  ifttt("https://maker.ifttt.com/trigger/button_pressed/with/key/56-YpOKO17vOh-gimC2xK1qRAhRdzXXXX", "my1", "my 2", "my 33333");
*/

  printf("Trying to connect to server\n");
  ifttt("https://maker.ifttt.com/trigger/alarm_triggered/with/key/cOHWoBOVnz2E_7xPiNLBga", "my1", "my 2", "my 33333");
  return 0;
}
