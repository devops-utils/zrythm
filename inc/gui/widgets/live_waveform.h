/*
 * Copyright (C) 2019 Alexandros Theodotou <alex at zrythm dot org>
 *
 * This file is part of Zrythm
 *
 * Zrythm is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Zrythm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Zrythm.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __GUI_WIDGETS_LIVE_WAVEFORM_H__
#define __GUI_WIDGETS_LIVE_WAVEFORM_H__

/**
 * \file
 *
 * Live waveform display like LMMS.
 */

#include <gtk/gtk.h>

#define LIVE_WAVEFORM_WIDGET_TYPE \
  (live_waveform_widget_get_type ())
G_DECLARE_FINAL_TYPE (
  LiveWaveformWidget,
  live_waveform_widget,
  Z, LIVE_WAVEFORM_WIDGET,
  GtkDrawingArea)

/**
 * @addtogroup widgets
 *
 * @{
 */

typedef struct _LiveWaveformWidget
{
  GtkDrawingArea parent_instance;

  /** Draw border or not. */
  int            draw_border;

} LiveWaveformWidget;

/**
 * Creates a LiveWaveformWidget for the
 * AudioEngine.
 */
void
live_waveform_widget_setup_engine (
  LiveWaveformWidget * self);

/**
 * @}
 */

#endif