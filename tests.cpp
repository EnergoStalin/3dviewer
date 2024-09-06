#include "Back/Controller.hpp"
#include "gtest/gtest.h"

ns::ControllerViewer C;
ns::Affine A;
ns::Parser P;

TEST(Viewer, P1) {
  float *Points;
  int *Facets;
  size_t dotsTriple, facetCount;
  ASSERT_ANY_THROW(
      P.setMatrixs("123", &Points, dotsTriple, &Facets, facetCount));
}

TEST(Viewer, P2) {
  float *Points;
  int *Facets;
  size_t dotsTriple, facetCount;
  P.setMatrixs("cube.objs", &Points, dotsTriple, &Facets, facetCount);

  EXPECT_EQ(Points[0], 0);
  EXPECT_EQ(Points[1], 0);
  EXPECT_EQ(Points[2], 0);
  EXPECT_EQ(Points[3], 0);
  EXPECT_EQ(Points[4], 0);
  EXPECT_EQ(Points[5], 2);
  EXPECT_EQ(Points[6], 0);
  EXPECT_EQ(Points[7], 2);
  EXPECT_EQ(Points[8], 0);
  EXPECT_EQ(Points[9], 0);
  EXPECT_EQ(Points[10], 2);
  EXPECT_EQ(Points[11], 2);
  EXPECT_EQ(Points[12], 2);
  EXPECT_EQ(Points[13], 0);
  EXPECT_EQ(Points[14], 0);
  EXPECT_EQ(Points[15], 2);
  EXPECT_EQ(Points[16], 0);
  EXPECT_EQ(Points[17], 2);
  EXPECT_EQ(Points[18], 2);
  EXPECT_EQ(Points[19], 2);
  EXPECT_EQ(Points[20], 0);
  EXPECT_EQ(Points[21], 2);
  EXPECT_EQ(Points[22], 2);
  EXPECT_EQ(Points[23], 2);

  EXPECT_EQ(Facets[0], 0);
  EXPECT_EQ(Facets[1], 6);
  EXPECT_EQ(Facets[2], 6);
  EXPECT_EQ(Facets[3], 4);
  EXPECT_EQ(Facets[4], 0);
  EXPECT_EQ(Facets[5], 2);
  EXPECT_EQ(Facets[6], 2);
  EXPECT_EQ(Facets[7], 6);
  EXPECT_EQ(Facets[8], 0);
  EXPECT_EQ(Facets[9], 3);
  EXPECT_EQ(Facets[10], 3);
  EXPECT_EQ(Facets[11], 2);
  EXPECT_EQ(Facets[12], 0);
  EXPECT_EQ(Facets[13], 1);
  EXPECT_EQ(Facets[14], 1);
  EXPECT_EQ(Facets[15], 3);
  EXPECT_EQ(Facets[16], 2);
  EXPECT_EQ(Facets[17], 7);
  EXPECT_EQ(Facets[18], 7);
  EXPECT_EQ(Facets[19], 6);
  EXPECT_EQ(Facets[20], 2);
  EXPECT_EQ(Facets[21], 3);
  EXPECT_EQ(Facets[22], 3);
  EXPECT_EQ(Facets[23], 7);
  EXPECT_EQ(Facets[24], 4);
  EXPECT_EQ(Facets[25], 6);
  EXPECT_EQ(Facets[26], 6);
  EXPECT_EQ(Facets[27], 7);
  EXPECT_EQ(Facets[28], 4);
  EXPECT_EQ(Facets[29], 7);
  EXPECT_EQ(Facets[30], 7);
  EXPECT_EQ(Facets[31], 5);
  EXPECT_EQ(Facets[32], 0);
  EXPECT_EQ(Facets[33], 4);
  EXPECT_EQ(Facets[34], 4);
  EXPECT_EQ(Facets[35], 5);
  EXPECT_EQ(Facets[36], 0);
  EXPECT_EQ(Facets[37], 5);
  EXPECT_EQ(Facets[38], 5);
  EXPECT_EQ(Facets[39], 1);

  EXPECT_EQ(dotsTriple, 8);
  EXPECT_EQ(dotsTriple, 8);

  delete[] Points;
  delete[] Facets;
}

