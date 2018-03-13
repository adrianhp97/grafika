#include "Tugas1.h"


/************ FUNGSI ABSTRAKSI *************/

int clearPixeTugasSatu(char * fbp, long int location) {
    *(fbp + location) = 0;
    *(fbp + location + 1) = 0;
    *(fbp + location + 2) = 0;
    *(fbp + location + 3) = 0;    

    return 0;
}

int clearScreenTugasSatu(char * fbp, long int location) {
    int x;
    int y;

    for (y = 100; y < 300; y++) {
        for (x = 100; x < 300; x++) {
            clearPixeTugasSatu(fbp, location);
        }
    }

    return 0;
}

int paintPixelTugasSatu(char * fbp, long int location, int r, int g, int b) {

    *(fbp + location) = b;        // Some blue
    *(fbp + location + 1) = g;     // A little green
    *(fbp + location + 2) = r;    // A lot of red
    *(fbp + location + 3) = 0;      // No transparency

    return 0;
}

void makeDotTugasSatu(int matrix[MAX_MATRIX][MAX_MATRIX], int x, int y, int size) {
    int i;
    int j;

    for (i = x; i < x + size; i++) {
        for (j = y; j < y + size; j++) {
            matrix[i][j] = 1;
        }
    }
}

void printGridTugasSatu(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
    int x;
    int y;

    for (x = 0; x < 50; x++) {
        for (y = 0; y < 50; y++) {
            if (grid[x][y] == 1) {
                makeDotTugasSatu(charMatrix, x * 5, y * 5, 5);
            }
        }
    }
}

void SetTugasSatu(int** grid, int x, int y) {
    grid[x][y] = 1;
}

void clearGridTugasSatu(int** grid) {
    int x;
    int y;
	for (x = 0; x < 50; x++) {
        for (y = 0; y < 50; y++) {
            grid[x][y] = 0;
        }
    }
}

void clearMatrixTugasSatu(int charMatrix[MAX_MATRIX][MAX_MATRIX]){
    int x;
    int y;
	for (x = 0; x < MAX_MATRIX; x++) {
		for (y = 0; y < MAX_MATRIX; y++) {
			charMatrix[x][y] = 0;
		}
	}
}

/* Cukup tambahin di sini aja, range x & y antara 1 s.d. 15. Di laptopku lebih dari itu segmentation fault */

void SetTugasSatuA(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);
	SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 12);
    SetTugasSatu(grid, 10, 13);
    SetTugasSatu(grid, 11, 10);
    SetTugasSatu(grid, 11, 12);
    SetTugasSatu(grid, 12, 12);
    SetTugasSatu(grid, 13, 12);
    SetTugasSatu(grid, 14, 11);
    SetTugasSatu(grid, 14, 12);
    SetTugasSatu(grid, 14, 13);
    SetTugasSatu(grid, 13, 10);
	SetTugasSatu(grid, 12, 10);
	SetTugasSatu(grid, 14, 14);
	SetTugasSatu(grid, 10, 14);
	printGridTugasSatu(grid, charMatrix);
}

void SetTugasSatuB(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);	
	SetTugasSatu(grid, 10, 10);
    SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 12);
    SetTugasSatu(grid, 10, 13);
    SetTugasSatu(grid, 10, 14);
    
	SetTugasSatu(grid, 11, 10);
    SetTugasSatu(grid, 12, 10);
	SetTugasSatu(grid, 13, 10);
    SetTugasSatu(grid, 14, 11);
    SetTugasSatu(grid, 11, 12);
    SetTugasSatu(grid, 12, 12);
	SetTugasSatu(grid, 13, 12);	

	SetTugasSatu(grid, 14, 13);
    SetTugasSatu(grid, 13, 14);
	SetTugasSatu(grid, 12, 14);
	SetTugasSatu(grid, 11, 14);
	printGridTugasSatu(grid,charMatrix);
}

void SetTugasSatuD(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);	
	SetTugasSatu(grid, 10, 10);
    SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 12);
    SetTugasSatu(grid, 10, 13);
    SetTugasSatu(grid, 10, 14);
    
	SetTugasSatu(grid, 11, 10);
    SetTugasSatu(grid, 12, 10);
	SetTugasSatu(grid, 13, 10);
    SetTugasSatu(grid, 14, 11);
    SetTugasSatu(grid, 14, 12);
    SetTugasSatu(grid, 14, 13);	

	SetTugasSatu(grid, 13, 14);
    SetTugasSatu(grid, 12, 14);
	SetTugasSatu(grid, 11, 14);
	printGridTugasSatu(grid,charMatrix);
}

