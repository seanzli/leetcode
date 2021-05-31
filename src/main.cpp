
#include "../code/offer_37/solution.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    Codec *test = new Codec();
    
    string t = "[1,2,3,4,null,null,5,5,null,1]";

    TreeNode* head =  test->deserialize(t);
    
    return 0;
}