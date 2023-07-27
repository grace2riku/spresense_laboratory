
#include <nuttx/config.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define SPRESENSE_MAIN_BOARD_UART_DEVICE_PATH "/dev/ttyS0"

int main(int argc, FAR char *argv[])
{  
  char buffer[30];
  int len;

  int fd = open(SPRESENSE_MAIN_BOARD_UART_DEVICE_PATH, O_RDWR);
  if (fd < 0)
  {
    printf("%s open error.\n", SPRESENSE_MAIN_BOARD_UART_DEVICE_PATH);
    return 1;
  }

  while (1) {
    len = read(fd, buffer, 1);
    if(len > 0)
    {
      printf("[read_serial]buffer=%c\n", buffer[0]);
      write(fd, buffer, 1);
    }
    else
    {
      printf("[read_serial]null\n");
      return 1;
    }

    if (buffer[0] == 'q') {
      break;
    }

  }

  close(fd);

  return 0;
}
