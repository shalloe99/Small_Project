#include <iostream>
#include <fstream>
#include <cmath>
#include "functions.h"
using namespace std;
int colorPath(const int elevations[MAX_ROWS][MAX_COLS], Pixel image[MAX_ROWS][MAX_COLS], int rows, int cols, Pixel color, int start_row){
		int	rowsN = 0;
		int rowsE = 0;
		int rowsS = 0;
		int elevation = 0;
		int steps = 0;
		for(int j = 0;j< cols-1;j++){
			image[start_row][j] = color;
//			cout<<"rows---"<<start_row<<endl;
//			cout<<"cols---"<<j<<endl;
			rowsN = start_row-1;
			if (rowsN < 0) rowsN = start_row;
			rowsE = start_row;
			rowsS = start_row+1;
			if (rowsN > rows) rowsN = start_row;
			int ElevationN = abs(elevations[rowsN][j+1] - elevations[start_row][j]);
			int ElevationE = abs(elevations[rowsE][j+1] - elevations[start_row][j]);
			int ElevationS = abs(elevations[rowsS][j+1] - elevations[start_row][j]);
			if(ElevationE <= ElevationN and ElevationE <=ElevationS){
					start_row = rowsE; // East is easier
					elevation = ElevationE;
			}else if(ElevationS <= ElevationN and ElevationS <=ElevationE){
				start_row = rowsS; // South is easier
				elevation = ElevationS;
			}else {//if(ElevationN <= ElevationE and ElevationN <=ElevationS)
				start_row = rowsN; // North is easier
				elevation = ElevationN;
			}
			steps += elevation;
		}
		image[start_row][cols-1] = color;
		return steps;
}

void findMaxMin(const int elevations[MAX_ROWS][MAX_COLS], int rows, int cols, int& max, int& min) {
	max = elevations[0][0];
	min = elevations[0][0];
	for (int i = 0; i <rows;i++){
		for (int j = 0; j <cols;j++){
				if(elevations[i][j]>max){
					max = elevations[i][j];
				}
				if(elevations[i][j]<min){
					min = elevations[i][j];
				}

			}
		}
}

void loadData(int elevations[MAX_ROWS][MAX_COLS], int rows, int cols, istream& inData) {
	int temp;
	if(inData.good()){
		for (int i = 0; i <rows;i++){
			for (int j = 0; j <cols;j++){
				inData >> temp;
				elevations[i][j] = temp;
			}
		}
	}
}

int scaleValue(int value, int max, int min) {
	int result = round(255.0*(value-min)/(max-min));
    return result;
}

void loadGreyscale(Pixel image[MAX_ROWS][MAX_COLS], const int elevations[MAX_ROWS][MAX_COLS], 
                    int rows, int cols, int max, int min){
	for (int i = 0; i <rows;i++){
			for (int j = 0; j <cols;j++){
					Pixel pixel;
					pixel.red = scaleValue(elevations[i][j],max,min);
					pixel.green = scaleValue(elevations[i][j],max,min);
					pixel.blue = scaleValue(elevations[i][j],max,min);
					image[i][j] = pixel;
			 }
			}
}

void outputImage(const Pixel image[MAX_ROWS][MAX_COLS], int rows, int cols, ostream& outData) {
	outData << "P3\n";
	outData << cols <<" "<<rows<<"\n";
	outData << 255<<"\n";
	for (int i = 0; i <rows;i++){
		for (int j = 0; j <cols-1;j++){
			outData<<image[i][j].red<<" "<<image[i][j].green<<" "<<image[i][j].blue<<" ";
		}
		outData<<image[i][cols-1].red<<" "<<image[i][cols-1].green<<" "<<image[i][cols-1].blue<<"\n";
	}
}

