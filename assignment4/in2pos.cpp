//in2pos.cpp:
#include <iostream>
#include <utility>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <stack>
 std::string const leftParanthesis = "(";
 std::string const rightParanthesis = ")";

std::string in2pos(std::string input);
int evaluateString(std::string equation);

int main(int argc, char* argv[]){

std::string input =argv[1];
// int output = evaluateString(input);
// std::cout <<  output << std::endl;
// std::string input ="1 + 2";
std::string equation = in2pos(input);
// int output = evaluateString(equation);
// std::cout << "input:" << input << std::endl;
std::cout << equation << std::endl;
// std::cout << "result:" << output << std::endl;
// input = "-10 + 20 * ( 30 / 2 )";
// equation = in2pos(input);
// output = evaluateString(equation);
// std::cout << "input:" << input << std::endl;
// std::cout << "equation:" << equation << std::endl;
// std::cout << "result:" << output << std::endl;
// input = "( 5 + 3 ) * 12 / 3";
// equation = in2pos(input);
// output = evaluateString(equation);
// std::cout << "input:" << input << std::endl;
// std::cout << "equation:" << equation << std::endl;
// std::cout << "result:" << output << std::endl;
// input = "33 + 12 - 12 / ( 4 * -9 )";
// equation = in2pos(input);
// output = evaluateString(equation);
// std::cout << "input:" << input << std::endl;
// std::cout << "equation:" << equation << std::endl;
// std::cout << "result:" << output << std::endl;
// input = "1 + 2 - 3 * 4 / 5 ^ 6";
// equation = in2pos(input);
// output = evaluateString(equation);
// std::cout << "input:" << input << std::endl;
// std::cout << "equation:" << equation << std::endl;
// std::cout << "result:" << output << std::endl;
// input = "12 / ( 4 * -9 )";
// equation = in2pos(input);
// output = evaluateString(equation);
// std::cout << "input:" << input << std::endl;
// std::cout << "equation:" << equation << std::endl;
// std::cout << "result:" << output << std::endl;
// input = "33 + 12 - 12 / ( 4 * -9 )";
// equation = in2pos(input);
// output = evaluateString(equation);
// std::cout << "input:" << input << std::endl;
// std::cout << "equation:" << equation << std::endl;
// std::cout << "result:" << output << std::endl;
}

std::vector <int> evalutateOperator(std::string entity){

    int operatorNumber;
    int precedence;
    if(entity == "-"){
        operatorNumber = 2;
        precedence = 1;
    } else if(entity == "+"){
        operatorNumber = 1;
        precedence = 1;
    } else if(entity == "*"){
        operatorNumber = 4;
        precedence = 2;
    } else if(entity == "/"){
        operatorNumber = 3;
        precedence = 2;
    } else if(entity == "^"){
        operatorNumber = 5;
        precedence = 3;
    }
    std::vector <int> output;
    output.push_back(operatorNumber);
    output.push_back(precedence);
    return output;
}