void SetTugasSatuE(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);	
	SetTugasSatu(grid, 10, 10);
    SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 12);
    SetTugasSatu(grid, 10, 13);
    SetTugasSatu(grid, 10, 14);
    
	SetTugasSatu(grid, 11, 14);
    SetTugasSatu(grid, 12, 14);
	SetTugasSatu(grid, 13, 14);
    SetTugasSatu(grid, 14, 14);

	SetTugasSatu(grid, 11, 10);
    SetTugasSatu(grid, 12, 10);
	SetTugasSatu(grid, 13, 10);
    SetTugasSatu(grid, 14, 10);

	SetTugasSatu(grid, 11, 12);
    SetTugasSatu(grid, 12, 12);
	SetTugasSatu(grid, 13, 12);

	printGridTugasSatu(grid,charMatrix);
}

void SetTugasSatuG(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);	
    SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 12);
    SetTugasSatu(grid, 10, 13);
    
	SetTugasSatu(grid, 11, 10);
    SetTugasSatu(grid, 12, 10);
	SetTugasSatu(grid, 13, 10);
	SetTugasSatu(grid, 14, 10);
    SetTugasSatu(grid, 13, 12);
    SetTugasSatu(grid, 14, 12);
    SetTugasSatu(grid, 14, 13);	
    SetTugasSatu(grid, 14, 14);	

	SetTugasSatu(grid, 13, 14);
    SetTugasSatu(grid, 12, 14);
	SetTugasSatu(grid, 11, 14);

	printGridTugasSatu(grid,charMatrix);
}

void SetTugasSatuH(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);
	SetTugasSatu(grid, 10, 10);
    SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 12);
    SetTugasSatu(grid, 10, 13);

    SetTugasSatu(grid, 11, 12);
    SetTugasSatu(grid, 12, 12);
    SetTugasSatu(grid, 13, 12);

    SetTugasSatu(grid, 14, 10);
    SetTugasSatu(grid, 14, 11);
    SetTugasSatu(grid, 14, 12);
    SetTugasSatu(grid, 14, 13);
	SetTugasSatu(grid, 14, 14);
	SetTugasSatu(grid, 10, 14);
    printGridTugasSatu(grid, charMatrix);
}

void SetTugasSatuI(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);	
	SetTugasSatu(grid, 12, 10);
    SetTugasSatu(grid, 12, 11);
    SetTugasSatu(grid, 12, 12);
    SetTugasSatu(grid, 12, 13);
    SetTugasSatu(grid, 12, 14);
    
	SetTugasSatu(grid, 10, 10);
    SetTugasSatu(grid, 11, 10);
    SetTugasSatu(grid, 13, 10);
    SetTugasSatu(grid, 14, 10);

	SetTugasSatu(grid, 10, 14);
    SetTugasSatu(grid, 11, 14);
    SetTugasSatu(grid, 13, 14);
    SetTugasSatu(grid, 14, 14);
	printGridTugasSatu(grid,charMatrix);
}

void SetTugasSatuK(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);	
	SetTugasSatu(grid, 10, 10);
    SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 12);
    SetTugasSatu(grid, 10, 13);
    SetTugasSatu(grid, 10, 14);
    
	SetTugasSatu(grid, 11, 12);
    SetTugasSatu(grid, 12, 11);
	SetTugasSatu(grid, 12, 13);
    SetTugasSatu(grid, 13, 10);
    SetTugasSatu(grid, 13, 14);
	printGridTugasSatu(grid,charMatrix);
}

void SetTugasSatuM(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);
	SetTugasSatu(grid, 10, 10);
    SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 12);
    SetTugasSatu(grid, 10, 13);
    SetTugasSatu(grid, 11, 11);
    SetTugasSatu(grid, 12, 12);
    SetTugasSatu(grid, 13, 11);
    SetTugasSatu(grid, 14, 10);
    SetTugasSatu(grid, 14, 11);
    SetTugasSatu(grid, 14, 12);
    SetTugasSatu(grid, 14, 13);
	SetTugasSatu(grid, 14, 14);
	SetTugasSatu(grid, 10, 14);
    printGridTugasSatu(grid, charMatrix);
}

