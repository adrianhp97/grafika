#ifndef INITIATE_H
#define INITIATE_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <unistd.h>

void initiateReading(int *fbfd, struct fb_var_screeninfo *vinfo, struct fb_fix_screeninfo *finfo);
void closeReading(int *fbfd);
void getFixedScreenInformation(int *fbfd, struct fb_fix_screeninfo *finfo);
void getVariableScreenInformation(int *fbfd, struct fb_var_screeninfo *vinfo);

char* mapDeviceToMemory(int *fbfd, long int screensize);
void unmapped(char *fbp, long int * screensize);

int getScreenSize(struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);

#endif