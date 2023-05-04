#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "parser.h"
#include "treeNode.h"
using namespace std;

// a helper function parsing the input into the formula string and the assignment string
void parseLine(const std::string &line, std::string &formulaStr, std::string &assignmentStr) {
    // your code starts here
    TreeNode* t;

    FormulaParser *formulaParser = new FormulaParser(formulaStr);
    AssignmentParser *assignmentParser = new AssignmentParser(assignmentStr);
    t=formulaParser->getTreeRoot();
    cout<<"sending into values"<<endl;
    cout<<t->getContent()<<endl;
    cout<<t->getRightChild()->getContent()<<endl;
    std::map<std::string, bool> values = assignmentParser->parseAssignment();
    bool res=t->evaluate(values);
    if(res){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
}

// The program shall continuously ask for new inputs from standard input and output to the standard output
// The program should terminate gracefully (and quietly) once it sees EOF
int main() {
    while (true) // continuously asking for new inputs from standard input
    {

        std::string line = "A + B * -0 * (1 + -CD); A : 0, B : 0, CD : 1";
//        ((1+0)+(0*-1)*(1*0+-1))
        if(line=="-1"){
            cout<<"0"<<endl;
        }
        else if(line=="-0"){
            cout<<"1"<<endl;
        }
        int i=0;
        std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
        line.erase(end_pos, line.end());
        std::string formulaStr; // store the formula string
        std::string assignmentStr; // store the assignment string
        // your code starts here
        cout<<line<<endl;
        std::string segment;
        std::vector<std::string> segList;
        int breakPoint;
        int count=0;
        for (int i=0;i<int(line.length());i++){
            if (line[i]==';'){
                breakPoint=i;
                count++;
            }
        }
        if (count==1){
            formulaStr=line.substr(0,breakPoint);
            assignmentStr=line.substr(breakPoint+1,line.length());
        }else if(count==0){
            cout<<"No semicolons--- Invalid Input"<<endl;
        }
        else{
            cout<<"Too many semicolons---Invalid Input"<<endl;
            break;
        }
        parseLine(line,formulaStr,assignmentStr); // Call this only for valid cases
        break;
    }
    return 0;
}

