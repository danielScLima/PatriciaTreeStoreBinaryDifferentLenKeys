#include "patriciatreestorebinarydifferentlenkeys.h"

#include <sstream> //for std::stringstream
#include <string>  //for std::string

PatriciaTreeStoreBinaryDifferentLenKeysDS::PatriciaTreeStoreBinaryDifferentLenKeysDS
(

)
{
}

NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* PatriciaTreeStoreBinaryDifferentLenKeysDS::getRoot()
{
    return this->root;
}

void PatriciaTreeStoreBinaryDifferentLenKeysDS::clearRoot()
{
    //it wa cleaned
    this->root = nullptr;
}

bool PatriciaTreeStoreBinaryDifferentLenKeysDS::insert(const std::string& data)
{
    bool valid = isAValidDataIoInsert(data);
    if (valid == false)
        return false;

    if (root == nullptr)
    {
        root = new NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys(data, nullptr, 0);
    }
    else
    {
        NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* tmp = root;
        while (true)
        {
            if (tmp->nodeType == NodeTypeOfPTSBDLK::LEAFNodeTypeOfPTSBDLK)
            {
                NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* leaf =
                        (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) tmp;
                bool ret = isEqualUntilPosition
                (
                    data,
                    leaf->data,
                    //leaf->index
                    leaf->data.length()-1
                );

                //Verifica se é igual até essa posição do nó
                if (ret && (data.length() == leaf->data.length())) //deve quebrar esse nó
                {
                    return false; //entrada duplicada
                }
                else if (ret && (data.length() > leaf->data.length()))
                {
                    //atualmente não acontece
                    //int pos = isEqualUntilWhichPosition(data, leaf->data);
                    //pos = pos+1; //+1 é o ponto de diferença

                    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* backupFather = leaf->father;
                    NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* backupLeaf = leaf;

                    //sempre a esquerda
                    //NodeLeaf* newLeaf = new NodeLeaf("", nullptr, pos);

                    int pos = leaf->data.length();
                    NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* nodeBranch =
                            new NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys
                    (
                        backupFather,
                        pos
                    );
                    //todo:
                    //tirar parametro de Nodeleaf
                    NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* newLeaf =
                            new NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys(data, nodeBranch, 0);
                    //o leaf antigo fica em missing, obrigatoriamente

                    nodeBranch->missing = leaf;
                    leaf->father = nodeBranch;

                    if (data.at(pos) == '0') //fica em left
                    {
                        nodeBranch->left = newLeaf;
                        newLeaf->father = nodeBranch;
                    }
                    else if (data.at(pos) == '1') //fica em right
                    {
                        nodeBranch->right = newLeaf;
                        newLeaf->father = nodeBranch;
                    }

                    if (backupFather != nullptr)
                    {
                        //replace in father (backupFather), o leaf por nodeBranch
                        replacePointerInFather
                        (
                            (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) backupFather,
                            leaf,
                            nodeBranch
                        );
                    }
                    else
                    {
                        root = nodeBranch;
                    }

                    break;
                }
                else //deve quebrar antes
                {
                    if (data.length() == leaf->data.length())
                    {
                        //staring from root
                        //insert in the first position with the diference id
                        int pos = isEqualUntilWhichPosition(data, leaf->data);
                        pos = pos+1; //+1 é o ponto de diferença

                        NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* prev = leaf;
                        NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* branchFather = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) prev->father;
                        while (branchFather != nullptr && branchFather->index > pos)
                        {
                            prev = branchFather;
                            branchFather = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) prev->father;
                        }

                        //insere em prev (quebrando)
                        NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* newFather =
                                new NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys(branchFather, pos);
                        if (branchFather == nullptr)
                            root = newFather;
                        NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* newLeaf =
                                new NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys("", nullptr, pos);
                        newFather->left = newLeaf;
                        newLeaf->father = newFather;
                        newFather->right = prev;
                        prev->father = newFather;

                        newLeaf->data = data;
                        if (data.at(pos) == '1') //deve ficar na direita
                        {
                            NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* temp = newFather->left;
                            newFather->left = newFather->right;
                            newFather->right = temp;
                        }

                        if (branchFather != nullptr)
                        {
                            //replace in father (branchFather), o prev por newFather
                            replacePointerInFather
                            (
                                (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) branchFather,
                                prev,
                                newFather
                            );
                        }
                        else
                        {
                            root = newFather;
                        }

                        break;
                    }
                    //this if not fully right
                    //else
                    //{
                    else if (data.length() < leaf->data.length())
                    {
                        //caso com 1111 e insere 1
                        //staring from root
                        //insert in the first position with the diference id
                        //int pos = isEqualUntilWhichPosition(data, leaf->data);
                        //pos = pos+1; //+1 é o ponto de diferença

                        int pos = data.length();
                        int less = -1;
                        for (int ind = 0; ind <data.length() && ind<leaf->data.length();++ind)
                        {
                            if (data.at(ind) != leaf->data.at(ind))
                            {
                                less = ind+1;
                                break;
                            }
                        }
                        if (less < pos)
                            less = pos;


                        char bitSample = leaf->data.at(pos);

                        NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* prev = leaf;
                        NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* branchFather =
                                (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) prev->father;
                        while (branchFather != nullptr && branchFather->index > pos)
                        {
                            prev = branchFather;
                            branchFather = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) prev->father;
                        }

                        NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* branchUp = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) prev;
                        if (branchUp!= nullptr && branchUp->index == pos) //não precisa criar branch
                        {
                            NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* newLeafMiss = new NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys(data, branchUp, pos);
                            branchUp->missing = newLeafMiss;
                        }
                        else
                        {
                            //insere em prev (quebrando)
                            NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* newFather =
                                    new NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys(branchFather, pos);
                            if (branchFather == nullptr)
                                root = newFather;
                            NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* newLeafMiss =
                                    new NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys(data, newFather, pos);

                            newFather->missing = newLeafMiss;
                            newLeafMiss->father = newFather;

                            //get bit representation
                            if (bitSample == '0')
                            {
                                newFather->left = prev;
                                prev->father = newFather;
                            }
                            else if (bitSample == '1')
                            {
                                newFather->right = prev;
                                prev->father = newFather;
                            }

                            if (branchFather != nullptr)
                            {
                                //replace in father (branchFather), o prev por newFather
                                replacePointerInFather
                                (
                                    (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) branchFather,
                                    prev,
                                    newFather
                                );
                            }
                            else
                            {
                                root = newFather;
                            }
                        }

                        break;
                    }
                }
            } //end of node leaf
            else //node is branch
            {
                //Assumindo que são dados binários
                NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* branch =
                        (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) tmp;

                if (data.size() > branch->index)
                {
                    if (data.at(branch->index) == '0')
                    {
                        //todo check left null
                        if (branch->left == nullptr)
                        {
                            NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* leaf =
                                    new NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys(data, branch, branch->index);
                            branch->left = leaf;

                            break;
                        }
                        else
                        {
                            //é o ramo left
                            tmp = branch->left;
                        }
                    }
                    else //data.at(branch->index) == '1'
                    {
                        //todo check right null
                        if (branch->right == nullptr)
                        {
                            NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* leaf =
                                    new NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys(data, branch, branch->index);
                            branch->right = leaf;

                            break;
                        }

                        //é o ramo right
                        tmp = branch->right;
                    }
                }
                else //o data é pequeno
                {
                    //if (tmp->father == nullptr) //é o root
                    //{
                    int indexOfDifference = branch->index;
                    int bitSample = getBitSampleForwardInPosAndDifference
                    (
                        tmp,
                        data,
                        data.length(),
                        indexOfDifference
                    );

                    while
                    (
                        branch->father != nullptr &&
                        indexOfDifference < ((NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) branch->father)->index
                    )
                    {
                        //branch é o tmp
                        tmp = branch->father;
                        branch = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) tmp;
                    }

                    if (branch->index == indexOfDifference)
                    {
                        NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* newLeaf =
                                new NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys(data, branch, data.length());
                        newLeaf->father = branch;
                        branch->missing = newLeaf;
                    }
                    else
                    {
                        NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* fatherOfBranchBackup = nullptr;
                        if (branch->father != nullptr)
                            fatherOfBranchBackup = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) branch->father;
                        bool branchWasRoot = branch->father == nullptr;

                        //NodeBranch* newBranch = new NodeBranch(nullptr, indexOfDifference);
                        NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* newBranch =
                                new NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys(fatherOfBranchBackup, indexOfDifference);
                        NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* newLeaf =
                                new NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys(data, newBranch, data.length());

                        if (bitSample == '0')
                        {
                            newBranch->left = tmp;
                            tmp->father = newBranch;

                            //newBranch->right = newLeaf;
                            newBranch->missing = newLeaf;
                            newLeaf->father = newBranch;
                        }
                        else //é '1'
                        {
                            //newBranch->left = newLeaf;
                            newBranch->missing = newLeaf;
                            newLeaf->father = newBranch;

                            newBranch->right = tmp;
                            tmp->father = newBranch;
                        }

                        if (branchWasRoot)
                            root = newBranch;
                        else
                        {
                            //update in fatherOfBranchBackup, branch por newBranch
                            replacePointerInFather
                            (
                                (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) fatherOfBranchBackup,
                                branch,
                                newBranch
                            );
                        }
                    }

                    break;
                    //}
                }
            }
        }
    }

    return true;
}