TEST(Viewer, A1) {
  float Points[] = {1, 2, 3, 4, 5, 6};
  A.Move(Points, 2, 1, 2, 3);
  EXPECT_EQ(Points[0], 2);
  EXPECT_EQ(Points[1], 4);
  EXPECT_EQ(Points[2], 6);
  EXPECT_EQ(Points[3], 5);
  EXPECT_EQ(Points[4], 7);
  EXPECT_EQ(Points[5], 9);
}

TEST(Viewer, A2) {
  float Points[] = {1, 2, 3, 4, 5, 6};
  A.Turn(Points, 2, 15, -15, 30);
  EXPECT_FLOAT_EQ(Points[0], 0.648669);
  EXPECT_FLOAT_EQ(Points[1], 0.95962548);
  EXPECT_FLOAT_EQ(Points[2], 3.5578573);
  EXPECT_FLOAT_EQ(Points[3], 3.39532);
  EXPECT_FLOAT_EQ(Points[4], 1.8233349);
  EXPECT_FLOAT_EQ(Points[5], 7.883352);
}

TEST(Viewer, A3) {
  float Points[] = {1, 2, 3, 4, 5, 6};
  A.Zoom(Points, 2, 1.1);
  EXPECT_FLOAT_EQ(Points[0], 1.1);
  EXPECT_FLOAT_EQ(Points[1], 2.2);
  EXPECT_FLOAT_EQ(Points[2], 3.3);
  EXPECT_FLOAT_EQ(Points[3], 4.4);
  EXPECT_FLOAT_EQ(Points[4], 5.5);
  EXPECT_FLOAT_EQ(Points[5], 6.6);
}

TEST(Viewer, A4) {
  float Points[] = {1, 2, 3, 4, 5, 6};
  A.CenterAndScaleCoords(Points, 2);
  EXPECT_GE(Points[0], -1);
  EXPECT_LE(Points[0], 1);
  EXPECT_GE(Points[1], -1);
  EXPECT_LE(Points[1], 1);
  EXPECT_GE(Points[2], -1);
  EXPECT_LE(Points[2], 1);
  EXPECT_GE(Points[3], -1);
  EXPECT_LE(Points[3], 1);
  EXPECT_GE(Points[4], -1);
  EXPECT_LE(Points[4], 1);
  EXPECT_GE(Points[5], -1);
  EXPECT_LE(Points[5], 1);
}

TEST(Viewer, C1) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.MoveUp();
  EXPECT_FLOAT_EQ(p[0], 0);
  EXPECT_FLOAT_EQ(p[1], 0.1);
  EXPECT_FLOAT_EQ(p[2], 0);
  EXPECT_FLOAT_EQ(p[3], 0);
  EXPECT_FLOAT_EQ(p[4], 0.1);
  EXPECT_FLOAT_EQ(p[5], 2);
  EXPECT_FLOAT_EQ(p[6], 0);
  EXPECT_FLOAT_EQ(p[7], 2.1);
  EXPECT_FLOAT_EQ(p[8], 0);
  EXPECT_FLOAT_EQ(p[9], 0);
  EXPECT_FLOAT_EQ(p[10], 2.1);
  EXPECT_FLOAT_EQ(p[11], 2);
  EXPECT_FLOAT_EQ(p[12], 2);
  EXPECT_FLOAT_EQ(p[13], 0.1);
  EXPECT_FLOAT_EQ(p[14], 0);
  EXPECT_FLOAT_EQ(p[15], 2);
  EXPECT_FLOAT_EQ(p[16], 0.1);
  EXPECT_FLOAT_EQ(p[17], 2);
  EXPECT_FLOAT_EQ(p[18], 2);
  EXPECT_FLOAT_EQ(p[19], 2.1);
  EXPECT_FLOAT_EQ(p[20], 0);
  EXPECT_FLOAT_EQ(p[21], 2);
  EXPECT_FLOAT_EQ(p[22], 2.1);
  EXPECT_FLOAT_EQ(p[23], 2);
}

