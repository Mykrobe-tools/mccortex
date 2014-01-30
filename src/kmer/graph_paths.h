#ifndef GRAPH_PATH_H_
#define GRAPH_PATH_H_

#include "cortex_types.h"
#include "db_graph.h"
#include "db_node.h"

// Returns true if new to colour, false otherwise
// packed points to <PathLen><PackedSeq>
// Returns address of path in PathStore by setting newidx
boolean graph_paths_find_or_add_mt(hkey_t hkey, dBGraph *db_graph, Colour ctpcol,
                                   const uint8_t *packed, size_t plen,
                                   PathIndex *newidx);

//
// Functions on graph+paths
//

// col is graph colour
// packed is just <PackedBases>
void graph_path_check_valid(dBNode node, size_t col, const uint8_t *packed,
                            size_t nbases, const dBGraph *db_graph);

void graph_paths_check_all_paths(const dBGraph *db_graph,
                                 size_t ctxcol, size_t ctpcol);

void graph_path_check_path(hkey_t node, PathIndex pindex,
                           size_t ctxcol, size_t ctpcol,
                           const dBGraph *db_graph);

//
// Check
//
// For debugging
void graph_paths_check_counts(const dBGraph *db_graph);

#endif /* GRAPH_PATH_H_ */