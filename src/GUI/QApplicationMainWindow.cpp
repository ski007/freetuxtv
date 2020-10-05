/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.c
 * Copyright (C) Eric Beuque 2010 <eric.beuque@gmail.com>
 * 
 * FreetuxTV is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * FreetuxTV is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
/*
#include <gtk/gtk.h>
#include <sqlite3.h>
#include <gdk/gdkx.h>
*/
#include <QMenuBar>
#include <GUIController/QApplicationMainWindowController.h>

#include "QApplicationMainWindow.h"
/*
#include "freetuxtv-window-add-recording.h"
#include "freetuxtv-window-add-channels-group.h"
#include "freetuxtv-window-tv-channels-database.h"

#include "freetuxtv-app.h"
#include "freetuxtv-i18n.h"
#include "freetuxtv-utils.h"
#include "freetuxtv-channels-list.h"
#include "freetuxtv-channels-group-infos.h"
#include "freetuxtv-tv-channels-list.h"
#include "freetuxtv-recordings-list.h"
#include "freetuxtv-db-sync.h"
#include "freetuxtv-models.h"
 */

QApplicationMainWindow::QApplicationMainWindow(QWidget * parent) : QMainWindow(parent)
{
	QWidget *widget;

	QMenuBar *pMenuBar = createMenuBar(this);
	setMenuBar(pMenuBar);

	/*

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "windowmain_menubox");
	gtk_box_pack_start (GTK_BOX (widget), GTK_WIDGET (pMenuBar), TRUE, TRUE, 0);
	gtk_widget_show_all(pMenuBar);

	// Initialize signals for windowmain
	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "windowmain");
	g_signal_connect(G_OBJECT(widget),
					 "delete-event",
					 G_CALLBACK(on_windowmain_deleteevent),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "windowmain_buttonclearfilter");
	g_signal_connect(G_OBJECT(widget),
					 "clicked",
					 G_CALLBACK(on_windowmain_buttonclearfilter_clicked),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "windowmain_entryfilter");
	g_signal_connect(G_OBJECT(widget),
					 "changed",
					 G_CALLBACK(on_windowmain_entryfilter_changed),
					 app);
	g_signal_connect(G_OBJECT(widget),
					 "focus-in-event",
					 G_CALLBACK(on_windowmain_entryfilter_focusin),
					 app);
	g_signal_connect(G_OBJECT(widget),
					 "focus-out-event",
					 G_CALLBACK(on_windowmain_entryfilter_focusout),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "windowmain_scaletime");
	g_signal_connect(G_OBJECT(widget),
					 "change-value",
					 G_CALLBACK(on_windowmain_valuechanged),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "windowmain_buttongotocurrent");
	g_signal_connect(G_OBJECT(widget),
					 "clicked",
					 G_CALLBACK(on_windowmain_buttongotocurrent_clicked),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "windowmain_buttonprevious");
	g_signal_connect(G_OBJECT(widget),
					 "clicked",
					 G_CALLBACK(on_windowmain_buttonprevious_clicked),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "windowmain_buttonnext");
	g_signal_connect(G_OBJECT(widget),
					 "clicked",
					 G_CALLBACK(on_windowmain_buttonnext_clicked),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "windowmain_buttonplaypause");
	g_signal_connect(G_OBJECT(widget),
					 "clicked",
					 G_CALLBACK(on_windowmain_buttonplaypause_clicked),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "windowmain_buttonstop");
	g_signal_connect(G_OBJECT(widget),
					 "clicked",
					 G_CALLBACK(on_windowmain_buttonstop_clicked),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "windowmain_buttonrecord");
	g_signal_connect(G_OBJECT(widget),
					 "clicked",
					 G_CALLBACK(on_windowmain_buttonrecord_clicked),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "windowmain_volumecontrol");
	g_signal_connect(G_OBJECT(widget),
					 "value-changed",
					 G_CALLBACK(on_windowmain_volumecontrol_value_changed),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "windowmain_buttonfullscreen");
	g_signal_connect(G_OBJECT(widget),
					 "clicked",
					 G_CALLBACK(on_windowmain_buttonfullscreen_clicked),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "windowmain_buttonminimode");
	g_signal_connect(G_OBJECT(widget),
					 "clicked",
					 G_CALLBACK(on_windowmain_buttonminimode_clicked),
					 app);

	// Initialize signals for windowminimode
	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
												   "windowminimode");
	g_signal_connect(G_OBJECT(widget),
					 "delete-event",
					 G_CALLBACK(on_windowmain_deleteevent),
					 app);

	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
												   "windowminimode_buttonnormalmode");
	g_signal_connect(G_OBJECT(widget),
					 "clicked",
					 G_CALLBACK(on_windowminimode_buttonnormalmode_clicked),
					 app);

	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
												   "windowminimode_buttonstayontop");
	g_signal_connect(G_OBJECT(widget),
					 "clicked",
					 G_CALLBACK(on_windowminimode_buttonstayontop_clicked),
					 app);

	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
												   "windowminimode_volumecontrol");
	g_signal_connect(G_OBJECT(widget),
					 "value-changed",
					 G_CALLBACK(on_windowmain_volumecontrol_value_changed),
					 app);

	// Initialize signals for dialogpreferences
	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "dialogpreferences");
	gtk_dialog_add_buttons (GTK_DIALOG(widget),
							"gtk-cancel", GTK_RESPONSE_CANCEL,
							"gtk-apply", GTK_RESPONSE_APPLY, NULL);

	g_signal_connect(G_OBJECT(widget),
					 "response",
					 G_CALLBACK(on_dialogpreferences_response),
					 app);
	g_signal_connect(G_OBJECT(widget),
					 "delete-event",
					 G_CALLBACK(gtk_widget_hide_on_delete),
					 NULL);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "dialogpreferences_directoryrecordings");
	g_signal_connect(G_OBJECT(widget),
					 "selection-changed",
					 G_CALLBACK(on_dialogpreferences_directoryrecordings_changed),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "dialogpreferences_radiotranscodingno");
	g_signal_connect(G_OBJECT(widget),
					 "toggled",
					 G_CALLBACK(on_dialogpreferences_radiotranscoding_toggled),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "dialogpreferences_radiotranscodingpredefinedformats");
	g_signal_connect(G_OBJECT(widget),
					 "toggled",
					 G_CALLBACK(on_dialogpreferences_radiotranscoding_toggled),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "dialogpreferences_transcodingformats");
	g_signal_connect(G_OBJECT(widget),
					 "changed",
					 G_CALLBACK(on_dialogpreferences_transcodingformats_changed),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "dialogpreferences_radioproxyno");
	g_signal_connect(G_OBJECT(widget),
					 "toggled",
					 G_CALLBACK(on_dialogpreferences_radioproxy_toggled),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "dialogpreferences_radioproxymanual");
	g_signal_connect(G_OBJECT(widget),
					 "toggled",
					 G_CALLBACK(on_dialogpreferences_radioproxy_toggled),
					 app);

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "dialogpreferences_checkuseauth");
	g_signal_connect(G_OBJECT(widget),
					 "toggled",
					 G_CALLBACK(on_dialogpreferences_checkuseauth_toggled),
					 app);

	// Initialize signals for dialoggroupproperties
	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
												  "dialoggroupproperties");
	gtk_dialog_add_buttons (GTK_DIALOG(widget),
							"gtk-cancel", GTK_RESPONSE_CANCEL, "gtk-apply", GTK_RESPONSE_APPLY, NULL);
	g_signal_connect(G_OBJECT(widget),
					 "response",
					 G_CALLBACK(on_dialoggroupproperties_response),
					 app);
	g_signal_connect(G_OBJECT(widget),
					 "delete-event",
					 G_CALLBACK(gtk_widget_hide_on_delete),
					 NULL);

	// Initialize signals for aboutdialog
	widget =  (GtkWidget *) gtk_builder_get_object (app->gui,
													"aboutdialog");

	gtk_about_dialog_set_version (GTK_ABOUT_DIALOG(widget), VERSION);

	g_signal_connect(G_OBJECT(widget),
					 "response",
					 G_CALLBACK(on_aboutdialog_response),
					 NULL);
	g_signal_connect(G_OBJECT(widget),
					 "delete-event",
					 G_CALLBACK(gtk_widget_hide_on_delete),
					 NULL);

	windowmain_enable_accelerators(app, TRUE);
	 */
}

