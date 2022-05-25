#ifndef SIMPLE_STAT_H
#define SIMPLE_STAT_H

#include <iostream>
#include <set>
#include <vector>


template <class T> class Simple_stat {
private:
  std::vector<T> v;            // initial data in vector
  std::vector<T> current_data; // vector with updated value
  T new_data;                  // data to be added
  T mean;
  T SD;
  T maximum;
  T minimum;
  std::set<T> data_set; // set of numbers appear at least once in data
  int sorted_length;    // length of sorted data vector
  std::vector<T> sorted_data[];      // sorted data in ascending order

public:
  Simple_stat();
  T squarert(T num); // sqaure root function without math library
  T update(std::vector<T> &v, T new_num); // update function for adding new value
  T get_max();
  T get_min();
  T get_mean(const std::vector<T> &v);
  T get_SD(const std::vector<T> &v, T mean);
  T display(const std::vector<T> &v); // this tentative function may not needed, I leave it here for now
  T sort_data(); // function to sort data in ascending order
  T find_and_count(T target); // find a number and count its occurrence in data
};

#endif