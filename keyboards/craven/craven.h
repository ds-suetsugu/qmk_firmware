/* Copyright 2017 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CRAVEN_H
#define CRAVEN_H

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
  k00,   k01,  k02,  k03,  k04,  k05,  k06,  k07,  k08,  k09,  k010, k011, k012, k013,  \
  k014,   k015, k016, k017, k018, k019, k020, k021, k022, k023, k024, k025, k026, k027, \
  k028,  k029, k030, k031, k032, k033, k034, k035, k036, k037, k038, k039, k040, k041,  \
  k042,  k043, k044, k045, k046, k047, k048, k049, k050, k051, k052, k053, k054, k055 \
) \
{ \
  {k00,  k01,  k02,  k03,  k04,  k05,  k06,  k07,  k08,  k09,  k010, k011, k012, k013}, \
  {k014, k015, k016, k017, k018, k019, k020, k021, k022, k023, k024, k025, k026, k027}, \
  {k028, k029, k030, k031, k032, k033, k034, k035, k036, k037, k038, k039, k040, k041}, \
  {k042, k043, k044, k045, k046, k047, k048, k049, k050, k051, k052, k053, k054, k055} \
}

#endif
