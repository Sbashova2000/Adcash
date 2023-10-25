#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(int numArgs,char** argStrings)
{
    size_t bestId = -10;
    float firstBestBid = -15.0;
    float secondBestBid = -15.0;
  

    string row;
    
    //giving the name of the file that we want
    char *csvFile = argStrings[1];

    ifstream file(csvFile);
    
    if(file.is_open() == 0)
    {
        cout << "Can not open the file" << endl;
        return -1;
    }

    size_t adId;
    float bid;
    char comma;
    
    while(getline(file,row))
    {
        istringstream adBidFile(row);
        
        if (adBidFile >> adId >> comma >> bid)
        {
            if(firstBestBid < bid)
            {
                secondBestBid = firstBestBid;
                firstBestBid = bid;
                bestId = adId;
            }
            else if (bid != firstBestBid && bid > secondBestBid)
            {
                secondBestBid = bid;
            }
        }
    }

    file.close();

    //cout << argStrings[0] << ", " << argStrings[1];
    if(bestId != -1)
    {
        
        cout << bestId << ", " << secondBestBid << endl;
    }
    else{
        cout << "There`s no valid ads in the file" << endl;
    }

    return 0;
}