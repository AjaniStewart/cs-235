#include "GeniusBar.hpp"


GeniusBar::GeniusBar() {}
bool GeniusBar::addWaitingCustomer(Customer& new_customer) {
    if (number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS) {
        genius_bar_[number_of_customers_] = new_customer;
        current_wait_time_ += WAIT_TIME_INCREMENT;
        new_customer.updateWaitTime(current_wait_time_);
        return true;
    }
    return false;
}

bool GeniusBar::assignGeniusToCustomer() {
    if (number_of_customers_ > 0 && number_of_available_geniuses_ > 0)
    {
        number_of_customers_--;
        number_of_available_geniuses_--;
    }
    return (number_of_customers_ > 0 && number_of_available_geniuses_ > 0);
}

bool GeniusBar::releaseGenius() {
    if (number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES) {
        number_of_available_geniuses_++;
    }
    return number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES;
}

bool GeniusBar::updateCustomersWaitTime() {
    if (number_of_customers_ > 0) {
        for (Customer customer : genius_bar_) {
            customer.updateWaitTime(customer.getWaitTime() + WAIT_TIME_INCREMENT);
        }
    }
    return number_of_customers_ > 0;
}