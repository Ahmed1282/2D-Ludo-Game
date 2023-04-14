//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
//#include "Board.h"
#include "util.h"
#include <iostream>
#include<cstdlib>//for random
#include<string>
#include<ctime> // for random time(null)
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

int number=0;//save the number of dice
int homegoti[16]; //goti is in home
int wongoti[16]; //goti win have completed the game
int xposition[16];  //to save x cordinate of Goti
int yposition[16];  //to save y cordinate of Goti
int dice_num=0 ;//Dice number
int turn = 0; //TURN of player
bool press = false;
int xcord[72] = /* all x cordinate position of the board*/ {260,300,340,260,300,340,260,300,340,260,300,340,260,300,340,260,300,340,20,20,20,60,60,60,100,100,100,140,140,140,180,180,180,220,220,220,260,260,260,260,260,260,300,300,300,300,300,300,340,340,340,340,340,340,380,380,380,420,420,420,460,460,460,500,500,500,540,540,540,580,580,580};

int ycord[72] =/* all y cordinate position of the board*/ {20,20,20,60,60,60,100,100,100,140,140,140,180,180,180,220,220,220,260,300,340,260,300,340,260,300,340,260,300,340,260,300,340,260,300,340,380,380,380,420,420,420,460,460,460,500,500,500,540,540,540,580,580,580,260,300,340,260,300,340,260,300,340,260,300,340,260,300,340,260,300,340};

int redxcord[56];//all x cordinate of red
int redycord[56];//all y cordinate of red
int bluexcord[56];//all x cordinate of blue
int blueycord[56];//all y cordinate of blue
int yellowxcord[56];//all x cordinate of yellow
int yellowycord[56];//all y cordinate of yellow
int greenxcord[56];//all x cordinate of green
int greenycord[56];//all y cordinate of green

