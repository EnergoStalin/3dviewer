#include "Model.hpp"

void ns::Affine::Move(float *A, const size_t dotsTriple, const double x,
                       const double y, const double z) {
  for (size_t i = 0; i < dotsTriple * 3; i += 3) {
    A[i] += x;
    A[i + 1] += y;
    A[i + 2] += z;
  }
}

void ns::Affine::Turn(float *A, const size_t dotsTriple, const double OX,
                       const double OY, const double OZ) {
  float degreeX = (OX * M_PI) / 180.0;
  float degreeY = (OY * M_PI) / 180.0;
  float degreeZ = (OZ * M_PI) / 180.0;
  float copy_dots[2] = {};

  if (degreeX) {
    for (size_t i = 0; i < dotsTriple * 3; i += 3) {
      copy_dots[0] = A[i + 2];
      copy_dots[1] = A[i + 1];

      A[i + 2] = cos(degreeX) * copy_dots[0] + sin(degreeX) * copy_dots[1];
      A[i + 1] = -sin(degreeX) * copy_dots[0] + cos(degreeX) * copy_dots[1];
    }
  }

  if (degreeY) {
    for (size_t i = 0; i < dotsTriple * 3; i += 3) {
      copy_dots[0] = A[i];
      copy_dots[1] = A[i + 2];

      A[i] = cos(degreeY) * copy_dots[0] + sin(degreeY) * copy_dots[1];
      A[i + 2] = -sin(degreeY) * copy_dots[0] + cos(degreeY) * copy_dots[1];
    }
  }

  if (degreeZ) {
    for (size_t i = 0; i < dotsTriple * 3; i += 3) {
      copy_dots[0] = A[i];
      copy_dots[1] = A[i + 1];

      A[i] = cos(degreeZ) * copy_dots[0] + sin(degreeZ) * copy_dots[1];
      A[i + 1] = -sin(degreeZ) * copy_dots[0] + cos(degreeZ) * copy_dots[1];
    }
  }
}

void ns::Affine::Zoom(float *A, const size_t dotsTriple, const float scale) {
  for (size_t i = 0; i < dotsTriple * 3; i++) {
    A[i] *= scale;
  }
}

void ns::Affine::Minmax(float *A, const size_t dotsTriple, float *nums,
                         int axis) {
  switch (axis) {
    case 0:
      nums[0] = A[0];
      nums[1] = nums[0];
      for (size_t i = 3; i < dotsTriple * 3; i += 3) {
        if (A[i] < nums[0])
          nums[0] = A[i];
        else if (A[i] > nums[1])
          nums[1] = A[i];
      }
      break;
    case 1:
      nums[0] = A[1];
      nums[1] = nums[0];
      for (size_t i = 4; i < dotsTriple * 3; i += 3) {
        if (A[i] < nums[0])
          nums[0] = A[i];
        else if (A[i] > nums[1])
          nums[1] = A[i];
      }
      break;
    case 2:
      nums[0] = A[2];
      nums[1] = nums[0];
      for (size_t i = 5; i < dotsTriple * 3; i += 3) {
        if (A[i] < nums[0])
          nums[0] = A[i];
        else if (A[i] > nums[1])
          nums[1] = A[i];
      }
      break;
  }
}

