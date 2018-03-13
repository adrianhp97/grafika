/*
	Tugas 1 Grafika
	Kevin Erdiza Yogatama 	- 13515016
	Kukuh Basuki			- 13515025
	Winarto					- 13515061
	Ray Andrew				- 13515073
	Adrian Hartarto			- 13515091
	Martin Lutta			- 13515121
*/

#define MAX_MTX 100
#define LETTER_SPACING 51
#define LINE_SPACING 70
#define X_POS 10

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <termios.h>

int shoot = 0;

/************ FUNGSI ABSTRAKSI *************/

int clearPixel(char * fbp, long int location) {
    *(fbp + location) = 0;
    *(fbp + location + 1) = 0;
    *(fbp + location + 2) = 0;
    *(fbp + location + 3) = 0;    

    return 0;
}

int clearScreen(char * fbp, long int location) {
    int x;
    int y;

    for (y = 100; y < 300; y++) {
        for (x = 100; x < 300; x++) {
            clearPixel(fbp, location);
        }
    }

    return 0;
}

int paintPixel(char * fbp, long int location, int r, int g, int b) {

    *(fbp + location) = b;        // Some blue
    *(fbp + location + 1) = g;     // A little green
    *(fbp + location + 2) = r;    // A lot of red
    *(fbp + location + 3) = 0;      // No transparency

    return 0;
}

void makeDot(int matrix[MAX_MTX][MAX_MTX], int x, int y, int size) {
    int i;
    int j;

    for (i = x; i < x + size; i++) {
        for (j = y; j < y + size; j++) {
            matrix[i][j] = 1;
        }
    }
}

void printGrid(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
    int x;
    int y;

    for (x = 0; x < 50; x++) {
        for (y = 0; y < 50; y++) {
            if (grid[x][y] == 1) {
                makeDot(charMatrix, x * 1, y * 1, 1);
            }
        }
    }
}

void Set(int grid[50][50], int x, int y) {
    grid[x][y] = 1;
}

void SetLine(int grid[50][50], int x0, int y0, int x1, int y1) {
   	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
  	int err = (dx>dy ? dx : -dy)/2, e2;

 	for(;;){
    	grid[x0][y0] = 1;
    	if (x0==x1 && y0==y1) 
			break;
    	e2 = err;
    	if (e2 >-dx) { err -= dy; x0 += sx; }
    	if (e2 < dy) { err += dx; y0 += sy; }
	}
}

void clearGrid(int grid[50][50]) {
    int x;
    int y;
	for (x = 0; x < 50; x++) {
        for (y = 0; y < 50; y++) {
            grid[x][y] = 0;
        }
    }
}

void clearMatrix(int charMatrix[MAX_MTX][MAX_MTX]){
    int x;
    int y;
	for (x = 0; x < MAX_MTX; x++) {
		for (y = 0; y < MAX_MTX; y++) {
			charMatrix[x][y] = 0;
		}
	}
}

/* Cukup tambahin di sini aja, range x & y antara 1 s.d. 15. Di laptopku lebih dari itu segmentation fault */

void Set2(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 19, 1, 49, 1);
	SetLine(grid, 28, 1, 9, 49);
	SetLine(grid, 42, 1, 23, 49);
	SetLine(grid, 1, 49, 30, 49);
	printGrid(grid,charMatrix);
	printGrid(grid, charMatrix);
}

void SetA(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 49, 25, 1);
	SetLine(grid, 25, 1, 49, 49);
	SetLine(grid, 13, 25, 37, 25);
	printGrid(grid, charMatrix);
}

void SetB(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);	
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 1, 49, 13);
	SetLine(grid, 49, 13, 1, 25);
	SetLine(grid, 1, 25, 49, 37);
	SetLine(grid, 49, 37, 1, 49);
	printGrid(grid,charMatrix);
}

void SetD(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);	
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 1, 49, 25);
	SetLine(grid, 49, 25, 1, 49);
	printGrid(grid,charMatrix);
}

void SetE(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);	
	SetLine(grid, 1, 1, 49, 1);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 49, 49, 49);
	SetLine(grid, 1, 25, 37, 25);

	printGrid(grid,charMatrix);
}

