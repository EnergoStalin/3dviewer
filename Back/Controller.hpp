/**
 * @file nsController.hpp
 * @brief Header file for the ControllerViewer class
 * @date 02.06.2024
 */
#ifndef CONTROLLER
#define CONTROLLER

#include "Model.hpp"

namespace ns {
/**
 * @class ControllerViewer
 * @brief Controller class between View and Model
 */
class ControllerViewer {
 private:
  float *Points_;
  int *Facets_;
  size_t dots_count_, facets_count_;

 public:
  /**
   * @brief Constructor of the ControllerViewer class
   */
  ControllerViewer();
  /**
   * @brief Deconstructor of the ControllerViewer class
   */
  ~ControllerViewer();

  /**
   * @brief Method of moving the model to the right
   */
  void MoveRight();
  /**
   * @brief Method of moving the model to the left
   */
  void MoveLeft();
  /**
   * @brief Method of moving the model to the up
   */
  void MoveUp();
  /**
   * @brief Method of moving the model to the down
   */
  void MoveDown();
  /**
   * @brief Method of moving the model to the in
   */
  void MoveIn();
  /**
   * @brief Method of moving the model to the out
   */
  void MoveOut();

  /**
   * @brief Method of model rotation along the OX axis
   */
  void TurnPlusOX();
  /**
   * @brief Method of model rotation along the OY axis
   */
  void TurnPlusOY();
  /**
   * @brief Method of model rotation along the OZ axis
   */
  void TurnPlusOZ();
  /**
   * @brief Method of model rotation along the OX axis
   */
  void TurnMinusOX();
  /**
   * @brief Method of model rotation along the OY axis
   */
  void TurnMinusOY();
  /**
   * @brief Method of model rotation along the OZ axis
   */
  void TurnMinusOZ();

  /**
   * @brief Method of model augmentation
   */
  void ZoomIn();
  /**
   * @brief Model reduction method
   */
  void ZoomOut();

  /**
   * @brief Method of normalization of values in the range from -1 to 1
   */
  void Normalize();

  /**
   * @brief Model loading method
   */
  void LoadModel(const std::string &filename);

  /**
   * @brief Getter of Point
   */
  float *GetPoint();
  /**
   * @brief Getter of Facet
   */
  int *GetFacet();

  /**
   * @brief Getter of DotsCount
   */
  size_t get_dots_count();
  /**
   * @brief Getter of FacetCount
   */
  size_t get_facets_count();
};
}  // namespace ns

#endif