void CheckStack(std::string entity, std::stack <std::string>* outputstack, std::string* output){
    std::string temp = "";
    bool running = true;
    if(entity == "("){
        (*outputstack).push("(");
        //std::cout << "left parenthesis" << std::endl;    
    } else if (entity == ")") {
        while(running){
            if((*outputstack).size() != 0){
                temp = (*outputstack).top();
                (*outputstack).pop();
                if(temp == "("){
                    running = false;
                } else {
                    (*output) = (*output) + temp + " ";
                }
            }else{
                running = false;
            }
        }
        //std::cout << "right parenthesis" << std::endl; 
    } else if (entity == "+" || entity == "-" || entity == "*" || entity == "/" || entity == "^") {
        std::vector <int>  operatorInfo = evalutateOperator(entity);
        std::vector <int>  stackOperatorInfo;
        //std::cout << operatorNumber << " ( " << entity << " ) " << std::endl;

        while(running){
            if(temp == "("){
                running = false;
            }
            if((*outputstack).size() != 0){
                temp = (*outputstack).top();
                if( temp == "("){
                    running = false;
                } else{
                    stackOperatorInfo = evalutateOperator(temp);    
                    //std::cout << stackOperatorNumber << " ( " << temp << " ) " << (operatorNumber < stackOperatorNumber || (stackOperatorNumber < 5 && operatorNumber == stackOperatorNumber))  << ": Made up of " << (operatorNumber < stackOperatorNumber) << " or " << (stackOperatorNumber < 5) << " and "  << (operatorNumber == stackOperatorNumber) << std::endl;
                    if(operatorInfo[0] < stackOperatorInfo[0] || (stackOperatorInfo[0] < 5 && operatorInfo[1] == stackOperatorInfo[1])){
                        (*outputstack).pop();
                        (*output) = (*output) + temp + " ";
                    } else {
                        
                        running = false;
                    }
                }
            }else{
                running = false;
            }
            
            
        }
        (*outputstack).push(entity);
    } else {
        (*output) = (*output) + entity + " "; 
        //std::cout << entity << std::endl;
    } 
}


std::string in2pos(std::string input){
    std::istringstream my_stream (input);
    std::string entity;
    std::string output = "";
    std::string temp = "";
    std::stack <std::string> outputstack;
    while(my_stream >> entity){
        //std::cout << entity << std::endl;
        CheckStack(entity, &outputstack, &output);
    }
    bool running = true;
    while(running){
            if(outputstack.size() != 0){
                temp = outputstack.top();
                outputstack.pop();
                output = output + temp + " ";
            }else{
                running = false;
            }
            
            
        }

    // if left parenthesis
    //     push it onto the stack
    // if operator
    //     pop and write to the output string all consecutive operators that are either operators of higher precedence, or left-associative operators of equal precedence
    //     push the operator onto the stack
    // if right parenthesis
    //     pop and write to the output string all operators until a left parenthesis is popped off the stack
    // if number
    //     it may be immediately written to the output string
    // if end of the string
    //     pop and write to the output string all operators until the stack is empty
    //std::string output = input;
    return output;
} 

int evaluateSign(std::string sign, int tempInt, int tempInt2){
    int result;
    double tempDouble = tempInt;
    double tempDouble2 = tempInt2;
    std::vector <int>  operatorInfo = evalutateOperator(sign);    
    switch(operatorInfo[0]){
        //Subtraction
        case 2:
            result = tempInt2 - tempInt;
            break;
        //Addition
        case 1:
            result = tempInt2 + tempInt;
            break;
        //Division
        case 3:
            result = floor(tempDouble2 / tempDouble);
            break;
        //Multiplication
        case 4:
            result = tempInt2 * tempInt;
            break;
        //Exponentiation
        case 5:
            result = pow(tempInt2, tempInt);
            break;
    }
    return result;
}

int evaluateString(std::string equation){
    std::istringstream my_stream (equation);
    std::string entity;
    std::string output = "";
    std::string temp = "";
    int result = 0;
    int tempInt = NULL;
    int tempInt2 = NULL;
    std::stack <std::string> tempstack;
    std::stack <int> outputstack;
    bool running = true;
    while(my_stream >> entity){
        //std::cout << "bring it out of the string:" << entity << std::endl;
        if (entity == "+" || entity == "-" || entity == "*" || entity == "/" || entity == "^") {
                tempInt = outputstack.top();
                outputstack.pop();
                tempInt2 = outputstack.top();
                outputstack.pop();
                result = evaluateSign(entity, tempInt, tempInt2);
                outputstack.push(result);      
        } else {
            outputstack.push(std::stoi(entity));
        }
    }
    if(outputstack.size() == 1){
        tempInt = outputstack.top();
        outputstack.pop();
        result = tempInt;
    }else{
       std::cout << "There was an error";
    }
    return result;
}