int PatriciaTreeStoreBinaryDifferentLenKeysDS::getBitSampleForwardInPosAndDifference
(
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* initial,
    const std::string& data,
    int pos,
    int& indexOfDifference
)
{
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* tmp = initial;
    while (true)
    {
        if (tmp->nodeType == NodeTypeOfPTSBDLK::LEAFNodeTypeOfPTSBDLK)
        {
            NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* leaf =
                    (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) tmp;

            indexOfDifference = pos;
            for (int i = 0; i<data.size(); ++i)
            {
                if (data.at(i) != leaf->data.at(i))
                {
                    pos = i;
                    break;
                }
            }
            if (indexOfDifference != pos)
                indexOfDifference = pos;

            return leaf->data.at(pos);
        }
        else //é um branch
        {
            NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* branch =
                    (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) tmp;
            if (branch->left != nullptr &&
                    branch->left->nodeType == NodeTypeOfPTSBDLK::LEAFNodeTypeOfPTSBDLK)
            {
                NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* leaf =
                        (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) branch->left;

                indexOfDifference = pos;
                for (int i = 0; i<data.size(); ++i)
                {
                    if (data.at(i) != leaf->data.at(i))
                    {
                        pos = i;
                        break;
                    }
                }
                if (indexOfDifference != pos)
                    indexOfDifference = pos;

                return leaf->data.at(pos);
            }
            else if (branch->right != nullptr &&
                     branch->right->nodeType == NodeTypeOfPTSBDLK::LEAFNodeTypeOfPTSBDLK)
            {
                NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* leaf =
                        (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) branch->right;

                indexOfDifference = pos;
                for (int i = 0; i<data.size(); ++i)
                {
                    if (data.at(i) != leaf->data.at(i))
                    {
                        pos = i;
                        break;
                    }
                }
                if (indexOfDifference != pos)
                    indexOfDifference = pos;

                return leaf->data.at(pos);
            }
            else if (branch->left != nullptr)
                tmp = branch->left;
            else
                tmp = branch->right;
        }
    }
}

