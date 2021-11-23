
// system includes
#include <iostream>


int main(int argc, char* argv[])
{
#if defined (PROJECT_NAME) && defined (VERSION)
    std::cout << "This is " << PROJECT_NAME << " version " << VERSION << std::endl;
    return 0;
#else
    std::cout << "Project meta data not found." << std::endl;
    std::cout << "Check the project declaration." << std::endl;
    return 1;
#endif
}