void AllCordinate()// Storing values of arrays 
{
redxcord[0]=xcord[3];redxcord[1]=xcord[6];redxcord[2]=xcord[9];redxcord[3]=xcord[12];redxcord[4]=xcord[15];
redxcord[5]=xcord[33];redxcord[6]=xcord[30];redxcord[7]=xcord[27];redxcord[8]=xcord[24];redxcord[9]=xcord[21];
redxcord[10]=xcord[18];redxcord[11]=xcord[19];redxcord[12]=xcord[20];
redxcord[13]=xcord[23];redxcord[14]=xcord[26];redxcord[15]=xcord[29];redxcord[16]=xcord[32];redxcord[17]=xcord[35];
redxcord[18]=xcord[36];redxcord[19]=xcord[39];redxcord[20]=xcord[42];redxcord[21]=xcord[45];redxcord[22]=xcord[48];
redxcord[23]=xcord[51];redxcord[24]=xcord[52];redxcord[25]=xcord[53];
redxcord[26]=xcord[50];redxcord[27]=xcord[47];redxcord[28]=xcord[44];redxcord[29]=xcord[41];redxcord[30]=xcord[33];
redxcord[31]=xcord[56];redxcord[32]=xcord[59];redxcord[33]=xcord[62];redxcord[34]=xcord[65];redxcord[35]=xcord[68];
redxcord[36]=xcord[71];redxcord[37]=xcord[70];redxcord[38]=xcord[69];
redxcord[39]=xcord[66];redxcord[40]=xcord[63];redxcord[41]=xcord[60];redxcord[42]=xcord[57];redxcord[43]=xcord[54];
redxcord[44]=xcord[17];redxcord[45]=xcord[14];redxcord[46]=xcord[11];redxcord[47]=xcord[8];redxcord[48]=xcord[5];
redxcord[49]=xcord[2];redxcord[50]=xcord[1];
redxcord[51]=xcord[4];redxcord[52]=xcord[7];redxcord[53]=xcord[10];redxcord[54]=xcord[13];redxcord[55]=xcord[16];


redycord[0]=ycord[3];redycord[1]=ycord[6];redycord[2]=ycord[9];redycord[3]=ycord[12];redycord[4]=ycord[15];
redycord[5]=ycord[33];redycord[6]=ycord[30];redycord[7]=ycord[27];redycord[8]=ycord[24];redycord[9]=ycord[21];
redycord[10]=ycord[18];redycord[11]=ycord[19];redycord[12]=ycord[20];
redycord[13]=ycord[23];redycord[14]=ycord[26];redycord[15]=ycord[29];redycord[16]=ycord[32];redycord[17]=ycord[35];
redycord[18]=ycord[36];redycord[19]=ycord[39];redycord[20]=ycord[42];redycord[21]=ycord[45];redycord[22]=ycord[48];
redycord[23]=ycord[51];redycord[24]=ycord[52];redycord[25]=ycord[53];
redycord[26]=ycord[50];redycord[27]=ycord[47];redycord[28]=ycord[44];redycord[29]=ycord[41];redycord[30]=ycord[38];
redycord[31]=ycord[56];redycord[32]=ycord[59];redycord[33]=ycord[62];redycord[34]=ycord[65];redycord[35]=ycord[68];
redycord[36]=ycord[71];redycord[37]=ycord[70];redycord[38]=ycord[69];
redycord[39]=ycord[66];redycord[40]=ycord[63];redycord[41]=ycord[60];redycord[42]=ycord[57];redycord[43]=ycord[54];
redycord[44]=ycord[17];redycord[45]=ycord[14];redycord[46]=ycord[11];redycord[47]=ycord[8];redycord[48]=ycord[5];
redycord[49]=ycord[2];redycord[50]=ycord[1];
redycord[51]=ycord[4];redycord[52]=ycord[7];redycord[53]=ycord[10];redycord[54]=ycord[13];redycord[55]=ycord[16];





bluexcord[0]=xcord[23];bluexcord[1]=xcord[26];bluexcord[2]=xcord[29];bluexcord[3]=xcord[32];bluexcord[4]=xcord[35]; 
bluexcord[5]=xcord[36];bluexcord[6]=xcord[39];bluexcord[7]=xcord[42];bluexcord[8]=xcord[45];bluexcord[9]=xcord[48];
bluexcord[10]=xcord[51];bluexcord[11]=xcord[52];bluexcord[12]=xcord[53];
bluexcord[13]=xcord[50];bluexcord[14]=xcord[47];bluexcord[15]=xcord[44];bluexcord[16]=xcord[41];bluexcord[17]=xcord[38];
bluexcord[18]=xcord[56];bluexcord[19]=xcord[59];bluexcord[20]=xcord[62];bluexcord[21]=xcord[65];bluexcord[22]=xcord[68];
bluexcord[23]=xcord[71];bluexcord[24]=xcord[70];bluexcord[25]=xcord[69];
bluexcord[26]=xcord[66];bluexcord[27]=xcord[63];bluexcord[28]=xcord[60];bluexcord[29]=xcord[57];bluexcord[30]=xcord[54];
bluexcord[31]=xcord[17];bluexcord[32]=xcord[14];bluexcord[33]=xcord[11];bluexcord[34]=xcord[8];bluexcord[35]=xcord[5];
bluexcord[36]=xcord[2];bluexcord[37]=xcord[1];bluexcord[38]=xcord[0];
bluexcord[39]=xcord[3];bluexcord[40]=xcord[6];bluexcord[41]=xcord[9];bluexcord[42]=xcord[12];bluexcord[43]=xcord[15];
bluexcord[44]=xcord[33];bluexcord[45]=xcord[30];bluexcord[46]=xcord[27];bluexcord[47]=xcord[24];bluexcord[48]=xcord[21];
bluexcord[49]=xcord[18];bluexcord[50]=xcord[19];
bluexcord[51]=xcord[22];bluexcord[52]=xcord[25];bluexcord[53]=xcord[28];bluexcord[54]=xcord[31];bluexcord[55]=xcord[34];



blueycord[0]=ycord[23];blueycord[1]=ycord[26];blueycord[2]=ycord[29];blueycord[3]=ycord[32];blueycord[4]=ycord[35]; 
blueycord[5]=ycord[36];blueycord[6]=ycord[39];blueycord[7]=ycord[42];blueycord[8]=ycord[45];blueycord[9]=ycord[48];
blueycord[10]=ycord[51];blueycord[11]=ycord[52];blueycord[12]=ycord[53];
blueycord[13]=ycord[50];blueycord[14]=ycord[47];blueycord[15]=ycord[44];blueycord[16]=ycord[41];blueycord[17]=ycord[38];
blueycord[18]=ycord[56];blueycord[19]=ycord[59];blueycord[20]=ycord[62];blueycord[21]=ycord[65];blueycord[22]=ycord[68];
blueycord[23]=ycord[71];blueycord[24]=ycord[70];blueycord[25]=ycord[69];
blueycord[26]=ycord[66];blueycord[27]=ycord[63];blueycord[28]=ycord[60];blueycord[29]=ycord[57];blueycord[30]=ycord[54];
blueycord[31]=ycord[17];blueycord[32]=ycord[14];blueycord[33]=ycord[11];blueycord[34]=ycord[8];blueycord[35]=ycord[5];
blueycord[36]=ycord[2];blueycord[37]=ycord[1];blueycord[38]=ycord[0];
blueycord[39]=ycord[3];blueycord[40]=ycord[6];blueycord[41]=ycord[9];blueycord[42]=ycord[12];blueycord[43]=ycord[15];
blueycord[44]=ycord[33];blueycord[45]=ycord[30];blueycord[46]=ycord[27];blueycord[47]=ycord[24];blueycord[48]=ycord[21];
blueycord[49]=ycord[18];blueycord[50]=ycord[19];
blueycord[51]=ycord[22];blueycord[52]=ycord[25];blueycord[53]=ycord[28];blueycord[54]=ycord[31];blueycord[55]=ycord[34];





yellowxcord[0]=xcord[50];yellowxcord[1]=xcord[47];yellowxcord[2]=xcord[44];yellowxcord[3]=xcord[41];yellowxcord[4]=xcord[38];
yellowxcord[5]=xcord[56];yellowxcord[6]=xcord[59];yellowxcord[7]=xcord[62];yellowxcord[8]=xcord[65];yellowxcord[9]=xcord[68];
yellowxcord[10]=xcord[71];yellowxcord[11]=xcord[70];yellowxcord[12]=xcord[69];
yellowxcord[13]=xcord[66];yellowxcord[14]=xcord[63];yellowxcord[15]=xcord[60];yellowxcord[16]=xcord[57];yellowxcord[17]=xcord[54];
yellowxcord[18]=xcord[17];yellowxcord[19]=xcord[14];yellowxcord[20]=xcord[11];yellowxcord[21]=xcord[8];yellowxcord[22]=xcord[5];
yellowxcord[23]=xcord[2];yellowxcord[24]=xcord[1];yellowxcord[25]=xcord[0];
yellowxcord[26]=xcord[3];yellowxcord[27]=xcord[6];yellowxcord[28]=xcord[9];yellowxcord[29]=xcord[12];yellowxcord[30]=xcord[15];
yellowxcord[31]=xcord[33];yellowxcord[32]=xcord[30];yellowxcord[33]=xcord[27];yellowxcord[34]=xcord[24];yellowxcord[35]=xcord[21];
yellowxcord[36]=xcord[18];yellowxcord[37]=xcord[19];yellowxcord[38]=xcord[20];
yellowxcord[39]=xcord[23];yellowxcord[40]=xcord[26];yellowxcord[41]=xcord[29];yellowxcord[42]=xcord[32];yellowxcord[43]=xcord[35];
yellowxcord[44]=xcord[36];yellowxcord[45]=xcord[39];yellowxcord[46]=xcord[42];yellowxcord[47]=xcord[45];yellowxcord[48]=xcord[48];
yellowxcord[49]=xcord[51];yellowxcord[50]=xcord[52];
yellowxcord[51]=xcord[49];yellowxcord[52]=xcord[48];yellowxcord[53]=xcord[43];yellowxcord[54]=xcord[40];yellowxcord[55]=xcord[37];


yellowycord[0]=ycord[50];yellowycord[1]=ycord[47];yellowycord[2]=ycord[44];yellowycord[3]=ycord[41];yellowycord[4]=ycord[38];
yellowycord[5]=ycord[56];yellowycord[6]=ycord[59];yellowycord[7]=ycord[62];yellowycord[8]=ycord[65];yellowycord[9]=ycord[68];
yellowycord[10]=ycord[71];yellowycord[11]=ycord[70];yellowycord[12]=ycord[69];
yellowycord[13]=ycord[66];yellowycord[14]=ycord[63];yellowycord[15]=ycord[60];yellowycord[16]=ycord[57];yellowycord[17]=ycord[54];
yellowycord[18]=ycord[17];yellowycord[19]=ycord[14];yellowycord[20]=ycord[11];yellowycord[21]=ycord[8];yellowycord[22]=ycord[5];
yellowycord[23]=ycord[2];yellowycord[24]=ycord[1];yellowycord[25]=ycord[0];
yellowycord[26]=ycord[3];yellowycord[27]=ycord[6];yellowycord[28]=ycord[9];yellowycord[29]=ycord[12];yellowycord[30]=ycord[15];
yellowycord[31]=ycord[33];yellowycord[32]=ycord[30];yellowycord[33]=ycord[27];yellowycord[34]=ycord[24];yellowycord[35]=ycord[21];
yellowycord[36]=ycord[18];yellowycord[37]=ycord[19];yellowycord[38]=ycord[20];
yellowycord[39]=ycord[23];yellowycord[40]=ycord[26];yellowycord[41]=ycord[29];yellowycord[42]=ycord[32];yellowycord[43]=ycord[35];
yellowycord[44]=ycord[36];yellowycord[45]=ycord[39];yellowycord[46]=ycord[42];yellowycord[47]=ycord[45];yellowycord[48]=ycord[48];
yellowycord[49]=ycord[51];yellowycord[50]=ycord[52];
yellowycord[51]=ycord[49];yellowycord[52]=ycord[48];yellowycord[53]=ycord[43];yellowycord[54]=ycord[40];yellowycord[55]=ycord[37];





greenxcord[0]=xcord[66];greenxcord[1]=xcord[63];greenxcord[2]=xcord[60];greenxcord[3]=xcord[57];greenxcord[4]=xcord[54]; 
greenxcord[5]=xcord[17];greenxcord[6]=xcord[14];greenxcord[7]=xcord[11];greenxcord[8]=xcord[8];greenxcord[9]=xcord[5];
greenxcord[10]=xcord[2];greenxcord[11]=xcord[1];greenxcord[12]=xcord[0];
greenxcord[13]=xcord[3];greenxcord[14]=xcord[6];greenxcord[15]=xcord[9];greenxcord[16]=xcord[12];greenxcord[17]=xcord[15];
greenxcord[18]=xcord[33];greenxcord[19]=xcord[30];greenxcord[20]=xcord[27];greenxcord[21]=xcord[24];greenxcord[22]=xcord[21];
greenxcord[23]=xcord[18];greenxcord[24]=xcord[19];greenxcord[25]=xcord[20];
greenxcord[26]=xcord[23];greenxcord[27]=xcord[26];greenxcord[28]=xcord[29];greenxcord[29]=xcord[32];greenxcord[30]=xcord[35];
greenxcord[31]=xcord[36];greenxcord[32]=xcord[39];greenxcord[33]=xcord[42];greenxcord[34]=xcord[45];greenxcord[35]=xcord[48];
greenxcord[36]=xcord[51];greenxcord[37]=xcord[52];greenxcord[38]=xcord[53];
greenxcord[39]=xcord[50];greenxcord[40]=xcord[47];greenxcord[41]=xcord[44];greenxcord[42]=xcord[41];greenxcord[43]=xcord[38];
greenxcord[44]=xcord[56];greenxcord[45]=xcord[59];greenxcord[46]=xcord[62];greenxcord[47]=xcord[65];greenxcord[48]=xcord[68];
greenxcord[49]=xcord[71];greenxcord[50]=xcord[70];
greenxcord[51]=xcord[67];greenxcord[52]=xcord[64];greenxcord[53]=xcord[61];greenxcord[54]=xcord[58];greenxcord[55]=xcord[55];




greenycord[0]=ycord[66];greenycord[1]=ycord[63];greenycord[2]=ycord[60];greenycord[3]=ycord[57];greenycord[4]=ycord[54]; 
greenycord[5]=ycord[17];greenycord[6]=ycord[14];greenycord[7]=ycord[11];greenycord[8]=ycord[8];greenycord[9]=ycord[5];
greenycord[10]=ycord[2];greenycord[11]=ycord[1];greenycord[12]=ycord[0];
greenycord[13]=ycord[3];greenycord[14]=ycord[6];greenycord[15]=ycord[9];greenycord[16]=ycord[12];greenycord[17]=ycord[15];
greenycord[18]=ycord[33];greenycord[19]=ycord[30];greenycord[20]=ycord[27];greenycord[21]=ycord[24];greenycord[22]=ycord[21];
greenycord[23]=ycord[18];greenycord[24]=ycord[19];greenycord[25]=ycord[20];
greenycord[26]=ycord[23];greenycord[27]=ycord[26];greenycord[28]=ycord[29];greenycord[29]=ycord[32];greenycord[30]=ycord[35];
greenycord[31]=ycord[36];greenycord[32]=ycord[39];greenycord[33]=ycord[42];greenycord[34]=ycord[45];greenycord[35]=ycord[48];
greenycord[36]=ycord[51];greenycord[37]=ycord[52];greenycord[38]=ycord[53];
greenycord[39]=ycord[50];greenycord[40]=ycord[47];greenycord[41]=ycord[44];greenycord[42]=ycord[41];greenycord[43]=ycord[38];
greenycord[44]=ycord[56];greenycord[45]=ycord[59];greenycord[46]=ycord[62];greenycord[47]=ycord[65];greenycord[48]=ycord[68];
greenycord[49]=ycord[71];greenycord[50]=ycord[70];
greenycord[51]=ycord[67];greenycord[52]=ycord[64];greenycord[53]=ycord[61];greenycord[54]=ycord[58];greenycord[55]=ycord[55];

for (int i=0; i<16 ; i++)
{
	homegoti[i] = 1;
	wongoti[i] = 0;
	xposition[i] = 1000; 
	yposition[i] = 1000; 
}


}









// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
void Board()//BOARD FUNCTION
{
	//BIG SQUARES
	DrawSquare( 0 , 0 , 240,colors[RED]); //RED SQUARE
	DrawSquare( 0 , 360 , 240,colors[BLUE]); //BLUE SQUARE
	DrawSquare( 360 , 0 , 240,colors[GREEN]); //GREEN SQUARE
	DrawSquare( 360 , 360 , 240,colors[YELLOW]); //YELLOW SQUARE
	
	//MIDDLE WHITE SQUARE(TRIANGLE)
	DrawSquare( 240 , 240 , 120,colors[WHITE]);
	 
	//INNER TRIANLGES
	DrawTriangle( 240, 240 , 360, 240 , 300 , 300, colors[RED] );
	DrawTriangle( 240, 240 , 240, 360 , 300 , 300, colors[BLUE] );
	DrawTriangle( 360, 240 , 360, 360 , 300 , 300, colors[GREEN] );
	DrawTriangle( 240, 360 , 360, 360 , 300 , 300, colors[YELLOW] );
	
	//BLUE PORTION WHITE AND BLUE BOXES
	DrawSquare( 0 , 240 , 40,colors[WHITE]);
	DrawSquare( 40 , 240 , 40,colors[WHITE]);
	DrawSquare( 80 , 240 , 40,colors[GRAY]);
	DrawSquare( 120 , 240 , 40,colors[WHITE]);
	DrawSquare( 160 , 240 , 40,colors[WHITE]);
	DrawSquare( 200 , 240 , 40,colors[WHITE]);
	
	DrawSquare( 0 , 280 , 40,colors[WHITE]);
	DrawSquare( 40 , 280 , 40,colors[BLUE]);
	DrawSquare( 80 , 280 , 40,colors[BLUE]);
	DrawSquare( 120 , 280 , 40,colors[BLUE]);
	DrawSquare( 160 , 280 , 40,colors[BLUE]);
	DrawSquare( 200 , 280 , 40,colors[BLUE]);
	DrawTriangle( 10, 290 , 10, 310 , 30 , 300, colors[BLUE] ); //LAST BOX TRIANGLE
	
	DrawSquare( 0 , 320 , 40,colors[WHITE]);
	DrawSquare( 40 , 320 , 40,colors[BLUE]);
	DrawSquare( 80 , 320 , 40,colors[WHITE]);
	DrawSquare( 120 , 320 , 40,colors[WHITE]);
	DrawSquare( 160 , 320 , 40,colors[WHITE]);
	DrawSquare( 200 , 320 , 40,colors[WHITE]);
	
	//GREEN PORTION WHITE AND GREEN BOXES
	DrawSquare( 360 , 240 , 40,colors[WHITE]);
	DrawSquare( 400 , 240 , 40,colors[WHITE]);
	DrawSquare( 440 , 240 , 40,colors[WHITE]);
	DrawSquare( 480 , 240 , 40,colors[WHITE]);
	DrawSquare( 520 , 240 , 40,colors[GREEN]);
	DrawSquare( 560 , 240 , 40,colors[WHITE]);
	
	DrawSquare( 360 , 280 , 40,colors[GREEN]);
	DrawSquare( 400 , 280 , 40,colors[GREEN]);
	DrawSquare( 440 , 280 , 40,colors[GREEN]);
	DrawSquare( 480 , 280 , 40,colors[GREEN]);
	DrawSquare( 520 , 280 , 40,colors[GREEN]);
	DrawSquare( 560 , 280 , 40,colors[WHITE]);
	DrawTriangle( 590, 290 , 590, 310 , 570 , 300, colors[GREEN] ); //LAST BOX TRIANGLE
	
	DrawSquare( 360 , 320 , 40,colors[WHITE]);
	DrawSquare( 400 , 320 , 40,colors[WHITE]);
	DrawSquare( 440 , 320 , 40,colors[WHITE]);
	DrawSquare( 480 , 320 , 40,colors[GRAY]);
	DrawSquare( 520 , 320 , 40,colors[WHITE]);
	DrawSquare( 560 , 320 , 40,colors[WHITE]);
	
	//RED PORTION WHITE AND RED BOXES
	DrawSquare( 240 , 0 , 40,colors[WHITE]);
	DrawSquare( 240 , 40 , 40,colors[RED]);
	DrawSquare( 240 , 80 , 40,colors[WHITE]);
	DrawSquare( 240 , 120 , 40,colors[WHITE]);
	DrawSquare( 240 , 160 , 40,colors[WHITE]);
	DrawSquare( 240 , 200 , 40,colors[WHITE]);
	
	DrawSquare( 280 , 0 , 40,colors[WHITE]);
	DrawSquare( 280 , 40 , 40,colors[RED]);
	DrawSquare( 280 , 80 , 40,colors[RED]);
	DrawSquare( 280 , 120 , 40,colors[RED]);
	DrawSquare( 280 , 160 , 40,colors[RED]);
	DrawSquare( 280 , 200 , 40,colors[RED]);
	DrawTriangle( 290, 10 , 310, 10 , 300 , 30, colors[RED] ); //LAST BOX TRIANGLE
	
	DrawSquare( 320 , 0 , 40,colors[WHITE]);
	DrawSquare( 320 , 40 , 40,colors[WHITE]);
	DrawSquare( 320 , 80 , 40,colors[GRAY]);
	DrawSquare( 320 , 120 , 40,colors[WHITE]);
	DrawSquare( 320 , 160 , 40,colors[WHITE]);
	DrawSquare( 320 , 200 , 40,colors[WHITE]);
	
	//YELLOW PORTION WHITE AND RED BOXES
	DrawSquare( 240 , 360 , 40,colors[WHITE]);
	DrawSquare( 240 , 400 , 40,colors[WHITE]);
	DrawSquare( 240 , 440 , 40,colors[WHITE]);
	DrawSquare( 240 , 480 , 40,colors[GRAY]);
	DrawSquare( 240 , 520 , 40,colors[WHITE]);
	DrawSquare( 240 , 560 , 40,colors[WHITE]);
	
	DrawSquare( 280 , 360 , 40,colors[YELLOW]);
	DrawSquare( 280 , 400 , 40,colors[YELLOW]);
	DrawSquare( 280 , 440 , 40,colors[YELLOW]);
	DrawSquare( 280 , 480 , 40,colors[YELLOW]);
	DrawSquare( 280 , 520 , 40,colors[YELLOW]);
	DrawSquare( 280 , 560 , 40,colors[WHITE]);
	DrawTriangle( 290, 590 , 310, 590 , 300 , 570, colors[YELLOW] ); //LAST BOX TRIANGLE
	
	DrawSquare( 320 , 360 , 40,colors[WHITE]);
	DrawSquare( 320 , 400 , 40,colors[WHITE]);
	DrawSquare( 320 , 440 , 40,colors[WHITE]);
	DrawSquare( 320 , 480 , 40,colors[WHITE]);
	DrawSquare( 320 , 520 , 40,colors[YELLOW]);
	DrawSquare( 320 , 560 , 40,colors[WHITE]);
	
	//Inner RED WHITE CIRLCE
	DrawCircle(120,120,80,colors[WHITE]);
		
		//INNER RED CIRCLES
		DrawCircle(81,120,15,colors[RED]);
		DrawCircle(120,81,15,colors[RED]);
		DrawCircle(120,159,15,colors[RED]);
		DrawCircle(159,120,15,colors[RED]);
		
	
	//Inner GREEN WHITE CIRLCES
	DrawCircle(480,120,80,colors[WHITE]);
	
		//INNER GREEN CIRCLE
		DrawCircle(441,120,15,colors[GREEN]);
		DrawCircle(480,81,15,colors[GREEN]);
		DrawCircle(480,159,15,colors[GREEN]);
		DrawCircle(519,120,15,colors[GREEN]);
	
	//Inner YELLOW WHITE CIRCLES
	DrawCircle(480,480,80,colors[WHITE]);
		
		//INNER YELLOW CIRCLES
		DrawCircle(441,480,15,colors[YELLOW]);
		DrawCircle(480,441,15,colors[YELLOW]);
		DrawCircle(480,519,15,colors[YELLOW]);
		DrawCircle(519,480,15,colors[YELLOW]);
	
	//Inner BLUE WHITE CIRLCES
	DrawCircle(120,480,80,colors[WHITE]);
		
		//INNER BLUE CIRCLESS
		DrawCircle(81,480,15,colors[BLUE]);
		DrawCircle(120,441,15,colors[BLUE]);
		DrawCircle(120,519,15,colors[BLUE]);
		DrawCircle(159,480,15,colors[BLUE]);
	
}
void Dice()//DICE FUNCTION
{
	int dice_num;
	dice_num = rand() % 6 + 1;
	//Dice
	DrawSquare( 650 , 500 , 100,colors[WHITE]);
	
	if( dice_num == 1){//if number is 1
	//Dice num1
	DrawCircle(700,550,20,colors[RED]);
	}
	
	else if( dice_num == 2){//if number is 2
	//Dice num2
	DrawCircle(675,550,15,colors[BLACK]);
	DrawCircle(725,550,15,colors[BLACK]);
	}
	
	else if( dice_num == 3){//if number is 3
	//Dice num3
	DrawCircle(675,580,10,colors[BLACK]);
	DrawCircle(700,550,10,colors[BLACK]);
	DrawCircle(725,520,10,colors[BLACK]);
	}
	
	else if( dice_num == 4){//if number is 4
	//Dice num4
	DrawCircle(675,580,10,colors[BLACK]);
	DrawCircle(725,580,10,colors[BLACK]);
	DrawCircle(725,520,10,colors[BLACK]);
	DrawCircle(675,520,10,colors[BLACK]);
	}
	
	else if( dice_num == 5){//if number is 5
	//Dice num5
	DrawCircle(675,580,10,colors[BLACK]);
	DrawCircle(725,580,10,colors[BLACK]);
	DrawCircle(700,550,10,colors[BLACK]);
	DrawCircle(725,520,10,colors[BLACK]);
	DrawCircle(675,520,10,colors[BLACK]);
	}
	
	else if( dice_num == 6){//if number is 6
	//Dice num6
	DrawCircle(675,580,10,colors[BLACK]);
	DrawCircle(725,580,10,colors[BLACK]);
	DrawCircle(675,550,10,colors[BLACK]);
	DrawCircle(725,550,10,colors[BLACK]);
	DrawCircle(725,520,10,colors[BLACK]);
	DrawCircle(675,520,10,colors[BLACK]);
	}
	
}
void Movement()// Function for moving gotis
{
	for(int i=0 ; i < 16 ; i++)
	{
	int CurrentPlayers;//total colours
	if(i < 4)  // find out Gotti of COlour
	CurrentPlayers=1;
	
	else if(i > 3 && i < 8)
	CurrentPlayers=2;
	
	else if(i > 7 && i < 12)
	CurrentPlayers=3;
	
	else if(i > 11 && i < 15) 
	CurrentPlayers=4; 
		
	if(homegoti[i] == 1)// if Goti is in home
	{
		if(CurrentPlayers == 1) //RED GOTI
		{
			if( i==0 )
			{
				DrawCircle(81,120,15,colors[BLACK]);
				DrawCircle(81,120,10,colors[RED]);
				
			}
			if( i==1 )
			{
				DrawCircle(120,81,15,colors[BLACK]);
				DrawCircle(120,81,10,colors[RED]);
				
			}			
			if( i==2 )
			{
				DrawCircle(120,159,15,colors[BLACK]);
				DrawCircle(120,159,10,colors[RED]);
				
			}			
			if( i==3 )
			{	
				DrawCircle(159,120,15,colors[BLACK]);
				DrawCircle(159,120,10,colors[RED]);
			}					
			
		}
		else if(CurrentPlayers == 2) //GREEN GOTI
		{
			if( i==4 )
			{
				DrawCircle(441,120,15,colors[BLACK]);
				DrawCircle(441,120,10,colors[GREEN]);	
			}
			if( i==5 )
			{
				DrawCircle(480,81,15,colors[BLACK]);
				DrawCircle(480,81,10,colors[GREEN]);	
				
			}			
			if( i==6 )
			{
				DrawCircle(480,159,15,colors[BLACK]);
				DrawCircle(480,159,10,colors[GREEN]);
				
			}			
			if( i==7 )
			{	
				DrawCircle(519,120,15,colors[BLACK]);
				DrawCircle(519,120,10,colors[GREEN]);
	
			}
		}
		else if(CurrentPlayers == 3) //YELLOW GOTI
		{
			if( i==8 )
			{
				DrawCircle(441,480,15,colors[BLACK]);
				DrawCircle(441,480,10,colors[YELLOW]);
	
			}
			if( i==9 )
			{
				DrawCircle(480,441,15,colors[BLACK]);
				DrawCircle(480,441,10,colors[YELLOW]);
				
			}			
			if( i==10 )
			{
				DrawCircle(480,519,15,colors[BLACK]);
				DrawCircle(480,519,10,colors[YELLOW]);
				
			}			
			if( i==11 )
			{	
				DrawCircle(519,480,15,colors[BLACK]);
				DrawCircle(519,480,10,colors[YELLOW]);
	
			}					
			
		}
		else if(CurrentPlayers == 4) //BLUE
		{
			if( i==12 )
			{
				DrawCircle(81,480,15,colors[BLACK]);
				DrawCircle(81,480,10,colors[BLUE]);
			}
			if( i==13 )
			{
				DrawCircle(120,441,15,colors[BLACK]);
				DrawCircle(120,441,10,colors[BLUE]);
				
			}			
			if( i==14 )
			{
				DrawCircle(120,519,15,colors[BLACK]);
				DrawCircle(120,519,10,colors[BLUE]);
				
			}			
			if( i==15 )
			{	
				DrawCircle(159,480,15,colors[BLACK]);
				DrawCircle(159,480,10,colors[BLUE]);
	
			}					
			
		}	continue;
	} 
	else if(wongoti[i] == 1) //if goti has won
	{    
		continue;
	} else 
	{
		if(CurrentPlayers == 1)
		{
			DrawCircle(xposition[i],yposition[i],13,colors[BLACK]);       //RED goti on the board location
			DrawCircle(xposition[i],yposition[i],10,colors[RED]);			
		} 
		else if(CurrentPlayers == 2)
		{
			DrawCircle(xposition[i],yposition[i],13,colors[BLACK]);       //GREEN goti on the board location
			DrawCircle(xposition[i],yposition[i],10,colors[GREEN]);			
		} 
		else if(CurrentPlayers == 3)
		{
			DrawCircle(xposition[i],yposition[i],13,colors[BLACK]);       //YELLOW goti on the board location
			DrawCircle(xposition[i],yposition[i],10,colors[YELLOW]);			
		} 
		else if(CurrentPlayers == 2)
		{
			DrawCircle(xposition[i],yposition[i],13,colors[BLACK]);       //BLUE goti on the board location
			DrawCircle(xposition[i],yposition[i],10,colors[BLUE]);			
		} 
	}
}
}
void Turn() //for turn
{
	turn = turn+1;
	
	if(turn > 4)
	{
	turn = 1 ;
	}
}
void NumberAdd()//For Adding the dice number to the goti 
{
	if(turn==1)
	{
		if (homegoti[0] ==1 && dice_num==6)
		{
			xposition[0]=0;
			yposition[0]=0;
			homegoti[0]=0;
		}
		else if((homegoti[0] !=1) && ((xposition[0]+dice_num)<56))
		{
			xposition[0]=xposition[0]+dice_num;
			yposition[0]=yposition[0]+dice_num;			
		}

	} else if(turn==2)
	{
		if(homegoti[4] ==1 && dice_num==6)
		{
			xposition[4]=0;
			yposition[4]=0;
			homegoti[4]=0;
		}
		else if((homegoti[4] !=1) && ((xposition[4]+dice_num)<56))
		{
	
			xposition[4]=xposition[4]+dice_num;
			yposition[4]=yposition[4]+dice_num;
		}
	} 
	else if (turn==3)
	{
		if (homegoti[9] ==1 && dice_num==6)
		{
			xposition[9]=0;
			yposition[9]=0;
			homegoti[9]=0;
		}
		else if((homegoti[9] !=1 ) && ((xposition[9]+dice_num)<56)) 
		{	
	
			xposition[9]=xposition[9]+dice_num;
			yposition[9]=yposition[9]+dice_num;
		}
	} 
	else if (turn==4)
	{
		if (homegoti[13] ==1 && dice_num==6)
		{
			xposition[13]=0;
			yposition[13]=0;
			homegoti[13]=0;
		}
		else if((homegoti[13] !=1 ) && ((xposition[13]+dice_num)<56)) 
		{	
	
			xposition[13]=xposition[13]+dice_num;
			yposition[13]=yposition[13]+dice_num;
		}
	}
}

	