TEST(Viewer, C2) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.MoveDown();
  EXPECT_FLOAT_EQ(p[0], 0);
  EXPECT_FLOAT_EQ(p[1], -0.1);
  EXPECT_FLOAT_EQ(p[2], 0);
  EXPECT_FLOAT_EQ(p[3], 0);
  EXPECT_FLOAT_EQ(p[4], -0.1);
  EXPECT_FLOAT_EQ(p[5], 2);
  EXPECT_FLOAT_EQ(p[6], 0);
  EXPECT_FLOAT_EQ(p[7], 1.9);
  EXPECT_FLOAT_EQ(p[8], 0);
  EXPECT_FLOAT_EQ(p[9], 0);
  EXPECT_FLOAT_EQ(p[10], 1.9);
  EXPECT_FLOAT_EQ(p[11], 2);
  EXPECT_FLOAT_EQ(p[12], 2);
  EXPECT_FLOAT_EQ(p[13], -0.1);
  EXPECT_FLOAT_EQ(p[14], 0);
  EXPECT_FLOAT_EQ(p[15], 2);
  EXPECT_FLOAT_EQ(p[16], -0.1);
  EXPECT_FLOAT_EQ(p[17], 2);
  EXPECT_FLOAT_EQ(p[18], 2);
  EXPECT_FLOAT_EQ(p[19], 1.9);
  EXPECT_FLOAT_EQ(p[20], 0);
  EXPECT_FLOAT_EQ(p[21], 2);
  EXPECT_FLOAT_EQ(p[22], 1.9);
  EXPECT_FLOAT_EQ(p[23], 2);
}

TEST(Viewer, C3) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.MoveRight();
  EXPECT_FLOAT_EQ(p[0], 0.1);
  EXPECT_FLOAT_EQ(p[1], 0);
  EXPECT_FLOAT_EQ(p[2], 0);
  EXPECT_FLOAT_EQ(p[3], 0.1);
  EXPECT_FLOAT_EQ(p[4], 0);
  EXPECT_FLOAT_EQ(p[5], 2);
  EXPECT_FLOAT_EQ(p[6], 0.1);
  EXPECT_FLOAT_EQ(p[7], 2);
  EXPECT_FLOAT_EQ(p[8], 0);
  EXPECT_FLOAT_EQ(p[9], 0.1);
  EXPECT_FLOAT_EQ(p[10], 2);
  EXPECT_FLOAT_EQ(p[11], 2);
  EXPECT_FLOAT_EQ(p[12], 2.1);
  EXPECT_FLOAT_EQ(p[13], 0);
  EXPECT_FLOAT_EQ(p[14], 0);
  EXPECT_FLOAT_EQ(p[15], 2.1);
  EXPECT_FLOAT_EQ(p[16], 0);
  EXPECT_FLOAT_EQ(p[17], 2);
  EXPECT_FLOAT_EQ(p[18], 2.1);
  EXPECT_FLOAT_EQ(p[19], 2);
  EXPECT_FLOAT_EQ(p[20], 0);
  EXPECT_FLOAT_EQ(p[21], 2.1);
  EXPECT_FLOAT_EQ(p[22], 2);
  EXPECT_FLOAT_EQ(p[23], 2);
}

