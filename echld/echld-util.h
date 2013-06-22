/* echld-util.h
 *  utility for echld
 *
 * $Id$
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * Copyright (c) 2013 by Luis Ontanon <luis@ontanon.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

typedef void (*echld_ping_cb_t)(long usec, void* data);
echld_state_t echld_ping(int child_id, echld_ping_cb_t pcb, void* cb_data);

typedef void (*echld_list_interface_cb_t)(char* intf_name, char* params, void* cb_data);
echld_state_t echld_list_interfaces(int child_id, echld_list_interface_cb_t, void* cb_data);

typedef void (*echild_get_packet_summary_cb_t)(char* summary, void* data);
echld_state_t echld_open_file(int child_id, const char* filename,echild_get_packet_summary_cb_t,void*);


echld_state_t echld_open_interface(int child_id, const char* intf_name, const char* params);
echld_state_t echld_start_capture(int child_id, echild_get_packet_summary_cb_t);
echld_state_t echld_stop_capture(int child_id);

typedef void (*echild_get_packets_cb)(char* tree_text,void* data);
typedef void (*echild_get_buffer_cb)(char* buffer_text, void* data);
echld_state_t echld_get_packets_range(int child_id, const char* range, echild_get_packets_cb, echild_get_buffer_cb, void* data);