QApplicationMainWindow::~QApplicationMainWindow()
{
	/*
	windowmain_enable_accelerators(app, FALSE);

#if GTK_API_VERSION == 3
	g_object_unref (app->widget.pAccelGroup);
#else
	gtk_accel_group_unref (app->widget.pAccelGroup);
#endif
	app->widget.pAccelGroup = NULL;

	if(app->widget.pTrayIcon){
		g_object_unref(app->widget.pTrayIcon);
		app->widget.pTrayIcon = NULL;
	}
	 */
}

QMenuBar* QApplicationMainWindow::createMenuBar(QWidget* parent)
{
	QMenuBar *pMenuBar = NULL;

	// Initialize menu bar
	pMenuBar = new QMenuBar (this);
	QMenu *pMenu;
	//GtkWidget *pMenuItem = NULL;
	//GtkWidget *pSubmenu = NULL;

	//GSList* pRadioGroup = NULL;

	// Menu : FreetuxTV
	pMenu = pMenuBar->addMenu(tr("&FreetuxTV"));

	m_pActionPreferences = new QAction(QIcon("preferences"), tr("&Preferences"));
	pMenu->addAction(m_pActionPreferences);

	pMenu->addSeparator();

	m_pActionQuit = new QAction(QIcon("application-exit"), tr("&Quit"));
	pMenu->addAction(m_pActionQuit);

	/*
	pMenuItem = gtk_separator_menu_item_new();
	gtk_menu_shell_append (GTK_MENU_SHELL (pMenu), pMenuItem);
	pMenuItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, NULL);
	gtk_menu_shell_append (GTK_MENU_SHELL (pMenu), pMenuItem);
	g_signal_connect(G_OBJECT(pMenuItem),
					 "activate",
					 G_CALLBACK(on_windowmain_menuitemquit_activate),
					 app);
	// End Menu : FreetuxTV

	// Menu : Channels
	pMenuItem = gtk_menu_item_new_with_mnemonic (_("_Channels"));
	gtk_menu_shell_append (GTK_MENU_SHELL (pMenuBar), pMenuItem);
	pMenu = gtk_menu_new ();
	gtk_menu_item_set_submenu (GTK_MENU_ITEM (pMenuItem), pMenu);
	pMenuItem = gtk_menu_item_new_with_mnemonic (_("_Add a group"));
	gtk_widget_set_tooltip_text (GTK_WIDGET(pMenuItem),
								 _("Add/create a channels group from different sources"));
	gtk_menu_shell_append (GTK_MENU_SHELL (pMenu), pMenuItem);
	g_signal_connect(G_OBJECT(pMenuItem),
					 "activate",
					 G_CALLBACK(on_windowmain_menuitemgroupsadd_activate),
					 app);
	pMenuItem = gtk_menu_item_new_with_mnemonic (_("_Synchronize TV channels database"));
	gtk_widget_set_tooltip_text (GTK_WIDGET(pMenuItem),
								 _("Synchronize the TV channels list in the local database from the XML database"));
	gtk_menu_shell_append (GTK_MENU_SHELL (pMenu), pMenuItem);
	g_signal_connect(G_OBJECT(pMenuItem),
					 "activate",
					 G_CALLBACK(on_windowmain_menuitemupdatetvchannels_activate),
					 app);
	// End Menu : Channels

	// Menu : Video
	pMenuItem = gtk_menu_item_new_with_mnemonic (_("_Video"));
	gtk_menu_shell_append (GTK_MENU_SHELL (pMenuBar), pMenuItem);
	pMenu = gtk_menu_new ();
	gtk_menu_item_set_submenu (GTK_MENU_ITEM (pMenuItem), pMenu);
	// SubMenu : Deinterlace
	pMenuItem = gtk_menu_item_new_with_mnemonic (_("_Deinterlace"));
	gtk_menu_shell_append (GTK_MENU_SHELL (pMenu), pMenuItem);
	pSubmenu = gtk_menu_new ();
	gtk_menu_item_set_submenu (GTK_MENU_ITEM (pMenuItem), pSubmenu);

	pMenuItem = gtk_radio_menu_item_new_with_label (pRadioGroup, _("Disable"));
	g_signal_connect(G_OBJECT(pMenuItem),
					 "activate",
					 G_CALLBACK(on_windowmain_menuitemdeinterlacedisable_activate),
					 app);
	pRadioGroup = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM(pMenuItem));
	gtk_menu_shell_append (GTK_MENU_SHELL (pSubmenu), pMenuItem);
	app->widget.pMenuDeinterlaceDisable = pMenuItem;

	pMenuItem = gtk_separator_menu_item_new();
	gtk_menu_shell_append (GTK_MENU_SHELL (pSubmenu), pMenuItem);

	pMenuItem = gtk_radio_menu_item_new_with_label (pRadioGroup, _("Blend"));
	g_signal_connect(G_OBJECT(pMenuItem),
					 "activate",
					 G_CALLBACK(on_windowmain_menuitemdeinterlaceblend_activate),
					 app);
	pRadioGroup = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM(pMenuItem));
	gtk_menu_shell_append (GTK_MENU_SHELL (pSubmenu), pMenuItem);
	app->widget.pMenuDeinterlaceBlend = pMenuItem;

	pMenuItem = gtk_radio_menu_item_new_with_label (pRadioGroup, _("Bob"));
	g_signal_connect(G_OBJECT(pMenuItem),
					 "activate",
					 G_CALLBACK(on_windowmain_menuitemdeinterlacebob_activate),
					 app);
	pRadioGroup = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM(pMenuItem));
	gtk_menu_shell_append (GTK_MENU_SHELL (pSubmenu), pMenuItem);
	app->widget.pMenuDeinterlaceBob = pMenuItem;

	pMenuItem = gtk_radio_menu_item_new_with_label (pRadioGroup, _("Discard"));
	g_signal_connect(G_OBJECT(pMenuItem),
					 "activate",
					 G_CALLBACK(on_windowmain_menuitemdeinterlacediscard_activate),
					 app);
	pRadioGroup = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM(pMenuItem));
	gtk_menu_shell_append (GTK_MENU_SHELL (pSubmenu), pMenuItem);
	app->widget.pMenuDeinterlaceDiscard = pMenuItem;

	pMenuItem = gtk_radio_menu_item_new_with_label (pRadioGroup, _("Linear"));
	g_signal_connect(G_OBJECT(pMenuItem),
					 "activate",
					 G_CALLBACK(on_windowmain_menuitemdeinterlacelinear_activate),
					 app);
	pRadioGroup = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM(pMenuItem));
	gtk_menu_shell_append (GTK_MENU_SHELL (pSubmenu), pMenuItem);
	app->widget.pMenuDeinterlaceLinear = pMenuItem;

	pMenuItem = gtk_radio_menu_item_new_with_label (pRadioGroup, _("Mean"));
	g_signal_connect(G_OBJECT(pMenuItem),
					 "activate",
					 G_CALLBACK(on_windowmain_menuitemdeinterlacemean_activate),
					 app);
	pRadioGroup = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM(pMenuItem));
	gtk_menu_shell_append (GTK_MENU_SHELL (pSubmenu), pMenuItem);
	app->widget.pMenuDeinterlaceMean = pMenuItem;

	pMenuItem = gtk_radio_menu_item_new_with_label (pRadioGroup, _("X"));
	g_signal_connect(G_OBJECT(pMenuItem),
					 "activate",
					 G_CALLBACK(on_windowmain_menuitemdeinterlacex_activate),
					 app);
	pRadioGroup = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM(pMenuItem));
	gtk_menu_shell_append (GTK_MENU_SHELL (pSubmenu), pMenuItem);
	app->widget.pMenuDeinterlaceX = pMenuItem;
	// End SubMenu : Deinterlace
	// End Menu : Video

	// Menu : Help
	pMenuItem = gtk_menu_item_new_with_mnemonic (_("_Help"));
	gtk_menu_shell_append (GTK_MENU_SHELL (pMenuBar), pMenuItem);
	pMenu = gtk_menu_new ();
	gtk_menu_item_set_submenu (GTK_MENU_ITEM (pMenuItem), pMenu);
	pMenuItem = gtk_image_menu_item_new_from_stock(GTK_STOCK_ABOUT, NULL);
	gtk_menu_shell_append (GTK_MENU_SHELL (pMenu), pMenuItem);
	g_signal_connect(G_OBJECT(pMenuItem),
					 "activate",
					 G_CALLBACK(on_windowmain_menuitemaboutdialog_activate),
					 app);
	// End Menu : Help
	 */

	return pMenuBar;
}

