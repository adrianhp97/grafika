#include "FrameBuffer.h"

FrameBuffer::FrameBuffer() {
  fbfd = open("/dev/fb0", O_RDWR);
  if (fbfd == -1) {
      perror("Error: cannot open framebuffer device");
      exit(1);
  }

  printf("The framebuffer device was opened successfully.\n");
  checkFixedScreenInformation();
  checkVariableScreenInformation();
  mapDeviceToMemory();
}

FrameBuffer::~FrameBuffer() {
  this->closeReading();
  delete fbp;
}

void FrameBuffer::checkFixedScreenInformation() {
  if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
    perror("Error reading fixed information");
    exit(2);
  }
}

void FrameBuffer::checkVariableScreenInformation() {
  if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
    perror("Error reading variable information");
    exit(3);
  }
}

void FrameBuffer::mapDeviceToMemory() {
  screensize = getScreenSize();
  fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
  if (atoi(fbp) == -1) {
      perror("Error: failed to map framebuffer device to memory");
      exit(4);
  }
  printf("The framebuffer device was mapped to memory successfully.\n");
}

void FrameBuffer::unmapped() {
  munmap(fbp, screensize);
}

int FrameBuffer::getScreenSize() {
  return vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
}

void FrameBuffer::closeReading() {
  close(fbfd);
}