void SetTugasSatuN(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);
	SetTugasSatu(grid, 10, 10);
    SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 12);
    SetTugasSatu(grid, 10, 13);
    SetTugasSatu(grid, 11, 11);
    SetTugasSatu(grid, 12, 12);
    SetTugasSatu(grid, 13, 13);
    SetTugasSatu(grid, 14, 10);
    SetTugasSatu(grid, 14, 11);
    SetTugasSatu(grid, 14, 12);
    SetTugasSatu(grid, 14, 13);
	SetTugasSatu(grid, 14, 14);
	SetTugasSatu(grid, 10, 14);
    printGridTugasSatu(grid, charMatrix);
}

void SetTugasSatuO(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);	
    SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 12);
    SetTugasSatu(grid, 10, 13);
    
	SetTugasSatu(grid, 11, 10);
    SetTugasSatu(grid, 12, 10);
	SetTugasSatu(grid, 13, 10);
    SetTugasSatu(grid, 14, 11);
    SetTugasSatu(grid, 14, 12);
    SetTugasSatu(grid, 14, 13);	

	SetTugasSatu(grid, 13, 14);
    SetTugasSatu(grid, 12, 14);
	SetTugasSatu(grid, 11, 14);
	printGridTugasSatu(grid,charMatrix);
}

void SetTugasSatuL(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);	
	SetTugasSatu(grid, 10, 10);
    SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 12);
    SetTugasSatu(grid, 10, 13);
    SetTugasSatu(grid, 10, 14);
    
	SetTugasSatu(grid, 11, 14);
    SetTugasSatu(grid, 12, 14);
	SetTugasSatu(grid, 13, 14);
    SetTugasSatu(grid, 14, 14);
	printGridTugasSatu(grid,charMatrix);
}

void SetTugasSatuR(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);	
	SetTugasSatu(grid, 10, 10);
    SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 12);
    SetTugasSatu(grid, 10, 13);
    SetTugasSatu(grid, 10, 14);
    
	SetTugasSatu(grid, 11, 10);
    SetTugasSatu(grid, 12, 10);
	SetTugasSatu(grid, 13, 10);
    SetTugasSatu(grid, 14, 11);
    SetTugasSatu(grid, 11, 12);
    SetTugasSatu(grid, 12, 12);
	SetTugasSatu(grid, 13, 12);	

	SetTugasSatu(grid, 14, 14);
    SetTugasSatu(grid, 13, 13);
	printGridTugasSatu(grid,charMatrix);
}

void SetTugasSatuS(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);	
    SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 14);
    
	SetTugasSatu(grid, 11, 14);
    SetTugasSatu(grid, 12, 14);
	SetTugasSatu(grid, 13, 14);

	SetTugasSatu(grid, 11, 10);
    SetTugasSatu(grid, 12, 10);
	SetTugasSatu(grid, 13, 10);
    SetTugasSatu(grid, 14, 10);
	SetTugasSatu(grid, 14, 13);

	SetTugasSatu(grid, 11, 12);
    SetTugasSatu(grid, 12, 12);
	SetTugasSatu(grid, 13, 12);

	printGridTugasSatu(grid,charMatrix);
}

void SetTugasSatuT(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);	
	SetTugasSatu(grid, 12, 10);
    SetTugasSatu(grid, 12, 11);
    SetTugasSatu(grid, 12, 12);
    SetTugasSatu(grid, 12, 13);
    SetTugasSatu(grid, 12, 14);
    
	SetTugasSatu(grid, 10, 10);
    SetTugasSatu(grid, 11, 10);
    SetTugasSatu(grid, 13, 10);
    SetTugasSatu(grid, 14, 10);
	printGridTugasSatu(grid,charMatrix);
}

void SetTugasSatuU(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);
	SetTugasSatu(grid, 10, 10);
    SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 12);
    SetTugasSatu(grid, 10, 13);

    SetTugasSatu(grid, 11, 14);
    SetTugasSatu(grid, 12, 14);
    SetTugasSatu(grid, 13, 14);

    SetTugasSatu(grid, 14, 10);
    SetTugasSatu(grid, 14, 11);
    SetTugasSatu(grid, 14, 12);
    SetTugasSatu(grid, 14, 13);
	SetTugasSatu(grid, 14, 14);
	SetTugasSatu(grid, 10, 14);
    printGridTugasSatu(grid, charMatrix);
}

