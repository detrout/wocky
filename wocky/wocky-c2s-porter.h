/*
 * wocky-c2s-porter.h - Header for WockyC2SPorter
 * Copyright (C) 2009-2011 Collabora Ltd.
 * @author Guillaume Desmottes <guillaume.desmottes@collabora.co.uk>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __WOCKY_C2S_PORTER_H__
#define __WOCKY_C2S_PORTER_H__

#include <glib-object.h>

#include "wocky-xmpp-connection.h"
#include "wocky-stanza.h"
#include "wocky-porter.h"

G_BEGIN_DECLS

/**
 * WockyC2SPorter:
 *
 * An object providing a convenient wrapper around a #WockyXmppConnection to
 * send and receive stanzas.
 */
typedef struct _WockyC2SPorter WockyC2SPorter;
typedef struct _WockyC2SPorterClass WockyC2SPorterClass;
typedef struct _WockyC2SPorterPrivate WockyC2SPorterPrivate;

struct _WockyC2SPorterClass {
    GObjectClass parent_class;
};

struct _WockyC2SPorter {
    GObject parent;
    WockyC2SPorterPrivate *priv;
};

GType wocky_c2s_porter_get_type (void);

/* TYPE MACROS */
#define WOCKY_TYPE_C2S_PORTER \
  (wocky_c2s_porter_get_type ())
#define WOCKY_C2S_PORTER(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), WOCKY_TYPE_C2S_PORTER, \
   WockyC2SPorter))
#define WOCKY_C2S_PORTER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass), WOCKY_TYPE_C2S_PORTER, \
   WockyC2SPorterClass))
#define WOCKY_IS_C2S_PORTER(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj), WOCKY_TYPE_C2S_PORTER))
#define WOCKY_IS_C2S_PORTER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass), WOCKY_TYPE_C2S_PORTER))
#define WOCKY_C2S_PORTER_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), WOCKY_TYPE_C2S_PORTER, \
   WockyC2SPorterClass))

WockyPorter * wocky_c2s_porter_new (WockyXmppConnection *connection,
    const gchar *full_jid);

G_END_DECLS

#endif /* #ifndef __WOCKY_C2S_PORTER_H__*/
