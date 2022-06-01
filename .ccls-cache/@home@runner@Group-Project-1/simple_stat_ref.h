#ifndef SIMPLE_STAT_REF_H
#define SIMPLE_STAT_REF_H

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



//Previous code from first draft main.cpp, just here for reference
/* Everything here as previously written before 5/23


  // set1 is a vector of numbers; initial data
  std::vector<double> set1{47, 67, 55, 92, 118}; 
  double new_data = 0;
  
  // initialize current_data vector
  std::vector<double> current_data = set1; 

  if (current_data.empty())
    // if current_data is empty (I also put this function in
    // fucntion update, will decide where is more appropriate)
  {
    current_data = set1; // current_data initialized to set1
  }

  // std::cout << "Data set: " << Simple_stat.update() << std::endl;
  // std::cout << "Maximum: " << Simple_stat.get_max() << std::endl;
  // std::cout << "Minimum: " << Simple_stat.get_min() << std::endl;
  // std::cout << "Mean: " << Simple_stat.get_mean() << std::endl;
  // std::cout << "Standard deviation: " << Simple_stat.get_SD() << std::endl;

  // this input still need to feed to update function (May 15)
  char answer = 'Y';
  while (!current_data.empty() && (answer == 'Y' || answer == 'y')) {
    std::cout << "Add new data? (y=yes / Any other character = No"
    << std::endl;
    std::cin >> answer;
    
    if (answer == 'Y' || answer == 'y') {
      std::cin >> new_data;
      //double Simple_stat<double>::update(current_data, new_data);
      

      
      // std::cout << "Data set: " << Simple_stat.display(current_data) << std::endl;
      // std::cout << "Maximum: " << Simple_stat.get_max() << std::endl;
      // std::cout << "Minimum: " << Simple_stat.get_min() << std::endl;
      // std::cout << "Mean: " << Simple_stat.get_mean() << std::endl;
      // std::cout << "Standard deviation: " << Simple_stat.get_SD() << std::endl;
    }
  }

  End of previously written code 5/23
  */ 



};

#endif