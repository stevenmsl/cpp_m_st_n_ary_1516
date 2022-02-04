#include <iostream>
#include <vector>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1516;

/*
 Input: root = [1,null,3,2,4,null,5,6]
 Output: [1,null,3,2,4,null,5,6]
*/

Node *testFixture1()
{
  /* build the tree first */
  auto *tree = new Node(1);

  tree->children.push_back(new Node(2));
  tree->children.push_back(new Node(3));

  tree->children[0]->children.push_back(new Node(4));
  tree->children[0]->children.push_back(new Node(5));
  tree->children[1]->children.push_back(new Node(6));

  tree->children[0]->children[0]->children.push_back(new Node(7));
  tree->children[0]->children[0]->children.push_back(new Node(8));

  return tree;
}

void test1()
{
  auto tree = testFixture1();

  cout << "Test 1" << endl;
  Solution sol;

  /* 4*/
  auto p = tree->children[0]->children[0];
  /* 7 */
  auto q = tree;

  auto root = sol.move(tree, p, q);
  cout << "result: use debugger to verify" << endl;
}

void test4()
{
  auto tree = testFixture1();

  cout << "Test 4" << endl;
  Solution sol;

  /* 2*/
  auto p = tree->children[0];
  /* 7 */
  auto q = tree->children[0]->children[0]->children[0];

  auto root = sol.move(tree, p, q);
  cout << "result: use debugger to verify" << endl;
}

void testLevelOrderHeight()
{
  auto fixture = testFixture1();
  cout << " Test Level Order Height - expect to see 5" << endl;
  cout << "tree height: " << LevelOrder::height(fixture) << endl;
}

void tesLevelOrderToVec()
{
  auto fixture = testFixture1();
  cout << " Test Level Order to Vec" << endl;
  cout << "result: use debugger to verify result" << endl;

  auto tree = LevelOrder::toVec(fixture);
}

void testXOR()
{
  int root = 0;
  int node = 1;

  root ^= node;

  root ^= 2;
  root ^= 3;
  root ^= 2;
  root ^= 3;
}
void testToStr()
{
  auto fixture = testFixture1();
  cout << LevelOrder::toStr(fixture) << endl;
}

main()
{
  test1();
  test4();
  //    testLevelOrderHeight();
  //    tesLevelOrderToVec();
  //   testXOR();
  // testToStr();
  return 0;
}