NodeOfPatriciaTreeStoreBinaryDifferentLenKeys *PatriciaTreeStoreBinaryDifferentLenKeysDS::search
(
    const std::string& data
)
{
    bool valid = isAValidDataIoInsert(data);
    if (valid == false)
        return nullptr;

    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* tmp = root;
    while (tmp != nullptr)
    {
        if (tmp->nodeType == NodeTypeOfPTSBDLK::LEAFNodeTypeOfPTSBDLK)
        {
            //check string
            NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* leaf =
                    (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) tmp;
            return (leaf->data.compare(data) == 0)? leaf: nullptr;
        }
        else //tmp->nodeType == NodeType::BRANCH
        {
            NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* branch =
                    (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) tmp;

            //o data tem esse index?
            if (data.size() > branch->index)
            {
                char c = data.at(branch->index);

                if (c == '0')
                {
                    if (branch->left != nullptr)
                        tmp = branch->left;
                    else if (branch->missing == nullptr)
                        return nullptr;
                    else
                    {
                        NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* leaf =
                                (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) branch->missing;
                        if (leaf->data.compare(data) == 0)
                        {
                            return leaf;
                        }
                        else
                        {
                            return nullptr;
                        }
                    }
                }
                else //c == '1'
                {
                    if (branch->right != nullptr)
                        tmp = branch->right;
                    else if (branch->missing == nullptr)
                        return nullptr;
                    else
                    {
                        NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* leaf =
                                (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) branch->missing;
                        if (leaf->data.compare(data) == 0)
                        {
                            return leaf;
                        }
                        else
                        {
                            return nullptr;
                        }
                    }
                }
            }
            else //pode ter no missing
            {
                if (branch->missing == nullptr)
                    return nullptr;
                else
                {
                    NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* leaf =
                            (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) branch->missing;
                    if (leaf->data.compare(data) == 0)
                    {
                        return leaf;
                    }
                    else
                    {
                        return nullptr;
                    }
                }
            }
        }
    }

    return nullptr;
}