TEST(Viewer, C4) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.MoveLeft();
  EXPECT_FLOAT_EQ(p[0], -0.1);
  EXPECT_FLOAT_EQ(p[1], 0);
  EXPECT_FLOAT_EQ(p[2], 0);
  EXPECT_FLOAT_EQ(p[3], -0.1);
  EXPECT_FLOAT_EQ(p[4], 0);
  EXPECT_FLOAT_EQ(p[5], 2);
  EXPECT_FLOAT_EQ(p[6], -0.1);
  EXPECT_FLOAT_EQ(p[7], 2);
  EXPECT_FLOAT_EQ(p[8], 0);
  EXPECT_FLOAT_EQ(p[9], -0.1);
  EXPECT_FLOAT_EQ(p[10], 2);
  EXPECT_FLOAT_EQ(p[11], 2);
  EXPECT_FLOAT_EQ(p[12], 1.9);
  EXPECT_FLOAT_EQ(p[13], 0);
  EXPECT_FLOAT_EQ(p[14], 0);
  EXPECT_FLOAT_EQ(p[15], 1.9);
  EXPECT_FLOAT_EQ(p[16], 0);
  EXPECT_FLOAT_EQ(p[17], 2);
  EXPECT_FLOAT_EQ(p[18], 1.9);
  EXPECT_FLOAT_EQ(p[19], 2);
  EXPECT_FLOAT_EQ(p[20], 0);
  EXPECT_FLOAT_EQ(p[21], 1.9);
  EXPECT_FLOAT_EQ(p[22], 2);
  EXPECT_FLOAT_EQ(p[23], 2);
}

TEST(Viewer, C5) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.MoveIn();
  EXPECT_FLOAT_EQ(p[0], 0);
  EXPECT_FLOAT_EQ(p[1], 0);
  EXPECT_FLOAT_EQ(p[2], 0.1);
  EXPECT_FLOAT_EQ(p[3], 0);
  EXPECT_FLOAT_EQ(p[4], 0);
  EXPECT_FLOAT_EQ(p[5], 2.1);
  EXPECT_FLOAT_EQ(p[6], 0);
  EXPECT_FLOAT_EQ(p[7], 2);
  EXPECT_FLOAT_EQ(p[8], 0.1);
  EXPECT_FLOAT_EQ(p[9], 0);
  EXPECT_FLOAT_EQ(p[10], 2);
  EXPECT_FLOAT_EQ(p[11], 2.1);
  EXPECT_FLOAT_EQ(p[12], 2);
  EXPECT_FLOAT_EQ(p[13], 0);
  EXPECT_FLOAT_EQ(p[14], 0.1);
  EXPECT_FLOAT_EQ(p[15], 2);
  EXPECT_FLOAT_EQ(p[16], 0);
  EXPECT_FLOAT_EQ(p[17], 2.1);
  EXPECT_FLOAT_EQ(p[18], 2);
  EXPECT_FLOAT_EQ(p[19], 2);
  EXPECT_FLOAT_EQ(p[20], 0.1);
  EXPECT_FLOAT_EQ(p[21], 2);
  EXPECT_FLOAT_EQ(p[22], 2);
  EXPECT_FLOAT_EQ(p[23], 2.1);
}

TEST(Viewer, C6) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.MoveOut();
  EXPECT_FLOAT_EQ(p[0], 0);
  EXPECT_FLOAT_EQ(p[1], 0);
  EXPECT_FLOAT_EQ(p[2], -0.1);
  EXPECT_FLOAT_EQ(p[3], 0);
  EXPECT_FLOAT_EQ(p[4], 0);
  EXPECT_FLOAT_EQ(p[5], 1.9);
  EXPECT_FLOAT_EQ(p[6], 0);
  EXPECT_FLOAT_EQ(p[7], 2);
  EXPECT_FLOAT_EQ(p[8], -0.1);
  EXPECT_FLOAT_EQ(p[9], 0);
  EXPECT_FLOAT_EQ(p[10], 2);
  EXPECT_FLOAT_EQ(p[11], 1.9);
  EXPECT_FLOAT_EQ(p[12], 2);
  EXPECT_FLOAT_EQ(p[13], 0);
  EXPECT_FLOAT_EQ(p[14], -0.1);
  EXPECT_FLOAT_EQ(p[15], 2);
  EXPECT_FLOAT_EQ(p[16], 0);
  EXPECT_FLOAT_EQ(p[17], 1.9);
  EXPECT_FLOAT_EQ(p[18], 2);
  EXPECT_FLOAT_EQ(p[19], 2);
  EXPECT_FLOAT_EQ(p[20], -0.1);
  EXPECT_FLOAT_EQ(p[21], 2);
  EXPECT_FLOAT_EQ(p[22], 2);
  EXPECT_FLOAT_EQ(p[23], 1.9);
}

