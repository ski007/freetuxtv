/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8-*- */
/*
 * freetuxtv
 * Copyright (C) FreetuxTV Team's 2008
 * Project homepage : http://code.google.com/p/freetuxtv/
 * 
 * freetuxtv is free software.
 * 
 */

#ifndef FREETUXTV_DB_SYNC_H
#define FREETUXTV_DB_SYNC_H

#include <glib.h>
#include <sqlite3.h>

#include "freetuxtv-app.h"
#include "freetuxtv-i18n.h"
#include "freetuxtv-channel-infos.h"
#include "freetuxtv-channels-group-infos.h"

typedef struct _DBSync DBSync;
struct _DBSync
{
	struct sqlite3 *db_link;
};

#define FREETUXTV_DBSYNC_ERROR freetuxtv_dbsync_error_quark ()
typedef enum
{
	FREETUXTV_DBSYNC_ERROR_OPEN,
	FREETUXTV_DBSYNC_ERROR_EXEC_QUERY
} FreetuxTVDBSyncError;

GQuark
freetuxtv_dbsync_error_quark ();

void
dbsync_open_db(DBSync *dbsync, GError** error);

void
dbsync_close_db (DBSync *dbsync);

void
dbsync_select_channels_groups (DBSync *dbsync,
			       FreetuxTVApp *app,
			       int (*callback)(FreetuxTVApp *app, FreetuxTVChannelsGroupInfos* channels_group_infos,
					       DBSync *dbsync, gpointer user_data, GError** error),
			       gpointer user_data, GError** error);

void
dbsync_select_channels_of_channels_group (DBSync *dbsync,
					  FreetuxTVChannelsGroupInfos* channels_group_infos,
					  FreetuxTVApp *app,
					  int (*callback)(FreetuxTVApp *app, 
							  FreetuxTVChannelInfos* channel_infos,
							  DBSync *dbsync, gpointer user_data, GError** error),
					  gpointer user_data, GError** error);

void
dbsync_add_channel (DBSync *dbsync,
		    FreetuxTVChannelInfos* channel_infos,
		    GError** error);

void
dbsync_add_channels_group (DBSync *dbsync,
			   FreetuxTVChannelsGroupInfos* channels_group_infos,
			   GError** error);

void
dbsync_update_channels_group (DBSync *dbsync,
			      FreetuxTVChannelsGroupInfos* channels_group_infos,
			      GError** error);

void
dbsync_delete_channels_group (DBSync *dbsync,
			      FreetuxTVChannelsGroupInfos* channels_group_infos,
			      GError** error);

void
dbsync_delete_channels_of_channels_group (DBSync *dbsync,
					  FreetuxTVChannelsGroupInfos* channels_group_infos,
					  GError** error);

#endif /* FREETUXTV_DB_SYNC_H */