/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Fire Gun
	
	Board(); //BOARD FUNCTION

	Turn();

	Dice();

	NumberAdd();
	
	Movement();


	
	
	/*
	DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Mushroom
	DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Spider
	DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	DrawCircle(50,670,10,colors[RED]);
	DrawCircle(70,670,10,colors[RED]);
	DrawCircle(90,670,10,colors[RED]);
	*/

	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	if ( key == 32/* Space key ASCII*/)
	{
		press = true;// exit the program when escape key is pressed.
	}
	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	
	
	

	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	/*cout << x << " " << y << endl;
	glutPostRedisplay();*/
}
void MouseMoved(int x, int y) {

	/*glutPostRedisplay();*/
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("PF Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	
	//No. Of Players in Game
	int player;
	string p1,p2,p3,p4;
	do{
		cout<<"\t W E L C O M E   T O   L U D O \n\n";
		cout<<"Enter number of Players (2-4) : "; //ASKING THE NUMBER OF PLAYERS
		cin>>player;
		cout<<endl;
		if(player == 2)// FOR 2 PLAYERS
		{
			cout<<"Enter name of Player 1"<<endl;//Inputting Name of Player 1
			cin>>p1;				
			cout<<"Enter name of Player 2"<<endl;//Inputting Name of Player 2
			cin>>p2;
		}
		else if(player == 3)// FOR 3 PLAYERS
		{
			cout<<"Enter name of Player 1"<<endl;//Inputting Name of Player 1
			cin>>p1;
			cout<<"Enter name of Player 2"<<endl;//Inputting Name of Player 2
			cin>>p2;
			cout<<"Enter name of Player 3"<<endl;//Inputting Name of Player 3
			cin>>p3;
		}
		else if(player == 4)// FOR 4 PLAYERS
		{
			cout<<"Enter name of Player 1"<<endl;//Inputting Name of Player 1
			cin>>p1;
			cout<<"Enter name of Player 2"<<endl;//Inputting Name of Player 2
			cin>>p2;
			cout<<"Enter name of Player 3"<<endl;//Inputting Name of Player 3
			cin>>p3;
			cout<<"Enter name of Player 4"<<endl;//Inputting Name of Player 4
			cin>>p4;
		}
		else// IF PERSON INPUT ANY OTHER NUMBER THAN 2 3 4
		{	
			cout<<"Invalid Data"<<endl;
			cout<<endl;
		}
		
	}while(player<2 || player>4); //LOOP INCASE USER ENTERS NUMBERS OTHER THAN 2,3,4
	
	//Colors
	int n,c1,c2,c3,c4;
	do{
		cout<<endl;
		cout<<"\tAssigning the colours"<<endl;
		cout<<"1-Select colours of players"<<endl;//FOR USER LIKED COLOURS
		cout<<"2-Randomly Assign colours of players"<<endl;//FOR RANDOM COLOURS
		cin>>n;
		cout<<endl;
		if(n == 1)//SELECT COLOURS OF PLAYERS WITH CHOICE
		{
			if(player == 2)// IF 2 PLAYERS
			{	
				do{
				cout<<"Enter "<<p1<<" colour"<<endl;//Colour of Player 1
				cout<<"1.RED 2.BLUE 3.YELLOW 4.GREEN"<<endl;
				cin>>c1;//Input colour 1
				cout<<endl;
				if(c1 < 1 || c1 > 4 ) //IF INPUT IS MORE THAN 4 OR LESS THAN 1
				{
					cout<<"Invlaid Input"<<endl;
					cout<<endl;
				}
				}while(c1 < 1 || c1 > 4);
				do{
				cout<<"Enter "<<p2<<" colour"<<endl;;//Colour of Player 2
				cout<<"1.RED 2.BLUE 3.YELLOW 4.GREEN"<<endl;
				cin>>c2;//input colour 2
				cout<<endl;
				if(c1 == c2 || c2 < 1 || c2 > 4) //IF PERSON INPUT BOTH NUMBER SAME and Number less than 1 and more than 4
				{
					cout<<"Invlaid Input"<<endl;
					cout<<endl;
				}
				}while(c1 == c2 || c2 < 1 || c2 > 4);//LOOP INCASE USER ENTERS SAME NUMBERS and Number less than 1 and more than 4
			}
			if(player == 3)// IF 3 PLAYERS
			{	 
				do{
				cout<<"Enter "<<p1<<" colour"<<endl;//Colour of Player 1
				cout<<"1.RED 2.BLUE 3.YELLOW 4.GREEN"<<endl;
				cin>>c1;//Input colour 1
				cout<<endl;
				if(c1 < 1 || c1 > 4 ) //IF INPUT IS MORE THAN 4 OR LESS THAN 1
				{
					cout<<"Invlaid Input"<<endl;
					cout<<endl;
				}
				}while(c1 < 1 || c1 > 4);
				do{
				cout<<"Enter "<<p2<<" colour"<<endl;//Colour of Player 2
				cout<<"1.RED 2.BLUE 3.YELLOW 4.GREEN"<<endl;
				cin>>c2;//input colour 2
				cout<<endl;
				if(c1 == c2 || c2 < 1 || c2 > 4) //IF PERSON INPUT BOTH NUMBER SAME and Number less than 1 and more than 4
				{
					cout<<"Invlaid Input"<<endl;
					cout<<endl;
				}
				}while(c1 == c2 || c2 < 1 || c2 > 4);//LOOP INCASE USER ENTERS SAME NUMBERS and Number less than 1 and more than 4
				do{
				cout<<"Enter "<<p3<<" colour"<<endl;//Colour of Player 3
				cout<<"1.RED 2.BLUE 3.YELLOW 4.GREEN"<<endl;
				cin>>c3;//input colour 3
				cout<<endl;
				if(c1 == c3 || c2 == c3 || c3 < 1 || c3 > 4)//IF PERSON INPUT BOTH NUMBER SAME and Number less than 1 and more than 4
				{
					cout<<"Invlaid Input"<<endl;
					cout<<endl;
				}
				}while(c1 == c3 || c2 == c3 || c3 < 1 || c3 > 4);//LOOP INCASE USER ENTERS SAME NUMBERS and Number less than 1 and more than 4
				
			}
			if(player == 4)// IF 4 PLAYERS
			{	
				do{
				cout<<"Enter "<<p1<<" colour"<<endl;//Colour of Player 1
				cout<<"1.RED 2.BLUE 3.YELLOW 4.GREEN"<<endl;
				cin>>c1;//Input colour 1
				cout<<endl;
				if(c1 < 1 || c1 > 4 ) //IF INPUT IS MORE THAN 4 OR LESS THAN 1
				{
					cout<<"Invlaid Input"<<endl;
					cout<<endl;
				}
				}while(c1 < 1 || c1 > 4);
				do{
				cout<<"Enter "<<p2<<" colour"<<endl;//Colour of Player 2
				cout<<"1.RED 2.BLUE 3.YELLOW 4.GREEN"<<endl;
				cin>>c2;//input colour 2
				cout<<endl;
				if(c1 == c2 || c2 < 1 || c2 > 4) //IF PERSON INPUT BOTH NUMBER SAME and Number less than 1 and more than 4
				{
					cout<<"Invlaid Input"<<endl;
					cout<<endl;
				}
				}while(c1 == c2 || c2 < 1 || c2 > 4);//LOOP INCASE USER ENTERS SAME NUMBERS and Number less than 1 and more than 4
				do{
				cout<<"Enter "<<p3<<" colour"<<endl;//Colour of Player 3
				cout<<"1.RED 2.BLUE 3.YELLOW 4.GREEN"<<endl;
				cin>>c3;//input colour 3
				cout<<endl;
				if(c1 == c3 || c2 == c3 || c3 < 1 || c3 > 4)//IF PERSON INPUT BOTH NUMBER SAME and Number less than 1 and more than 4
				{
					cout<<"Invlaid Input"<<endl;
					cout<<endl;
				}
				}while(c1 == c3 || c2 == c3 || c3 < 1 || c3 > 4);//LOOP INCASE USER ENTERS SAME NUMBERS and Number less than 1 and more than 4
				do{
				cout<<"Enter "<<p4<<" colour"<<endl;//Colour of Player 4
				cout<<"1.RED 2.BLUE 3.YELLOW 4.GREEN"<<endl;
				cin>>c4;//input colour 4
				cout<<endl;
				if(c4 == c3 || c4 == c2 || c4 == c1 || c4 < 1 || c4 > 4)//IF PERSON INPUT BOTH NUMBER SAME and Number less than 1 and more than 4
				{
					cout<<"Invlaid Input"<<endl;
					cout<<endl;
				}
				}while(c4 == c3 || c4 == c2 || c4 == c1 || c4 < 1 || c4 > 4);//LOOP INCASE USER ENTERS SAME NUMBERS and Number less than 1 and more than 4
			}
		}
		else if(n == 2)//RANDOMLY ASSIGN COLOURS OF PLAYERS
		{
		 srand (time(NULL));
		 
		 if(player == 2)
		 {
		 	c1 = rand() % 4 + 1;//ASSIGNING RANDOM COLOUR FOR PLAYER1
		 	if(c1 == 1)
		 	{
		 		cout<<p1<<" is assigned RED"<<endl;//PLAYER 1 IS RED
		 	}
		 	else if(c1 == 2)
		 	{
		 		cout<<p1<<" is assigned BLUE"<<endl;//PLAYER 1 IS BLUE
		 	}
		 	else if(c1 == 3)
		 	{
		 		cout<<p1<<" is assigned YELLOW"<<endl;//PLAYER 1 IS YELLOW
		 	}
		 	else if(c1 == 4)
		 	{
		 		cout<<p1<<" is assigned GREEN"<<endl;//PLAYER 1 IS GREEN
		 	}
		 	
		 	do
		 	{	
		 		c2 = rand() % 4 + 1;//ASSIGNING RANDOM COLOUR FOR PLAYER2
		 	}while( c2 == c1);//LOOP INCASE NUMBERS ARE NOT SAME
		 	if(c2 == 1)
		 	{
		 		cout<<p2<<" is assigned RED"<<endl;//PLAYER 2 IS RED
		 	}
		 	else if(c2 == 2)
		 	{
		 		cout<<p2<<" is assigned BLUE"<<endl;//PLAYER 2 IS BLUE
		 	}
		 	else if(c2 == 3)
		 	{
		 		cout<<p2<<" is assigned YELLOW"<<endl;//PLAYER 2 IS YELLOW
		 	}
		 	else if(c2 == 4)
		 	{
		 		cout<<p2<<" is assigned GREEN"<<endl;//PLAYER 2 IS GREEN
		 	}
		 }
		 
		 if(player == 3)
		 {
		 	c1 = rand() % 4 + 1;//ASSIGNING RANDOM COLOUR FOR PLAYER1
		 	if(c1 == 1)
		 	{
		 		cout<<p1<<" is assigned RED"<<endl;//PLAYER 1 IS RED
		 	}
		 	else if(c1 == 2)
		 	{
		 		cout<<p1<<" is assigned BLUE"<<endl;//PLAYER 1 IS BLUE
		 	}
		 	else if(c1 == 3)
		 	{
		 		cout<<p1<<" is assigned YELLOW"<<endl;//PLAYER 1 IS YELLOW
		 	}
		 	else if(c1 == 4)
		 	{
		 		cout<<p1<<" is assigned GREEN"<<endl;//PLAYER 1 IS GREEN
		 	}
		 	
		 	do
		 	{	
		 		c2 = rand() % 4 + 1;//ASSIGNING RANDOM COLOUR FOR PLAYER2
		 	}while( c2 == c1);//LOOP INCASE NUMBERS ARE NOT SAME
		 	if(c2 == 1)
		 	{
		 		cout<<p2<<" is assigned RED"<<endl;//PLAYER 2 IS RED
		 	}
		 	else if(c2 == 2)
		 	{
		 		cout<<p2<<" is assigned BLUE"<<endl;//PLAYER 2 IS BLUE
		 	}
		 	else if(c2 == 3)
		 	{
		 		cout<<p2<<" is assigned YELLOW"<<endl;//PLAYER 2 IS YELLOW
		 	}
		 	else if(c2 == 4)
		 	{
		 		cout<<p2<<" is assigned GREEN"<<endl;//PLAYER 2 IS GREEN
		 	}
		 	
		 	do
		 	{	
		 		c3= rand() % 4 + 1;//ASSIGNING RANDOM COLOUR FOR PLAYER3
		 	}while( c3 == c1 || c3 == c2);//LOOP INCASE NUMBERS ARE NOT SAME
		 	if(c3 == 1)
		 	{
		 		cout<<p3<<" is assigned RED"<<endl;//PLAYER 3 IS RED
		 	}
		 	else if(c3 == 2)
		 	{
		 		cout<<p3<<" is assigned BLUE"<<endl;//PLAYER 3 IS BLUE
		 	}
		 	else if(c3 == 3)
		 	{
		 		cout<<p3<<" is assigned YELLOW"<<endl;//PLAYER 3 IS YELLOW
		 	}
		 	else if(c3 == 4)
		 	{
		 		cout<<p3<<" is assigned GREEN"<<endl;//PLAYER 3 IS GREEN
		 	}
		 }
		 
		  if(player == 4)
		 {
		 	c1 = rand() % 4 + 1;//ASSIGNING RANDOM COLOUR FOR PLAYER1
		 	if(c1 == 1)
		 	{
		 		cout<<p1<<" is assigned RED"<<endl;//PLAYER 1 IS RED
		 	}
		 	else if(c1 == 2)
		 	{
		 		cout<<p1<<" is assigned BLUE"<<endl;//PLAYER 1 IS BLUE
		 	}
		 	else if(c1 == 3)
		 	{
		 		cout<<p1<<" is assigned YELLOW"<<endl;//PLAYER 1 IS YELLOW
		 	}
		 	else if(c1 == 4)
		 	{
		 		cout<<p1<<" is assigned GREEN"<<endl;//PLAYER 1 IS GREEN
		 	}
		 	
		 	do
		 	{	
		 		c2 = rand() % 4 + 1;//ASSIGNING RANDOM COLOUR FOR PLAYER2
		 	}while( c2 == c1);//LOOP INCASE NUMBERS ARE NOT SAME
		 	if(c2 == 1)
		 	{
		 		cout<<p2<<" is assigned RED"<<endl;//PLAYER 2 IS RED
		 	}
		 	else if(c2 == 2)
		 	{
		 		cout<<p2<<" is assigned BLUE"<<endl;//PLAYER 2 IS BLUE
		 	}
		 	else if(c2 == 3)
		 	{
		 		cout<<p2<<" is assigned YELLOW"<<endl;//PLAYER 2 IS YELLOW
		 	}
		 	else if(c2 == 4)
		 	{
		 		cout<<p2<<" is assigned GREEN"<<endl;//PLAYER 2 IS GREEN
		 	}
		 	
		 	do
		 	{	
		 		c3= rand() % 4 + 1;//ASSIGNING RANDOM COLOUR FOR PLAYER3
		 	}while( c3 == c1 || c3 == c2);//LOOP INCASE NUMBERS ARE NOT SAME
		 	if(c3 == 1)
		 	{
		 		cout<<p3<<" is assigned RED"<<endl;//PLAYER 3 IS RED
		 	}
		 	else if(c3 == 2)
		 	{
		 		cout<<p3<<" is assigned BLUE"<<endl;//PLAYER 3 IS BLUE
		 	}
		 	else if(c3 == 3)
		 	{
		 		cout<<p3<<" is assigned YELLOW"<<endl;//PLAYER 3 IS YELLOW
		 	}
		 	else if(c3 == 4)
		 	{
		 		cout<<p3<<" is assigned GREEN"<<endl;//PLAYER 3 IS GREEN
		 	}
		 	
		 	do
		 	{	
		 		c4 = rand() % 4 + 1;//ASSIGNING RANDOM COLOUR FOR PLAYER4
		 	}while( c4 == c1 || c4 == c2 || c4 == c3);//LOOP INCASE NUMBERS ARE NOT SAME
		 	if(c4 == 1)
		 	{
		 		cout<<p4<<" is assigned RED"<<endl;//PLAYER 4 IS RED
		 	}
		 	else if(c4 == 2)
		 	{
		 		cout<<p4<<" is assigned BLUE"<<endl;//PLAYER 4 IS BLUE
		 	}
		 	else if(c4 == 3)
		 	{
		 		cout<<p4<<" is assigned YELLOW"<<endl;//PLAYER 4 IS YELLOW
		 	}
		 	else if(c4 == 4)
		 	{
		 		cout<<p4<<" is assigned GREEN"<<endl;//PLAYER 4 IS GREEN
		 	}
		 }
		 	
		}
		else
		{	
			cout<<"Invalid Data"<<endl;
			cout<<endl;
		}
		}while( n < 1 || n > 2);//LOOP INCASE NUMBERS IS NOT 1 OR 2
		
	AllCordinate();
		
		
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
