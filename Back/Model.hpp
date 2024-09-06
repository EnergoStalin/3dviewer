/**
 * @file nsModel.hpp
 * @brief Header file for the Affine and Parser classes
 * @date 02.06.2024
 */
#ifndef MODEL
#define MODEL

#include <math.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

namespace ns {
/**
 * @class Affine class
 * @brief Class for affine transformations
 */
class Affine {
 public:
  /**
   * @brief Method for model movement
   */
  static void Move(float *A, const size_t dotsTriple, const double x,
                   const double y, const double z);
  /**
   * @brief Method for rotating the model
   */
  static void Turn(float *A, const size_t dotsTriple, const double OX,
                   const double OY, const double OZ);
  /**
   * @brief Method for zoom the model
   */
  static void Zoom(float *A, const size_t dotsTriple, float scale);
  /**
   * @brief Method for normalize the model
   */
  static void CenterAndScaleCoords(float *A, const size_t dotsTriple);

 private:
  static void Minmax(float *A, const size_t dotsTriple, float *nums, int axis);
};

class Parser {
 public:
  /**
   * @brief Method for parsing file
   */
  static void setMatrixs(const std::string &fileName, float **Points,
                         size_t &dotsTriple, int **Facets, size_t &facetsCount);

 private:
  static void get_quantity_of_points_and_facets(std::ifstream &filePointer,
                                                int &pointRows, int &facetRows);
  static void fill_points_and_facets(std::ifstream &filePointer, float *Points,
                                     int *Facets);
  static std::vector<std::string> split(const std::string &str);
};
}  // namespace ns

#endif
