#ifndef UTIL_H
#define UTIL_H

#include "node.h"

#include <vector>
#include <string>

using namespace sol1516;
using namespace std;

namespace sol1516
{
    class LevelOrder
    {
    public:
        static vector<Node *> toVec(Node *tree);
        static string toStr(Node *tree);
        static int height(Node *tree);
    };

}

#endif