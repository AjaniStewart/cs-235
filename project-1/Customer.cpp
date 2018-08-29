#include <string>
#include "Customer.hpp"
using namespace std;

Customer::Customer() {}
Customer::Customer(string name, string device, int wait_time)
    : name_(name), defective_device_(device), wait_time_(wait_time) {}

string Customer::getName() { return name_; }
string Customer::getDevice() { return defective_device_; }
int Customer::getWaitTime() { return wait_time_; }
void Customer::updateWaitTime(int new_time) {
    wait_time_ = new_time;
} 
