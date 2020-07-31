#ifndef NODEBRANCHOFPATRICIATREESTOREBINARYDIFFERENTLENKEYS_H
#define NODEBRANCHOFPATRICIATREESTOREBINARYDIFFERENTLENKEYS_H

#include "NodeOfPatriciaTreeStoreBinaryDifferentLenKeys.h"
#include <iostream>

/*!
 * \brief The NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys struct
 */
struct NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys:
        public NodeOfPatriciaTreeStoreBinaryDifferentLenKeys
{
public:
    /*!
     * \brief NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys
     * \param father
     * \param index
     */
    NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys
    (
        NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* father,
        int index
    ):
        NodeOfPatriciaTreeStoreBinaryDifferentLenKeys(NodeTypeOfPTSBDLK::BRANCHNodeTypeOfPTSBDLK, father),
        index(index)
    {

    }

    /*!
     * \brief dealockSubtree
     */
    virtual void dealockSubtree()
    {
		if (left != nullptr)
		{
			left->dealockSubtree();
			delete left;
		}

		if (right != nullptr)
		{
			right->dealockSubtree();
			delete right;
		}
    }

    int index = 0; //A posição de diferença
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* left = nullptr;//left no index (menor valor)
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* right = nullptr;//right no index (maior valor)
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* missing = nullptr;//nó que não tem posição index (tem index-1)
};

#endif // NODEBRANCHOFPATRICIATREESTOREBINARYDIFFERENTLENKEYS_H
