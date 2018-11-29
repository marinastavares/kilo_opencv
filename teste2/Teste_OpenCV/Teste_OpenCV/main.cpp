#include "FindCenter.hpp"



int main() {
    
    VideoCapture cap("/Users/marinastavares/Dev_Kilobots/kilobots/kilobots_tests/tentativa1.mov");
    char arquivo[] ="/Users/marinastavares/Dev_Kilogui/kilo_opencv/teste2/Teste_OpenCV/Teste_OpenCV/id_xy.txt";
    const char *filename = "/Users/marinastavares/Dev_Kilogui/kilo_opencv/teste2/Teste_OpenCV/Teste_OpenCV/id_xy.txt";
    
    ArUco (cap, arquivo, filename);
    
    
    return 0;
}
