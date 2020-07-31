#ifndef NODELEAFOFPATRICIATREESTOREBINARYDIFFERENTLENKEYS_H
#define NODELEAFOFPATRICIATREESTOREBINARYDIFFERENTLENKEYS_H

#include "NodeOfPatriciaTreeStoreBinaryDifferentLenKeys.h"
#include <iostream>

/*!
 * \brief The NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys struct
 */
struct NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys:
        public NodeOfPatriciaTreeStoreBinaryDifferentLenKeys
{
public:
    /*!
     * \brief NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys
     * \param data
     * \param father
     * \param index
     */
    NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys
    (
        const std::string& data,
        NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* father,
        int index
    ):
        NodeOfPatriciaTreeStoreBinaryDifferentLenKeys(NodeTypeOfPTSBDLK::LEAFNodeTypeOfPTSBDLK, father),
        index(index), data(data)
    {

    }

    /*!
     * \brief dealockSubtree
     */
    virtual void dealockSubtree()
    {
        //do nothing
    }

    int index = 0;
    std::string data; //todas as leafs tem o mesmo tamanho de data
};

#endif // NODELEAFOFPATRICIATREESTOREBINARYDIFFERENTLENKEYS_H
