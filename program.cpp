// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "patriciatreestorebinarydifferentlenkeys.h"

TEST_CASE( "Testing the insert call in the patriciatreestorebinarydifferentlenkeys", "[single-file]" )
{
	PatriciaTreeStoreBinaryDifferentLenKeys tree;
	
	NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* root = tree.getRoot();
	REQUIRE (root == nullptr);
	
	REQUIRE(tree.insert("01010"));
	
	root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nleaf != nullptr);
	REQUIRE(nleaf->data.compare("01010") == 0);
	
	REQUIRE(tree.insert("01011"));
	
	root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::BRANCH);
	NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* nbranch =
	(NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nbranch != nullptr);
	REQUIRE(nbranch->index == 4);
	
	REQUIRE(nbranch->left->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf1 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->left;
	REQUIRE(nleaf1 != nullptr);
	REQUIRE(nleaf1->data.compare("01010") == 0);
	
	REQUIRE(nbranch->right->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf2 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->right;
	REQUIRE(nleaf2 != nullptr);
	REQUIRE(nleaf2->data.compare("01011") == 0);
	
	REQUIRE(tree.insert("11010"));
	
	root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::BRANCH);
	nbranch = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nbranch != nullptr);
	REQUIRE(nbranch->index == 0);
	
	REQUIRE(nbranch->left->nodeType == NodeType::BRANCH);
	NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* nbranch2 =
	(NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->left;
	REQUIRE(nbranch2 != nullptr);
	REQUIRE(nbranch2->index == 4);
	
	REQUIRE(nbranch2->left->nodeType == NodeType::LEAF);
	nleaf1 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->left;
	REQUIRE(nleaf1 != nullptr);
	REQUIRE(nleaf1->data.compare("01010") == 0);
	
	REQUIRE(nbranch2->right->nodeType == NodeType::LEAF);
	nleaf2 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->right;
	REQUIRE(nleaf2 != nullptr);
	REQUIRE(nleaf2->data.compare("01011") == 0);
	
	REQUIRE(nbranch->right->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf3 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->right;
	REQUIRE(nleaf3 != nullptr);
	REQUIRE(nleaf3->data.compare("11010") == 0);
	
	REQUIRE(tree.insert("11110"));
	
	root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::BRANCH);
	nbranch = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nbranch != nullptr);
	REQUIRE(nbranch->index == 0);
	
	REQUIRE(nbranch->left->nodeType == NodeType::BRANCH);
	nbranch2 = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->left;
	REQUIRE(nbranch2 != nullptr);
	REQUIRE(nbranch2->index == 4);
	
	REQUIRE(nbranch->right->nodeType == NodeType::BRANCH);
	NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* nbranch3 =
	(NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->right;
	REQUIRE(nbranch3 != nullptr);
	REQUIRE(nbranch3->index == 2);
	
	//leafs
	
	REQUIRE(nbranch2->left->nodeType == NodeType::LEAF);
	nleaf1 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->left;
	REQUIRE(nleaf1 != nullptr);
	REQUIRE(nleaf1->data.compare("01010") == 0);
	
	REQUIRE(nbranch2->right->nodeType == NodeType::LEAF);
	nleaf2 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->right;
	REQUIRE(nleaf2 != nullptr);
	REQUIRE(nleaf2->data.compare("01011") == 0);
	
	REQUIRE(nbranch3->left->nodeType == NodeType::LEAF);
	nleaf3 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->left;
	REQUIRE(nleaf3 != nullptr);
	REQUIRE(nleaf3->data.compare("11010") == 0);
	
	REQUIRE(nbranch3->right->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf4 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->right;
	REQUIRE(nleaf4 != nullptr);
	REQUIRE(nleaf4->data.compare("11110") == 0);
}

TEST_CASE( "Testing the insert call in the patriciatreestorebinarydifferentlenkeys, with diferent lengths", "[single-file]" )
{
	PatriciaTreeStoreBinaryDifferentLenKeys tree;
	
	NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* root = tree.getRoot();
	REQUIRE (root == nullptr);
	
	REQUIRE(tree.insert("01010"));
	
	root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nleaf != nullptr);
	REQUIRE(nleaf->data.compare("01010") == 0);
	
	REQUIRE(tree.insert("01011"));
	
	root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::BRANCH);
	NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* nbranch =
	(NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nbranch != nullptr);
	REQUIRE(nbranch->index == 4);
	
	REQUIRE(nbranch->left->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf1 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->left;
	REQUIRE(nleaf1 != nullptr);
	REQUIRE(nleaf1->data.compare("01010") == 0);
	
	REQUIRE(nbranch->right->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf2 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->right;
	REQUIRE(nleaf2 != nullptr);
	REQUIRE(nleaf2->data.compare("01011") == 0);
	
	REQUIRE(tree.insert("11010"));
	
	root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::BRANCH);
	nbranch = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nbranch != nullptr);
	REQUIRE(nbranch->index == 0);
	
	REQUIRE(nbranch->left->nodeType == NodeType::BRANCH);
	NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* nbranch2 =
	(NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->left;
	REQUIRE(nbranch2 != nullptr);
	REQUIRE(nbranch2->index == 4);
	
	REQUIRE(nbranch2->left->nodeType == NodeType::LEAF);
	nleaf1 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->left;
	REQUIRE(nleaf1 != nullptr);
	REQUIRE(nleaf1->data.compare("01010") == 0);
	
	REQUIRE(nbranch2->right->nodeType == NodeType::LEAF);
	nleaf2 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->right;
	REQUIRE(nleaf2 != nullptr);
	REQUIRE(nleaf2->data.compare("01011") == 0);
	
	REQUIRE(nbranch->right->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf3 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->right;
	REQUIRE(nleaf3 != nullptr);
	REQUIRE(nleaf3->data.compare("11010") == 0);
	
	REQUIRE(tree.insert("11110"));
	
	root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::BRANCH);
	nbranch = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nbranch != nullptr);
	REQUIRE(nbranch->index == 0);
	
	REQUIRE(nbranch->left->nodeType == NodeType::BRANCH);
	nbranch2 = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->left;
	REQUIRE(nbranch2 != nullptr);
	REQUIRE(nbranch2->index == 4);
	
	REQUIRE(nbranch->right->nodeType == NodeType::BRANCH);
	NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* nbranch3 =
	(NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->right;
	REQUIRE(nbranch3 != nullptr);
	REQUIRE(nbranch3->index == 2);
	
	//leafs
	
	REQUIRE(nbranch2->left->nodeType == NodeType::LEAF);
	nleaf1 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->left;
	REQUIRE(nleaf1 != nullptr);
	REQUIRE(nleaf1->data.compare("01010") == 0);
	
	REQUIRE(nbranch2->right->nodeType == NodeType::LEAF);
	nleaf2 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->right;
	REQUIRE(nleaf2 != nullptr);
	REQUIRE(nleaf2->data.compare("01011") == 0);
	
	REQUIRE(nbranch3->left->nodeType == NodeType::LEAF);
	nleaf3 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->left;
	REQUIRE(nleaf3 != nullptr);
	REQUIRE(nleaf3->data.compare("11010") == 0);
	
	REQUIRE(nbranch3->right->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf4 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->right;
	REQUIRE(nleaf4 != nullptr);
	REQUIRE(nleaf4->data.compare("11110") == 0);
	
	//tamanhos diferentes
	REQUIRE(tree.insert("11"));
	
	root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::BRANCH);
	nbranch = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nbranch != nullptr);
	REQUIRE(nbranch->index == 0);
	
	REQUIRE(nbranch->left->nodeType == NodeType::BRANCH);
	nbranch2 = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->left;
	REQUIRE(nbranch2 != nullptr);
	REQUIRE(nbranch2->index == 4);
	
	REQUIRE(nbranch->right->nodeType == NodeType::BRANCH);
	nbranch3 =
	(NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->right;
	REQUIRE(nbranch3 != nullptr);
	REQUIRE(nbranch3->index == 2);
	
	//leafs
	
	REQUIRE(nbranch2->left->nodeType == NodeType::LEAF);
	nleaf1 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->left;
	REQUIRE(nleaf1 != nullptr);
	REQUIRE(nleaf1->data.compare("01010") == 0);
	
	REQUIRE(nbranch2->right->nodeType == NodeType::LEAF);
	nleaf2 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->right;
	REQUIRE(nleaf2 != nullptr);
	REQUIRE(nleaf2->data.compare("01011") == 0);
	
	REQUIRE(nbranch3->left->nodeType == NodeType::LEAF);
	nleaf3 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->left;
	REQUIRE(nleaf3 != nullptr);
	REQUIRE(nleaf3->data.compare("11010") == 0);
	
	REQUIRE(nbranch3->right->nodeType == NodeType::LEAF);
	nleaf4 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->right;
	REQUIRE(nleaf4 != nullptr);
	REQUIRE(nleaf4->data.compare("11110") == 0);
	
	//new leaf
	REQUIRE(nbranch3->missing->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf5 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->missing;
	REQUIRE(nleaf5 != nullptr);
	REQUIRE(nleaf5->data.compare("11") == 0);
	
	//second insertion
	REQUIRE(tree.insert("0101"));
	
	root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::BRANCH);
	nbranch = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nbranch != nullptr);
	REQUIRE(nbranch->index == 0);
	
	REQUIRE(nbranch->left->nodeType == NodeType::BRANCH);
	nbranch2 = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->left;
	REQUIRE(nbranch2 != nullptr);
	REQUIRE(nbranch2->index == 4);
	
	REQUIRE(nbranch->right->nodeType == NodeType::BRANCH);
	nbranch3 =
	(NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->right;
	REQUIRE(nbranch3 != nullptr);
	REQUIRE(nbranch3->index == 2);
	
	//leafs
	
	REQUIRE(nbranch2->left->nodeType == NodeType::LEAF);
	nleaf1 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->left;
	REQUIRE(nleaf1 != nullptr);
	REQUIRE(nleaf1->data.compare("01010") == 0);
	
	REQUIRE(nbranch2->right->nodeType == NodeType::LEAF);
	nleaf2 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->right;
	REQUIRE(nleaf2 != nullptr);
	REQUIRE(nleaf2->data.compare("01011") == 0);
	
	REQUIRE(nbranch3->left->nodeType == NodeType::LEAF);
	nleaf3 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->left;
	REQUIRE(nleaf3 != nullptr);
	REQUIRE(nleaf3->data.compare("11010") == 0);
	
	REQUIRE(nbranch3->right->nodeType == NodeType::LEAF);
	nleaf4 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->right;
	REQUIRE(nleaf4 != nullptr);
	REQUIRE(nleaf4->data.compare("11110") == 0);
	
	REQUIRE(nbranch3->missing->nodeType == NodeType::LEAF);
	nleaf5 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->missing;
	REQUIRE(nleaf5 != nullptr);
	REQUIRE(nleaf5->data.compare("11") == 0);
	
	//new leaf
	REQUIRE(nbranch2->missing->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf6 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->missing;
	REQUIRE(nleaf6 != nullptr);
	REQUIRE(nleaf6->data.compare("0101") == 0);
	
	//010 - change structure
	REQUIRE(tree.insert("010"));
	
	root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::BRANCH);
	nbranch = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nbranch != nullptr);
	REQUIRE(nbranch->index == 0);
	
	REQUIRE(nbranch->left->nodeType == NodeType::BRANCH);
	nbranch2 = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->left;
	REQUIRE(nbranch2 != nullptr);
	REQUIRE(nbranch2->index == 3);
	
	REQUIRE(nbranch->right->nodeType == NodeType::BRANCH);
	nbranch3 =
	(NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->right;
	REQUIRE(nbranch3 != nullptr);
	REQUIRE(nbranch3->index == 2);
	
	REQUIRE(nbranch3->left->nodeType == NodeType::LEAF);
	nleaf3 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->left;
	REQUIRE(nleaf3 != nullptr);
	REQUIRE(nleaf3->data.compare("11010") == 0);
	
	REQUIRE(nbranch3->right->nodeType == NodeType::LEAF);
	nleaf4 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->right;
	REQUIRE(nleaf4 != nullptr);
	REQUIRE(nleaf4->data.compare("11110") == 0);
	
	REQUIRE(nbranch3->missing->nodeType == NodeType::LEAF);
	nleaf5 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->missing;
	REQUIRE(nleaf5 != nullptr);
	REQUIRE(nleaf5->data.compare("11") == 0);
	
	REQUIRE(nbranch2->right->nodeType == NodeType::BRANCH);
	NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* nbranch4 =
	(NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->right;
	REQUIRE(nbranch4 != nullptr);
	REQUIRE(nbranch4->index == 4);
	
	REQUIRE(nbranch2->left == nullptr);
	
	REQUIRE(nbranch2->missing->nodeType == NodeType::LEAF);
	nleaf6 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->missing;
	REQUIRE(nleaf6 != nullptr);
	REQUIRE(nleaf6->data.compare("010") == 0);
	
	REQUIRE(nbranch4->left->nodeType == NodeType::LEAF);
	nleaf1 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch4->left;
	REQUIRE(nleaf1 != nullptr);
	REQUIRE(nleaf1->data.compare("01010") == 0);
	
	REQUIRE(nbranch4->right->nodeType == NodeType::LEAF);
	nleaf2 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch4->right;
	REQUIRE(nleaf2 != nullptr);
	REQUIRE(nleaf2->data.compare("01011") == 0);
	
	//it is missing one
	REQUIRE(nbranch4->missing->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf7 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch4->missing;
	REQUIRE(nleaf7 != nullptr);
	REQUIRE(nleaf7->data.compare("0101") == 0);
}

TEST_CASE( "Testing the remove call in the patriciatreestorebinarydifferentlenkeys", "[single-file]" )
{
	PatriciaTreeStoreBinaryDifferentLenKeys tree;
	
	REQUIRE(tree.insert("01010"));
	REQUIRE(tree.insert("01011"));
	REQUIRE(tree.insert("11010"));
	REQUIRE(tree.insert("11110"));
	
	NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::BRANCH);
	NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* nbranch =
	(NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nbranch != nullptr);
	REQUIRE(nbranch->index == 0);
	
	REQUIRE(nbranch->left->nodeType == NodeType::BRANCH);
	NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* nbranch2 =
	(NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->left;
	REQUIRE(nbranch2 != nullptr);
	REQUIRE(nbranch2->index == 4);
	
	REQUIRE(nbranch->right->nodeType == NodeType::BRANCH);
	NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* nbranch3 =
	(NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->right;
	REQUIRE(nbranch3 != nullptr);
	REQUIRE(nbranch3->index == 2);
	
	//leafs
	
	REQUIRE(nbranch2->left->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf1 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->left;
	REQUIRE(nleaf1 != nullptr);
	REQUIRE(nleaf1->data.compare("01010") == 0);
	
	REQUIRE(nbranch2->right->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf2 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->right;
	REQUIRE(nleaf2 != nullptr);
	REQUIRE(nleaf2->data.compare("01011") == 0);
	
	REQUIRE(nbranch3->left->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf3 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->left;
	REQUIRE(nleaf3 != nullptr);
	REQUIRE(nleaf3->data.compare("11010") == 0);
	
	REQUIRE(nbranch3->right->nodeType == NodeType::LEAF);
	NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* nleaf4 =
	(NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch3->right;
	REQUIRE(nleaf4 != nullptr);
	REQUIRE(nleaf4->data.compare("11110") == 0);
	
	NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* rem = tree.remove("11010");
	REQUIRE(rem != nullptr);
	delete rem;
	
	root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::BRANCH);
	nbranch = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nbranch != nullptr);
	REQUIRE(nbranch->index == 0);
	
	REQUIRE(nbranch->left->nodeType == NodeType::BRANCH);
	nbranch2 = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->left;
	REQUIRE(nbranch2 != nullptr);
	REQUIRE(nbranch2->index == 4);
	
	//leafs
	
	REQUIRE(nbranch2->left->nodeType == NodeType::LEAF);
	nleaf1 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->left;
	REQUIRE(nleaf1 != nullptr);
	REQUIRE(nleaf1->data.compare("01010") == 0);
	
	REQUIRE(nbranch2->right->nodeType == NodeType::LEAF);
	nleaf2 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->right;
	REQUIRE(nleaf2 != nullptr);
	REQUIRE(nleaf2->data.compare("01011") == 0);
	
	REQUIRE(nbranch->right->nodeType == NodeType::LEAF);
	nleaf4 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch->right;
	REQUIRE(nleaf4 != nullptr);
	REQUIRE(nleaf4->data.compare("11110") == 0);
	
	rem = tree.remove("11110");
	REQUIRE(rem != nullptr);
	delete rem;
	
	root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::BRANCH);
	nbranch2 = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nbranch2 != nullptr);
	REQUIRE(nbranch2->index == 4);
	
	REQUIRE(nbranch2->left->nodeType == NodeType::LEAF);
	nleaf1 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->left;
	REQUIRE(nleaf1 != nullptr);
	REQUIRE(nleaf1->data.compare("01010") == 0);
	
	REQUIRE(nbranch2->right->nodeType == NodeType::LEAF);
	nleaf2 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) nbranch2->right;
	REQUIRE(nleaf2 != nullptr);
	REQUIRE(nleaf2->data.compare("01011") == 0);
	
	rem = tree.remove("01011");
	REQUIRE(rem != nullptr);
	delete rem;
	
	root = tree.getRoot();
	REQUIRE (root != nullptr);
	
	REQUIRE(root->nodeType == NodeType::LEAF);
	nleaf1 = (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) root;
	REQUIRE(nleaf1 != nullptr);
	REQUIRE(nleaf1->data.compare("01010") == 0);
	
	rem = tree.remove("01010");
	REQUIRE(rem != nullptr);
	delete rem;
	
	root = tree.getRoot();
	REQUIRE (root == nullptr);
	
}

TEST_CASE( "Testing the search call in the patriciatreestorebinarydifferentlenkeys", "[single-file]" )
{
	PatriciaTreeStoreBinaryDifferentLenKeys tree;
	
	REQUIRE(tree.insert("01010"));
	REQUIRE(tree.insert("01011"));
	REQUIRE(tree.insert("11010"));
	REQUIRE(tree.insert("11110"));
	
	REQUIRE(tree.search("01010") != nullptr);
	REQUIRE(tree.search("01011") != nullptr);
	REQUIRE(tree.search("11010") != nullptr);
	REQUIRE(tree.search("11110") != nullptr);
}

TEST_CASE( "Testing the search call, case 2, in the patriciatreestorebinarydifferentlenkeys", "[single-file]" )
{
	PatriciaTreeStoreBinaryDifferentLenKeys tree;
	
	REQUIRE(tree.insert("01010"));
	REQUIRE(tree.insert("01011"));
	REQUIRE(tree.insert("11010"));
	REQUIRE(tree.insert("11110"));
	
	REQUIRE(tree.search("01010") != nullptr);
	REQUIRE(tree.search("01011") != nullptr);
	REQUIRE(tree.search("11010") != nullptr);
	REQUIRE(tree.search("11110") != nullptr);
	
	NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* rem = tree.remove("01010");
	REQUIRE(rem != nullptr);
	delete rem;
	rem = tree.remove("01011");
	REQUIRE(rem != nullptr);
	delete rem;
	
	REQUIRE(tree.search("01010") == nullptr);
	REQUIRE(tree.search("01011") == nullptr);
	REQUIRE(tree.search("11010") != nullptr);
	REQUIRE(tree.search("11110") != nullptr);
}
