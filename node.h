#ifndef NODE_H
#define NODE_H

#include <vector>
#include <cinttypes>
using namespace std;

namespace sol1516
{
    struct Node
    {
        int val;
        vector<Node *> children;

        Node() : val(0) {}
        Node(int val) : val(val) {}
    };
}
#endif