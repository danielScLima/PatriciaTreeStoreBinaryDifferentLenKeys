#ifndef NODEOFPATRICIATREESTOREBINARYDIFFERENTLENKEYS_H
#define NODEOFPATRICIATREESTOREBINARYDIFFERENTLENKEYS_H

/*!
 * \brief The NodeTypeOfPTSBDLK enum
 */
enum NodeTypeOfPTSBDLK
{
    LEAFNodeTypeOfPTSBDLK, BRANCHNodeTypeOfPTSBDLK
};

/*!
 * \brief The NodeOfPatriciaTreeStoreBinaryDifferentLenKeys struct
 */
struct NodeOfPatriciaTreeStoreBinaryDifferentLenKeys
{
public:
    /*!
     * \brief NodeOfPatriciaTreeStoreBinaryDifferentLenKeys
     * \param nodeType
     * \param father
     */
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys
    (
        NodeTypeOfPTSBDLK nodeType,
        NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* father
    ):
        nodeType(nodeType), father(father)
    {

    }

    /*!
     * \brief ~NodeOfPatriciaTreeStoreBinaryDifferentLenKeys
     */
    virtual ~NodeOfPatriciaTreeStoreBinaryDifferentLenKeys()
    {}

    /*!
     * \brief dealockSubtree
     */
    virtual void dealockSubtree() = 0;

    NodeTypeOfPTSBDLK nodeType = NodeTypeOfPTSBDLK::LEAFNodeTypeOfPTSBDLK;
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* father = nullptr;
};

#endif // NODEOFPATRICIATREESTOREBINARYDIFFERENTLENKEYS_H
