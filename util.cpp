#include "util.h"
#include <vector>
#include <string>
#include <queue>
#include <functional>
using namespace sol1516;
using namespace std;

/* C++ notes
   - queue.front() won't remove the item
     from the queue; you need to call
     the queue.pop() to remove the item
     from the queue
*/
vector<Node *> LevelOrder::toVec(Node *tree)
{
    vector<Node *> result;
    if (tree == nullptr)
        return result;
    queue<Node *> q;
    q.push(tree);

    /*
      - you don't really need to know how many nodes
        at a certain level
    */
    while (!q.empty())
    {
        /* visiting the node */
        auto node = q.front();
        result.push_back(node);
        q.pop();
        for (auto c : node->children)
            q.push(c);
    }

    return result;
}

/* this needs mor work */
string LevelOrder::toStr(Node *tree)
{
    if (tree == nullptr)
        return "[]";

    queue<Node *> q;
    string result;

    result += "[";

    q.push(tree);

    while (!q.empty())
    {
        if (q.front() != tree)
            /* level separator */
            result += "null";
        /* number of nodes at a given level */
        auto count = q.size();

        while (count > 0)
        {
            auto node = q.front();
            result += to_string(node->val);
            q.pop();
            count--;
            for (auto c : node->children)
                q.push(c);
        }
    }

    return result;
}

int LevelOrder::height(Node *tree)
{

    if (tree == nullptr)
        return 0;

    function<int(Node *, int)> visit = [&visit](Node *node, int parentLevel)
    {
        int maxLevel = parentLevel + 1;
        for (auto c : node->children)
        {
            auto level = visit(c, parentLevel + 1);
            if (level > maxLevel)
                maxLevel = level;
        }
        return maxLevel;
    };
    /* root has not parent hence the parent level is 0 */
    return visit(tree, 0);
}