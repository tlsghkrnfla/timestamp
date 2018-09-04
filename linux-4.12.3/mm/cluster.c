/*
 *	// CLUSTER
 *	linux/mm/cluster.c
 *
 */

#include <linux/fs.h>
#include <linux/list.h>
#include <linux/sched.h>
#include <linux/mm_types.h>
#include <linux/mm.h>
#include <linux/pagemap.h>
#include <linux/file.h>
#include <linux/swap.h>
#include <linux/writeback.h>
#include <linux/uio.h>
#include <linux/sched/signal.h>
#include <linux/cluster.h>

DEFINE_PER_CPU(struct CLUSTER_table, CLUSTER_tables);
EXPORT_PER_CPU_SYMBOL(CLUSTER_tables);

struct CLUSTER_table cluster_table;
struct CLUSTER_table *get_CLUSTER_table(void)
{
	return &cluster_table;
}
EXPORT_SYMBOL(get_CLUSTER_table);

