#ifndef PATRICIA_TREE_STORE_BINARY_DIFFERENT_LEN_KEYS_H
#define PATRICIA_TREE_STORE_BINARY_DIFFERENT_LEN_KEYS_H

#include <iostream>
#include <vector>

#include "NodeOfPatriciaTreeStoreBinaryDifferentLenKeys.h"
#include "NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys.h"
#include "NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys.h"

/*!
 * \brief The PatriciaTreeStoreBinaryDifferentLenKeys class
 */
class PatriciaTreeStoreBinaryDifferentLenKeys
{
private:
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* root = nullptr;

    /*!
     * \brief getDrawInNode
     * \param node
     * \param nodesDefinition
     * \param linksDefinition
     * \param nullCounter
     */
    void getDrawInNode
    (
        NodeOfPatriciaTreeStoreBinaryDifferentLenKeys *node,
        std::string &nodesDefinition,
        std::string &linksDefinition,
        int &nullCounter
    );

    /*!
     * \brief getPointerAsString
     * \param node
     * \return
     */
    std::string getPointerAsString
    (
        NodeOfPatriciaTreeStoreBinaryDifferentLenKeys *node
    );

    /*!
     * \brief isEqualUntilPosition
     * \param one
     * \param two
     * \param pos
     * \return
     */
    bool isEqualUntilPosition
    (
        const std::string& one,
        const std::string& two,
        int pos
    );

    /*!
     * \brief isEqualUntilWhichPosition
     * \param one
     * \param two
     * \return
     */
    int isEqualUntilWhichPosition(const std::string& one, const std::string& two);

    /*!
     * \brief replacePointerInFather
     * \param father
     * \param oldSon
     * \param newSon
     */
    void replacePointerInFather
    (
        NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* father,
        NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* oldSon,
        NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* newSon
    );

    /*!
     * \brief getBitSampleForwardInPosAndDifference
     * \param initial
     * \param data
     * \param pos
     * \param indexOfDifference
     * \return
     */
    int getBitSampleForwardInPosAndDifference
    (
        NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* initial,
        const std::string& data,
        int pos,
        int& indexOfDifference
    );

    /*!
     * \brief branchChildrensCount
     * \param branch
     * \return
     */
    bool branchChildrensCount
    (
        NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys *branch
    );
public:
    /*!
     * \brief PatriciaTreeStoreBinaryDifferentLenKeys
     */
    PatriciaTreeStoreBinaryDifferentLenKeys();

    ~PatriciaTreeStoreBinaryDifferentLenKeys();

    /*!
     * \brief getGraphvizDraw
     * \return
     */
    const std::string getGraphvizDraw();

    /*!
     * \brief insert
     * \param data
     * \return
     */
    bool insert(const std::string& data);

    /*!
     * \brief search
     * \param data
     * \return
     */
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* search(const std::string& data);

    /*!
     * \brief remove
     * \param data
     * \return
     */
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys *remove(const std::string& data);

    /*!
     * \brief isAValidDataIoInsert
     * \param data
     * \return
     */
    bool isAValidDataIoInsert(const std::string& data);

    /*!
     * \brief getRoot
     * \return
     */
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* getRoot();
};

#endif // PATRICIA_TREE_STORE_BINARY_DIFFERENT_LEN_KEYS_H
