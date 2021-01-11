#include "pch.h"
#include "MazeTraversal.h"
#pragma once 

#include<iostream> 
#include<fstream>
#include<windows.h> 
using namespace std;

MazeTraversal::MazeTraversal(int size) :size(size) {
    curr_row = 2;
    curr_col = 0;
    start_row = 2;
    start_col = 0;
    end_row = 4;
    end_col = 11;
    Dir = '0';
    cellWidthPx = 40;
    cellWidthPx = 40;
    maze = new char* [size];
    for (int i = 0; i < size; i++)
        maze[i] = new char[size];
    LoadMaze();
};
void MazeTraversal::LoadMaze() {
    ifstream in("maze.txt");
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            in >> maze[i][j];

}// call in constructor  
void MazeTraversal::moveUp() {
    if (curr_row > 0 && maze[curr_row - 1][curr_col] != '#')
    {
        curr_row--;
    }
}
void MazeTraversal::moveLeft() {
    if (curr_col > 0 && maze[curr_row][curr_col - 1] != '#')
    {
        curr_col--;
    }
}
void MazeTraversal::moveDown() {
    if (curr_row < 11 && maze[curr_row + 1][curr_col] != '#')
    {
        curr_row++;
    }
}
void MazeTraversal::moveRight() {
    if (curr_col < 11 && maze[curr_row][curr_col + 1] != '#' )
    {
        curr_col++;
    }
}
//bool MazeTraversal::DestinationReached() {
//
//    if (curr_row == 4 && curr_col == 11)
//    {
//        return 1;
//    }
//    else
//        return 0;
//}

bool MazeTraversal::DestinationReached() {
    if (this->curr_col == this->end_col && this->curr_row == this->end_row)return true;
    return false;
}
void MazeTraversal::display(CDC* pDC) {
    HDC hRes = *pDC;
    CImage* cimage = new CImage();
    cimage->Load(L"images\\wall5.png");//images folder is placed in working directory 	                  
   // pDC->FillSolidRect(0, 0, 480, 480, RGB(0, 0, 0));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (maze[i][j] == '#')
                cimage->Draw(hRes, j * 40, i * 40, 40, 40);

    CImage* cimage1 = new CImage();
    cimage1->Load(L"images\\right.png");//images folder is placed in working directory 	                  
    //pDC->FillSolidRect(curr_col * 40, curr_row * 40, 40, 40, RGB(0, 0, 0));
    cimage1->Draw(hRes, curr_col * 40, curr_row * 40, 40, 40);
    cimage1->Destroy();

}

void MazeTraversal::moveToNextCell() {
    if (maze[curr_row][(curr_col + 1)] != '#')
        curr_col++;
    if (maze[curr_row][(curr_col - 1)] != '#')
        curr_col--;
    if (maze[curr_row + 1][curr_col] != '#')
        curr_row++;
    else if (maze[curr_row - 1][curr_col] != '#')
        curr_row--;
}// it will be needed for automation  
MazeTraversal::~MazeTraversal() {
    for (int i = 0; i < size; i++)
        delete[]maze[i];
    delete[]maze;
}
//getter functions  
int MazeTraversal::getCellWidthPx() {
    return 40;
}
int MazeTraversal::getCellHeightPx() 
{
    return 40;
}

int MazeTraversal::getSize() {
    return size;
}
int MazeTraversal::getStartRow() { 
    return start_row; 
}
int MazeTraversal::getStartCol() {
    return start_col; 
}
int MazeTraversal::getCurrRow() { 
    return curr_row;
}
int MazeTraversal::getCurrCol() {
    return curr_col; 
}
char MazeTraversal::getCellValueAt(int i, int j) {
    return maze[i][j];
} 