void SetTugasSatuY(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);	
	SetTugasSatu(grid, 12, 12);
    SetTugasSatu(grid, 12, 12);
    SetTugasSatu(grid, 12, 13);
    SetTugasSatu(grid, 12, 14);
    
	SetTugasSatu(grid, 10, 10);
    SetTugasSatu(grid, 11, 11);
    SetTugasSatu(grid, 13, 11);
    SetTugasSatu(grid, 14, 10);
	printGridTugasSatu(grid,charMatrix);
}

void SetTugasSatuW(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]) {
	clearGridTugasSatu(grid);
	SetTugasSatu(grid, 10, 10);
    SetTugasSatu(grid, 10, 11);
    SetTugasSatu(grid, 10, 12);
    SetTugasSatu(grid, 10, 13);

    SetTugasSatu(grid, 12, 13);

    SetTugasSatu(grid, 14, 10);
    SetTugasSatu(grid, 14, 11);
    SetTugasSatu(grid, 14, 12);
    SetTugasSatu(grid, 14, 13);
	SetTugasSatu(grid, 13, 14);
	SetTugasSatu(grid, 11, 14);
    printGridTugasSatu(grid, charMatrix);
}

void SetTugasSatuV(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX])
{
	clearGridTugasSatu(grid);

	SetTugasSatu(grid, 10, 10);
	SetTugasSatu(grid, 10, 11);
	SetTugasSatu(grid, 11, 12);
	SetTugasSatu(grid, 11, 13);

	SetTugasSatu(grid, 12, 14);

	SetTugasSatu(grid, 13, 13);
	SetTugasSatu(grid, 13, 12);
	SetTugasSatu(grid, 14, 11);
	SetTugasSatu(grid, 14, 10);

	printGridTugasSatu(grid, charMatrix);
}

void SetTugasSatuZ(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX])
{
	clearGridTugasSatu(grid);

	SetTugasSatu(grid, 10, 10);
	SetTugasSatu(grid, 11, 10);
	SetTugasSatu(grid, 12, 10);
	SetTugasSatu(grid, 13, 10);
	SetTugasSatu(grid, 14, 10);

	SetTugasSatu(grid, 13, 11);
	SetTugasSatu(grid, 12, 12);
	SetTugasSatu(grid, 11, 13);

	SetTugasSatu(grid, 10, 14);
	SetTugasSatu(grid, 11, 14);
	SetTugasSatu(grid, 12, 14);
	SetTugasSatu(grid, 13, 14);
	SetTugasSatu(grid, 14, 14);

	printGridTugasSatu(grid, charMatrix);
}