void SetG(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);	
    SetLine(grid, 1, 1, 49, 1);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 49, 49, 49);
	SetLine(grid, 49, 49, 49, 25);
	SetLine(grid, 30, 25, 49, 25);

	printGrid(grid,charMatrix);
}

void SetH(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 25, 49, 25);
	SetLine(grid, 49, 1, 49, 49);
    printGrid(grid, charMatrix);
}

void SetI(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);	
	SetLine(grid, 1, 1, 49, 1);
	SetLine(grid, 25, 1, 25, 49);
	SetLine(grid, 1, 49, 49, 49);
	printGrid(grid,charMatrix);
}

void SetK(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);	
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 25, 49, 1);
	SetLine(grid, 1, 25, 49, 49);
	printGrid(grid,charMatrix);
}

void SetM(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 1, 25, 20);
	SetLine(grid, 25, 20, 49, 1);
	SetLine(grid, 49, 1, 49, 49);
	
    printGrid(grid, charMatrix);
}

void SetN(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 1, 49, 49);
	SetLine(grid, 49, 49, 49, 1);
    printGrid(grid, charMatrix);
}

void SetO(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);	
    SetLine(grid, 1, 25, 25, 1);
	SetLine(grid, 25, 1, 49, 25);
	SetLine(grid, 49, 25, 25, 49);
	SetLine(grid, 1, 25, 25, 49);
	printGrid(grid,charMatrix);
}

void SetL(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);	
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 49, 49, 49);

	printGrid(grid,charMatrix);
}

void SetR(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);	
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 1, 40, 15);
	SetLine(grid, 40, 15, 1, 30);
	SetLine(grid, 1, 30, 49, 49);

	printGrid(grid,charMatrix);
}

void SetS(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);	
    SetLine(grid, 1, 1, 49, 1);
	SetLine(grid, 1, 1, 1, 25);
	SetLine(grid, 1, 25, 49, 25);
	SetLine(grid, 49, 25, 49, 49);
	SetLine(grid, 1, 49, 49, 49);

	printGrid(grid,charMatrix);
}

void SetT(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);	
	SetLine(grid, 1, 1, 49, 1);
	SetLine(grid, 25, 1, 25, 49);

	printGrid(grid,charMatrix);
}

void SetU(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 49, 1, 49, 49);
	SetLine(grid, 1, 49, 49, 49);
    printGrid(grid, charMatrix);
}

void SetY(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);	
	SetLine(grid, 1, 1, 25, 20);
	SetLine(grid, 25, 20, 49, 1);
	SetLine(grid, 25, 20, 25, 49);
	printGrid(grid,charMatrix);
}

void SetW(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 13, 49);
	SetLine(grid, 13, 49, 25, 27);
	SetLine(grid, 25, 27, 37, 49);
	SetLine(grid, 37, 49, 49, 1);
    printGrid(grid, charMatrix);
}

void SetV(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX])
{
	clearGrid(grid);

	SetLine(grid, 1, 1, 25, 49);
	SetLine(grid, 25, 49, 49, 1);

	printGrid(grid, charMatrix);
}

void SetV2(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX])
{
	clearGrid(grid);

	SetLine(grid, 1, 25, 49, 1);
	SetLine(grid, 1, 25, 49, 49);
	SetLine(grid, 49, 1, 25, 25);
	SetLine(grid, 49, 49, 25, 25);
	printGrid(grid, charMatrix);
}

void SetBullet(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX])
{
	clearGrid(grid);

	SetLine(grid, 13, 20, 25, 1);
	SetLine(grid, 25, 1, 37, 20);
	SetLine(grid, 13, 20, 13, 49);
	SetLine(grid, 37, 20, 37, 49);
	SetLine(grid, 13, 49, 37, 49);
	printGrid(grid, charMatrix);
}

void SetZ(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX])
{
	clearGrid(grid);

	SetLine(grid, 1, 1, 49, 1);
	SetLine(grid, 49, 1, 1, 49);
	SetLine(grid, 1, 49, 49, 49);

	printGrid(grid, charMatrix);
}


