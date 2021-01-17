
#include "../code133/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    Node *in = new Node(1);
    Node *in2 = new Node(2);
    Node *in3 = new Node(3);
    Node *in4 = new Node(4);
    in->neighbors.push_back(in2);
    in->neighbors.push_back(in3);
    in2->neighbors.push_back(in);
    in2->neighbors.push_back(in3);
    in3->neighbors.push_back(in3);
    in3->neighbors.push_back(in4);
    in4->neighbors.push_back(in);
    in4->neighbors.push_back(in3);
    
    Node* out = test->cloneGraph(in);

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