void creditTugas()
{
    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    char *fbp = 0;
    char *backbuf = 0;
    int x = 0, y = 0, len = 0;
    long int location = 0;
    int charMatrix[MAX_MATRIX][MAX_MATRIX];
	int tugasText[7][MAX_MATRIX][MAX_MATRIX];
	int adrianText[15][MAX_MATRIX][MAX_MATRIX];
	int kukuhText[12][MAX_MATRIX][MAX_MATRIX];
int kevinText[12][MAX_MATRIX][MAX_MATRIX];
	int martinText[12][MAX_MATRIX][MAX_MATRIX];
	int rayText[10][MAX_MATRIX][MAX_MATRIX];
	int winartoText[7][MAX_MATRIX][MAX_MATRIX];    
	int** grid = (int **)malloc(50 * sizeof(int*));
	for(int i = 0; i < 50; i++) grid[i] = (int *)malloc(50 * sizeof(int));

    // Initialize Empty Matrix
	for (len = 0; len < 15; len++) {
		if(len <= 7) {
			clearMatrixTugasSatu(tugasText[len]);
			clearMatrixTugasSatu(winartoText[len]);		
		}
		if(len <= 10) {
			clearMatrixTugasSatu(rayText[len]);
		}
		if (len <= 12) {
			clearMatrixTugasSatu(martinText[len]);
clearMatrixTugasSatu(kevinText[len]);
			clearMatrixTugasSatu(kukuhText[len]);
		}
		clearMatrixTugasSatu(adrianText[len]);
	}
    // Initialize Empty Grid
    clearGridTugasSatu(grid);

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
    if (atoi(fbp) == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

    backbuf = (char *)mmap(0, screensize, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    if (atoi(backbuf) == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(5);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

    /* Cukup tambahin di sini aja, range x & y antara 1 s.d. 15. Di laptopku lebih dari itu segmentation fault */ 
	//Tugas 1
	SetTugasSatuT(grid, tugasText[0]);
	SetTugasSatuU(grid, tugasText[1]);
	SetTugasSatuG(grid, tugasText[2]);
	SetTugasSatuA(grid, tugasText[3]);
	SetTugasSatuS(grid, tugasText[4]);
	SetTugasSatuI(grid, tugasText[6]);
	//Adrian
	SetTugasSatuA(grid, adrianText[0]);
	SetTugasSatuD(grid, adrianText[1]);
	SetTugasSatuR(grid, adrianText[2]);
	SetTugasSatuI(grid, adrianText[3]);
	SetTugasSatuA(grid, adrianText[4]);
	SetTugasSatuN(grid, adrianText[5]);
	SetTugasSatuH(grid, adrianText[7]);
	SetTugasSatuA(grid, adrianText[8]);
	SetTugasSatuR(grid, adrianText[9]);
	SetTugasSatuT(grid, adrianText[10]);
	SetTugasSatuA(grid, adrianText[11]);
	SetTugasSatuR(grid, adrianText[12]);
	SetTugasSatuT(grid, adrianText[13]);
	SetTugasSatuO(grid, adrianText[14]);

	//Kevin
	SetTugasSatuK(grid, kevinText[0]);
	SetTugasSatuE(grid, kevinText[1]);
	SetTugasSatuV(grid, kevinText[2]);
	SetTugasSatuI(grid, kevinText[3]);
	SetTugasSatuN(grid, kevinText[4]);

	SetTugasSatuE(grid, kevinText[6]);
	SetTugasSatuR(grid, kevinText[7]);
	SetTugasSatuD(grid, kevinText[8]);
	SetTugasSatuI(grid, kevinText[9]);
	SetTugasSatuZ(grid, kevinText[10]);
	SetTugasSatuA(grid, kevinText[11]);

	//Kukuh
	SetTugasSatuK(grid, kukuhText[0]);	
	SetTugasSatuU(grid, kukuhText[1]);	
	SetTugasSatuK(grid, kukuhText[2]);	
	SetTugasSatuU(grid, kukuhText[3]);	
	SetTugasSatuH(grid, kukuhText[4]);	
	SetTugasSatuB(grid, kukuhText[6]);	
	SetTugasSatuA(grid, kukuhText[7]);	
	SetTugasSatuS(grid, kukuhText[8]);	
	SetTugasSatuU(grid, kukuhText[9]);	
	SetTugasSatuK(grid, kukuhText[10]);	
	SetTugasSatuI(grid, kukuhText[11]);	


	//Martin
	SetTugasSatuM(grid, martinText[0]);
	SetTugasSatuA(grid, martinText[1]);
	SetTugasSatuR(grid, martinText[2]);
	SetTugasSatuT(grid, martinText[3]);
	SetTugasSatuI(grid, martinText[4]);
	SetTugasSatuN(grid, martinText[5]);
	SetTugasSatuL(grid, martinText[7]);
	SetTugasSatuU(grid, martinText[8]);
	SetTugasSatuT(grid, martinText[9]);
	SetTugasSatuT(grid, martinText[10]);
	SetTugasSatuA(grid, martinText[11]);
	
	//Ray Andrew
	SetTugasSatuR(grid, rayText[0]);
	SetTugasSatuA(grid, rayText[1]);
	SetTugasSatuY(grid, rayText[2]);
	SetTugasSatuA(grid, rayText[4]);
	SetTugasSatuN(grid, rayText[5]);
	SetTugasSatuD(grid, rayText[6]);
	SetTugasSatuR(grid, rayText[7]);
	SetTugasSatuE(grid, rayText[8]);
	SetTugasSatuW(grid, rayText[9]);

	//Winarto
	SetTugasSatuW(grid, winartoText[0]);
	SetTugasSatuI(grid, winartoText[1]);
	SetTugasSatuN(grid, winartoText[2]);
	SetTugasSatuA(grid, winartoText[3]);
	SetTugasSatuR(grid, winartoText[4]);
	SetTugasSatuT(grid, winartoText[5]);
	SetTugasSatuO(grid, winartoText[6]);

    // Loop forever
    //while(1) {
	
	int i,charLen;
	for(i = vinfo.yres; i > -3*MAX_MATRIX*1.5; i=i-4) {
        for (y = 0; y < 600; y++){
			int yPosition = (y+i+vinfo.yoffset);
			//printf("yPos = %d\n", yPosition);
			if(yPosition < vinfo.yres-5){	        
				for (x = 0; x < 1000; x++) {
		            location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
		                        (yPosition) * finfo.line_length;
		            clearPixeTugasSatu(backbuf, location);
		        }
			}
		}
        for (y = 0; y < MAX_MATRIX; y++){
			int yPosition = (y+i+vinfo.yoffset);
			//Print tugas I
			if(yPosition < vinfo.yres-5) {		
				for (charLen = 0; charLen < 7; charLen++) {
				    for (x = 400; x < 400+MAX_MATRIX; x++) {
				        location = ((charLen * 30) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition) * finfo.line_length;
				        if (tugasText[charLen][x-400][y] == 1) {
				            paintPixelTugasSatu(backbuf, location, 255, 255, 255);
				        }
				    }
				}
			}

			//Print Nama Adrian
			if(yPosition+50 < vinfo.yres-5) {		
				for (charLen = 0; charLen < 15; charLen++) {
				    for (x = 300; x < 300+MAX_MATRIX; x++) {
				        location = ((charLen * 30) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+50) * finfo.line_length;
				        if (adrianText[charLen][x-300][y] == 1) {
				            paintPixelTugasSatu(backbuf, location, 200, 20, 20);
				        }
				    }
				}
			}						

			//Print Nama Kukuh
			if(yPosition+100 < vinfo.yres-5) {		
				for (charLen = 0; charLen < 12; charLen++) {
				    for (x = 300; x < 300+MAX_MATRIX; x++) {
				        location = ((charLen * 30) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+100) * finfo.line_length;
				        if (kukuhText[charLen][x-300][y] == 1) {
				            paintPixelTugasSatu(backbuf, location, 200, 140, 100);
				        }
				    }
				}
			}

			//Print Nama Kevin
			if(yPosition+150 < vinfo.yres-5) {		
				for (charLen = 0; charLen < 12; charLen++) {
				    for (x = 300; x < 300+MAX_MATRIX; x++) {
				        location = ((charLen * 30) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+150) * finfo.line_length;
				        if (kevinText[charLen][x-300][y] == 1) {
				            paintPixelTugasSatu(backbuf, location, 200, 140, 100);
				        }
				    }
				}
			}

			//Print Nama Martin	
			if(yPosition+200 < vinfo.yres-5) {		
				for (charLen = 0; charLen < 12; charLen++) {
				    for (x = 300; x < 300+MAX_MATRIX; x++) {
				        location = ((charLen * 30) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+200) * finfo.line_length;
				        if (martinText[charLen][x-300][y] == 1) {
				            paintPixelTugasSatu(backbuf, location, 100, 150, 150);
				        }
				    }
				}
			}

			//Print Nama Ray
			if(yPosition+250 < vinfo.yres-5) {			
				for (charLen = 0; charLen < 10; charLen++) {
				    for (x = 300; x < 300+MAX_MATRIX; x++) {
				        location = ((charLen * 30) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition + 250) * finfo.line_length;
				        if (rayText[charLen][x-300][y] == 1) {
				            paintPixelTugasSatu(backbuf, location, 80, 140, 200);
				        }
				    }
				}
			}
			
			//Print Nama Winarto
			if(yPosition+300 < vinfo.yres-5) {		
				for (charLen = 0; charLen < 7; charLen++) {
				    for (x = 300; x < 300+MAX_MATRIX; x++) {
				        location = ((charLen * 30) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+300) * finfo.line_length;
				        if (winartoText[charLen][x-300][y] == 1) {
				            paintPixelTugasSatu(backbuf, location, 135, 180, 100);
				        }
				    }
				}
			}
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
}