void ns::Affine::CenterAndScaleCoords(float *A, const size_t dotsTriple) {
  float minmaxCoods[2];
  float minX, minY, minZ, maxX, maxY, maxZ;
  float centerX, centerY, centerZ;
  float scaleX, scaleY, scaleZ, Dmax, scaleVal;

  ns::Affine::Minmax(A, dotsTriple, minmaxCoods, 0);
  minX = minmaxCoods[0];
  maxX = minmaxCoods[1];

  ns::Affine::Minmax(A, dotsTriple, minmaxCoods, 1);
  minY = minmaxCoods[0];
  maxY = minmaxCoods[1];

  ns::Affine::Minmax(A, dotsTriple, minmaxCoods, 2);
  minZ = minmaxCoods[0];
  maxZ = minmaxCoods[1];

  centerX = minX + (maxX - minX) / 2;
  centerY = minY + (maxY - minY) / 2;
  centerZ = minZ + (maxZ - minZ) / 2;

  for (size_t i = 0; i < dotsTriple * 3; i += 3) {
    A[i] -= centerX;
    A[i + 1] -= centerY;
    A[i + 2] -= centerZ;
  }

  scaleX = maxX - minX;
  scaleY = maxY - minY;
  scaleZ = maxZ - minZ;
  Dmax = scaleX;

  if (Dmax < scaleY) Dmax = scaleY;
  if (Dmax < scaleZ) Dmax = scaleZ;

  scaleVal = (2 * 0.7) / Dmax;

  for (size_t i = 0; i < dotsTriple * 3; i++) {
    A[i] *= scaleVal;
  }
}

void ns::Parser::setMatrixs(const std::string &fileName, float **Points,
                             size_t &dotsTriple, int **Facets,
                             size_t &facetCount) {
  int pointRows = 0, facetRows = 0;

  std::ifstream file;
  file.open(fileName);

  if (!file.is_open())
    throw std::runtime_error("Failed to open file: " + fileName);

  Parser::get_quantity_of_points_and_facets(file, pointRows, facetRows);
  file.close();
  file.open(fileName);

  if (!file.is_open())
    throw std::runtime_error("Failed to open file: " + fileName);
  *Points = new float[pointRows * 3];
  *Facets = new int[facetRows * 2];
  dotsTriple = pointRows;
  facetCount = facetRows * 2;
  Parser::fill_points_and_facets(file, *Points, *Facets);
}

std::vector<std::string> ns::Parser::split(const std::string &str) {
  std::vector<std::string> tokens;
  std::stringstream ss(str);
  std::string token;

  while (std::getline(ss, token, ' ')) {
    // std::replace(token.begin(), token.end(), '.', ',');
    if (token != "") tokens.push_back(token);
  }

  return tokens;
}

void ns::Parser::get_quantity_of_points_and_facets(std::ifstream &filePointer,
                                                    int &pointRows,
                                                    int &facetRows) {
  int facets_in_lines = 0;
  std::string buffer;
  std::vector<std::string> splitSTR;

  while (std::getline(filePointer, buffer)) {
    if (buffer[0] == 'v' && buffer[1] == ' ') {
      pointRows++;
    } else if (buffer[0] == 'f' && buffer[1] == ' ') {
      splitSTR = split(buffer);
      for (size_t i = 2; i < splitSTR.size(); i++) {
        facets_in_lines++;
        facetRows += 2;
      }
      if (facets_in_lines >= 2) {
        facetRows -= 2;
      }
      facets_in_lines = 0;
    }
  }
}

void ns::Parser::fill_points_and_facets(std::ifstream &filePointer,
                                         float *Points, int *Facets) {
  std::string buffer;
  std::vector<std::string> splitSTR;
  int index_of_points = 0, index_of_facets = 0, previous = 0, current = 0;

  while (std::getline(filePointer, buffer)) {
    if (buffer[0] == 'v' && buffer[1] == ' ') {
      splitSTR = split(buffer);
      Points[index_of_points] = std::stod(splitSTR[1]);
      index_of_points++;
      Points[index_of_points] = std::stod(splitSTR[2]);
      index_of_points++;
      Points[index_of_points] = std::stod(splitSTR[3]);
      index_of_points++;
    } else if (buffer[0] == 'f' && buffer[1] == ' ') {
      splitSTR = split(buffer);
      previous = std::stoi(splitSTR[1]) - 1;
      for (size_t i = 2; i < splitSTR.size(); i++) {
        current = std::stoi(splitSTR[i]) - 1;
        Facets[index_of_facets++] = previous;
        Facets[index_of_facets++] = current;
        previous = current;
      }
    }
  }
}
