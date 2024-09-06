#include "Controller.hpp"

ns::ControllerViewer::ControllerViewer()
    : Points_(nullptr), Facets_(nullptr), dots_count_(0), facets_count_(0) {};

void ns::ControllerViewer::MoveRight() {
  ns::Affine::Move(Points_, dots_count_, 0.1, 0, 0);
}

void ns::ControllerViewer::MoveLeft() {
  ns::Affine::Move(Points_, dots_count_, -0.1, 0, 0);
}

void ns::ControllerViewer::MoveDown() {
  ns::Affine::Move(Points_, dots_count_, 0, -0.1, 0);
}

void ns::ControllerViewer::MoveUp() {
  ns::Affine::Move(Points_, dots_count_, 0, 0.1, 0);
}

void ns::ControllerViewer::MoveIn() {
  ns::Affine::Move(Points_, dots_count_, 0, 0, 0.1);
}

void ns::ControllerViewer::MoveOut() {
  ns::Affine::Move(Points_, dots_count_, 0, 0, -0.1);
}

void ns::ControllerViewer::TurnPlusOX() {
  ns::Affine::Turn(Points_, dots_count_, 15, 0, 0);
}

void ns::ControllerViewer::TurnPlusOY() {
  ns::Affine::Turn(Points_, dots_count_, 0, 15, 0);
}

void ns::ControllerViewer::TurnPlusOZ() {
  ns::Affine::Turn(Points_, dots_count_, 0, 0, 15);
}

void ns::ControllerViewer::TurnMinusOX() {
  ns::Affine::Turn(Points_, dots_count_, -15, 0, 0);
}

void ns::ControllerViewer::TurnMinusOY() {
  ns::Affine::Turn(Points_, dots_count_, 0, -15, 0);
}

void ns::ControllerViewer::TurnMinusOZ() {
  ns::Affine::Turn(Points_, dots_count_, 0, 0, -15);
}

void ns::ControllerViewer::ZoomIn() {
  ns::Affine::Zoom(Points_, dots_count_, 1.1);
}

void ns::ControllerViewer::ZoomOut() {
  ns::Affine::Zoom(Points_, dots_count_, 0.9);
}

void ns::ControllerViewer::Normalize() {
  ns::Affine::CenterAndScaleCoords(Points_, dots_count_);
}

void ns::ControllerViewer::LoadModel(const std::string &filename) {
  if (Points_) delete[] Points_;
  if (Facets_) delete[] Facets_;

  ns::Parser::setMatrixs(filename, &Points_, dots_count_, &Facets_,
                          facets_count_);
}

float *ns::ControllerViewer::GetPoint() { return Points_; }

int *ns::ControllerViewer::GetFacet() { return Facets_; }

ns::ControllerViewer::~ControllerViewer() {
  if (Points_) delete[] Points_;
  if (Facets_) delete[] Facets_;
}

size_t ns::ControllerViewer::get_dots_count() { return this->dots_count_; }

size_t ns::ControllerViewer::get_facets_count() { return this->facets_count_; }
