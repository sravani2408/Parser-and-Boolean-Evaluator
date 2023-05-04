#include "treeNode.h"
#include <iostream>

TreeNode::TreeNode(std::string cntt): content {cntt } {}

std::string TreeNode::getContent() const {
    // your code starts here
    return this->content;
}

TreeNode *TreeNode::getLeftChild() const {
    // your code starts here
    return this->leftChild;
}
TreeNode *TreeNode::getRightChild() const {
    // your code starts here
    return this->rightChild;
}

void TreeNode::updateLeftChild(TreeNode *lChild) {
    // your code starts here
    this->leftChild = lChild;

}

void TreeNode::updateChildren(TreeNode *lChild, TreeNode *rChild) {
    // your code starts here
    this->leftChild=lChild;
    this->rightChild=rChild;
}
OperatorNode::OperatorNode(std::string cntt): TreeNode{cntt} {}

bool OperatorNode::evaluate(const std::map<std::string, bool> &assignment) const {
    std::string rootcontent= this->getContent();
    bool left = getLeftChild()->evaluate(assignment);
    bool right= getRightChild() == nullptr? false : getRightChild()->evaluate(assignment);
    if(rootcontent.compare("+")==0){
        return left||right;
    }
    if(rootcontent.compare("*")==0){
        return left&&right;
    }
    if(rootcontent.compare("-")==0){
        return !left;
    }
    return false;
}
//bool OperatorNode::evaluate_nodes() const {
//    if(this->getContent()=="+"){
//        return (this->getLeftChild()->evaluate_nodes())|| this->getRightChild()->evaluate_nodes();
//    }
//    if(this->getContent()=="*"){
//        return bool(this->getLeftChild()->evaluate_nodes()&& this->getRightChild()->evaluate_nodes());
//    }
//    if(this->getContent()=="-"){
//        return(!this->getLeftChild()->evaluate_nodes());
//    }
//    return false;
//}

ConstantNode::ConstantNode(std::string cntt): TreeNode{cntt} {}

bool ConstantNode::evaluate(const std::map<std::string, bool> &assignment) const {
    // your code starts here
    if (this->getContent() == "0") {
        return false;
    }
    return true;
}
//bool ConstantNode::evaluate_nodes() const {
//    if (this->getContent() == "0") {
//        return false;
//    }
//    return true;
//}

VariableNode::VariableNode(std::string cntt): TreeNode{cntt} {}

bool VariableNode::evaluate(const std::map<std::string, bool> &assignment) const {
    // your code starts here
    if(assignment.find(this->getContent())!=assignment.end()){
        return assignment.at(this->getContent());
    }
    return false;// Putting a try catch block for error
}
//void VariableNode::setMapValues(std::map<std::string, int> map) {
//    this->tree_assignment=map;
//    std::cout<<this<<std::endl;
//    std::cout<<&this->tree_assignment<<std::endl;
//    std::cout<<map.at("Ur");
//}
//bool VariableNode::getMapValues(std::string s) const{
//    std::cout<<this<<std::endl;
//    std::cout<<&this->tree_assignment<<std::endl;
//    if(this->tree_assignment.at(s)==1)
//        return true;
//    else{
//        return false;
//    }
//}

//bool VariableNode::evaluate_nodes() const {
//    std::cout<<"in evaluate nodes.................."<<std::endl;
//    std::cout<<this<<std::endl;
//    std::cout<<"...............................dgfdgsd>>>>>>>>>>>>>>>>>>>>>>";
//    std::cout<<this->getMapValues("Ur");
//    if(this->getMapValues(this->getContent()))
//        return true;
//    return false;
//}

TreeNode::~TreeNode() {
    // your code starts here
}
