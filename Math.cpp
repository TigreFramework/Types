//
// Created by pedro on 12/12/17.
//


#include "Math.h"

#include <csignal>

jmp_buf Math::env;

void Math::SIGABRTHandle(int code) {
    longjmp (env, 1);
}

int Math::toInt(std::string value) {
    signal(SIGABRT, SIGABRTHandle);
    if (setjmp (env) == 0) {
        int i = std::stoi(value.c_str());
        signal(SIGINT, SIG_DFL);
        return i;
    }else{
        throw new MathException("Value is not a Int number");
    }
}

float Math::toFloat(std::string value) {
    signal(SIGABRT, SIGABRTHandle);
    if (setjmp (env) == 0) {
        float i =  std::stof(value.c_str());
        signal(SIGINT, SIG_DFL);
        return i;
    }else{
        throw new MathException("Value is not a Float number");
    }
}

double Math::toDouble(std::string value) {
    signal(SIGABRT, SIGABRTHandle);
    if (setjmp (env) == 0) {
        double i =  std::stod(value.c_str());
        signal(SIGINT, SIG_DFL);
        return i;
    }else{
        throw new MathException("Value is not a Double number");
    }
}



MathException::MathException(char const* const message) throw() : std::runtime_error(message)  { }

char const * MathException::what() const throw()  {
    return std::exception::what();
}