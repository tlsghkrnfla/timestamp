/*
 *	// CLUSTER
 *	linux/mm/cluster.c
 *
 */

#include <linux/cluster.h>

DEFINE_PER_CPU(struct CLUSTER_table, CLUSTER_tables);
EXPORT_PER_CPU_SYMBOL(CLUSTER_tables);

