
#include "pa.hpp"

int main (int argc, char *argv[]) {
    
    //argc counts the number of parsed cmd arguments; Always >= 1 cuz it counts
    //program name. Therefore, since argv which contains the parsed cmd 
    //arguments, argv[0] will contain the program name. With 5 other required 
    //cmd arguments, we need to check for the correct number of inputs.
    //if (argc != 6) {
    //    std::cout << "Usage: ./program-name rows cols start cycle width\n";
    //    exit(0); //same as return 0; to end the program
    //}

    std::vector<std::string> cmdline_params;
    for (int i{0}; i<4; ++i) {
        cmdline_params.push_back(argv[i+1]);
    }
    
    struct hlp2::mystery_type const& board = hlp2::create_board(cmdline_params);

    std::string width;
    width = argc < 6 ? "" : argv[5];

    hlp2::print_board(board, width);
   
    return 0;
}
