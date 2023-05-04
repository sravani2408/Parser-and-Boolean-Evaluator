#ifndef TNODE_H
#define TNODE_H

#include <string>
#include <map>

// abstract superclass of the syntax tree node
class TreeNode {
    std::string content;
    TreeNode *leftChild = nullptr;
    TreeNode *rightChild = nullptr;
public:
    TreeNode *getLeftChild() const;
    TreeNode *getRightChild() const;
public:
    TreeNode(std::string cntt);
    std::string getContent() const;
    virtual bool evaluate(const std::map<std::string, bool> &assignment) const = 0; // pure virtual method
    void updateLeftChild(TreeNode *lChild); // for the operator "-", the operand is stored in leftChild
    void updateChildren(TreeNode *lChild, TreeNode *rChild);
//    virtual bool evaluate_nodes() const=0;
    virtual ~TreeNode();
};

// concrete tree node of opertaor type
class OperatorNode : public TreeNode {
public:
    OperatorNode(std::string cntt);
    bool evaluate(const std::map<std::string, bool> &assignment) const override;
//    bool evaluate_nodes() const override;
};

// concrete tree node of constant type
class ConstantNode : public TreeNode {
public:
    ConstantNode(std::string cntt);
    bool evaluate(const std::map<std::string, bool> &assignment) const override;
//    bool evaluate_nodes() const override;
};

// concrete tree node of varibale type
class VariableNode : public TreeNode {
    std::map<std::string, int> tree_assignment;
public:
    VariableNode(std::string cntt);
//    void setMapValues(std::map<std::string,int> map);
//    bool getMapValues(std::string s) const;
    bool evaluate(const std::map<std::string, bool> &assignment) const override;
//    bool evaluate_nodes() const override;
};
#endif