NodeOfPatriciaTreeStoreBinaryDifferentLenKeys *PatriciaTreeStoreBinaryDifferentLenKeysDS::remove
(
    const std::string& data
)
{
    bool valid = isAValidDataIoInsert(data);
    if (valid == false)
        return nullptr;

    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys *node = search(data);
    if (node == nullptr)
        return nullptr;

    //só remove leaf
    if (node->father == nullptr) //o root é leaf
    {
        //é o root .. não existem outros nós (unico caso comum elemento)
        root = nullptr;
        return node;
    }
    else
    {
        //O pai não é nulo
        NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* fatherNode =
                (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) node->father;
        NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* grandParent = nullptr;
        if (fatherNode != nullptr)
            grandParent = (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) fatherNode->father;

        //Remove elemento
        replacePointerInFather
        (
            fatherNode,
            node,
            nullptr
        );

        int count = branchChildrensCount(fatherNode);

        if (count >= 2) //não precisa fazer mais nada
        {
            return node;
        }
        else //precisa remover o fatherNode (ele tem zero ou um nós)
        {
            //if (count == 0) //não existe essa situação
            if (count == 1)
            {
                NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* backup = nullptr;
                if (fatherNode->left != nullptr)
                    backup = fatherNode->left;
                else if (fatherNode->right != nullptr)
                    backup = fatherNode->right;
                else
                    backup = fatherNode->missing;

                if (grandParent != nullptr)
                {
                    backup->father = grandParent;
                    replacePointerInFather
                    (
                        grandParent,
                        fatherNode,
                        backup
                    );
                }
                else
                {
                    backup->father = nullptr;
                    root = backup;
                }

                delete fatherNode;
            }

            return node;
        }
    }
}

bool PatriciaTreeStoreBinaryDifferentLenKeysDS::branchChildrensCount
(
    NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* branch
)
{
    int sum = 0;
    if (branch->left != nullptr)
        sum++;
    if (branch->right != nullptr)
        sum++;
    if (branch->missing != nullptr)
        sum++;

    return sum;
}

bool PatriciaTreeStoreBinaryDifferentLenKeysDS::isAValidDataIoInsert(const std::string& data)
{
    for (auto caracter: data)
    {
        if (caracter != '0' && caracter != '1')
            return false;
    }
    return true;
}

void PatriciaTreeStoreBinaryDifferentLenKeysDS::replacePointerInFather
(
    NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* father,
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* oldSon,
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* newSon
)
{
    if (father->left == oldSon)
        father->left = newSon;
    else if (father->right == oldSon)
        father->right = newSon;
}

bool PatriciaTreeStoreBinaryDifferentLenKeysDS::isEqualUntilPosition
(
    const std::string& one,
    const std::string& two,
    int pos
)
{
    if (pos >= one.length() || pos >= two.length())
        return false;

    for (int index = 0; index <= pos; ++index)
    {
        if (one.at(index) != two.at(index))
            return false;
    }

    return true; //they are equal until such position
}

