
void FrameBuffer::FrameBuffer() {
  *fbfd = open("/dev/fb0", O_RDWR);
  if (*fbfd == -1) {
      perror("Error: cannot open framebuffer device");
      exit(1);
  }
  printf("The framebuffer device was opened successfully.\n");
  if (ioctl(*fbfd, FBIOGET_FSCREENINFO, finfo) == -1) {
    perror("Error reading fixed information");
    exit(2);
  }
  if (ioctl(*fbfd, FBIOGET_VSCREENINFO, vinfo) == -1) {
    perror("Error reading variable information");
    exit(3);
  }
}

void FrameBuffer::getFixedScreenInformation() {
  return this.fb_fix_screeninfo;
}

void FrameBuffer::getVariableScreenInformation() {
  return this.fb_var_screeninfo;
}

char* FrameBuffer::mapDeviceToMemory(int *fbfd, long int screensize) {
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

void FrameBuffer::unmapped(char *fbp, long int * screensize) {
  munmap(fbp, *screensize);
}

int FrameBuffer::getScreenSize(struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {
  return vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
}
// void closeReading(int *fbfd) {
//   close(*fbfd);
// }