//
// Created by pedro on 30/11/17.
//

#ifndef INTEGRATION_DATE_H
#define INTEGRATION_DATE_H

#include <time.h>
#include <string>

class Difference {

    public:
        Difference(double seconds);



    //private:
        int days;
        int hours;
        int minutes;
        int seconds;
        double _seconds;
};

class Date {

    public:
        Date();
        Date(time_t _time);
        std::string format(std::string format) const;
        std::string formatUTC(std::string format) const;
        Difference *diff(Date *date);
        void addDays( int days );
        static Date *now();
        static Date *fromFormat(std::string format, std::string date);
    //private:
        time_t _time;

};


#endif //INTEGRATION_DATE_H
