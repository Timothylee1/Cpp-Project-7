/******************************************************************************
\File pa.hpp
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
#include <iostream>
#include <vector>
#include <string>

namespace hlp2 {

    struct mystery_type {
        char* grid;
        int R; //Rows
        int C; //Columns
        char start; //Starting char, from 0 to 127
        int cycle; //Number of chars in the sequence; Cycle size
    };

    // cmdline_params includes all command-line parameters
    // except first parameter [which is the program'name] ...
    mystery_type create_board(std::vector<std::string> const& cmdline_params);
    // width could be empty string if the required number of command-line
    // parameters are not provided by client ...
    void print_board(mystery_type const& board, std::string const& width);
} // end of hlp2
