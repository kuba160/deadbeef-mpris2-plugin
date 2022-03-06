#ifndef MPRISSERVER_H_
#define MPRISSERVER_H_

#include <gio/gio.h>
#ifdef HAVE_GIOUNIX
#include <gio/gdesktopappinfo.h>
#endif

#define DDB_API_LEVEL 9
#define DDB_WARN_DEPRECATED 1
#include <deadbeef/deadbeef.h>
#include "artwork.h"

#define SETTING_PREVIOUS_ACTION "mpris2.previous_action"
#define PREVIOUS_ACTION_PREVIOUS 0
#define PREVIOUS_ACTION_PREV_OR_RESTART 1

struct ArtworkData {
	uintptr_t mutex;
	DB_playItem_t *track;
	char *path;
	char *default_path;
};

struct MprisData {
	DB_functions_t *deadbeef;
	ddb_artwork_plugin_t *artwork;
	DB_plugin_action_t *prevOrRestart;
	GDBusNodeInfo *gdbusNodeInfo;
	int previousAction;
	struct ArtworkData artworkData;
};

void* startServer(void*);
void stopServer(void);

void emitVolumeChanged(float);
void emitSeeked(float);
void emitMetadataChanged(int, struct MprisData*);
void emitPlaybackStatusChanged(int, struct MprisData*);
void emitLoopStatusChanged(int);
void emitShuffleStatusChanged(int);
void emitCanGoChanged(struct MprisData *);

#endif
