//
// Created by pedro on 30/11/17.
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <nlohmann/json/single_include/nlohmann/json.hpp>
#include "Date.h"

Date::Date() {

}

Date::Date(time_t _time) : _time(_time){

}

Date *Date::now() {
    time_t _time = std::time(nullptr);
    return new Date( _time );
}

std::string Date::format(std::string format) const {
    std::stringstream buffer;
    buffer << std::put_time(std::localtime(&this->_time), format.c_str());
    return buffer.str();
}

std::string Date::formatUTC(std::string format) const {
    std::stringstream buffer;
    buffer << std::put_time(std::gmtime(&this->_time), format.c_str());
    return buffer.str();
}

Difference *Date::diff(Date *date) {
    double diff = difftime(this->_time, date->_time);
    return new Difference(diff);
}

Difference::Difference(double seconds) : _seconds(seconds) {
    this->days = (int)seconds / 60 / 60 / 24;
    this->hours = (int)(seconds / 60 / 60) % 24;
    this->minutes = (int)(seconds / 60) % 60;
    this->seconds = (int)seconds % 60;
}

Date* Date::fromFormat(std::string format, std::string date) {
    std::tm tm = {};
    std::istringstream ss(date.c_str());
    ss >> std::get_time(&tm, format.c_str()); // or just %T in this case
    std::time_t time = mktime(&tm);
    return new Date(time);
}

Date Date::parse(std::string format, std::string date) {
    std::tm tm = {};
    std::istringstream ss(date.c_str());
    ss >> std::get_time(&tm, format.c_str()); // or just %T in this case
    std::time_t time = mktime(&tm);
    return Date{ time };
}

void Date::addDays(int days) {
    const time_t ONE_DAY = 24 * 60 * 60 ;
    // Seconds since start of epoch
    this->_time = this->_time + (days * ONE_DAY) ;
}

void to_json(nlohmann::json& j, const Date& p){
    j = p.format("%d/%m/%Y %H:%M:%S");
}