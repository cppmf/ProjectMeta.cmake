
// system includes
#include <iostream>


int main(int argc, char* argv[])
{
#if defined (META_PROJECT_NAME) && defined (META_VERSION)
    std::cout << "This is " << META_PROJECT_NAME << " version " << META_VERSION << std::endl;
#else
    std::cout << "Project meta data not found." << std::endl;
    std::cout << "Check the project declaration." << std::endl;
#endif

    return 0;
}