TEST(Viewer, C7) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.TurnPlusOX();
  EXPECT_FLOAT_EQ(p[0], 0);
  EXPECT_FLOAT_EQ(p[1], 0);
  EXPECT_FLOAT_EQ(p[2], 0);
  EXPECT_FLOAT_EQ(p[3], 0);
  EXPECT_FLOAT_EQ(p[4], -0.51763809);
  EXPECT_FLOAT_EQ(p[5], 1.9318516);
  EXPECT_FLOAT_EQ(p[6], 0);
  EXPECT_FLOAT_EQ(p[7], 1.9318516);
  EXPECT_FLOAT_EQ(p[8], 0.51763809);
  EXPECT_FLOAT_EQ(p[9], 0);
  EXPECT_FLOAT_EQ(p[10], 1.4142135);
  EXPECT_FLOAT_EQ(p[11], 2.4494896);
  EXPECT_FLOAT_EQ(p[12], 2);
  EXPECT_FLOAT_EQ(p[13], 0);
  EXPECT_FLOAT_EQ(p[14], 0);
  EXPECT_FLOAT_EQ(p[15], 2);
  EXPECT_FLOAT_EQ(p[16], -0.51763809);
  EXPECT_FLOAT_EQ(p[17], 1.9318516);
  EXPECT_FLOAT_EQ(p[18], 2);
  EXPECT_FLOAT_EQ(p[19], 1.9318516);
  EXPECT_FLOAT_EQ(p[20], 0.51763809);
  EXPECT_FLOAT_EQ(p[21], 2);
  EXPECT_FLOAT_EQ(p[22], 1.4142135);
  EXPECT_FLOAT_EQ(p[23], 2.4494896);
}

TEST(Viewer, C8) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.TurnPlusOY();
  EXPECT_FLOAT_EQ(p[0], 0);
  EXPECT_FLOAT_EQ(p[1], 0);
  EXPECT_FLOAT_EQ(p[2], 0);
  EXPECT_FLOAT_EQ(p[3], 0.51763809);
  EXPECT_FLOAT_EQ(p[4], 0);
  EXPECT_FLOAT_EQ(p[5], 1.9318516);
  EXPECT_FLOAT_EQ(p[6], 0);
  EXPECT_FLOAT_EQ(p[7], 2);
  EXPECT_FLOAT_EQ(p[8], 0);
  EXPECT_FLOAT_EQ(p[9], 0.51763809);
  EXPECT_FLOAT_EQ(p[10], 2);
  EXPECT_FLOAT_EQ(p[11], 1.9318516);
  EXPECT_FLOAT_EQ(p[12], 1.9318516);
  EXPECT_FLOAT_EQ(p[13], 0);
  EXPECT_FLOAT_EQ(p[14], -0.51763809);
  EXPECT_FLOAT_EQ(p[15], 2.4494896);
  EXPECT_FLOAT_EQ(p[16], 0);
  EXPECT_FLOAT_EQ(p[17], 1.4142135);
  EXPECT_FLOAT_EQ(p[18], 1.9318516);
  EXPECT_FLOAT_EQ(p[19], 2);
  EXPECT_FLOAT_EQ(p[20], -0.51763809);
  EXPECT_FLOAT_EQ(p[21], 2.4494896);
  EXPECT_FLOAT_EQ(p[22], 2);
  EXPECT_FLOAT_EQ(p[23], 1.4142135);
}

