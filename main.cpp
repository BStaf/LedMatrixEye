#include <iostream>
#include <bitset>
#include "Animation.h"
#include "Animation.cpp"
#include "AnimationSetup.h"

using namespace std;


void printBLine(byte val){
	cout << std::bitset<8>(val)<< endl;
}

void printAr(byte *  matrix){
	for (int i=0;i<8;i++){
		printBLine(matrix[i]);
	}
}
int main(){
	Animation * n = new Animation(openEyeMatrixCnt, openEyeMatrix, 0, 1);
	cout << "Hellow World!" << endl;
	for (int i=0; i<openEyeMatrixCnt;i++){
		n->CurMS = i+1;
		n->Update();
		printAr(n->CurrentViewMatrix);
		cout <<  endl;
	}
	return 0;
}

