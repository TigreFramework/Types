//
// Created by pedro on 12/12/17.
//

#ifndef INTEGRATION_MATH_H
#define INTEGRATION_MATH_H


#include <csetjmp>
#include <string>
#include <TigreFramework/Core/Kernel/Exception.h>

class MathException : public Exception  {

    public:
        MathException(std::string message);

};

class Math {

    public:
        static int toInt(std::string value);
        static float toFloat(std::string value);
        static double toDouble(std::string value);

    private:
        static jmp_buf env;
        static void SIGABRTHandle(int code);

};


#endif //INTEGRATION_MATH_H
