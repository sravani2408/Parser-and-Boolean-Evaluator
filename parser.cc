#include "parser.h"
#include "treeNode.h"
#include "tokenizer.h"
#include <iostream>
using namespace std;
FormulaParser::FormulaParser(std::string ln): tknzr {new Tokenizer{ln,true}} {

}
TreeNode *FormulaParser::parseFormula() {
    // your code starts here
    TreeNode *left_plus= parseConjTerm();
    TreeNode *plusNode;
    if (tknzr->getToken().content=="+"){
        plusNode = new OperatorNode("+");
        tknzr->advanceToken();
        TreeNode *right_plus=parseFormula();
        plusNode->updateChildren(left_plus,right_plus);
        return plusNode;
    }
    return left_plus;
}

TreeNode *FormulaParser::parseConjTerm() {
    // your code starts here
    TreeNode *star_left= parseTerm();
    TreeNode *starNode;
    if (tknzr->hasToken() && tknzr->getToken().content=="*"){
        starNode = new OperatorNode("*");
        tknzr->advanceToken();
        TreeNode *star_right = parseConjTerm();
        starNode->updateChildren(star_left,star_right);
        return starNode;
    }
    return star_left;
}
TreeNode *FormulaParser::parseTerm() {
    // your code starts here
    TreeNode *t;
    if (tknzr->getToken().type=="constant"){
        t=new ConstantNode(tknzr->getToken().content);
        tknzr->advanceToken();
        return t;
    }
    else if (tknzr->getToken().type=="variable"){
        t=new VariableNode(tknzr->getToken().content);
        tknzr->advanceToken();
        return t;
    }
    else if (tknzr->getToken().content=="-"){
        t=new OperatorNode("-");
        tknzr->advanceToken();
        TreeNode *t1=parseTerm();
        t->updateLeftChild(t1);
        return t;
    }
    else if (tknzr->getToken().content=="(") {
        tknzr->advanceToken();
        t = parseFormula();
        if (tknzr->getToken().content != ")")
        {
            std::cout<<"ERROR: ) not found - Invalid String";
        }
        else
        {
            tknzr->advanceToken();
            return t;
        }
    }
    return t;
}

TreeNode * FormulaParser::getTreeRoot() {
    // your code starts here
    return parseFormula();
}

FormulaParser::~FormulaParser() {
    // your code starts here
    delete tknzr;
}

AssignmentParser::AssignmentParser(std::string ln): tknzr {new Tokenizer{ln,false}} {

}

std::map<std::string, bool> AssignmentParser::parseAssignment() {
    std::map<std::string, bool> results;
    // your code starts here
    std::string key;
    int b;
    while(tknzr->hasToken()){
        if(tknzr->getToken().type == "variable"){
            key = tknzr->getToken().content;
        }
        if(tknzr->getToken().type == "constant" && tknzr->getToken().content=="0"){
            b=0;
            results.insert({key,b});

        }
        if(tknzr->getToken().type == "constant" && tknzr->getToken().content=="1")
        {
            b=1;
            results.insert({key,b});

        }
        tknzr->advanceToken();
    }
    return results;
}


AssignmentParser::~AssignmentParser() {
    // your code starts here
    delete tknzr;
}
