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

#ifndef __UNDO_MOVE_TIMELINE_SELECTIONS_ACTION_H__
#define __UNDO_MOVE_TIMELINE_SELECTIONS_ACTION_H__

#include "actions/undoable_action.h"

typedef struct TimelineSelections
  TimelineSelections;

typedef struct MoveTimelineSelectionsAction
{
  UndoableAction              parent_instance;

  /** Ticks moved. */
  long        ticks;

  /** Tracks moved. */
  int         delta;

  /** Lanes moved. */
  int         delta_lanes;

  int         first_call;

  /** Timeline selections clone. */
  TimelineSelections * ts;
} MoveTimelineSelectionsAction;

/**
 * Creates a new MoveTimelineSelectionsAction.
 */
UndoableAction *
move_timeline_selections_action_new (
  TimelineSelections * ts,
  const long           ticks,
  const int            delta,
  const int            delta_lanes);

int
move_timeline_selections_action_do (
	MoveTimelineSelectionsAction * self);

int
move_timeline_selections_action_undo (
	MoveTimelineSelectionsAction * self);

char *
move_timeline_selections_action_stringize (
	MoveTimelineSelectionsAction * self);

void
move_timeline_selections_action_free (
	MoveTimelineSelectionsAction * self);

#endif
