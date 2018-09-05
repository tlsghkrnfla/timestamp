#ifndef _LINUX_CLUSTER_H
#define _LINUX_CLUSTER_H

#include <linux/errno.h>

#ifdef __KERNEL__

#include <linux/mmdebug.h>
#include <linux/gfp.h>
#include <linux/bug.h>
#include <linux/list.h>
#include <linux/fs.h>
#include <linux/mmzone.h>
#include <linux/rbtree.h>
#include <linux/atomic.h>
#include <linux/debug_locks.h>
#include <linux/mm_types.h>
#include <linux/range.h>
#include <linux/pfn.h>
#include <linux/percpu-refcount.h>
#include <linux/bit_spinlock.h>
#include <linux/shrinker.h>
#include <linux/resource.h>
#include <linux/page_ext.h>
#include <linux/err.h>

struct CLUSTER_table;

struct CLUSTER_nvme_operations {
	int (*CLUSTER_direct_read)(struct CLUSTER_table *, struct bio *);
	int (*CLUSTER_direct_write)(struct CLUSTER_table *, struct bio *);
};

struct CLUSTER_table {
	void *nvmeq;
	struct CLUSTER_nvme_operations *CLUSTER_nvme_ops;
	struct list_head pagelist, write_pagelist;
	struct list_head iodlist;
};

typedef int (CLUSTER_end_io_t)(struct bio *, int);

struct task_overlap_data {
	// vfs
	struct file *file;
	char __user *buf;
	size_t count;
	loff_t *pos;

	// fs
	struct list_head pagelist;
	int page_count, bio_count;
	CLUSTER_end_io_t *end_io;

	// polling
	int tag;

	// journaling
	void *journal;
};

DECLARE_PER_CPU(struct CLUSTER_table, CLUSTER_tables);

#endif /* __KERNEL__ */
#endif /* _LINUX_CLUSTER_H */

