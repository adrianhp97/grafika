#include <iostream>

using namespace std;

#ifndef MATRIKS_H
#define MATRIKS_H

class Matriks {
	public:
		//ctor, cctor, dtor, operator=
		Matriks();
		Matriks(int);
		Matriks(const Matriks&);
		~Matriks();
		Matriks& operator=(const Matriks&);

		//getter, setter
		int getNbElmnt();
		char getDataAt(int, int);
		void setNbElmnt(int);
		void setDataAt(int, int, int);

		//method
		void printMatriks();

	protected:
		char** dataMatriks;
		int nbElmnt;
};

#endif