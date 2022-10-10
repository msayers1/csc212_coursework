#include "n-queens.h"

int main()
{
    unsigned int n;
    std::cout << "Enter Board Size: ";

    std::cin >> n;

    NQueens Q(n);
    
    std::cout << "Solving by row." << std::endl;
    
    Q.solve("column");

    Q.display_board();

    std::cout << "Solving by row." << std::endl;

    NQueens Qrow(n);

    Qrow.solve("row");

    Qrow.display_board();

    
    return 0;
}