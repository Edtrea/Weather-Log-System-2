/**
 * @file TIME.H
 * @author Lim Wen Chao
 * @brief Time class for storing 24 hour time
 * Splits in hour and minute before storing as unsigned int
 * Expects only 24hour time
 * @version 0.1
 * @date 2022-02-21
 * 
 * @version 1.0
 * @date 2022-04-05
 * Added Operator overload > for Bst insertion
 * Added Operator overload < for Bst insertion
 */

#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time
{
    public:
            /**
             * @brief Construct a new Time object
             * 
             */
        Time():m_hour(-1),m_minute(-1){};
            /**
             * @brief Construct a new Time object
             * 
             * @param h 
             * @param m 
             */
        Time(unsigned int h, unsigned int m);
            /**
             * @brief Destroy the Time object
             * 
             */
        ~Time(){};
        
            /**
             * @brief Get the Hour object
             * 
             * @return int 
             */
        int GetHour() const;
            /**
             * @brief Get the Minute object
             * 
             * @return int 
             */
        int GetMinute() const;
        
            /**
             * @brief Set the Hour object
             * 
             * @param h 
             */
        void SetHour(unsigned int h);
            /**
             * @brief Set the Minute object
             * 
             * @param m 
             */
        void SetMinute(unsigned int m);

            /**
             * @brief 
             * 
             * @return string 
             */
        string Display24HTime() const;

    private:
        int m_hour;
        int m_minute;
};

    /**
     * @brief Operator overload of < comparison. Compares Hour and minute.
     * 
     * @param lt - The Time object on the left of comparison
     * @param rt - The Time object on the right of comparison
     * @return true - If lt is less than rt
     * @return false - If lt is larger than rt
     */
bool operator < (const Time& lt, const Time& rt);

    /**
     * @brief Operator overload of > comparison. Compares hour and minute
     * 
     * @param lt - The Time object on the left of comparison
     * @param rt - The Time object on the right of comparison
     * @return true - If lt is more than rt
     * @return false - If lt is more than rt
     */
bool operator > (const Time& lt, const Time& rt);

#endif