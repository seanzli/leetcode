
#include "../code116/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    Node *in = new Node(1);
    in->left = new Node(2);
    in->left->left = new Node(4);
    in->left->right = new Node(5);
    in->right = new Node(3);
    in->right->left = new Node(6);
    in->right->right = new Node(7);

    test->connect(in);

/*     for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << ",";
        }
        cout << endl;
    } */
    return 0;
}