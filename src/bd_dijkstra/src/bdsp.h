 /*
 * Bi Directional Shortest path algorithm for PostgreSQL
 *
 * Copyright (c) 2005 Sylvain Pasche
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */
#ifndef _BDSP_H
#define _BDSP_H


#include "postgres.h"

typedef struct edge
{
    int id;
    int source;
    int target;
    float8 cost;
    float8 reverse_cost;
} edge_t;


typedef struct 
{
    int vertex_id;
    int edge_id;
    float8 cost;
} path_element_t;

#ifdef __cplusplus
extern "C"
#endif

int bidirsp_wrapper( edge_t *edges, 
			unsigned int edge_count,
			int maxNode,
			int start_vertex, 
			int end_vertex,
		    bool directed, 
		    bool has_reverse_cost,
            path_element_t **path, 
            int *path_count, 
            char **err_msg
            );

#endif
