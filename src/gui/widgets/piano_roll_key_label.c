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

#include "gui/backend/clip_editor.h"
#include "gui/backend/piano_roll.h"
#include "gui/widgets/editable_label.h"
#include "gui/widgets/piano_roll_key_label.h"
#include "project.h"

#include <gtk/gtk.h>

G_DEFINE_TYPE (PianoRollKeyLabelWidget,
               piano_roll_key_label_widget,
               GTK_TYPE_STACK)

void
piano_roll_key_label_widget_refresh (
  PianoRollKeyLabelWidget * self)
{
  if (PIANO_ROLL->drum_mode)
    {
      gtk_stack_set_visible_child (
        GTK_STACK (self),
        GTK_WIDGET (self->editable_lbl));
      gtk_widget_set_visible (
        GTK_WIDGET (self->lbl), 0);
      gtk_widget_set_visible (
        GTK_WIDGET (self->editable_lbl), 1);
    }
  else
    {
      gtk_stack_set_visible_child (
        GTK_STACK (self),
        GTK_WIDGET (self->lbl));
      gtk_widget_set_visible (
        GTK_WIDGET (self->lbl), 1);
      gtk_widget_set_visible (
        GTK_WIDGET (self->editable_lbl), 0);
    }
}

/**
 * Creates a PianoRollKeyLabelWidget for the given
 * MIDI note descriptor.
 */
PianoRollKeyLabelWidget *
piano_roll_key_label_widget_new (
  MidiNoteDescriptor * descr)
{
  PianoRollKeyLabelWidget * self =
    g_object_new (PIANO_ROLL_KEY_LABEL_WIDGET_TYPE,
                  NULL);

  /* create and add the labels to the stack */
  self->descr = descr;
  self->editable_lbl =
    editable_label_widget_new (
      descr,
      midi_note_descriptor_get_custom_name,
      midi_note_descriptor_set_custom_name,
      -1);
  gtk_label_set_xalign (
    self->editable_lbl->label, 0.0);
  gtk_widget_set_margin_left (
    GTK_WIDGET (self->editable_lbl), 4);
  self->lbl =
    GTK_LABEL (gtk_label_new (descr->note_name));
  gtk_widget_set_halign (
    GTK_WIDGET (self->lbl), GTK_ALIGN_START);
  gtk_label_set_xalign (self->lbl, 0.0);
  gtk_widget_set_margin_left (
    GTK_WIDGET (self->lbl), 4);
  gtk_widget_set_visible (
    GTK_WIDGET (self->lbl), 1);
  gtk_stack_add_named (
    GTK_STACK (self),
    GTK_WIDGET (self->editable_lbl),
    "editable");
  gtk_stack_add_named (
    GTK_STACK (self),
    GTK_WIDGET (self->lbl),
    "lbl");

  gtk_widget_set_visible (
    GTK_WIDGET (self), 1);

  return self;
}

static void
piano_roll_key_label_widget_class_init (
  PianoRollKeyLabelWidgetClass * _klass)
{
  GtkWidgetClass * klass = GTK_WIDGET_CLASS (_klass);
  gtk_widget_class_set_css_name (
    klass, "piano-roll-label");
}

static void
piano_roll_key_label_widget_init (
  PianoRollKeyLabelWidget * self)
{
}