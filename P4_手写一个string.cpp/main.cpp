#include <iostream>
#include "xstring.hpp"
using namespace std;

int main() {


   xstring s1="hihihihi";
   xstring s2(s1);
   xstring s3 = std::move(s1);

    xstring s4 = "hello";

    std::cout << s3 << std::endl;

    return 0;
}