TEST(Viewer, C9) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.TurnPlusOZ();
  EXPECT_FLOAT_EQ(p[0], 0);
  EXPECT_FLOAT_EQ(p[1], 0);
  EXPECT_FLOAT_EQ(p[2], 0);
  EXPECT_FLOAT_EQ(p[3], 0);
  EXPECT_FLOAT_EQ(p[4], 0);
  EXPECT_FLOAT_EQ(p[5], 2);
  EXPECT_FLOAT_EQ(p[6], 0.51763809);
  EXPECT_FLOAT_EQ(p[7], 1.9318516);
  EXPECT_FLOAT_EQ(p[8], 0);
  EXPECT_FLOAT_EQ(p[9], 0.51763809);
  EXPECT_FLOAT_EQ(p[10], 1.9318516);
  EXPECT_FLOAT_EQ(p[11], 2);
  EXPECT_FLOAT_EQ(p[12], 1.9318516);
  EXPECT_FLOAT_EQ(p[13], -0.51763809);
  EXPECT_FLOAT_EQ(p[14], 0);
  EXPECT_FLOAT_EQ(p[15], 1.9318516);
  EXPECT_FLOAT_EQ(p[16], -0.51763809);
  EXPECT_FLOAT_EQ(p[17], 2);
  EXPECT_FLOAT_EQ(p[18], 2.4494896);
  EXPECT_FLOAT_EQ(p[19], 1.4142135);
  EXPECT_FLOAT_EQ(p[20], 0);
  EXPECT_FLOAT_EQ(p[21], 2.4494896);
  EXPECT_FLOAT_EQ(p[22], 1.4142135);
  EXPECT_FLOAT_EQ(p[23], 2);
}

TEST(Viewer, C10) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.TurnMinusOX();
  EXPECT_FLOAT_EQ(p[0], 0);
  EXPECT_FLOAT_EQ(p[1], 0);
  EXPECT_FLOAT_EQ(p[2], 0);
  EXPECT_FLOAT_EQ(p[3], 0);
  EXPECT_FLOAT_EQ(p[4], 0.51763809);
  EXPECT_FLOAT_EQ(p[5], 1.9318516);
  EXPECT_FLOAT_EQ(p[6], 0);
  EXPECT_FLOAT_EQ(p[7], 1.9318516);
  EXPECT_FLOAT_EQ(p[8], -0.51763809);
  EXPECT_FLOAT_EQ(p[9], 0);
  EXPECT_FLOAT_EQ(p[10], 2.4494896);
  EXPECT_FLOAT_EQ(p[11], 1.4142135);
  EXPECT_FLOAT_EQ(p[12], 2);
  EXPECT_FLOAT_EQ(p[13], 0);
  EXPECT_FLOAT_EQ(p[14], 0);
  EXPECT_FLOAT_EQ(p[15], 2);
  EXPECT_FLOAT_EQ(p[16], 0.51763809);
  EXPECT_FLOAT_EQ(p[17], 1.9318516);
  EXPECT_FLOAT_EQ(p[18], 2);
  EXPECT_FLOAT_EQ(p[19], 1.9318516);
  EXPECT_FLOAT_EQ(p[20], -0.51763809);
  EXPECT_FLOAT_EQ(p[21], 2);
  EXPECT_FLOAT_EQ(p[22], 2.4494896);
  EXPECT_FLOAT_EQ(p[23], 1.4142135);
}

TEST(Viewer, C11) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.TurnMinusOY();
  EXPECT_FLOAT_EQ(p[0], 0);
  EXPECT_FLOAT_EQ(p[1], 0);
  EXPECT_FLOAT_EQ(p[2], 0);
  EXPECT_FLOAT_EQ(p[3], -0.51763809);
  EXPECT_FLOAT_EQ(p[4], 0);
  EXPECT_FLOAT_EQ(p[5], 1.9318516);
  EXPECT_FLOAT_EQ(p[6], 0);
  EXPECT_FLOAT_EQ(p[7], 2);
  EXPECT_FLOAT_EQ(p[8], 0);
  EXPECT_FLOAT_EQ(p[9], -0.51763809);
  EXPECT_FLOAT_EQ(p[10], 2);
  EXPECT_FLOAT_EQ(p[11], 1.9318516);
  EXPECT_FLOAT_EQ(p[12], 1.9318516);
  EXPECT_FLOAT_EQ(p[13], 0);
  EXPECT_FLOAT_EQ(p[14], 0.51763809);
  EXPECT_FLOAT_EQ(p[15], 1.4142135);
  EXPECT_FLOAT_EQ(p[16], 0);
  EXPECT_FLOAT_EQ(p[17], 2.4494896);
  EXPECT_FLOAT_EQ(p[18], 1.9318516);
  EXPECT_FLOAT_EQ(p[19], 2);
  EXPECT_FLOAT_EQ(p[20], 0.51763809);
  EXPECT_FLOAT_EQ(p[21], 1.4142135);
  EXPECT_FLOAT_EQ(p[22], 2);
  EXPECT_FLOAT_EQ(p[23], 2.4494896);
}