int PatriciaTreeStoreBinaryDifferentLenKeysDS::isEqualUntilWhichPosition
(
    const std::string& one,
    const std::string& two
)
{
    if (one.length() != two.length())
        return 0; //todo: check here

    int max = -1;
    for (int index = 0; index < one.length(); ++index)
    {
        if (one.at(index) != two.at(index))
        {
            return max;//ends here
        }
        else
        {
            max = index;
        }
    }

    return max;
}

std::string PatriciaTreeStoreBinaryDifferentLenKeysDS::getPointerAsString
(
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys* node
)
{
    const void * address = static_cast<const void*>(node);
    std::stringstream ss;
    ss << address;
    std::string name = ss.str();
    return "\""+name+"\"";
}

void PatriciaTreeStoreBinaryDifferentLenKeysDS::getDrawInNode
(
    NodeOfPatriciaTreeStoreBinaryDifferentLenKeys *node,
    std::string &nodesDefinition,
    std::string &linksDefinition,
    int &nullCounter
)
{
    if (node->nodeType == NodeTypeOfPTSBDLK::LEAFNodeTypeOfPTSBDLK)
    {
        NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys* conv =
                (NodeLeafOfPatriciaTreeStoreBinaryDifferentLenKeys*) node;
        nodesDefinition +=  getPointerAsString(conv)+" [shape=box label=\""+
                conv->data+"\"];";
    }
    else //NodeType::BRANCH
    {
        NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys* conv =
                (NodeBranchOfPatriciaTreeStoreBinaryDifferentLenKeys*) node;
        nodesDefinition +=  getPointerAsString(conv)+" [shape=circle label=\""+
                std::to_string(conv->index)+"\" ];";

        if (conv->left == nullptr)
        {
            nodesDefinition += "NULL"+std::to_string(nullCounter)+" [label=\"NULL\"]";
            linksDefinition += getPointerAsString(conv) +
                    " -> NULL"+std::to_string(nullCounter++)+" [label=\"left\"];";
        }
        else
        {
            linksDefinition += getPointerAsString(conv) +" -> "+
                    getPointerAsString(conv->left)+" [label=\"left\"];";
            getDrawInNode
            (
                conv->left,
                nodesDefinition,
                linksDefinition,
                nullCounter
            );
        }

        if (conv->right == nullptr)
        {
            nodesDefinition += "NULL"+std::to_string(nullCounter)+" [label=\"NULL\"]";
            linksDefinition += getPointerAsString(conv) +
             " -> NULL"+std::to_string(nullCounter++)+" [label=\"right\"];";
        }
        else
        {
            linksDefinition += getPointerAsString(conv) +" -> "+
                    getPointerAsString(conv->right)+" [label=\"right\"];";
            getDrawInNode
            (
                conv->right,
                nodesDefinition,
                linksDefinition,
                nullCounter
            );
        }

        if (conv->missing == nullptr)
        {
            nodesDefinition += "NULL"+std::to_string(nullCounter)+" [label=\"NULL\"]";
            linksDefinition += getPointerAsString(conv)
            +" -> NULL"+std::to_string(nullCounter++)+" [color=red];";
        }
        else
        {
            linksDefinition += getPointerAsString(conv) +" -> "+
                    getPointerAsString(conv->missing)+" [color=red] ;";
            getDrawInNode
            (
                conv->missing,
                nodesDefinition,
                linksDefinition,
                nullCounter
            );
        }
    }
}

const std::string PatriciaTreeStoreBinaryDifferentLenKeysDS::getGraphvizDraw()
{
    std::string general = "digraph g{";
    std::string nodesDefinition;
    std::string linksDefinition;

    if (root == nullptr)
    {
        nodesDefinition += "Root [shape=none]; NULL [shape=none]";
        linksDefinition += "Root -> NULL;";
    }
    else
    {
        int nullCounter = 0;
        linksDefinition += "Root -> "+getPointerAsString(root)+";";
        getDrawInNode(root, nodesDefinition, linksDefinition, nullCounter);
    }

    general += nodesDefinition;
    general += linksDefinition;
    general += "}";

    return general;
}


PatriciaTreeStoreBinaryDifferentLenKeysDS::~PatriciaTreeStoreBinaryDifferentLenKeysDS()
{
    if (this->root != nullptr)
    {
        this->root->dealockSubtree();
        delete this->root;
    }
}
