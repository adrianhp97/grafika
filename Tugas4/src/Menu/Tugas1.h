#define MAX_MATRIX 100

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

/************ FUNGSI ABSTRAKSI *************/

int clearPixeTugasSatu(char * fbp, long int location);

int clearScreenTugasSatu(char * fbp, long int location);

int paintPixelTugasSatu(char * fbp, long int location, int r, int g, int b);

void makeDotTugasSatu(int matrix[MAX_MATRIX][MAX_MATRIX], int x, int y, int size);

void printGridTugasSatu(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);

void SetTugasSatu(int** grid, int x, int y);

void clearGridTugasSatu(int** grid);

void clearMatrixTugasSatu(int charMatrix[MAX_MATRIX][MAX_MATRIX]);

/* Cukup tambahin di sini aja, range x & y antara 1 s.d. 15. Di laptopku lebih dari itu segmentation fault */

void SetTugasSatuA(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);

void SetTugasSatuB(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);
void SetTugasSatuD(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);

void SetTugasSatuE(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);

void SetTugasSatuG(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);
void SetTugasSatuH(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);
void SetTugasSatuI(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);
void SetTugasSatuK(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);

void SetTugasSatuM(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);
void SetTugasSatuN(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);

void SetTugasSatuO(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);
void SetTugasSatuL(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);
void SetTugasSatuR(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);

void SetTugasSatuS(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);
void SetTugasSatuT(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);

void SetTugasSatuU(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);
void SetTugasSatuY(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);
void SetTugasSatuW(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);

void SetTugasSatuV(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);

void SetTugasSatuZ(int** grid, int charMatrix[MAX_MATRIX][MAX_MATRIX]);

void creditTugas();
