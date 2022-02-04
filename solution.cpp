#include "solution.h"

#include <functional>
#include <unordered_map>
#include <stack>
using namespace sol1516;
using namespace std;

/* takeaways
   - construct parent map as we need
     to find p and q's parents
   - if q is in p's subtree there is more
     work to do as we need to move q up the
     tree to replace p
     - remove q from its parent
     - q takes p's place so now p's
       parent is q's parent
       - this is how you we move
         q up the tree
     -  also a special case is when p is
        the root then it has no parent.
        So by replacing we just make q
        the new root
        - you also need to remove q from
          its parent as now q is the new
          root and has no parent
     - add p to q's parent

   - if q is not in p's subtree
     - just remove p from its parent
       and add p to q's children

*/

Node *Solution::move(Node *tree, Node *p, Node *q)
{
  unordered_map<Node *, Node *> parents;
  stack<Node *> stack;
  stack.push(tree);
  /* constrcut the parent map */
  while (!stack.empty())
  {
    auto node = stack.top();
    stack.pop();
    for (auto c : node->children)
    {
      parents[c] = node;
      stack.push(c);
    }
  }

  /* C++ note
     - add this to avoid surprise when use
       the subscript operator
  */
  parents[tree] = nullptr;

  /*
    - p is a direct child of q;
      nothing needs to be changed
  */
  if (parents[p] == q)
    return tree;

  /*
    - find out if q is p's subtree; case 1
  */
  bool qSubTreeOfP = false;
  auto node = q;
  while (node != nullptr)
  {
    if (parents[node] == p)
    {
      qSubTreeOfP = true;
      break;
    }
    node = parents[node];
  }

  if (parents[p] != nullptr)
  {
    auto pParent = parents[p];
    /*
      - it's better to draw a tree
        to visualize how this work
    */
    if (qSubTreeOfP)
    {
      /*
         - find q's parent and remove q from its parent
         - as we are moving q up the tree to where p is
      */
      auto qParent = parents[q];
      auto qIndex = find(qParent->children.begin(), qParent->children.end(), q);
      qParent->children.erase(qIndex);
      /* q take p's place and move up the tree */
      auto pIndex = find(pParent->children.begin(), pParent->children.end(), p);
      *pIndex = q;
    }
    else
    {
      /* simply remove p from its parent */
      auto pIndex = find(pParent->children.begin(), pParent->children.end(), p);
      pParent->children.erase(pIndex);
    }

    /* put p as the very last element of q */
    q->children.push_back(p);
    return tree;
  }
  /* p is the root before being moved  */
  else
  {
    /* remove q from its parent as q is the new root */
    auto qParent = parents[q];
    auto qIndex = find(qParent->children.begin(), qParent->children.end(), q);
    qParent->children.erase(qIndex);
    q->children.push_back(p);
    return q;
  }

  return nullptr;
}