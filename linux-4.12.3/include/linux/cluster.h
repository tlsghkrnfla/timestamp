#ifndef _LINUX_CLUSTER_H
#define _LINUX_CLUSTER_H

#include <linux/errno.h>

#ifdef __KERNEL__

#include <linux/mmdebug.h>
#include <linux/gfp.h>
#include <linux/bug.h>
#include <linux/list.h>
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
#include <linux/page_ref.h>

struct CLUSTER_nvme_operations {
	void (*CLUSTER_nvme_queue_rq)(void *);
};

struct CLUSTER_table {
	struct CLUSTER_nvme_operations *CLUSTER_nvme_ops;
	struct list_head *pagelist;
};

DECLARE_PER_CPU(struct list_head, CLUSTER_pagelist);

struct CLUSTER_table *get_CLUSTER_table(void);
ssize_t CLUSTER_do_generic_file_read(struct file *filp, loff_t *ppos,
								struct iov_iter *iter, ssize_t written);

#endif /* __KERNEL__ */
#endif /* _LINUX_CLUSTER_H */

