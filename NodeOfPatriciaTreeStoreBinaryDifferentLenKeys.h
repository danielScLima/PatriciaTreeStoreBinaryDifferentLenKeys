#ifndef NODEOFPATRICIATREESTOREBINARYDIFFERENTLENKEYS_H
#define NODEOFPATRICIATREESTOREBINARYDIFFERENTLENKEYS_H

/*!
 * \brief The NodeType enum
 */
enum NodeType
{
    LEAF, BRANCH
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
        NodeType nodeType,
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

    NodeType nodeType = NodeType::LEAF;
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* father = nullptr;
};

#endif // NODEOFPATRICIATREESTOREBINARYDIFFERENTLENKEYS_H
