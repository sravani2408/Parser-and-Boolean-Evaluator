#include "tokenizer.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

Tokenizer::Tokenizer(std::string ln,bool flag) {
    // complete the constructor
    Tokenizer::token_line = ln;
    Tokenizer::token_index=0;
    this->token_flag=flag;
    if (this->token_flag){
        formula(this->token_line);
    }else{
        assignment(this->token_line);
    }
}
bool Tokenizer::advanceToken() {
    // your code starts here

//    cout<<"advance token is..........."<<token_index<<endl;
    if (int(this->token_vector.size())<this->token_index+1){
        return false;
    }
    this->token_index++;
//    cout<<"advance token is..........."<<token_index<<endl;
    return true;
}
bool Tokenizer::hasToken() const {
    // your code starts here
    if (int(this->token_vector.size())<this->token_index+1){
//    cout<<"returning false in hastoken"<<token_index<<endl;
        return false;
    }
    return true;
}
void Tokenizer::formula(std::string ln) {
    std::string operators ="()+-*";
    int i=0;
    while(i<ln.length()){
        Token token;
        if(operators.find(ln[i])!=std::string::npos){
            token.content=this->token_line[i];
            token.type="operator";
            i++;
        }
        else if ((ln[i]) == '1' || ln[i] == '0'){
            token.content=this->token_line[i];
            token.type="constant";
            i++;
        }
        else{
            std::string dummy="";
            while(i<int(ln.length())){
                if (operators.find(ln[i])!=std::string::npos){
                    break;
                }
                dummy+=ln[i];
                i++;
            }
            token.type="variable";
            token.content=dummy;
        }
        this->token_vector.push_back(token);
    }
}

void Tokenizer::assignment(std::string ln) {
    int i=0;
    while(i<int(ln.length())){
        Token token;
        if(ln[i]=='1' || ln[i]=='0'){
            token.type="constant";
            token.content=ln[i];
            i++;
        }else if(ln[i]==','){
            i++;
            continue;
        }
        else{
            std::string dummy="";
            while(i<int(ln.length())){
                if (ln[i]==':'){
                    i++;
                    break;
                }
                dummy+=ln[i];
                i++;
            }
            token.type="variable";
            token.content=dummy;
        }
        token_vector.push_back(token);
    }

}
// only can be called when hasToken() is true
Token Tokenizer::getToken() {
    Token resultToken;
    if (hasToken())
        resultToken=this->token_vector[this->token_index];
    return resultToken;
}
