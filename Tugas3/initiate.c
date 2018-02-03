#include "initiate.h"

void initiateReading(int *fbfd, struct fb_var_screeninfo *vinfo, struct fb_fix_screeninfo *finfo) {
  *fbfd = open("/dev/fb0", O_RDWR);
  if (*fbfd == -1) {
      perror("Error: cannot open framebuffer device");
      exit(1);
  }
  printf("The framebuffer device was opened successfully.\n");

  getFixedScreenInformation(fbfd, finfo);
  getVariableScreenInformation(fbfd, vinfo);
}

void getFixedScreenInformation(int *fbfd, struct fb_fix_screeninfo *finfo) {
  if (ioctl(*fbfd, FBIOGET_FSCREENINFO, finfo) == -1) {
    perror("Error reading fixed information");
    exit(2);
  }
}

void getVariableScreenInformation(int *fbfd, struct fb_var_screeninfo *vinfo) {
  if (ioctl(*fbfd, FBIOGET_VSCREENINFO, vinfo) == -1) {
    perror("Error reading variable information");
    exit(3);
  }
}

int getScreenSize(struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {
  return vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
}

char* mapDeviceToMemory(int *fbfd, long int screensize) {
  char *fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, *fbfd, 0);
  if ((int)fbp == -1) {
      perror("Error: failed to map framebuffer device to memory");
      exit(4);
  }
  else {
    printf("The framebuffer device was mapped to memory successfully.\n");
    return fbp;
  }
}

void unmapped(char *fbp, long int * screensize) {
  munmap(fbp, *screensize);
}

void closeReading(int *fbfd) {
  close(*fbfd);
}