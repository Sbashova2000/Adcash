#include <iostream>


size_t minimum(size_t a, size_t b)
{
    return a < b ? a : b;
}


size_t solution(size_t num, size_t counter)
{
    if(num == 1)
        return counter;
    else if(num % 2 == 0)
        return  solution(num / 2,counter+1);
    
    return minimum(solution(num - 1,counter+1), solution(num + 1,counter+1));
}


int main()
{
    size_t num;
    std::cout << "Please enter a positive number: \n";
    std::cin >> num;
    
    if(num <= 0)
    {
        std::cout << "Please enter a POSITIVE number!";
        std::cout<<std::endl;
        return -1;
    }

    int counter = 0;
    std::cout << "To convert " << num << " to 1 there are: " << solution(num,counter) << " steps" << std::endl;

    //                         TESTS
    // std::cout << "To convert " << 4 << " to 1 there are: " << solution(4) << " steps" << std::endl;
    //std::cout << "To convert " << 15 << " to 1 there are: " << solution(15) << " steps" << std::endl;
    //std::cout << "To convert " << 17 << " to 1 there are: " << solution(17) << " steps" << std::endl;

    return 0;
}