TEST(Viewer, C12) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.TurnMinusOZ();
  EXPECT_FLOAT_EQ(p[0], 0);
  EXPECT_FLOAT_EQ(p[1], 0);
  EXPECT_FLOAT_EQ(p[2], 0);
  EXPECT_FLOAT_EQ(p[3], 0);
  EXPECT_FLOAT_EQ(p[4], 0);
  EXPECT_FLOAT_EQ(p[5], 2);
  EXPECT_FLOAT_EQ(p[6], -0.51763809);
  EXPECT_FLOAT_EQ(p[7], 1.9318516);
  EXPECT_FLOAT_EQ(p[8], 0);
  EXPECT_FLOAT_EQ(p[9], -0.51763809);
  EXPECT_FLOAT_EQ(p[10], 1.9318516);
  EXPECT_FLOAT_EQ(p[11], 2);
  EXPECT_FLOAT_EQ(p[12], 1.9318516);
  EXPECT_FLOAT_EQ(p[13], 0.51763809);
  EXPECT_FLOAT_EQ(p[14], 0);
  EXPECT_FLOAT_EQ(p[15], 1.9318516);
  EXPECT_FLOAT_EQ(p[16], 0.51763809);
  EXPECT_FLOAT_EQ(p[17], 2);
  EXPECT_FLOAT_EQ(p[18], 1.4142135);
  EXPECT_FLOAT_EQ(p[19], 2.4494896);
  EXPECT_FLOAT_EQ(p[20], 0);
  EXPECT_FLOAT_EQ(p[21], 1.4142135);
  EXPECT_FLOAT_EQ(p[22], 2.4494896);
  EXPECT_FLOAT_EQ(p[23], 2);
}

TEST(Viewer, C13) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.ZoomIn();
  EXPECT_FLOAT_EQ(p[0], 0);
  EXPECT_FLOAT_EQ(p[1], 0);
  EXPECT_FLOAT_EQ(p[2], 0);
  EXPECT_FLOAT_EQ(p[3], 0);
  EXPECT_FLOAT_EQ(p[4], 0);
  EXPECT_FLOAT_EQ(p[5], 2.2);
  EXPECT_FLOAT_EQ(p[6], 0);
  EXPECT_FLOAT_EQ(p[7], 2.2);
  EXPECT_FLOAT_EQ(p[8], 0);
  EXPECT_FLOAT_EQ(p[9], 0);
  EXPECT_FLOAT_EQ(p[10], 2.2);
  EXPECT_FLOAT_EQ(p[11], 2.2);
  EXPECT_FLOAT_EQ(p[12], 2.2);
  EXPECT_FLOAT_EQ(p[13], 0);
  EXPECT_FLOAT_EQ(p[14], 0);
  EXPECT_FLOAT_EQ(p[15], 2.2);
  EXPECT_FLOAT_EQ(p[16], 0);
  EXPECT_FLOAT_EQ(p[17], 2.2);
  EXPECT_FLOAT_EQ(p[18], 2.2);
  EXPECT_FLOAT_EQ(p[19], 2.2);
  EXPECT_FLOAT_EQ(p[20], 0);
  EXPECT_FLOAT_EQ(p[21], 2.2);
  EXPECT_FLOAT_EQ(p[22], 2.2);
  EXPECT_FLOAT_EQ(p[23], 2.2);
}

