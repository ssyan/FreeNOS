/*
 * Copyright (C) 2009 Niek Linnenbank
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include <Log.h>
#include "ProcessScheduler.h"

ProcessScheduler::ProcessScheduler()
{
    m_index = 0;
}

Process * ProcessScheduler::select(Vector<Process *> *procs, Process *idle)
{
    Size size = procs->size();

    for (Size i = 0; i < size; i++)
    {
        m_index = (m_index + 1) % size;

        Process *p = procs->at(m_index);
        if (p && p != idle && p->getState() == Process::Ready)
        {
            return p;
        }
    }
    return (Process *) NULL;
}
