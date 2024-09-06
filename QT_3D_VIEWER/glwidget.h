#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QColor>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLExtraFunctions>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QSettings>
#include <QTimer>
#include <QWheelEvent>

#include "../Back/Controller.hpp"

enum {
  Normal,
  Flustrum,
};

enum {
  Stipple,
  Solid,
};

enum {
  Void,
  Circle,
  Square,
};

#define ORGNAME ""
#define APPNAME "3dviewer"

/*!\brief OpenGL class*/
class glwidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT
 private:
  QSettings *settings;

  int viewMode;  //

  int facetsMode;       //
  int facetsThickness;  //

  int dotsViewMode;  //
  float dotsSize;    //

  /*!\brief Method for loading Points*/
  void loadPoints();
  /*!\brief Method for loading Facets*/
  void loadFacets();

 public:
  glwidget(QWidget *parent = nullptr);
  ~glwidget();

  ns::ControllerViewer _contr;

  QColor BackgroundColor = QColorConstants::Black;  //
  QColor DotsColor = QColorConstants::Green;        //
  QColor FacetColor = QColorConstants::Blue;        //

  void initializeGL() override;
  void paintGL() override;

  /*! \brief Method that return facets thickness */
  double getFacetsThickness();
  /*! \brief Method that return size of points */
  double getPointsSize();

  /*! \brief Method changing the display mode */
  void changeViewMode(int viewMode);
  /*! \brief Method changing the facets mode */
  void changeFacetMode(int lineMode);
  /*! \brief Method changing facet color */
  void setFacetColor(QColor color);
  /*! \brief Method changing facet thickness */
  void setFacetThickness(double thickness);

  /*! \brief Method changing dots view */
  void setDotsViewMode(int mode);
  /*! \brief Method changing dots size */
  void setDotsSize(double size);
  /*! \brief Method changing dots color */
  void setDotsColor(QColor color);

  /*! \brief Method changing background color */
  void setBGColor(QColor color);

  void saveSettings();
  void loadSettings();
  void resetSettings();

  /*! \brief Method that free memory from _p and _f */
  void makeClean();

 signals:
};

#endif  // GLWIDGET_H
