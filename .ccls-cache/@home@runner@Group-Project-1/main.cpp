#include "simple_stat.h"
#include <iostream>
#include <set>
#include <vector>

// --------------- Main Function ---------------

int main() {
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
}