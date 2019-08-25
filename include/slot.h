#pragma once

typedef enum {
	ST_UNKNOWN = 0,
	ST_ACTIVE = 1,
	ST_INACTIVE = 2,
	ST_BOOTED = 4 | ST_ACTIVE,
} SlotState;

typedef struct {
	gchar *bundle_compatible;
	gchar *bundle_version;
	gchar *bundle_description;
	gchar *bundle_build;
	gchar *status;
	RaucChecksum checksum;
	gchar *installed_timestamp;
	guint32 installed_count;
	gchar *activated_timestamp;
	guint32 activated_count;
} RaucSlotStatus;

typedef struct _RaucSlot {
	/** name of the slot. A glib intern string. */
	const gchar *name;
	/** user-friendly description of the slot. A glib intern string. */
	gchar *description;
	/** slot class the slot belongs to. A glib intern string. */
	const gchar *sclass;
	/** device this slot uses */
	gchar *device;
	/** the slots partition type */
	gchar *type;
	/** the name this slot is known to the bootloader */
	gchar *bootname;
	/** flag indicating if the slot is updatable */
	gboolean readonly;
	/** flag indicating if slot skipping optimization should be used */
	gboolean install_same;
	/** extra mount options for this slot */
	gchar *extra_mount_opts;
	/** flag indicating to resize after writing (only for ext4) */
	gboolean resize;
	/** start address of first boot-partition (only for boot-mbr-switch) */
	guint64 region_start;
	/** size of both partitions(only for boot-mbr-switch) */
	guint64 region_size;

	/** current state of the slot (runtime) */
	SlotState state;
	gboolean boot_good;
	struct _RaucSlot *parent;
	gchar *mount_point;
	gchar *ext_mount_point;
	RaucSlotStatus *status;
} RaucSlot;