TEST(Viewer, C14) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.ZoomOut();
  EXPECT_FLOAT_EQ(p[0], 0);
  EXPECT_FLOAT_EQ(p[1], 0);
  EXPECT_FLOAT_EQ(p[2], 0);
  EXPECT_FLOAT_EQ(p[3], 0);
  EXPECT_FLOAT_EQ(p[4], 0);
  EXPECT_FLOAT_EQ(p[5], 2 * 0.9);
  EXPECT_FLOAT_EQ(p[6], 0);
  EXPECT_FLOAT_EQ(p[7], 2 * 0.9);
  EXPECT_FLOAT_EQ(p[8], 0);
  EXPECT_FLOAT_EQ(p[9], 0);
  EXPECT_FLOAT_EQ(p[10], 2 * 0.9);
  EXPECT_FLOAT_EQ(p[11], 2 * 0.9);
  EXPECT_FLOAT_EQ(p[12], 2 * 0.9);
  EXPECT_FLOAT_EQ(p[13], 0);
  EXPECT_FLOAT_EQ(p[14], 0);
  EXPECT_FLOAT_EQ(p[15], 2 * 0.9);
  EXPECT_FLOAT_EQ(p[16], 0);
  EXPECT_FLOAT_EQ(p[17], 2 * 0.9);
  EXPECT_FLOAT_EQ(p[18], 2 * 0.9);
  EXPECT_FLOAT_EQ(p[19], 2 * 0.9);
  EXPECT_FLOAT_EQ(p[20], 0);
  EXPECT_FLOAT_EQ(p[21], 2 * 0.9);
  EXPECT_FLOAT_EQ(p[22], 2 * 0.9);
  EXPECT_FLOAT_EQ(p[23], 2 * 0.9);
}

TEST(Viewer, C15) {
  C.LoadModel("cube.objs");
  float *p = C.GetPoint();
  C.Normalize();
  EXPECT_FLOAT_EQ(p[0], -0.69999999);
  EXPECT_FLOAT_EQ(p[1], -0.69999999);
  EXPECT_FLOAT_EQ(p[2], -0.69999999);
  EXPECT_FLOAT_EQ(p[3], -0.69999999);
  EXPECT_FLOAT_EQ(p[4], -0.69999999);
  EXPECT_FLOAT_EQ(p[5], 0.69999999);
  EXPECT_FLOAT_EQ(p[6], -0.69999999);
  EXPECT_FLOAT_EQ(p[7], 0.69999999);
  EXPECT_FLOAT_EQ(p[8], -0.69999999);
  EXPECT_FLOAT_EQ(p[9], -0.69999999);
  EXPECT_FLOAT_EQ(p[10], 0.69999999);
  EXPECT_FLOAT_EQ(p[11], 0.69999999);
  EXPECT_FLOAT_EQ(p[12], 0.69999999);
  EXPECT_FLOAT_EQ(p[13], -0.69999999);
  EXPECT_FLOAT_EQ(p[14], -0.69999999);
  EXPECT_FLOAT_EQ(p[15], 0.69999999);
  EXPECT_FLOAT_EQ(p[16], -0.69999999);
  EXPECT_FLOAT_EQ(p[17], 0.69999999);
  EXPECT_FLOAT_EQ(p[18], 0.69999999);
  EXPECT_FLOAT_EQ(p[19], 0.69999999);
  EXPECT_FLOAT_EQ(p[20], -0.69999999);
  EXPECT_FLOAT_EQ(p[21], 0.69999999);
  EXPECT_FLOAT_EQ(p[22], 0.69999999);
  EXPECT_FLOAT_EQ(p[23], 0.69999999);
}

TEST(Viewer, C16) {
  C.LoadModel("cube.objs");
  EXPECT_EQ(C.get_dots_count(), 8);
  EXPECT_EQ(C.get_facets_count(), 40);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
