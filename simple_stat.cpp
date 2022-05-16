#include "simple_stat.h"
#include <iostream>
#include <set>
#include <vector>

// --------------- Square root function ---------------
template <class T> 
T Simple_stat<T>::squarert(T num)
{
    T root=num/3;
    T i;
    if (num <= 0) return 0;
    for (i=0; i<32; i++)
        root = (root + num / root) / 2;
    return root;
}

template <class T>
Simple_stat<T>::Simple_stat() {
  
}

// --------------- Update function ---------------
template <class T> 
T Simple_stat<T>::update(std::vector<T> &v, T new_num) {
  // T v;
  // T new_num;
  std::vector<T> current_data;

  if (current_data.empty()) // if current_data is empty
  {
    for (T x : v) // each element in initial vector v gets built into vector current_data
    {
      current_data.insert(x);
    }

    return current_data; // return updated current_data vector
  } else                 // if current_data already has data
  {
    current_data.push_back(new_num); // add new element into current_data

    return current_data; // return updated current_data vector
  }
}

// --------------- Maximum function ---------------
template <class T> // Maximum function
T Simple_stat<T>::get_max() {
  int sorted_length = sorted_data.size();

  T maximum = sorted_data[sorted_length - 1]; // Last element of sorted_data is the maximum

  return maximum;
}

// --------------- Minimum function ---------------
template <class T> 
T Simple_stat<T>::get_min() {
  T minimum = sorted_data[0]; // First element of sorted_data is the minimum
  return minimum;
}

// --------------- Mean function ---------------
template <class T> 
T Simple_stat<T>::get_mean(const std::vector<T> &v) {
  T sum = 0;
  T mean = 0;
  int v_length = v.size();
  
  for (int i = 0; i < v_length; i++) {
    sum = sum + v[i]; // sum of all elements in vector
  }

  mean = sum / v_length; // get mean value

  return mean;
}

// --------------- Standard deviation function ---------------
template <class T> 
T Simple_stat<T>::get_SD(const std::vector<T> &v, T mean) {
  T sum_of_sq = 0;
  int v_length = v.size();

  for (int i = 0; i < v_length; i++) {
    sum_of_sq = sum_of_sq + (v[i] - mean) * (v[i] - mean);
  }

  T var = sum_of_sq / v_length; // variance

  T SD = sqrt(var); // population standard deviation

  return SD;
}

// --------------- Display function ---------------
template <class T> 
T Simple_stat<T>::display(const std::vector<T> &v) {
  std::cout << "Data: ";
  for (T x = v.begin(); x != v.end(); x++)
    std::cout << *x << " ";
  std::cout << std::endl;
}

// --------------- Sort the data in ascending order ---------------
template <class T>
T Simple_stat<T>::sort_data() // this function uses bubble sort
{
  std::vector<T> sorted_data;
  int i;
  for (i = 0; i < v[v.size() - 1]; i++) {
    int j;
    for (j = v[v.size() - 1]; j > i; j--) {
      if (v[j] < v[j - 1]) {
        int temp;
        temp = v[j];
        v[j] = v[j - 1];
        v[j - 1] = temp;
      }
    }
  }
  return sorted_data;
}
// --------------- Find a number and count its occurrence ---------------
template <class T>
T Simple_stat<T>::find_and_count(T target) // using binary search
{
  // set the lower and upper ends
  int beg = 0, end = sorted_data.size() - 1;

  // initialize the result by -1
  int found = -1; // found is -1 if not found, 1 if found

  int first_location;
  int last_location;

  // loop till the 1st location is found
  while (beg <= end) {
    // find the mid-value in the search space and compares it with the target
    int mid = (beg + end) / 2;

    // if the target is found, update the result
    if (target == sorted_data[mid]) {
      // go on searching towards the left (lower indices)
      if (sorted_data[mid - 1] == target && mid - 1 >= 0) {
        end = mid - 1;
        first_location = mid - 1;
      }
      // go on searching towards the right (higher indices)
      else {
        first_location = mid;
      }
      found = 1; // found
    }

    // if the target is less than the middle element, discard the right half
    else if (target < sorted_data[mid]) {
      end = mid - 1;
    }
    // if the target is more than the middle element, discard the left half
    else {
      beg = mid + 1;
    }
  }

  // set the lower and upper ends
  beg = 0, end = sorted_data.size() - 1;

  while (beg <= end) {
    // find the mid-value in the search space and compares it with the target
    int mid = (beg + end) / 2;

    // if the target is found, update the result
    if (target == sorted_data[mid]) {

      // go on searching towards the left (lower indices)
      if (sorted_data[mid + 1] == target && mid + 1 <= sorted_data.size() - 1) {
        beg = mid + 1;
        last_location = mid + 1;
      }
      // go on searching towards the right (higher indices)
      else {
        last_location = mid;
      }
      found = 1;
    }

    // if the target is less than the middle element, discard the right half
    else if (target < sorted_data[mid]) {
      end = mid - 1;
    }
    // if the target is more than the middle element, discard the left half
    else {
      beg = mid + 1;
    }
  }

  if (found == 1) // if number is found
  {
    std::cout << "Location of first occurence of " << target
              << "in data is at index " << first_location << std::endl;

    std::cout << "Location of last occurence of " << target
              << "in data is at index " << last_location << std::endl;

    std::cout << "Total count of occurence of " << target << "in data is "
              << last_location - first_location + 1 << std::endl;
  } else // if number is not found
  {
    std::cout << "Number entered is not found." << std::endl;
  }
}