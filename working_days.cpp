#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



// Function to check if a given date is a government holiday (replace with your actual holiday list)
bool isHoliday_or_weekend(int day, int month, int year) {
    // Replace this with a comprehensive list of government holidays for your region
    // You can use a vector or a hash table to store holiday dates efficiently
    vector<pair<int, int>> holidays = {{5,1},{6,1},{12,1},{13,1},{19,1},{20,1},{27,1},
    {2,2},{3,2},{9,2},{10,2},{16,2},{17,2},{21,2},{23,2},{24,2},{26,2},{1,3},
    {2,3},{8,3},{9,3},{15,3},{16,3},{17,3},{22,3},{23,3},{26,3},{29,3},{30,3},{5,4},{6,4},
    {10,4},{11,4},{12,4},{13,4},{14,4},{19,4},{20,4},{26,4},{27,4},{1,5},{3,5},{4,5},{10,5},
    {11,5},{17,5},{18,5},{22,5},{24,5},{25,5},{31,5},{1,6},{7,6},{8,6},{14,6},{15,6},{17,6},
    {18,6},{21,6},{22,6},{28,6},{29,6},{5,7},{6,7},{12,7},{13,7},{17,7},{19,7},{20,7},{26,7},
    {27,7},{2,8},{3,8},{9,8},{10,8},{15,8},{16,8},{17,8},{23,8},{24,8},{26,8},{30,8},{31,8},
    {6,9},{7,9},{13,9},{14,9},{16,9},{20,9},{21,9},{27,9},{28,9},{4,10},{5,10},{11,10},{12,10},
    {13,10},{18,10},{19,10},{25,10},{26,10},{1,11},{2,11},{8,11},{9,11},{15,11},{16,11},{22,11},
    {23,11},{29,11},{30,11},{6,12},{7,12},{13,12},{14,12},{16,12},{20,12},{21,12},{25,12},{27,12},{28,12}}; // Holidays of the year 2024

    for (auto holiday : holidays) {
        if (holiday.first == day && holiday.second == month) {
            return true;
        }
    }
    return false;
}

// Function to calculate working days between two dates
int calculateWorkingDays(int startDay, int startMonth, int startYear,
                         int endDay, int endMonth, int endYear) {
    int workingDays = 0;

    // Ensure start date is before or equal to end date
    if (startYear > endYear || (startYear == endYear && startMonth > endMonth) ||
        (startYear == endYear && startMonth == endMonth && startDay > endDay)) {
        swap(startDay, endDay);
        swap(startMonth, endMonth);
        swap(startYear, endYear);
    }

    // Iterate through each day from start date to end date
    for (int year = startYear; year <= endYear; year++) {
        for (int month = (year == startYear ? startMonth : 1); month <= (year == endYear ? endMonth : 12); month++) {
            for (int day = (year == startYear && month == startMonth ? startDay : 1);
                 day <= (year == endYear && month == endMonth ? endDay : 31); day++) {
                if (!isHoliday_or_weekend(day, month, year)) {
                    workingDays++;
                }
            }
        }
    }

    return workingDays;
}

int main() {
    int startDay, startMonth, startYear, endDay, endMonth, endYear;

    cout << "Enter frist date (DD MM YYYY): ";
    cin >> startDay >> startMonth >> startYear;

    cout << "Enter last date (DD MM YYYY): ";
    cin >> endDay >> endMonth >> endYear;

    int workingDays = calculateWorkingDays(startDay, startMonth, startYear, endDay, endMonth, endYear);

    cout << "Number of working days between the two dates: " << workingDays << endl;

    return 0;
}