//RENDER 
//void *renderPlane(void *vargp);

//TULIS KODE FITUR PELURU DI SINI
void *renderer2(void *vargp) {
	for(;;){	
		char c = getchar();
		if (c) {
			shoot = 1;		
		}
	}
}

/*****************************************************************/
/* Cukup ubah di bagian Set aja kalau mau nyetak huruf           */
/*****************************************************************/
//Jadiin global untuk share sesama thread
    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    char *fbp = 0;
    char *backbuf = 0;
    int x = 0, y = 0, len = 0;
    long int location = 0;
    int charMatrix[MAX_MTX][MAX_MTX];
	int tugasText[7][MAX_MTX][MAX_MTX];
	int adrianText[15][MAX_MTX][MAX_MTX];
	int kukuhText[12][MAX_MTX][MAX_MTX];
	int kevinText[12][MAX_MTX][MAX_MTX];
	int martinText[12][MAX_MTX][MAX_MTX];
	int rayText[10][MAX_MTX][MAX_MTX];
	int winartoText[7][MAX_MTX][MAX_MTX];
	int plane[MAX_MTX][MAX_MTX];    
	int grid[50][50];
	int bullet[MAX_MTX][MAX_MTX];
	int offsetSet = 0;
	int offset = 0;

int main()
{
	//For player input
	pthread_t tid, tplane;

	struct termios info;
	tcgetattr(0, &info);          /* get current terminal attirbutes; 0 is the file descriptor for stdin */
	info.c_lflag &= ~ICANON;      /* disable canonical mode */
	info.c_cc[VMIN] = 1;          /* wait until at least one keystroke available */
	info.c_cc[VTIME] = 0;         /* no timeout */
	tcsetattr(0, TCSANOW, &info); /* set immediately */
	pthread_create(&tid, NULL, renderer2, NULL);


    // Initialize Empty Matrix
	for (len = 0; len < 15; len++) {
		if(len <= 7) {
			clearMatrix(tugasText[len]);
			clearMatrix(winartoText[len]);		
		}
		if(len <= 10) {
			clearMatrix(rayText[len]);
		}
		if (len <= 12) {
			clearMatrix(martinText[len]);
clearMatrix(kevinText[len]);
			clearMatrix(kukuhText[len]);
		}
		clearMatrix(adrianText[len]);
	}
    // Initialize Empty Grid
    clearGrid(grid);

    // Open the file for reading and writing
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Figure out the size of the screen in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;


    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((int)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

    backbuf = (char *)mmap(0, screensize, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    if ((int)backbuf == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(5);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

    /* Cukup tambahin di sini aja, range x & y antara 1 s.d. 15. Di laptopku lebih dari itu segmentation fault */ 
	
	//Bullet
	SetBullet(grid, bullet);
	//Plane
	SetV2(grid, plane);
	//Tugas 1
	SetT(grid, tugasText[0]);
	SetU(grid, tugasText[1]);
	SetG(grid, tugasText[2]);
	SetA(grid, tugasText[3]);
	SetS(grid, tugasText[4]);
	Set2(grid, tugasText[6]);
	//Adrian
	SetA(grid, adrianText[0]);
	SetD(grid, adrianText[1]);
	SetR(grid, adrianText[2]);
	SetI(grid, adrianText[3]);
	SetA(grid, adrianText[4]);
	SetN(grid, adrianText[5]);
	SetH(grid, adrianText[7]);
	SetA(grid, adrianText[8]);
	SetR(grid, adrianText[9]);
	SetT(grid, adrianText[10]);
	SetA(grid, adrianText[11]);
	SetR(grid, adrianText[12]);
	SetT(grid, adrianText[13]);
	SetO(grid, adrianText[14]);

	//Kevin
	SetK(grid, kevinText[0]);
	SetE(grid, kevinText[1]);
	SetV(grid, kevinText[2]);
	SetI(grid, kevinText[3]);
	SetN(grid, kevinText[4]);

	SetE(grid, kevinText[6]);
	SetR(grid, kevinText[7]);
	SetD(grid, kevinText[8]);
	SetI(grid, kevinText[9]);
	SetZ(grid, kevinText[10]);
	SetA(grid, kevinText[11]);

	//Kukuh
	SetK(grid, kukuhText[0]);	
	SetU(grid, kukuhText[1]);	
	SetK(grid, kukuhText[2]);	
	SetU(grid, kukuhText[3]);	
	SetH(grid, kukuhText[4]);	
	SetB(grid, kukuhText[6]);	
	SetA(grid, kukuhText[7]);	
	SetS(grid, kukuhText[8]);	
	SetU(grid, kukuhText[9]);	
	SetK(grid, kukuhText[10]);	
	SetI(grid, kukuhText[11]);	


	//Martin
	SetM(grid, martinText[0]);
	SetA(grid, martinText[1]);
	SetR(grid, martinText[2]);
	SetT(grid, martinText[3]);
	SetI(grid, martinText[4]);
	SetN(grid, martinText[5]);
	SetL(grid, martinText[7]);
	SetU(grid, martinText[8]);
	SetT(grid, martinText[9]);
	SetT(grid, martinText[10]);
	SetA(grid, martinText[11]);
	
	//Ray Andrew
	SetR(grid, rayText[0]);
	SetA(grid, rayText[1]);
	SetY(grid, rayText[2]);
	SetA(grid, rayText[4]);
	SetN(grid, rayText[5]);
	SetD(grid, rayText[6]);
	SetR(grid, rayText[7]);
	SetE(grid, rayText[8]);
	SetW(grid, rayText[9]);

	//Winarto
	SetW(grid, winartoText[0]);
	SetI(grid, winartoText[1]);
	SetN(grid, winartoText[2]);
	SetA(grid, winartoText[3]);
	SetR(grid, winartoText[4]);
	SetT(grid, winartoText[5]);
	SetO(grid, winartoText[6]);

    // Loop forever
    //while(1) {
	//pthread_create(&tplane, NULL, renderPlane, NULL);
	int i,charLen;
	for(i = vinfo.yres; i > -3*MAX_MTX*1.8; i=i-4) {
        for (y = -768; y < 600; y++){
			int yPosition = (y+i+vinfo.yoffset);
			//printf("yPos = %d\n", yPosition);
			if(yPosition < vinfo.yres-5){	        
				for (x = 0; x < 1366; x++) {
		            location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
		                        (yPosition) * finfo.line_length;
		            clearPixel(backbuf, location);
		        }
			}
		}
        for (y = 0; y < MAX_MTX; y++){
			int yPosition = (y+i+vinfo.yoffset);
			if(shoot) {
				if(!offsetSet) {
					offset = i;
					offsetSet = 1;
					printf("%d", offset);
				}
				//printf("%d", offset);
				int bulletY = y+(i*2)+vinfo.yoffset + (vinfo.yres - offset * 2);
				if(bulletY < vinfo.yres-5) {		
				   	for (x = 850; x < MAX_MTX+850; x++) {
				        location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (bulletY) * finfo.line_length;
				        if (bullet[x-850][y] == 1) {
				            paintPixel(backbuf, location, 255, 255, 255);
				        }
				    }
			}
			}			
			if(yPosition < vinfo.yres-5) {		
				   	for (x = 0; x < MAX_MTX; x++) {
				        location = (x + i + 598 + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (y + vinfo.yoffset) * finfo.line_length;
				        if (plane[x][y] == 1) {
				            paintPixel(backbuf, location, 255, 255, 255);
				        }
				    }
			}
			//Print tugas I
			if(yPosition < vinfo.yres-5) {		
				for (charLen = 0; charLen < 7; charLen++) {
				    for (x = X_POS+100; x < X_POS+100+MAX_MTX; x++) {
				        location = ((charLen * LETTER_SPACING) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition) * finfo.line_length;
				        if (tugasText[charLen][x-X_POS-100][y] == 1) {
				            paintPixel(backbuf, location, 255, 255, 255);
				        }
				    }
				}
			}

			//Print Nama Adrian
			if(yPosition+LINE_SPACING < vinfo.yres-5) {		
				for (charLen = 0; charLen < 15; charLen++) {
				    for (x = X_POS; x < X_POS+MAX_MTX; x++) {
				        location = ((charLen * LETTER_SPACING) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+LINE_SPACING) * finfo.line_length;
				        if (adrianText[charLen][x-X_POS][y] == 1) {
				            paintPixel(backbuf, location, 200, 20, 20);
				        }
				    }
				}
			}						

			//Print Nama Kukuh
			if(yPosition+2*LINE_SPACING < vinfo.yres-5) {		
				for (charLen = 0; charLen < 12; charLen++) {
				    for (x = X_POS; x < X_POS+MAX_MTX; x++) {
				        location = ((charLen * LETTER_SPACING) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+2*LINE_SPACING) * finfo.line_length;
				        if (kukuhText[charLen][x-X_POS][y] == 1) {
				            paintPixel(backbuf, location, 200, 140, 100);
				        }
				    }
				}
			}

			//Print Nama Kevin
			if(yPosition+3*LINE_SPACING < vinfo.yres-5) {		
				for (charLen = 0; charLen < 12; charLen++) {
				    for (x = X_POS; x < X_POS+MAX_MTX; x++) {
				        location = ((charLen * LETTER_SPACING) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+3*LINE_SPACING) * finfo.line_length;
				        if (kevinText[charLen][x-X_POS][y] == 1) {
				            paintPixel(backbuf, location, 200, 140, 100);
				        }
				    }
				}
			}

			//Print Nama Martin	
			if(yPosition+4*LINE_SPACING < vinfo.yres-5) {		
				for (charLen = 0; charLen < 12; charLen++) {
				    for (x = X_POS; x < X_POS+MAX_MTX; x++) {
				        location = ((charLen * LETTER_SPACING) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+4*LINE_SPACING) * finfo.line_length;
				        if (martinText[charLen][x-X_POS][y] == 1) {
				            paintPixel(backbuf, location, 100, 150, 150);
				        }
				    }
				}
			}

			//Print Nama Ray
			if(yPosition+5*LINE_SPACING < vinfo.yres-5) {			
				for (charLen = 0; charLen < 10; charLen++) {
				    for (x = X_POS; x < X_POS+MAX_MTX; x++) {
				        location = ((charLen * LETTER_SPACING) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition + 5*LINE_SPACING) * finfo.line_length;
				        if (rayText[charLen][x-X_POS][y] == 1) {
				            paintPixel(backbuf, location, 80, 140, 200);
				        }
				    }
				}
			}
			
			//Print Nama Winarto
			if(yPosition+6*LINE_SPACING < vinfo.yres-5) {		
				for (charLen = 0; charLen < 7; charLen++) {
				    for (x = X_POS; x < X_POS+MAX_MTX; x++) {
				        location = ((charLen * LETTER_SPACING) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+6*LINE_SPACING) * finfo.line_length;
				        if (winartoText[charLen][x-X_POS][y] == 1) {
				            paintPixel(backbuf, location, 135, 180, 100);
				        }
				    }
				}
			}
		usleep(500);		
		}
        
	
		int copy;
		for (copy=0;copy<screensize;copy++)
		{
			((char *)(fbp))[copy] = backbuf[copy];
		}
       //sleep(1);
    }
    munmap(fbp, screensize);
    close(fbfd);
	pthread_join(tid, NULL);
	//pthread_join(tplane, NULL);
    return 0;
}

/*void *renderPlane(void *vargp) {
	int i, charLen;
	for(i = vinfo.xres; i > 0; i++) {
		for (y = 0; y < MAX_MTX; y++){
			//if(yPosition < vinfo.yres-5) {		
				   	for (x = 0; x < MAX_MTX; x++) {
				        location = (x + i + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (y + vinfo.yoffset) * finfo.line_length;
				        if (plane[x][y] == 1) {
				            paintPixel(backbuf, location, 255, 255, 255);
				        }
				    }
			//}
		}
	usleep(5000);	
	}
}*/
