//
// Created by pedro on 12/12/17.
//

#ifndef INTEGRATION_MATH_H
#define INTEGRATION_MATH_H


#include <csetjmp>
#include <string>
#include <stdexcept>

class MathException : public std::runtime_error  {
    public:
        MathException(char const* const message) throw();
        virtual char const* what() const throw();
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
