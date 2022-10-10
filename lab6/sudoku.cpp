#include "sudoku.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
#include <stack>
Sudoku::Sudoku() {
    this->board = nullptr;
}

Sudoku::~Sudoku() {
    delete this->board;
}

Sudoku::Sudoku(std::string f_name) {
    this->board = new std::vector<std::vector<unsigned int >>(this->BOARD_SIZE, std::vector<unsigned int>(BOARD_SIZE));

    unsigned int i = 0, j = 0;

    std::ifstream file(f_name);
    std::string line;

    while(std::getline(file, line)) {
        std::stringstream iss(line);
        unsigned int temp;
        while(iss >> temp) {
            (*this->board)[i][j] = temp;
            j++;
        }
        j = 0;
        i++;
    }
}

bool Sudoku::solve() {
    unsigned int row, col;
    row = 0;
    col = 0;
    solve_rec(row, col);   

    // this triggers backtracking
    return false;
}

bool Sudoku::solve_rec(unsigned int& row, unsigned int& col){
    std::stack<std::pair<int, int>> stack;
    std::pair<int, int> set;
    std::pair<int, int> remove_pair;
    if(find_empty_location(row, col) == false){
        return true;
    }
    int num = 1;
    for(num = 1; num < 10; num++){
        //std::cout << row << " by " << col << ":" << num << std::endl;
        if(is_valid(row, col, num)){
            std::cout << row << " by " << col << " set to " << num << std::endl;
            (*this->board)[row][col] = num;
            // set.first = row;
            // set.second = col;
            // stack.push(set);
            if(solve_rec(row, col)){
                return true;
            }
                    
        }
        
    }
    //remove_pair = stack.top();
    // std::cout << typeid(remove_pair).name() << std::endl;//<< ":" <<  (remove_pair).first << std::endl;
    // (*this->board)[(remove_pair).first][(remove_pair).second] = 0;
    std::cout << row << " by " << col << " cleared" << std::endl;
    (*this->board)[row][col] = 0;
    solve_rec(row,col);
    // if(find_empty_location(row, col) == true){
    //     //std::cout << row << " by " << col << std::endl;
    //     solve_rec(row, col);
    // }
    // stack.pop();
    return false;
}

bool Sudoku::find_empty_location(unsigned int& row, unsigned int& col) {
    for (row = 0; row < this->BOARD_SIZE; row++) {
        for (col = 0; col < this->BOARD_SIZE; col++) {
            if ((*this->board)[row][col] == 0) { return true; }
        }
    }
    return false;
}



// If this is an empty space & the given number does not exist in the same
// row, column, or box then it will return true.
bool Sudoku::is_valid(unsigned int row, unsigned int col, int num){
    return (*this->board)[row][col] == 0
            && !check_row(row, num)
            && !check_col(col, num)
            && !check_box(row - row % 3, col - col % 3, num);
}

bool Sudoku::check_row(unsigned int row, unsigned int num){
    for (int col = 0; col < this->BOARD_SIZE; col++){
        if ((*this->board)[row][col] == num){ return true; }
    }
    return false;
}

bool Sudoku::check_col(unsigned int col, unsigned int num){
    for (int row = 0; row < this->BOARD_SIZE; row++){
        if ((*this->board)[row][col] == num) { return true; }
    }
    return false;
}

bool Sudoku::check_box(unsigned int boxStartRow, unsigned int boxStartCol, unsigned int num){
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            if ((*this->board)[row + boxStartRow][col + boxStartCol] == num) { return true; }
        }
    }
    return false;
}

void Sudoku::display_board(){
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++){
            std::cout << (*this->board)[i][j] << " ";
        }
        std::cout << std::endl;
    }
}