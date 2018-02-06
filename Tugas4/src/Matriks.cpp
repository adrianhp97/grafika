#include "Matriks.h"

Matriks::Matriks() {
	
}

Matriks::Matriks(int rowColumn) {
	dataMatriks = new char*[rowColumn];
	for (int idx = 0; idx < rowColumn; idx++) {
		dataMatriks[idx] = new char[rowColumn];
	}
	nbElmnt = rowColumn;
}

Matriks::Matriks(const Matriks& matriksDifferent) {
	dataMatriks = new char*[matriksDifferent.nbElmnt];
	for (int idx = 0; idx < matriksDifferent.nbElmnt; idx++) {
		dataMatriks[idx] = new char[matriksDifferent.nbElmnt];
	}
	for (int idxRow = 0; idxRow < matriksDifferent.nbElmnt; idxRow++) {
		for (int idxCol = 0; idxCol < matriksDifferent.nbElmnt; idxCol++) {
			dataMatriks[idxRow][idxCol] = matriksDifferent.dataMatriks[idxRow][idxCol];
		}
	}
	nbElmnt = matriksDifferent.nbElmnt;
}

Matriks::~Matriks() {
	for (int idx = 0; idx < nbElmnt; idx++) {
		delete [] dataMatriks[idx];
	}
	delete [] dataMatriks;
}

Matriks& Matriks::operator=(const Matriks& matriksDifferent) {
	for (int idx = 0; idx < nbElmnt; idx++) {
		delete [] dataMatriks[idx];
	}
	delete [] dataMatriks;

	dataMatriks = new char*[matriksDifferent.nbElmnt];
	for (int idx = 0; idx < matriksDifferent.nbElmnt; idx++) {
		dataMatriks[idx] = new char[matriksDifferent.nbElmnt];
	}
	for (int idxRow = 0; idxRow < matriksDifferent.nbElmnt; idxRow++) {
		for (int idxCol = 0; idxCol < matriksDifferent.nbElmnt; idxCol++) {
			dataMatriks[idxRow][idxCol] = matriksDifferent.dataMatriks[idxRow][idxCol];
		}
	}
	nbElmnt = matriksDifferent.nbElmnt;

	return *this;
}

void Matriks::printMatriks() {
	for (int idxRow = 0; idxRow < nbElmnt; idxRow++) {
		if (idxRow == 0) {
			for(int idx = 0; idx < nbElmnt + 2; idx++) {
				cout << "-";
			}
			cout << endl;
		}
		for (int idxCol = 0; idxCol < nbElmnt; idxCol++) {
			if (idxCol == 0) {
				cout << "|";
			}
			cout << dataMatriks[idxRow][idxCol];
			if (idxCol == nbElmnt - 1) {
				cout << "|";
			}
		}
		if (idxRow == nbElmnt - 1) {
			cout << endl;
			for(int idx = 0; idx < nbElmnt + 2; idx++) {
				cout << "-";
			}
		}
		cout << endl;
	}
}

int Matriks::getNbElmnt() {
	return nbElmnt;
}

char Matriks::getDataAt(int row, int col) {
	return dataMatriks[row][col];
}

void Matriks::setNbElmnt(int value) {
	nbElmnt = value;
}

void Matriks::setDataAt(int row, int col, int value) {
	dataMatriks[row][col] = value;
}