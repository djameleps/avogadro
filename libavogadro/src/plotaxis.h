/**********************************************************************
  PlotAxis -- Part of the Avogadro 2D plotting interface

  Copyright (C) 2003 Jason Harris <kstars@30doradus.org> (KDE)
  Copyright (C) 2008 David Lonie <loniedavid@gmail.com> (Avogadro)

  This file is part of the Avogadro molecular editor project.
  For more information, see <http://avogadro.cc/>

  This file is based on KPlotWidget from the KDE library. For more
  information see <http://www.kde.org/>

  Avogadro is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  Avogadro is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
  02110-1301, USA.
 **********************************************************************/

#ifndef PLOTAXIS_H
#define PLOTAXIS_H

#include <QtCore/QString>
#include <QtCore/QList>

#include <avogadro/global.h>

namespace Avogadro {

  /**
   * @class PlotAxis plotaxis.h <avogadro/plotaxis.h>
   * @short Axis for PlotWidget
   *
   * Contains all data for drawing an axis including format specification axis labels.
   *
   * @author Andreas Nicolai
   * @version 1.0
   */
  class A_EXPORT PlotAxis {
  public:

    /**
     * Constructor, constructs an axis with the label @p label.
     */
    explicit PlotAxis( const QString& label = QString() );

    /**
     * Destructor.
     */
    ~PlotAxis();

    /**
     * @return whether the axis is visible or not
     */
    bool isVisible() const;

    /**
     * Sets the "visible" property of the axis.
     * @param visible if true, this axis will be drawn on the PlotWidget
     */
    void setVisible( bool visible );

    /**
     * @return whether tick labels will be drawn for this axis
     */
    bool areTickLabelsShown() const;

    /**
     * Determine whether tick labels will be drawn for this axis.
     * @param b if true, tick labels will be drawn.
     */
    void setTickLabelsShown( bool b );

    /**
     * Sets the axis label.
     * Set the label to an empty string to omit the axis label.
     * @param label a string describing the data plotted on the axis.
     */
    void setLabel( const QString& label );

    /**
     * @return the label string for this axis
     */
    QString label() const;

    /**
     * @return the ticklabel string for the given value, rendered according
     * to the current format specification.
     * @param the value to be rendered as a tick label.
     * @sa setTickLabelFormat()
     */
    QString tickLabel( double value ) const;

    /**
     * Set the display format for converting the double value of the
     * tick's position to the QString for the tick label.
     *
     * Normally, the format character is one of 'e', 'E', 'f', 'g', or 'G'
     * (see the documentation for QString::arg(double) for details).
     *
     * In addition, it is possible to set the format character to 't';
     * in this case the tickmark value is interpreted as a time in hours,
     * and the ticklabel string will be in "hh:mm" clock format.
     * Note that when the format character is 't', the fieldWidth and prec
     * values are ignored.
     *
     * @param format the format specification character
     * @param fieldWidth the number of characters in the output string.
     * If set to 0, the string will be as wide as it needs to be to fully
     * render the value.
     * @param precision the number of characters following the decimal point.
     */
    void setTickLabelFormat( char format = 'g', int fieldWidth = 0, int precision = -1 );

    /**
     * @return the field width of the tick labels
     */
    int tickLabelWidth() const;

    /**
     * @return the number format of the tick labels
     */
    char tickLabelFormat() const;

    /**
     * @return the number precision of the tick labels
     */
    int tickLabelPrecision() const;

    /**
     * Determine the positions of major and minor tickmarks for this axis.
     * @note this function is called by PlotWidget whenever the plot's
     * limits are modified.
     * @param x0 the minimum data coordinate of the axis.
     * @param length the range covered by the axis, in data units.
     * @sa majorTickMarks()
     * @sa minorTickMarks()
     */
    void setTickMarks( double x0, double length );

    /**
     * @return the list of coordinates of the major tickmarks for this axis
     * @note the positions of tickmarks are automatically computed by setTickMarks().
     * @sa setTickMarks()
     * @sa minorTickMarks()
     */
    QList< double > majorTickMarks() const;

    /**
     * @return the list with the minor tickmarks
     * @note the positions of tickmarks are automatically computed by setTickMarks().
     * @sa setTickMarks()
     * @sa majorTickMarks()
     */
    QList< double > minorTickMarks() const;

  private:
    class Private;
    Private * const d;

    Q_DISABLE_COPY( PlotAxis )
  };

}

#endif // PLOTAXIS_H
