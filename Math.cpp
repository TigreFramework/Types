//
// Created by pedro on 12/12/17.
//


#include "Math.h"

//#include <csignal>
#include <exception>

/*jmp_buf Math::env;

void Math::SIGABRTHandle(int code) {
    longjmp (env, 1);
}*/

int Math::toInt(std::string value) {
    //signal(SIGABRT, SIGABRTHandle);
    try{
        int i = std::stoi(value);
        //signal(SIGINT, SIG_DFL);
        return i;
    }catch (std::exception &exception) {
        throw MathException("Value \""+value+"\" is not a Int number");
    }
}

float Math::toFloat(std::string value) {
    //signal(SIGABRT, SIGABRTHandle);
    try{
        float i =  std::stof(value);
        //signal(SIGINT, SIG_DFL);
        return i;
    }catch (std::exception &exception) {
        throw MathException("Value \""+value+"\" is not a Float number");
    }
}

double Math::toDouble(std::string value) {
    //signal(SIGABRT, SIGABRTHandle);
    try{
        double i =  std::stod(value);
        //signal(SIGINT, SIG_DFL);
        return i;
    }catch (std::exception &exception) {
        throw MathException("Value \""+value+"\" is not a Double number");
    }
}



MathException::MathException(std::string message) : Exception(std::move(message))  { }