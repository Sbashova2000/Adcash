#include <iostream>
#include <fstream>
#include <time.h>

int main()
{
    srand(time(0));

    std::ofstream ofile("File.csv");
    if (ofile.is_open())
    {
        /*ofile << "1, 0.5" << endl;
        ofile << "2, 33" << endl;
        ofile << "3, 12" << endl;
        ofile << "4, 33.5" << endl;*/

        for (int i = 1; i <= 10000; i++)
        {
            //generate random bids 
            ofile << i << ", " << (rand() % 10000) / 100.0 << std::endl;
        }
        ofile.close();
    }
    else
    {
        std::cout << "Can not open the file!" << std::endl;
    }

    return 0;
}