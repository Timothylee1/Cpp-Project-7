/******************************************************************************
\File pa.cpp
\Author Timothy Lee Ke xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: More Problem Solving with vectors and strings 
\Par Programming Assignment #4
\Date 12-02-2022

  \Brief
  This program is used to create a generalized checkerboard of chars in a 
  rectangular or square grid as defined by the command-line parameters.
  The five parameters, excluding the program name, are R (rows), C (columns),
  start (starting char), cycle (cycle size or number of sequences), W (width,
  specifies each grid element printed as W * W square). After forming the grid,
  it is printed and the program ends.
  The grid is represented as a R * C matrix containing [start + (R + C) %cycle]
  characters.
  E.g. 
  R = 5, C = 6, start = 'a', cycle = 4
    abcdab
    bcdabc
    cdabcd
    dabcda
    abcdab

  R = 5, C = 6, start = 'a', cycle = 4, W = 2
    aabbccddaabb
    aabbccddaabb
    bbccddaabbcc
    bbccddaabbcc
    ccddaabbccdd
    ccddaabbccdd
    ddaabbccddaa
    ddaabbccddaa
    aabbccddaabb
    aabbccddaabb
  
  - create_board
        Creates the board containing the grid and the first 4 command-line
        parameters, R, C, start, and cycle. These parameters are parsed 
        to this function through a read only vector type string as command-line
        parameters are of type c-string and are unable to be converted to int 
        as is. This function then converts the vector elements and dynamically
        allocates the board struct with enough memory space, followed by the 
        grid and then assigns data to the respective members in the struct.
        To which it returns a dereferenced pointer of board of type 
        mystery_type, which matches the struct type.

  - print_board
        Prints the board created in create_board function. Before printing, it
        checks the board's members for any values less than or equal to 0. It 
        also checks for starting char and cycle size to see if it will exceed
        the number of ASCII characters, and it checks if the width parameter is
        less than or equals to 0. If any of those are true, the program will 
        exit. If width doesn't contain any value, empty, the prints out a line
        informing the correct input before exiting. Here, the deallocation of 
        memory takes place before function exit.
 
******************************************************************************/
#include "pa.hpp"

namespace hlp2 {

    /*************************************************************************/
    /*! 
    \brief
        Creates the board containing the grid and the first 4 command-line
        parameters, R, C, start, and cycle. These parameters are parsed 
        to this function through a read only vector type string as command-line
        parameters are of type c-string and are unable to be converted to int 
        as is. This function then converts the vector elements and dynamically
        allocates the board struct with enough memory space, followed by the 
        grid and then assigns data to the respective members in the struct.
        To which it returns a dereferenced pointer of board of type 
        mystery_type, which matches the struct type.

    \param cmdline_params
        A vector of type string that contains the 4 command-line parameters.

    \param r
        Converted string to int for rows.

    \param c
        Converted string to int for columns.
    
    \param cy
        Converted string to int for cycle.
    
    \param st
        varible containing the starting char, read from cmdline_params.
    
    \param board
        The dynamically allocated board of type mystery_type that contains the 
        pointer to the struct.

    \param g_r
        Count for grid rows for element assignment.
    
    \param g_c
        Count for grid columns for element assignment.

    */    
    /*************************************************************************/
    mystery_type create_board(std::vector<std::string> const& cmdline_params) {
        int r = stoi(cmdline_params[0]), c = stoi(cmdline_params[1]);
        int cy = stoi(cmdline_params[3]);
        char st = cmdline_params[2][0];
        
        struct mystery_type *board = new mystery_type[r * c];
        board->grid = new char [r * c];
        board->R = r; board->C = c; board->start = st; board->cycle = cy;

        //fill grid with chars
        for (int g_r{0}; g_r < r; ++g_r) {
            for(int g_c{0}; g_c < c; ++g_c) {
                *(board->grid+g_r * c + g_c) = (st +(g_r + g_c)%cy);
            }
        }
        return *board;
    }

    /*************************************************************************/
    /*! 
    \brief
        Prints the board created in create_board function. Before printing, it
        checks the board's members for any values less than or equal to 0. It 
        also checks for starting char and cycle size to see if it will exceed
        the number of ASCII characters, and it checks if the width parameter is
        less than or equals to 0. If any of those are true, the program will 
        exit. If width doesn't contain any value, empty, the prints out a line
        informing the correct input before exiting. Here, the deallocation of 
        memory takes place before function exit.
    
    \param board
        The dynamically allocated board of type mystery_type that contains the 
        read only reference to the struct for which data is to be printed from.

    \param width
        Contains the command-line pramater for width that is parsed from main.
        It is a read only string to prevent modifications.

    \param w
        The converted string to int of width.
    
    \param g_r
        Count for grid rows for element assignment.
    
    \param elementrow
        Count for grid rows for element assignment for width comparison.
    
    \param g_c
        Count for grid columns for element assignment.
    
    \param elementcolumn
        Count for grid columns for element assignment for width comparison.
    */    
    /*************************************************************************/
    void print_board(mystery_type const& board, std::string const& width) { 
        if (width.empty()) {
            std::cout << "Usage: ./program-name rows cols start cycle width\n";
            delete[] board.grid;
            return; //same as return 0; to end the program
        }
        int W = stoi(width);
        
        //checks has to be here else, previous function will exit and main will call this function with no inputs
        //thereby crashing the program
        if (W <= 0) { 
            delete[] board.grid; return; 
        }

        if (board.R <= 0 || board.C <= 0 || board.cycle <= 0 || board.start <= 0) { 
            delete[] board.grid; return; 
        }

        if (board.start + board.cycle > 128) { 
            delete[] board.grid; return; 
        }
        
        for(int g_r{0}; g_r < board.R; ++g_r) {
            for(int elementrow{0}; elementrow < W; ++elementrow) {
                for(int g_c{0}; g_c < board.C; ++g_c) {
                    for(int elementcolumn{0}; elementcolumn < W; ++elementcolumn) {
                        std::cout << static_cast<char>(board.start + (g_r + g_c) % board.cycle);
                    }
                }
            std::cout << "\n";
            }
        }
        delete[] board.grid;
    }
} // end of hlp2