QAction* QApplicationMainWindow::getActionPreferences() const
{
	return m_pActionPreferences;
}

QAction* QApplicationMainWindow::getActionQuit() const
{
	return m_pActionQuit;
}

/*
void
windowmain_display_buttons (FreetuxTVApp *app, FreetuxTVWindowMode mode)
{
	GtkWidget *widget;
	gboolean sensitive;
	GtkWidget *image = NULL;
	// Button previous
	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
	                                               "windowmain_buttonprevious");
	switch(mode){
		case WINDOW_MODE_STOPPED :
			if(app->current.pPathChannel != NULL){
				sensitive = TRUE;		
			}else{
				sensitive = FALSE;	
			}
			break;
		case WINDOW_MODE_RECORDING :
			sensitive = FALSE;
			break;
		case WINDOW_MODE_PLAYING :
			sensitive = TRUE;
			break;
		default:
			sensitive = FALSE;
			break;
	}
	gtk_widget_set_sensitive(widget, sensitive);

	// Button next
	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
	                                               "windowmain_buttonnext");
	switch(mode){
		case WINDOW_MODE_STOPPED :
			if(app->current.pPathChannel != NULL){
				sensitive = TRUE;		
			}else{
				sensitive = FALSE;	
			}
			break;
		case WINDOW_MODE_RECORDING :
			sensitive = FALSE;
			break;
		case WINDOW_MODE_PLAYING :
			sensitive = TRUE;		
			break;
		default:
			break;
	}
	gtk_widget_set_sensitive(widget, sensitive);

	// Button play/pause
	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
	                                               "windowmain_buttonplaypause");
	switch(mode){
		case WINDOW_MODE_STOPPED :
			if(app->current.pPathChannel == NULL){
				sensitive = FALSE;
			}else{
				sensitive = TRUE;
			}
			image = gtk_image_new_from_stock (GTK_STOCK_MEDIA_PLAY, GTK_ICON_SIZE_BUTTON);
			break;
		case WINDOW_MODE_PAUSED :
			sensitive = TRUE;
			image = gtk_image_new_from_stock (GTK_STOCK_MEDIA_PLAY, GTK_ICON_SIZE_BUTTON);
			break;
		case WINDOW_MODE_PLAYING :
			sensitive = TRUE;
			image = gtk_image_new_from_stock (GTK_STOCK_MEDIA_PAUSE, GTK_ICON_SIZE_BUTTON);
			break;
		case WINDOW_MODE_RECORDING :
			sensitive = FALSE;
			image = gtk_image_new_from_stock (GTK_STOCK_MEDIA_PAUSE, GTK_ICON_SIZE_BUTTON);
			break;
	}
	gtk_widget_set_sensitive(widget, sensitive);
	if(image){
		gtk_button_set_image (GTK_BUTTON(widget), image);
	}

	// Button stop
	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
	                                               "windowmain_buttonstop");
	switch(mode){
		case WINDOW_MODE_STOPPED :
			sensitive = FALSE;
			break;
		case WINDOW_MODE_PLAYING :
		case WINDOW_MODE_RECORDING :
			sensitive = TRUE;		
			break;
		default:
			break;
	}
	gtk_widget_set_sensitive(widget, sensitive);

	// Button record
	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
	                                               "windowmain_buttonrecord");
	switch(mode){
		case WINDOW_MODE_STOPPED :
		case WINDOW_MODE_RECORDING :
			sensitive = FALSE;
			break;
		case WINDOW_MODE_PLAYING :
			sensitive = TRUE;		
			break;
		default:
			break;
	}
	gtk_widget_set_sensitive(widget, sensitive);
}

void
windowmain_show_error (FreetuxTVApp *app, gchar *msg)
{
	GtkWidget *windowmain;
	GtkWidget* dialog;

	windowmain = (GtkWidget *) gtk_builder_get_object (app->gui,
	                                                   "windowmain");

	dialog = gtk_message_dialog_new(GTK_WINDOW(windowmain),
	                                GTK_DIALOG_MODAL, 
	                                GTK_MESSAGE_ERROR,
	                                GTK_BUTTONS_OK,
	                                msg, NULL);

	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

void
windowmain_show_gerror (FreetuxTVApp *app, GError* error)
{
	g_return_if_fail(error != NULL);
	windowmain_show_error (app, error->message);
}

void
windowmain_statusbar_push (FreetuxTVApp *app, gchar *context, gchar *msg)
{
	int context_id;

	GtkWidget *statusbar;
	statusbar = (GtkWidget *) gtk_builder_get_object (app->gui,
	                                                  "windowmain_statusbar");
	context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), 
	                                          context);
	gtk_statusbar_push (GTK_STATUSBAR(statusbar), 
	                    context_id,
	                    msg);
	
	while (g_main_context_iteration(NULL, FALSE)){}
}


void
windowmain_statusbar_pop (FreetuxTVApp *app, gchar *context)
{	
	int context_id;

	GtkWidget *statusbar;
	statusbar = (GtkWidget *) gtk_builder_get_object (app->gui,
	                                                  "windowmain_statusbar");
	context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), 
	                                          context);
	gtk_statusbar_pop (GTK_STATUSBAR(statusbar),
	                   context_id);

	while (g_main_context_iteration(NULL, FALSE)){}
}

void
windowmain_update_statusbar_infos (FreetuxTVApp *app)
{
	GtkWidget *widget;
	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
	                                               "windowmain_channelscount");

	gint channels_count;
	channels_count = channels_list_get_channels_count (app);

	gchar *str;
	str = g_strdup_printf("%d", channels_count);
	gtk_label_set_text(GTK_LABEL(widget), str);
	g_free(str);	
}

void
windowmain_timebar_update (FreetuxTVApp *app, glong time_ms, glong length_ms, gfloat position)
{
	GtkWidget *widget;

	gdouble time_s = time_ms/1000.0;
	gdouble length_s = length_ms/1000.0;

	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
	                                               "windowmain_labeltime");
	gtk_label_set_text(GTK_LABEL(widget), format_time2((glong)time_s));

	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
	                                               "windowmain_labellength");
	gtk_label_set_text(GTK_LABEL(widget), format_time2((glong)length_s));	

	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
	                                               "adjustment_time");
	gtk_adjustment_set_value (GTK_ADJUSTMENT(widget), position);

	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
	                                               "windowmain_hboxtimebar");
	if(gtk_libvlc_media_player_is_seekable(app->player, NULL)){
		gtk_widget_set_sensitive(widget, TRUE);
	}else{
		gtk_widget_set_sensitive(widget, FALSE);
	}
}

void
windowmain_show_dialog_addrecordings(FreetuxTVApp *app, FreetuxTVChannelInfos* pChannelInfos, GError** error)
{
	g_return_if_fail (error != NULL);
	
	GtkWidget* pParent;
	pParent = (GtkWidget *) gtk_builder_get_object (app->gui, "windowmain");

	DBSync dbsync;
	
	// Create and show the window
	FreetuxTVWindowRecording* pWindowRecording;
	FreetuxTVRecordingInfos* pRecordingInfos = NULL;
	gint res;
	
	pWindowRecording = freetuxtv_window_recording_new (GTK_WINDOW(pParent), app, pChannelInfos);
	res = gtk_builder_dialog_run (GTK_BUILDER_DIALOG(pWindowRecording));

	if(res == GTK_RESPONSE_OK){
		pRecordingInfos = freetuxtv_window_recording_get_recording_infos (pWindowRecording);
	}

	// Destroy the window
	gtk_builder_widget_destroy(GTK_BUILDER_WIDGET(pWindowRecording));
	pWindowRecording = NULL;

	if(res == GTK_RESPONSE_OK){
		dbsync_open_db (&dbsync, error);
		if(*error == NULL){
			freetuxtv_recording_infos_set_status(pRecordingInfos, FREETUXTV_RECORDING_STATUS_WAITING);

			recordings_list_add_recording (app, &dbsync, pRecordingInfos, error);
		}
		dbsync_close_db(&dbsync);

		if(*error == NULL){
			GTimeVal now;
			g_get_current_time (&now);
			gint64 now64 = g_time_val_to_int64(&now);

			if(freetuxtv_recording_infos_has_time(pRecordingInfos, now64)){
				freetuxtv_action_start_recording (app, pRecordingInfos, error);
			}
		}
	}

	if(pRecordingInfos){
		g_object_unref (pRecordingInfos);
		pRecordingInfos = NULL;
	}
}
/*
void
windowmain_enable_accelerators(FreetuxTVApp *app, gboolean enable)
{
	g_return_if_fail(app != NULL);
	
	GtkWidget* widget;

	widget = (GtkWidget *)gtk_builder_get_object (app->gui,
	                                              "windowmain");
	if(enable){
		if(!app->current.bIsAccelGroupActivated){
			gtk_window_add_accel_group(GTK_WINDOW(widget), app->widget.pAccelGroup);
		}
	}else{
		if(app->current.bIsAccelGroupActivated){
			gtk_window_remove_accel_group(GTK_WINDOW(widget), app->widget.pAccelGroup);
		}
	}

	widget = (GtkWidget *) gtk_builder_get_object (app->gui,
	                                               "windowminimode");
	if(enable){
		if(!app->current.bIsAccelGroupActivated){
			gtk_window_add_accel_group(GTK_WINDOW(widget), app->widget.pAccelGroup);
		}
	}else{
		if(app->current.bIsAccelGroupActivated){
			gtk_window_remove_accel_group(GTK_WINDOW(widget), app->widget.pAccelGroup);
		}
	}

	app->current.bIsAccelGroupActivated = enable;
}

static void
windowmain_add_accelerator (GtkAccelGroup *p_accel_group,
                           const gchar *accelerator, const gchar *accel_path,
                           GCallback callback, gpointer user_data)
{
	guint key;
	GdkModifierType mods;
	GClosure *closure = NULL;

	gtk_accelerator_parse (accelerator, &key, &mods);
	closure = g_cclosure_new (callback, user_data, NULL);
	gtk_accel_group_connect (p_accel_group, key, mods, GTK_ACCEL_VISIBLE, closure);
	gtk_accel_map_add_entry (accel_path, key, mods);
}


*/