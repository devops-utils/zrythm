/*
 * Copyright (C) 2019 Alexandros Theodotou <alex at zrythm dot org>
 *
 * This file is part of Zrythm
 *
 * Zrythm is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Zrythm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with Zrythm.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * \file
 *
 * Automation editor backend.
 */

#ifndef __GUI_BACKEND_AUTOMATION_EDITOR_H__
#define __GUI_BACKEND_AUTOMATION_EDITOR_H__

#include <cyaml/cyaml.h>

/**
 * @addtogroup gui_backend
 *
 * @{
 */

#define AUTOMATION_EDITOR \
  (&CLIP_EDITOR->automation_editor)

typedef struct ZRegion ZRegion;

/**
 * Backend for the automation editor.
 */
typedef struct AutomationEditor
{
  int    fixme;
} AutomationEditor;

static const cyaml_schema_field_t
automation_editor_fields_schema[] =
{
  CYAML_FIELD_INT (
    "fixme", CYAML_FLAG_DEFAULT,
    AutomationEditor, fixme),

  CYAML_FIELD_END
};

static const cyaml_schema_value_t
automation_editor_schema =
{
  CYAML_VALUE_MAPPING (
    CYAML_FLAG_POINTER,
    AutomationEditor,
    automation_editor_fields_schema),
};

/**
 * Inits the AutomationEditor after a Project has been
 * loaded.
 */
void
automation_editor_init_loaded (
  AutomationEditor * self);

/**
 * Initializes the AutomationEditor.
 */
void
automation_editor_init (
  AutomationEditor * self);

/**
 * @}
 */

#endif
